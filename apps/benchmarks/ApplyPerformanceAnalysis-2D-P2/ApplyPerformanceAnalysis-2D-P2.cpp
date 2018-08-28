
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
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"
#include "tinyhhg_core/primitivestorage/loadbalancing/SimpleBalancer.hpp"
#include "tinyhhg_core/p1functionspace/VertexDoFMacroFace.hpp"
#include "tinyhhg_core/mixedoperators/EdgeDoFToVertexDoFOperator/EdgeDoFToVertexDoFApply.hpp"

using walberla::real_t;

static void performBenchmark( hhg::P2Function< double > & src, hhg::P2Function< double > & dst, hhg::P2ConstantLaplaceOperator & laplace,
                              const uint_t & level, Face & face, const uint_t & sampleSize, walberla::WcTimingTree & timingTree )
{
  const std::string benchInfoString = "level" + (level < 10 ? "0" + std::to_string( level ) : std::to_string( level ) ) + "-" + "sampleSize" + std::to_string( sampleSize );

  /// Vertex to Vertex
  for ( uint_t i = 0; i < sampleSize; i++ )
  {
    timingTree.start( "Vertex-to-Vertex-Apply-" + benchInfoString );
    LIKWID_MARKER_START( "Vertex-to-Vertex-Apply-" + benchInfoString );
    hhg::vertexdof::macroface::apply( level, face,
                                      laplace.getVertexToVertexOpr().getFaceStencilID(),
                                      src.getVertexDoFFunction()->getFaceDataID(),
                                      dst.getVertexDoFFunction()->getFaceDataID(),
                                      hhg::Replace );
    LIKWID_MARKER_STOP( "Vertex-to-Vertex-Apply-" + benchInfoString );
    timingTree.stop( "Vertex-to-Vertex-Apply-" + benchInfoString );
  }

  /// Edge to Vertex
  for ( uint_t i = 0; i < sampleSize; i++ )
  {
    timingTree.start( "Edge-to-Vertex-Apply-" + benchInfoString );
    LIKWID_MARKER_START( "Edge-to-Vertex-Apply-" + benchInfoString );
    hhg::EdgeDoFToVertexDoF::applyFace( level, face,
                                        laplace.getEdgeToVertexOpr().getFaceStencilID(),
                                        src.getEdgeDoFFunction()->getFaceDataID(),
                                        dst.getVertexDoFFunction()->getFaceDataID(),
                                        hhg::Replace );
    LIKWID_MARKER_STOP( "Edge-to-Vertex-Apply-" + benchInfoString );
    timingTree.stop( "Edge-to-Vertex-Apply-" + benchInfoString );
  }

  /// Edge to Edge
  for ( uint_t i = 0; i < sampleSize; i++ )
  {
    timingTree.start( "Edge-to-Edge-Apply-" + benchInfoString );
    LIKWID_MARKER_START( "Edge-to-Edge-Apply-" + benchInfoString );
    hhg::edgedof::macroface::apply( level, face,
                                    laplace.getEdgeToEdgeOpr().getFaceStencilID(),
                                    src.getEdgeDoFFunction()->getFaceDataID(),
                                    dst.getEdgeDoFFunction()->getFaceDataID(),
                                    hhg::Replace );
    LIKWID_MARKER_STOP( "Edge-to-Edge-Apply-" + benchInfoString );
    timingTree.stop( "Edge-to-Edge-Apply-" + benchInfoString );
  }

  /// Vertex to Edge
  for ( uint_t i = 0; i < sampleSize; i++ )
  {
    timingTree.start( "Vertex-to-Edge-Apply-" + benchInfoString );
    LIKWID_MARKER_START( "Vertex-to-Edge-Apply-" + benchInfoString );
    hhg::VertexDoFToEdgeDoF::applyFace( level, face,
                                        laplace.getEdgeToVertexOpr().getFaceStencilID(),
                                        src.getVertexDoFFunction()->getFaceDataID(),
                                        dst.getEdgeDoFFunction()->getFaceDataID(),
                                        hhg::Replace );
    LIKWID_MARKER_STOP( "Vertex-to-Edge-Apply-" + benchInfoString );
    timingTree.stop( "Vertex-to-Edge-Apply-" + benchInfoString );
  }
}

