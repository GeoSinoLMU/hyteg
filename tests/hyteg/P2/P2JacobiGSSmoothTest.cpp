/*
 * Copyright (c) 2017-2019 Marcus Mohr.
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
#include <hyteg/communication/Syncing.hpp>
#include <hyteg/p1functionspace/VertexDoFMacroEdge.hpp>
#include <hyteg/p1functionspace/VertexDoFMacroFace.hpp>

#include "core/Environment.h"
#include "core/math/Random.h"

#include "hyteg/VTKWriter.hpp"
#include "hyteg/p2functionspace/P2ConstantOperator.hpp"
#include "hyteg/p2functionspace/P2Function.hpp"
#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "hyteg/primitivestorage/loadbalancing/SimpleBalancer.hpp"

using walberla::real_t;
using namespace hyteg;

// ----------------------------------------------------------------
//  Perform a single undamped Jacobi smoothing step on a quadratic
//  polynomial and check that this does not alter the polynomial;
//  do the same for Gauss-Seidel
// ----------------------------------------------------------------

// Coefficients of the test polynomial
#define COEFF_A00 real_c( 2.0 )
#define COEFF_A10 real_c( 0.0 )
#define COEFF_A01 real_c( 0.0 )
#define COEFF_A11 real_c( 1.0 )
#define COEFF_A20 real_c( 0.0 )
#define COEFF_A02 real_c( 0.0 )

int main( int argc, char** argv )
{
   uint_t level     = 2;
   bool   outputVTK = true;

   // Setup enviroment
   walberla::Environment walberlaEnv( argc, argv );
   walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );
   walberla::MPIManager::instance()->useWorldComm();

   // Generate a regular mesh of a square centered around the origin
   // with a cross pattern an 8 triangles
   MeshInfo meshInfo = MeshInfo::meshRectangle( Point2D( {-1.0, -1.0} ), Point2D( {1.0, 1.0} ), MeshInfo::CRISS, 3, 3 );

   // Prepare primitive storage
   SetupPrimitiveStorage setupStorage( meshInfo, uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );
   loadbalancing::roundRobin( setupStorage );
   WALBERLA_LOG_INFO_ON_ROOT( setupStorage );
   std::shared_ptr< PrimitiveStorage > storage = std::make_shared< PrimitiveStorage >( setupStorage );

   // Setup polynomial
   std::function< real_t( const Point3D& ) > myPolyFunc = []( const Point3D& x ) {
      real_t val = COEFF_A00 + COEFF_A10 * x[0] + COEFF_A01 * x[1] + COEFF_A11 * x[0] * x[1];
      val += COEFF_A20 * x[0] * x[0] + COEFF_A02 * x[1] * x[1];
      return val;
   };
   P2Function< real_t > poly( "quadratic polynomial", storage, level, level );
   poly.interpolate( myPolyFunc, level );

   // Setup right-hand side
   P2ConstantMassOperator massOp( storage, level, level );
   P2Function< real_t >   rhs( "right-hand side", storage, level, level );
   rhs.interpolate( -2.0 * ( COEFF_A20 + COEFF_A02 ), level );
   massOp.apply( rhs, rhs, level, Inner );
   rhs.interpolate( 0.0, level, DirichletBoundary );

   // Execute a single Jacobi smoothing step
   P2ConstantLaplaceOperator Lap( storage, level, level );
   P2Function< real_t >      smoothedJac( "after one Jacobi step", storage, level, level );
   Lap.smooth_jac( smoothedJac, rhs, poly, 1.0, level, Inner );

   // Execute a single Gauss-Seidel smoothing step
   P2Function< real_t > smoothedGS( "after one GS step", storage, level, level );
   smoothedGS.assign( {1.0}, {poly}, level, All );
   Lap.smooth_gs( smoothedGS, rhs, level, Inner );

   // Compute difference to before
   P2Function< real_t > differenceJac( "difference Jacobi", storage, level, level );
   P2Function< real_t > differenceGS( "difference Gauss-Seidel", storage, level, level );
   differenceJac.assign( {1.0, -1.0}, {poly, smoothedJac}, level, Inner );
   differenceGS.assign( {1.0, -1.0}, {poly, smoothedGS}, level, Inner );

   // output data for visualisation
   if ( outputVTK )
   {
      VTKOutput vtkOutput( "../../output", "P2JacobiGSSmoothTest", storage );
      vtkOutput.add( poly );
      vtkOutput.add( differenceGS );
      vtkOutput.add( differenceJac );
      vtkOutput.add( smoothedGS );
      vtkOutput.add( smoothedJac );
      vtkOutput.write( level );
   }

   real_t errorNorm = real_c( 0.0 );

   // Check size of difference for Gauss-Seidel smoother
   errorNorm = std::sqrt( differenceGS.dotGlobal( differenceGS, level ) );
   WALBERLA_CHECK_LESS( errorNorm, 2e-13 );
   errorNorm = differenceGS.getMaxMagnitude( level );
   WALBERLA_CHECK_LESS( errorNorm, 1e-13 );
   WALBERLA_LOG_INFO_ON_ROOT( "Check passed for Gaus-Seidel" );

   // Check size of difference for Jacobi smoother
   errorNorm = std::sqrt( differenceJac.dotGlobal( differenceJac, level ) );
   WALBERLA_CHECK_LESS( errorNorm, 2e-13 );
   errorNorm = differenceJac.getMaxMagnitude( level );
   WALBERLA_CHECK_LESS( errorNorm, 1e-13 );
   WALBERLA_LOG_INFO_ON_ROOT( "Check passed for Jacobi" );

   return EXIT_SUCCESS;
}