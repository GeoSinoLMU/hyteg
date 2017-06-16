
#include "core/debug/Debug.h"

#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"

#include <algorithm>
#include <set>

namespace hhg {

SetupPrimitiveStorage::SetupPrimitiveStorage( const MeshInfo & meshInfo )
{
  // Adding vertices to storage
  MeshInfo::VertexContainer vertices = meshInfo.getVertices();
  for ( auto it = vertices.begin(); it != vertices.end(); it++ )
  {
    PrimitiveID vertexID( it->first );
    Point3D coordinates( it->second );
    vertices_[ vertexID.getID() ] = new SetupVertex( vertexID, coordinates );
  }

  // Adding edges to storage
  MeshInfo::EdgeContainer edges = meshInfo.getEdges();
  for ( auto it = edges.begin(); it != edges.end(); it++ )
  {
    // Generating edgeID using the largest
    PrimitiveID edgeID = generatePrimitiveID();
    PrimitiveID vertexID0 = PrimitiveID( it->first.first  );
    PrimitiveID vertexID1 = PrimitiveID( it->first.second );
    DoFType dofType = it->second;
    WALBERLA_ASSERT_EQUAL( edges_.count( edgeID.getID() ), 0 );
    WALBERLA_ASSERT_EQUAL( vertices_.count( vertexID0.getID() ), 1 );
    WALBERLA_ASSERT_EQUAL( vertices_.count( vertexID1.getID() ), 1 );
    edges_[ edgeID.getID() ] = new SetupEdge( edgeID, vertexID0, vertexID1, dofType );
  }

  // Adding faces to storage
  MeshInfo::FaceContainer faces = meshInfo.getFaces();
  for ( auto it = faces.begin(); it != faces.end(); it++ )
  {
    PrimitiveID faceID = generatePrimitiveID();
    PrimitiveID vertexID0 = PrimitiveID( (*it)[0] );
    PrimitiveID vertexID1 = PrimitiveID( (*it)[1] );
    PrimitiveID vertexID2 = PrimitiveID( (*it)[2] );

    WALBERLA_ASSERT_EQUAL( faces_.count( faceID.getID() ), 0 );
    WALBERLA_ASSERT_EQUAL( vertices_.count( vertexID0.getID() ), 1 );
    WALBERLA_ASSERT_EQUAL( vertices_.count( vertexID1.getID() ), 1 );
    WALBERLA_ASSERT_EQUAL( vertices_.count( vertexID2.getID() ), 1 );

    PrimitiveID edgeID0;
    PrimitiveID edgeID1;
    PrimitiveID edgeID2;

    bool foundEdge0 = findEdgeByVertexIDs( vertexID0, vertexID1, edgeID0 );
    bool foundEdge1 = findEdgeByVertexIDs( vertexID1, vertexID2, edgeID1 );
    bool foundEdge2 = findEdgeByVertexIDs( vertexID2, vertexID0, edgeID2 );

    WALBERLA_CHECK( foundEdge0 && foundEdge1 && foundEdge2, "Could not successfully construct faces from MeshInfo" );

    WALBERLA_ASSERT_EQUAL( edges_.count( edgeID0.getID() ), 1 );
    WALBERLA_ASSERT_EQUAL( edges_.count( edgeID1.getID() ), 1 );
    WALBERLA_ASSERT_EQUAL( edges_.count( edgeID2.getID() ), 1 );

    faces_[ faceID.getID() ] = new SetupFace( faceID, edgeID0, edgeID1, edgeID2 );
  }
}


bool SetupPrimitiveStorage::findEdgeByVertexIDs( const PrimitiveID & vertexID0, const PrimitiveID & vertexID1, PrimitiveID & edge ) const
{
  if ( vertices_.count( vertexID0.getID() ) == 0 || vertices_.count( vertexID1.getID() ) == 0 )
  {
    return false;
  }

  for ( auto it = edges_.begin(); it != edges_.end(); it++ )
  {
    if (   ( it->second->getVertexID0() == vertexID0 && it->second->getVertexID1() == vertexID1 )
	|| ( it->second->getVertexID0() == vertexID1 && it->second->getVertexID1() == vertexID0 ) )
    {
	edge = PrimitiveID( it->first );
	return true;
    }
  }

  return false;
}


void SetupPrimitiveStorage::toStream( std::ostream & os ) const
{
  os << "\n";

  os << "Vertices:   ID | Position\n"
     << "-------------------------\n";
  for ( auto it = vertices_.begin(); it != vertices_.end(); it++ )
  {
    Point3D coordinates = it->second->getCoordinates();
    os << "          " << std::setw(4) << it->first << " | "  << coordinates << "\n";
  }
  os << "\n";

  os << "Edges:      ID | VertexID_0 | VertexID_1 | DoF Type            \n"
     << "---------------------------------------------------------------\n";
  for ( auto it = edges_.begin(); it != edges_.end(); it++ )
  {
    os << "          " << std::setw(4) << it->first << " | "
       << std::setw(10) << it->second->getVertexID0().getID() << " | "
       << std::setw(10) << it->second->getVertexID1().getID() << " | "
       << std::setw(20) << it->second->getDoFType() << "\n";
  }
  os << "\n";

  os << "Faces:      ID | EdgeID_0 | EdgeID_1 | EdgeID_2\n"
     << "-----------------------------------------------------\n";
  for ( auto it = faces_.begin(); it != faces_.end(); it++ )
  {
    os << "          " << std::setw(4) << it->first << " | "
       << std::setw(8) << it->second->getEdgeID0().getID() << " | "
       << std::setw(8) << it->second->getEdgeID1().getID() << " | "
       << std::setw(8) << it->second->getEdgeID2().getID() << "\n";
  }
}

PrimitiveID SetupPrimitiveStorage::generatePrimitiveID()
{
  uint_t maxIDVertices = vertices_.size() == 0 ? 0 : vertices_.rbegin()->first;
  uint_t maxIDEdges    = edges_.size() == 0 ? 0 : edges_.rbegin()->first;
  uint_t maxIDFaces    = faces_.size() == 0 ? 0 : faces_.rbegin()->first;

  return PrimitiveID( std::max( std::max( maxIDVertices, maxIDFaces ), maxIDEdges ) + 1 );
}

}