int main( int argc, char* argv[] )
{
   LIKWID_MARKER_INIT;

   walberla::Environment env( argc, argv );
   walberla::MPIManager::instance()->useWorldComm();

   walberla::WcTimingTree wcTimingTreeApp;

   LIKWID_MARKER_THREADINIT;

   ///// Parameters /////

   auto cfg = std::make_shared< walberla::config::Config >();
   if( env.config() == nullptr )
   {
      auto defaultFile = "./ApplyPerformanceAnalysis-2D-P2.prm";
      WALBERLA_LOG_PROGRESS_ON_ROOT( "No Parameter file given loading default parameter file: " << defaultFile );
      cfg->readParameterFile( defaultFile );
   } else
   {
      cfg = env.config();
   }
   const walberla::Config::BlockHandle mainConf = cfg->getBlock( "Parameters" );

   const uint_t      minLevel        = mainConf.getParameter< uint_t >( "minLevel" );
   const uint_t      maxLevel        = mainConf.getParameter< uint_t >( "maxLevel" );
   const std::string meshFileName    = mainConf.getParameter< std::string >( "mesh" );

   ///// Mesh /////

   hhg::MeshInfo meshInfo = hhg::MeshInfo::fromGmshFile( meshFileName );
   hhg::SetupPrimitiveStorage setupStorage( meshInfo, walberla::uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );
   hhg::loadbalancing::roundRobin( setupStorage );

   std::shared_ptr< hhg::PrimitiveStorage > storage = std::make_shared< hhg::PrimitiveStorage >( setupStorage );

   std::function< real_t( const hhg::Point3D& ) > exact = []( const hhg::Point3D& xx ) {
       return std::sin( walberla::math::PI * xx[0] ) + std::cos( walberla::math::PI * xx[1] );
   };

   std::shared_ptr< walberla::WcTimingTree > timingTree( new walberla::WcTimingTree() );
   storage->setTimingTree( timingTree );

   ///// Functions / operators / allocation /////

   hhg::P2Function< double > src( "src", storage, minLevel, maxLevel );
   hhg::P2Function< double > dst( "dst", storage, minLevel, maxLevel );

   hhg::P2ConstantLaplaceOperator laplace( storage, minLevel, maxLevel );

   for ( uint_t level = minLevel; level <= maxLevel; level++ )
   {
     src.interpolate( exact, level, hhg::Inner );
   }

   ///// Apply benchmarks /////

   std::vector< PrimitiveID > macroFaces = storage->getFaceIDs();
   WALBERLA_CHECK_EQUAL( macroFaces.size(), 1 );
   auto face = storage->getFace( macroFaces.front() );

   for ( uint_t level = minLevel; level <= maxLevel; level++ )
   {
     WALBERLA_CHECK_LESS_EQUAL( maxLevel, 14 );
     uint_t sampleSize = (1 << (14 - level));
     performBenchmark( src, dst, laplace, level, *face, sampleSize, wcTimingTreeApp );
   }

   auto wcTPReduced = wcTimingTreeApp.getReduced();
   WALBERLA_LOG_INFO_ON_ROOT( wcTPReduced );

   walberla::WcTimingTree tt  = timingTree->getReduced();
   auto                   tt2 = tt.getCopyWithRemainder();
   WALBERLA_LOG_INFO_ON_ROOT(tt2);

   nlohmann::json ttJson;
   walberla::timing::to_json( ttJson, wcTPReduced );
   std::ofstream jsonOutput;
   jsonOutput.open ( "ApplyPerformanceAnalysis-2D-P2.json" );
   jsonOutput << ttJson.dump(4);
   jsonOutput.close();

   if( mainConf.getParameter< bool >( "VTKOutput" ) )
   {
      WALBERLA_LOG_INFO_ON_ROOT( "Writing VTK output" );
      hhg::VTKOutput vtkOutput( "./output", "ApplyPerformanceAnalysis-2D-P2.cpp" );
      vtkOutput.add( &src );
      vtkOutput.add( &dst );
      vtkOutput.write( maxLevel );
   }

   LIKWID_MARKER_CLOSE;
}
