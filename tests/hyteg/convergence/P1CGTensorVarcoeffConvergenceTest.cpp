/*
 * Copyright (c) 2017-2019 Dominik Thoennes.
 *
 * This file is part of HyTeG
 * (see https://i10git.cs.fau.de/hyteg/hyteg).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <core/Environment.h>
#include <core/timing/Timer.h>

#include "core/Format.hpp"
#include "hyteg/dataexport/VTKOutput.hpp"
#include "hyteg/p1functionspace/P1CoefficientOperator.hpp"
#include "hyteg/p1functionspace/P1ConstantOperator.hpp"
#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/primitivestorage/PrimitiveStorage.hpp"
#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "hyteg/primitivestorage/loadbalancing/SimpleBalancer.hpp"
#include "hyteg/solvers/CGSolver.hpp"

using walberla::real_t;
using walberla::uint_c;
using walberla::uint_t;

using namespace hyteg;

int main( int argc, char* argv[] )
{
   walberla::Environment walberlaEnv( argc, argv );
   walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );
   walberla::MPIManager::instance()->useWorldComm();

   std::string meshFileName = "../../data/meshes/quad_2el.msh";

   MeshInfo              meshInfo = MeshInfo::fromGmshFile( meshFileName );
   SetupPrimitiveStorage setupStorage( meshInfo, uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );

   hyteg::loadbalancing::roundRobin( setupStorage );

   size_t minLevel = 2;
   size_t maxLevel = 4;

   std::shared_ptr< PrimitiveStorage > storage = std::make_shared< PrimitiveStorage >( setupStorage );

   hyteg::P1Function< real_t >               r( "r", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >               f( "f", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >               u( "u", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >               u_exact( "u_exact", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >               err( "err", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >               npoints_helper( "npoints_helper", storage, minLevel, maxLevel );
   std::shared_ptr< P1Function< real_t > > coefficient_11 =
       std::make_shared< P1Function< real_t > >( "coeff_11", storage, minLevel, maxLevel );
   std::shared_ptr< P1Function< real_t > > coefficient_12 =
       std::make_shared< P1Function< real_t > >( "coeff_12", storage, minLevel, maxLevel );
   std::shared_ptr< P1Function< real_t > > coefficient_22 =
       std::make_shared< P1Function< real_t > >( "coeff_22", storage, minLevel, maxLevel );
   std::vector< std::shared_ptr< P1Function< real_t > > > coefficients;
   coefficients.push_back( coefficient_11 );
   coefficients.push_back( coefficient_12 );
   coefficients.push_back( coefficient_22 );

   hyteg::P1MassOperator                     M( storage, minLevel, maxLevel );
   hyteg::P1TensorCoefficientLaplaceOperator L( storage, coefficients, minLevel, maxLevel );

   std::shared_ptr< walberla::WcTimingTree > timingTree( new walberla::WcTimingTree() );
   r.enableTiming( timingTree );
   f.enableTiming( timingTree );
   u.enableTiming( timingTree );
   u_exact.enableTiming( timingTree );
   err.enableTiming( timingTree );
   npoints_helper.enableTiming( timingTree );

   L.enableTiming( timingTree );

   std::function< real_t( const hyteg::Point3D& ) > coeff_11 = []( const hyteg::Point3D& x ) {
      return 7 * pow( x[0], 2 ) + 3 * x[0] + 4 * x[1] + 1;
   };
   std::function< real_t( const hyteg::Point3D& ) > coeff_12 = []( const hyteg::Point3D& x ) {
      return 4 * pow( x[0], 2 ) + 2 * x[0] + 3 * x[1] + 1;
   };
   std::function< real_t( const hyteg::Point3D& ) > coeff_22 = []( const hyteg::Point3D& x ) {
      return 8 * pow( x[0], 2 ) + 4 * x[0] + 5 * x[1] + 1;
   };
   std::function< real_t( const hyteg::Point3D& ) > exact = []( const hyteg::Point3D& x ) { return sin( x[0] ) * sinh( x[1] ); };
   std::function< real_t( const hyteg::Point3D& ) > rhs   = []( const hyteg::Point3D& x ) {
      return -2 * ( 4 * x[0] + 1 ) * sin( x[0] ) * cosh( x[1] ) - ( 14 * x[0] + 3 ) * cos( x[0] ) * sinh( x[1] ) -
             2 * ( 4 * pow( x[0], 2 ) + 2 * x[0] + 3 * x[1] + 1 ) * cos( x[0] ) * cosh( x[1] ) +
             ( 7 * pow( x[0], 2 ) + 3 * x[0] + 4 * x[1] + 1 ) * sin( x[0] ) * sinh( x[1] ) -
             ( 8 * pow( x[0], 2 ) + 4 * x[0] + 5 * x[1] + 1 ) * sin( x[0] ) * sinh( x[1] ) - 5 * sin( x[0] ) * cosh( x[1] ) -
             3 * cos( x[0] ) * sinh( x[1] );
   };
   std::function< real_t( const hyteg::Point3D& ) > ones = []( const hyteg::Point3D& ) { return 1.0; };

   u.interpolate( exact, maxLevel, hyteg::DirichletBoundary );
   coefficient_11->interpolate( coeff_11, maxLevel );
   coefficient_12->interpolate( coeff_12, maxLevel );
   coefficient_22->interpolate( coeff_22, maxLevel );
   u_exact.interpolate( exact, maxLevel );
   npoints_helper.interpolate( rhs, maxLevel );
   M.apply( npoints_helper, f, maxLevel, hyteg::All );

   //  typedef hyteg::GaussSeidelPreconditioner<hyteg::P1Function< real_t >, hyteg::P1ConstantLaplaceOperator> PreconditionerType;
   //  auto prec = std::make_shared<PreconditionerType>(L, 30);

   auto solver =
       hyteg::CGSolver< hyteg::P1TensorCoefficientLaplaceOperator >( storage, minLevel, maxLevel );
   walberla::WcTimer timer;
   solver.solve( L, u, f,  maxLevel);
   timer.end();
   WALBERLA_LOG_INFO_ON_ROOT( walberla::format( "time was: %f", timer.last() ) );
   err.assign( {1.0, -1.0}, {u, u_exact}, maxLevel );

   npoints_helper.interpolate( ones, maxLevel );
   real_t npoints = npoints_helper.dotGlobal( npoints_helper, maxLevel );

   real_t discr_l2_err = std::sqrt( err.dotGlobal( err, maxLevel ) / npoints );

   WALBERLA_LOG_INFO_ON_ROOT( "discrete L2 error = " << discr_l2_err );

   //hyteg::VTKWriter< P1Function< real_t > >({ u, u_exact, &f, &r, &err, coefficient.get() }, maxLevel, "../output", "cg_P1_varcoeff");

   walberla::WcTimingTree tt = timingTree->getReduced();
   WALBERLA_LOG_INFO_ON_ROOT( tt );

   WALBERLA_CHECK_LESS( discr_l2_err, 9.1e-05 );

   return 0;
}
