#include "tinyhhg_core/tinyhhg.hpp"
#include "tinyhhg_core/primitivedata/PrimitiveDataID.hpp"
//#include "tinyhhg_core/p1bubblefunctionspace/p1bubblememory.hpp"


using namespace hhg::communication;
using namespace hhg;

int main (int argc, char** argv) {
  walberla::mpi::Environment MPIenv( argc, argv);
  walberla::MPIManager::instance()->useWorldComm();
//  hhg::PrimitiveDataID<VertexP1BubbleFunctionMemory, Vertex> vertexid;
//  hhg::PrimitiveDataID<EdgeP1BubbleFunctionMemory,   Edge  > edgeid;
//  hhg::PrimitiveDataID<FaceP1BubbleFunctionMemory,   Face  > faceid;
//  uint_t level = 3;


  //P1BubblePackInfo* packInfo = new P1BubblePackInfo(level,vertexid,edgeid,faceid);

  hhg::MeshInfo meshInfo = MeshInfo::fromGmshFile( "../../data/meshes/tri_2el.msh" );
  hhg::SetupPrimitiveStorage setupStorage( meshInfo, 1 );

  hhg::PrimitiveStorage storage(walberla::MPIManager::instance()->rank() , setupStorage);
  
}