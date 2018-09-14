
#include "core/DataTypes.h"
#include "core/Environment.h"
#include "core/config/Config.h"
#include "core/mpi/MPIManager.h"

#include "tinyhhg_core/LikwidWrapper.hpp"
#include "tinyhhg_core/VTKWriter.hpp"
#include "tinyhhg_core/mesh/MeshInfo.hpp"
#include "tinyhhg_core/p2functionspace/P2ConstantOperator.hpp"
#include "tinyhhg_core/p2functionspace/P2Function.hpp"
#include "tinyhhg_core/p2functionspace/P2Petsc.hpp"
#include "tinyhhg_core/petsc/PETScLUSolver.hpp"
#include "tinyhhg_core/petsc/PETScManager.hpp"
#include "tinyhhg_core/petsc/PETScSparseMatrix.hpp"
#include "tinyhhg_core/petsc/PETScVector.hpp"
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"
#include "tinyhhg_core/primitivestorage/loadbalancing/SimpleBalancer.hpp"

using walberla::real_t;

int main( int argc, char* argv[] )
{
   LIKWID_MARKER_INIT;

   walberla::Environment env( argc, argv );
   walberla::MPIManager::instance()->useWorldComm();

   walberla::WcTimingTree wcTimingTreeApp;

   LIKWID_MARKER_THREADINIT;

   PETScManager petscManager;

   auto cfg = std::make_shared< walberla::config::Config >();
   if( env.config() == nullptr )
   {
      auto defaultFile = "./PetscCompare-2D-P2-Apply.prm";
      WALBERLA_LOG_PROGRESS_ON_ROOT( "No Parameter file given loading default parameter file: " << defaultFile );
      cfg->readParameterFile( defaultFile );
   } else
   {
      cfg = env.config();
   }
   const walberla::Config::BlockHandle mainConf = cfg->getBlock( "Parameters" );

   const uint_t level = mainConf.getParameter< uint_t >( "level" );

   std::string meshFileName = mainConf.getParameter< std::string >( "mesh" );

   wcTimingTreeApp.start( "Mesh setup + load balancing" );
   hhg::MeshInfo meshInfo = hhg::MeshInfo::fromGmshFile( meshFileName );

   //hhg::MeshInfo::meshUnitSquare( 2 );

   hhg::SetupPrimitiveStorage setupStorage( meshInfo, walberla::uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );

   hhg::loadbalancing::roundRobin( setupStorage );

   std::shared_ptr< hhg::PrimitiveStorage > storage = std::make_shared< hhg::PrimitiveStorage >( setupStorage );
   wcTimingTreeApp.stop( "Mesh setup + load balancing" );

   std::function< real_t( const hhg::Point3D& ) > ones  = []( const hhg::Point3D& ) { return 1.0; };
   std::function< real_t( const hhg::Point3D& ) > exact = []( const hhg::Point3D& xx ) {
       //return 5.0;
       return std::sin( walberla::math::PI * xx[0] ) + std::cos( walberla::math::PI * xx[1] );
       //return ( real_c(std::rand()) / real_c(RAND_MAX));
   };

   std::shared_ptr< walberla::WcTimingTree > timingTree( new walberla::WcTimingTree() );
   storage->setTimingTree( timingTree );

   wcTimingTreeApp.start( "Function allocation" );
   hhg::P2Function< double > oneFunc( "x", storage, level, level );
   hhg::P2Function< double > x( "x", storage, level, level );
   hhg::P2Function< double > y( "y", storage, level, level );
   hhg::P2Function< double > z( "z", storage, level, level );
   hhg::P2Function< double > diff( "diff", storage, level, level );
   hhg::P2Function< PetscInt >    numerator( "numerator", storage, level, level );
   wcTimingTreeApp.stop( "Function allocation" );

   wcTimingTreeApp.start( "Operator assembly" );
   hhg::P2ConstantLaplaceOperator mass( storage, level, level );
   wcTimingTreeApp.stop( "Operator assembly" );

   wcTimingTreeApp.start( "Interpolation" );
   x.interpolate( exact, level, hhg::Inner );
   oneFunc.interpolate( ones, level );
   wcTimingTreeApp.stop( "Interpolation" );

   wcTimingTreeApp.start( "Enumeration" );
   const uint_t globalDoFs = hhg::numberOfGlobalDoFs< P2FunctionTag >( *storage, level );
   const uint_t localDoFs = hhg::numberOfLocalDoFs< P2FunctionTag >( *storage, level );
   numerator.enumerate( level );
   wcTimingTreeApp.stop( "Enumeration" );

   wcTimingTreeApp.start( "Petsc setup" );
   hhg::PETScSparseMatrix< hhg::P2ConstantLaplaceOperator, hhg::P2Function > matPetsc( localDoFs, globalDoFs );
   matPetsc.createMatrixFromFunction( mass, level, numerator, hhg::Inner );
   hhg::PETScVector< real_t, hhg::P2Function > vecPetsc( localDoFs );
   vecPetsc.createVectorFromFunction( x, numerator, level, hhg::Inner );
   hhg::PETScVector< real_t, hhg::P2Function > dstvecPetsc( localDoFs );
   wcTimingTreeApp.stop( "Petsc setup" );

   wcTimingTreeApp.start( "HyTeG apply" );
   LIKWID_MARKER_START( "HyTeG-apply" );
   mass.apply( x, y, level, hhg::Inner );
   LIKWID_MARKER_STOP( "HyTeG-apply" );
   wcTimingTreeApp.stop( "HyTeG apply" );

   //vecPetsc.print("../output/vector0.vec");
   PetscErrorCode ierr;

   wcTimingTreeApp.start( "Petsc apply" );
   LIKWID_MARKER_START( "Petsc-MatMult" );
   ierr = MatMult( matPetsc.get(), vecPetsc.get(), dstvecPetsc.get() );
   LIKWID_MARKER_STOP( "Petsc-MatMult" );
   wcTimingTreeApp.stop( "Petsc apply" );

   CHKERRQ( ierr );

   dstvecPetsc.createFunctionFromVector( z, numerator, level, hhg::Inner );

   // WALBERLA_LOG_INFO_ON_ROOT( y.dotGlobal( oneFunc, level, hhg::Inner ) );
   // WALBERLA_LOG_INFO_ON_ROOT( z.dotGlobal( oneFunc, level, hhg::Inner ) );

   //dstvecPetsc.print("../output/vector1.vec");

   auto wcTPReduced = wcTimingTreeApp.getReduced();
   WALBERLA_LOG_INFO_ON_ROOT( wcTPReduced );

   walberla::WcTimingTree tt  = timingTree->getReduced();
   auto                   tt2 = tt.getCopyWithRemainder();
   WALBERLA_LOG_INFO_ON_ROOT(tt2);

   nlohmann::json ttJson;
   walberla::timing::to_json( ttJson, tt2 );
   std::ofstream jsonOutput;
   jsonOutput.open ( "TimingTree.json" );
   jsonOutput << ttJson.dump(4);
   jsonOutput.close();

   diff.assign( {1.0, -1.0}, {&z, &y}, level, hhg::All );

   if( mainConf.getParameter< bool >( "VTKOutput" ) )
   {
      WALBERLA_LOG_INFO_ON_ROOT("writing VTK output");
      hhg::VTKOutput vtkOutput( "./output", "PetscCompare-2D-P2-Apply" );
      vtkOutput.add( &x );
      vtkOutput.add( &z );
      vtkOutput.add( &y );
      vtkOutput.add( &diff );
      vtkOutput.write( level );
   }

   WALBERLA_CHECK_FLOAT_EQUAL( y.dotGlobal( oneFunc, level, hhg::Inner ), z.dotGlobal( oneFunc, level, hhg::Inner ) )

   LIKWID_MARKER_CLOSE;
}