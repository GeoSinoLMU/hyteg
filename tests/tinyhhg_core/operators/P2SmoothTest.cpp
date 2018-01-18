#include "core/Environment.h"
#include "core/debug/CheckFunctions.h"
#include "core/debug/TestSubsystem.h"
#include "core/timing/all.h"

#include "tinyhhg_core/p2functionspace/P2Function.hpp"
#include "tinyhhg_core/p2functionspace/P2ConstantOperator.hpp"
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"


namespace hhg {

static void testP2Smooth() {
  const uint_t level = 2;

  MeshInfo mesh = MeshInfo::fromGmshFile("../../data/meshes/tri_1el.msh");

  SetupPrimitiveStorage setupStorage(mesh, uint_c(walberla::mpi::MPIManager::instance()->numProcesses()));

  std::shared_ptr <PrimitiveStorage> storage = std::make_shared<PrimitiveStorage>(setupStorage);

  auto x = std::make_shared < P2Function < real_t > > ("x", storage, level, level);
  auto rhs = std::make_shared < P2Function < real_t > > ("rhs", storage, level, level);

  P2ConstantLaplaceOperator p2operator( storage, level, level );



  for(auto faceIt : storage->getFaces()){
    auto face = faceIt.second;
    hhg::P2::face::smoothGSvertexDoFTmpl< 5 >(*face,
                                         p2operator.getVertexToVertexOpr().getFaceStencilID(),
                                         x->getVertexDoFFunction()->getFaceDataID(),
        p2operator.getEdgeToVertexOpr().getFaceStencilID(),
        x->getEdgeDoFFunction()->getFaceDataID(),
    rhs->getVertexDoFFunction()->getFaceDataID());


  }
}

}/// namespace hhg

int main( int argc, char* argv[] )
{
  walberla::debug::enterTestMode();

  walberla::Environment walberlaEnv(argc, argv);
  walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );
  walberla::MPIManager::instance()->useWorldComm();
  hhg::testP2Smooth();

  return EXIT_SUCCESS;
}