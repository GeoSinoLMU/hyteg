
#include "tinyhhg_core/tinyhhg.hpp"
#include "core/debug/CheckFunctions.h"
#include "core/debug/TestSubsystem.h"
#include "core/mpi/SendBuffer.h"
#include "core/mpi/RecvBuffer.h"

namespace hhg {

std::string getExampleMeshFileContent()
{
  std::string content =
  "$MeshFormat\n"
  "2.2 0 8\n"
  "$EndMeshFormat\n"
  "$Nodes\n"
  "4\n"
  "1 0 0 0\n"
  "2 1 0 0\n"
  "3 0 1 0\n"
  "4 1 1 0\n"
  "$EndNodes\n"
  "$Elements\n"
  "9\n"
  "1 15 2 1 1 1\n"
  "2 15 2 1 2 2\n"
  "3 15 2 1 3 3\n"
  "4 1 2 1 1 1 2\n"
  "5 1 2 1 2 2 4\n"
  "6 1 2 1 2 4 3\n"
  "7 1 2 1 3 3 1\n"
  "8 2 2 0 5 2 4 1\n"
  "9 2 2 0 5 1 4 3\n"
  "$EndElements\n";

  return content;
}

class TestData
{
public:
  bool a = false;
  int i = 100;
  std::vector<bool> aa;
};

class VertexTestData
{
public:
  bool a = false;
  int i = 200;
  std::vector<bool> aa;
};

class EdgeTestData
{
public:
  bool a = false;
  int i = 300;
  std::vector<bool> aa;
};

class TestDataHandling : public NoSerializePrimitiveDataHandling< TestData >
{
public:

  TestData * initialize( const Primitive * const block ) const
  {
    TestData * testData = new TestData();
    testData->i = 7777;
    return testData;
  }

};

class VertexTestDataHandling : public NoSerializePrimitiveDataHandling< VertexTestData >
{
public:

  VertexTestData * initialize( const Primitive * const block ) const
  {
    VertexTestData * testData = new VertexTestData();
    testData->i = 8888;
    return testData;
  }

};

class EdgeTestDataHandling : public NoSerializePrimitiveDataHandling< EdgeTestData >
{
public:

  EdgeTestData * initialize( const Primitive * const block ) const
  {
    EdgeTestData * testData = new EdgeTestData();
    testData->i = 9999;
    return testData;
  }

};

static void testPrimitiveData()
{

  std::string meshFileName = "./tmpMeshFile.msh";
  std::string meshFileContent = getExampleMeshFileContent();
  std::ofstream file( meshFileName );
  file << meshFileContent;
  file.close();

  MeshInfo meshInfo( meshFileName );
  SetupPrimitiveStorage setupStorage( meshInfo );
  PrimitiveStorage storage( setupStorage );

  PrimitiveID primitiveID = storage.addVertex();
  Vertex *primitive = storage.getVertex( primitiveID );


  TestDataHandling testDataHandling;
  VertexTestDataHandling vertexTestDataHandling;
  EdgeTestDataHandling edgeTestDataHandling;

  PrimitiveDataID< TestData > testDataID = storage.addPrimitiveData( testDataHandling, "primitive data" );
  TestData * testData = primitive->getData( testDataID );
  WALBERLA_CHECK_EQUAL( testData->i, 7777 );

  PrimitiveDataID< VertexTestData > vertexTestDataID = storage.addVertexData( vertexTestDataHandling, "vertex data" );
  VertexTestData * vertexTestData = primitive->getData( vertexTestDataID );
  WALBERLA_CHECK_EQUAL( vertexTestData->i, 8888 );


#if 0
  TestData *p_testData = primitive.getData( testDataID );
  OtherTestData *p_otherTestData = primitive.getData( otherTestDataID );

  WALBERLA_CHECK_EQUAL( p_testData->i, 100 );
  WALBERLA_CHECK_EQUAL( p_otherTestData->i, 200 );
#endif
}

} // namespace hhg


int main(int argc, char* argv[])
{
   walberla::debug::enterTestMode();

   walberla::Environment walberlaEnv(argc, argv);
   walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::TRACING );
   walberla::MPIManager::instance()->useWorldComm();
   hhg::testPrimitiveData();

   return EXIT_SUCCESS;
}
