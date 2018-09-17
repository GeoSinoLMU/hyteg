#pragma once

#include "core/mpi/all.h"

#include "tinyhhg_core/Function.hpp"
#include "tinyhhg_core/types/pointnd.hpp"

#include "tinyhhg_core/primitives/Vertex.hpp"
#include "tinyhhg_core/primitives/Edge.hpp"
#include "tinyhhg_core/primitives/Face.hpp"

#include "tinyhhg_core/communication/BufferedCommunication.hpp"

#include "tinyhhg_core/edgedofspace/EdgeDoFMacroCell.hpp"
#include "tinyhhg_core/edgedofspace/EdgeDoFMacroFace.hpp"
#include "tinyhhg_core/edgedofspace/EdgeDoFMacroEdge.hpp"
#include "tinyhhg_core/edgedofspace/EdgeDoFPackInfo.hpp"
#include "tinyhhg_core/FunctionProperties.hpp"
#include "tinyhhg_core/boundary/BoundaryConditions.hpp"

namespace hhg {

using walberla::real_c;

namespace edgedof {
///@name Size Functions
///@{

inline uint_t edgeDoFMacroVertexFunctionMemorySize( const uint_t &level, const Primitive & primitive )
{
  WALBERLA_UNUSED( level );
  return 2 * primitive.getNumNeighborEdges();
}

inline uint_t edgeDoFMacroEdgeFunctionMemorySize( const uint_t &level, const Primitive & primitive )
{
  return levelinfo::num_microedges_per_edge( level ) + primitive.getNumNeighborFaces() * ( 3 * ( levelinfo::num_microedges_per_edge( level ) ) - 1 );
}

inline uint_t edgeDoFMacroFaceFunctionMemorySize( const uint_t &level, const Primitive & primitive )
{
  WALBERLA_UNUSED( primitive );
  return 3 * ( ( ( levelinfo::num_microedges_per_edge( level ) + 1 ) * levelinfo::num_microedges_per_edge( level ) ) / 2 );
}

inline uint_t edgeDoFMacroCellFunctionMemorySize( const uint_t & level, const Primitive & primitive )
{
  WALBERLA_UNUSED( primitive );
  return   6 * ( levelinfo::num_microvertices_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) ) )
         + ( levelinfo::num_microvertices_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) - 1 ) );
}

///@}

}// namespace edgedof

template< typename ValueType >
class EdgeDoFFunction : public Function< EdgeDoFFunction< ValueType > >
{
public:

  EdgeDoFFunction( const std::string & name, const std::shared_ptr< PrimitiveStorage > & storage ) :
    Function< EdgeDoFFunction< ValueType > >( name, storage ),
    vertexDataID_( storage->generateInvalidPrimitiveDataID< MemoryDataHandling< FunctionMemory< ValueType >, Vertex >, Vertex >() ),
    edgeDataID_(   storage->generateInvalidPrimitiveDataID< MemoryDataHandling< FunctionMemory< ValueType >, Edge >,   Edge >() ),
    faceDataID_(   storage->generateInvalidPrimitiveDataID< MemoryDataHandling< FunctionMemory< ValueType >, Face >,   Face >() )
  {}

  EdgeDoFFunction( const std::string & name, const std::shared_ptr< PrimitiveStorage > & storage, const uint_t & minLevel, const uint_t & maxLevel ) :
    EdgeDoFFunction( name, storage, minLevel, maxLevel, BoundaryCondition::create012BC() )
  {}

  EdgeDoFFunction( const std::string & name, const std::shared_ptr< PrimitiveStorage > & storage, const uint_t & minLevel, const uint_t & maxLevel, const BoundaryCondition & boundaryCondition ) :
      Function< EdgeDoFFunction< ValueType > >( name, storage, minLevel, maxLevel ), boundaryCondition_( boundaryCondition )
  {
    std::shared_ptr<MemoryDataHandling<FunctionMemory< ValueType >, Vertex >> vertexDataHandling =
        std::make_shared< MemoryDataHandling<FunctionMemory< ValueType >, Vertex >>(minLevel, maxLevel, edgedof::edgeDoFMacroVertexFunctionMemorySize);

    std::shared_ptr<MemoryDataHandling<FunctionMemory< ValueType >, Edge >> edgeDataHandling   =
        std::make_shared< MemoryDataHandling<FunctionMemory< ValueType >, Edge   >>(minLevel, maxLevel, edgedof::edgeDoFMacroEdgeFunctionMemorySize);

    std::shared_ptr<MemoryDataHandling<FunctionMemory< ValueType >, Face >> faceDataHandling   =
        std::make_shared< MemoryDataHandling<FunctionMemory< ValueType >, Face   >>(minLevel, maxLevel, edgedof::edgeDoFMacroFaceFunctionMemorySize);

    std::shared_ptr<MemoryDataHandling<FunctionMemory< ValueType >, Cell >> cellDataHandling   =
        std::make_shared< MemoryDataHandling<FunctionMemory< ValueType >, Cell   >>(minLevel, maxLevel, edgedof::edgeDoFMacroCellFunctionMemorySize);


    storage->addVertexData( vertexDataID_, vertexDataHandling, name );
    storage->addEdgeData(   edgeDataID_,   edgeDataHandling,   name );
    storage->addFaceData(   faceDataID_,   faceDataHandling,   name );
    storage->addCellData(   cellDataID_,   cellDataHandling,   name );

    for (uint_t level = minLevel; level <= maxLevel; ++level) {
      //communicators_[level]->setLocalCommunicationMode(communication::BufferedCommunicator::BUFFERED_MPI);
      communicators_[level]->addPackInfo(
        std::make_shared<EdgeDoFPackInfo<ValueType> >(level, vertexDataID_, edgeDataID_, faceDataID_, this->getStorage()));
    }
  }

  inline void
  assign( const std::vector< ValueType > scalars, const std::vector< EdgeDoFFunction< ValueType >* > functions,
          uint_t level, DoFType flag = All );

  inline void
  add( const std::vector< ValueType > scalars, const std::vector< EdgeDoFFunction< ValueType >* > functions,
       uint_t level, DoFType flag = All );

  /// Interpolates a given expression to a EdgeDoFFunction

  inline void
  interpolate( const std::function< ValueType( const Point3D & ) >& expr,
                          uint_t level, DoFType flag = All);

  inline void
  interpolateExtended( const std::function<ValueType(const Point3D &, const std::vector<ValueType>&)> &expr,
                       const std::vector<EdgeDoFFunction<ValueType>*> srcFunctions,
                      uint_t level,
                      DoFType flag = All);

  inline real_t
  dotLocal( EdgeDoFFunction< ValueType >& rhs, uint_t level, DoFType flag = All );

  inline void enumerate( uint_t level );

  const PrimitiveDataID< FunctionMemory< ValueType >, Vertex>   & getVertexDataID() const { return vertexDataID_; }
  const PrimitiveDataID< FunctionMemory< ValueType >,   Edge>   & getEdgeDataID()   const { return edgeDataID_; }
  const PrimitiveDataID< FunctionMemory< ValueType >,   Face>   & getFaceDataID()   const { return faceDataID_; }
  const PrimitiveDataID< FunctionMemory< ValueType >,   Cell>   & getCellDataID()   const { return cellDataID_; }


  inline real_t getMaxMagnitude( uint_t level, DoFType flag = All, bool mpiReduce = true );

  inline BoundaryCondition getBoundaryCondition() const { return boundaryCondition_; }

  template< typename SenderType, typename ReceiverType >
  inline void startCommunication( const uint_t & level ) const
  {
    if ( isDummy() ) { return; }
    communicators_.at( level )->template startCommunication< SenderType, ReceiverType >();
  }

  template< typename SenderType, typename ReceiverType >
  inline void endCommunication( const uint_t & level ) const
  {
    if ( isDummy() ) { return; }
    communicators_.at( level )->template endCommunication< SenderType, ReceiverType >();
  }

  template< typename SenderType, typename ReceiverType >
  inline void communicate( const uint_t & level ) const
  {
    if ( isDummy() ) { return; }
    communicators_.at( level )->template communicate< SenderType, ReceiverType >();
  }

  inline void setLocalCommunicationMode( const communication::BufferedCommunicator::LocalCommunicationMode & localCommunicationMode )
  {
    if ( isDummy() ) { return; }
    for ( auto & communicator : communicators_ )
    {
      communicator.second->setLocalCommunicationMode( localCommunicationMode );
    }
  }

   using Function< EdgeDoFFunction< ValueType > >::isDummy;

private:

   inline void enumerate( uint_t level, ValueType& offset );

   using Function< EdgeDoFFunction< ValueType > >::communicators_;

   PrimitiveDataID< FunctionMemory< ValueType >, Vertex > vertexDataID_;
   PrimitiveDataID< FunctionMemory< ValueType >, Edge > edgeDataID_;
   PrimitiveDataID< FunctionMemory< ValueType >, Face > faceDataID_;
   PrimitiveDataID< FunctionMemory< ValueType >, Cell > cellDataID_;

   BoundaryCondition boundaryCondition_;

   /// friend P2Function for usage of enumerate
   friend class P2Function< ValueType >;
};

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::interpolate(const std::function< ValueType( const Point3D& ) >& expr,
                                                      uint_t level, DoFType flag)
{
  if ( isDummy() ) { return; }
  std::function< ValueType(const Point3D&,const std::vector<ValueType>&)> exprExtended = [&expr](const hhg::Point3D& x, const std::vector<ValueType>&) {
      return expr(x);
  };
  interpolateExtended( exprExtended, {}, level, flag );
}

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::interpolateExtended(const std::function<ValueType(const Point3D &, const std::vector<ValueType>&)> &expr,
                                                              const std::vector<EdgeDoFFunction<ValueType>*> srcFunctions,
                                                              uint_t level,
                                                              DoFType flag)
{
  if ( isDummy() ) { return; }
  this->startTiming( "Interpolate" );
  // Collect all source IDs in a vector
  std::vector<PrimitiveDataID<FunctionMemory< ValueType >, Edge>>   srcEdgeIDs;
  std::vector<PrimitiveDataID<FunctionMemory< ValueType >, Face>>   srcFaceIDs;
  std::vector<PrimitiveDataID<FunctionMemory< ValueType >, Cell>>   srcCellIDs;

  for (auto& function : srcFunctions)
  {
    srcEdgeIDs.push_back(function->edgeDataID_);
    srcFaceIDs.push_back(function->faceDataID_);
    srcCellIDs.push_back(function->cellDataID_);
  }

  for ( auto & it : this->getStorage()->getEdges() )
  {
    Edge & edge = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( edge.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroedge::interpolate< ValueType >( level, edge, edgeDataID_, srcEdgeIDs, expr );
    }
  }

  communicators_[ level ]->template startCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getFaces() )
  {
    Face & face = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( face.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroface::interpolate< ValueType >( level, face, faceDataID_, srcFaceIDs, expr );
    }
  }

  communicators_[ level ]->template endCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getCells() )
  {
    Cell & cell = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( cell.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macrocell::interpolate< ValueType >( level, cell, cellDataID_, srcCellIDs, expr );
    }
  }
  this->stopTiming( "Interpolate" );
}

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::assign(const std::vector<ValueType> scalars, const std::vector<EdgeDoFFunction< ValueType >*> functions, size_t level, DoFType flag)
{
  if ( isDummy() ) { return; }
  this->startTiming( "Assign" );
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Edge >>     srcEdgeIDs;
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Face >>     srcFaceIDs;
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Cell >>     srcCellIDs;

  for ( auto& function : functions )
  {
      srcEdgeIDs.push_back( function->edgeDataID_);
      srcFaceIDs.push_back( function->faceDataID_ );
      srcCellIDs.push_back( function->cellDataID_ );
  }

  for ( auto & it : this->getStorage()->getEdges() )
  {
    Edge & edge = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( edge.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroedge::assign< ValueType >( level, edge, scalars, srcEdgeIDs, edgeDataID_ );
    }
  }

  communicators_[ level ]->template startCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getFaces() )
  {
    Face & face = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( face.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroface::assign< ValueType >( level, face, scalars, srcFaceIDs, faceDataID_ );
    }
  }

  communicators_[ level ]->template endCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getCells() )
  {
    Cell & cell = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( cell.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macrocell::assign< ValueType >( level, cell, scalars, srcCellIDs, cellDataID_ );
    }
  }


  this->stopTiming( "Assign" );
}

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::add(const std::vector<ValueType> scalars, const std::vector<EdgeDoFFunction< ValueType >*> functions, size_t level, DoFType flag)
{
  if ( isDummy() ) { return; }
  this->startTiming( "Add" );
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Edge >>     srcEdgeIDs;
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Face >>     srcFaceIDs;
  std::vector<PrimitiveDataID< FunctionMemory< ValueType >, Cell >>     srcCellIDs;

  for ( auto& function : functions )
  {
      srcEdgeIDs.push_back( function->edgeDataID_);
      srcFaceIDs.push_back( function->faceDataID_ );
      srcCellIDs.push_back( function->cellDataID_ );
  }

  for ( auto & it : this->getStorage()->getEdges() )
  {
    Edge & edge = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( edge.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroedge::add< ValueType >( level, edge, scalars, srcEdgeIDs, edgeDataID_ );
    }
  }

  communicators_[ level ]->template startCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getFaces() )
  {
    Face & face = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( face.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macroface::add< ValueType >( level, face, scalars, srcFaceIDs, faceDataID_ );
    }
  }

  communicators_[ level ]->template endCommunication< Edge, Face >();

  for ( auto & it : this->getStorage()->getCells() )
  {
    Cell & cell = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( cell.getMeshBoundaryFlag() ), flag ) )
    {
      edgedof::macrocell::add< ValueType >( level, cell, scalars, srcCellIDs, cellDataID_ );
    }
  }

  this->stopTiming( "Add" );
}

template< typename ValueType >
inline real_t EdgeDoFFunction< ValueType >::dotLocal(EdgeDoFFunction< ValueType >& rhs, size_t level, DoFType flag)
{
  if ( isDummy() ) { return real_c(0); }
  this->startTiming( "Dot (local)" );
  real_t scalarProduct =  0.0 ;

  for ( auto & it : this->getStorage()->getEdges() )
  {
    Edge & edge = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( edge.getMeshBoundaryFlag() ), flag ) )
    {
      scalarProduct += edgedof::macroedge::dot< ValueType >( level, edge, edgeDataID_, rhs.edgeDataID_ );
    }
  }

  for ( auto & it : this->getStorage()->getFaces() )
  {
    Face & face = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( face.getMeshBoundaryFlag() ), flag ) )
    {
      scalarProduct += edgedof::macroface::dot< ValueType >( level, face, faceDataID_, rhs.faceDataID_ );
    }
  }

  for ( auto & it : this->getStorage()->getCells() )
  {
    Cell & cell = *it.second;

    if ( testFlag( boundaryCondition_.getBoundaryType( cell.getMeshBoundaryFlag() ), flag ) )
    {
      scalarProduct += edgedof::macrocell::dot< ValueType >( level, cell, cellDataID_, rhs.cellDataID_ );
    }
  }

  this->stopTiming( "Dot (local)" );

  return scalarProduct;
}

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::enumerate(uint_t level)
{
   if ( isDummy() ) { return; }
   this->startTiming( "Enumerate" );

   uint_t counter = hhg::numberOfLocalDoFs< EdgeDoFFunctionTag >( *( this->getStorage() ), level );

   std::vector< uint_t > dofs_per_rank = walberla::mpi::allGather( counter );

   ValueType startOnRank = 0;

   for( uint_t i = 0; i < uint_c(walberla::MPIManager::instance()->rank()); ++i )
   {
      startOnRank += dofs_per_rank[i];
   }

   enumerate( level, startOnRank);
   this->stopTiming( "Enumerate" );
}

template< typename ValueType >
inline void EdgeDoFFunction< ValueType >::enumerate(uint_t level, ValueType& offset)
{

  for (auto& it : this->getStorage()->getEdges()) {
    Edge& edge = *it.second;
    edgedof::macroedge::enumerate< ValueType >(level, edge, edgeDataID_, offset);
  }

  communicators_[level]->template startCommunication<Edge, Face>();


  for (auto& it : this->getStorage()->getFaces()) {
    Face& face = *it.second;
    edgedof::macroface::enumerate< ValueType >(level, face, faceDataID_, offset);
  }

  communicators_[level]->template endCommunication<Edge, Face>();

  communicators_[level]->template startCommunication<Face, Edge>();
  communicators_[level]->template endCommunication<Face, Edge>();

  communicators_[level]->template startCommunication<Edge, Vertex>();
  communicators_[level]->template endCommunication<Edge, Vertex>();

}


template< typename ValueType >
inline real_t EdgeDoFFunction< ValueType >::getMaxMagnitude( uint_t level, DoFType flag, bool mpiReduce )
{
  if ( isDummy() ) { return real_c(0); }
  real_t localMax = real_t(0.0);

  for( auto& it : this->getStorage()->getEdges() )
  {
    Edge &edge = *it.second;
    const DoFType edgeBC = this->getBoundaryCondition().getBoundaryType( edge.getMeshBoundaryFlag() );
    if ( testFlag( edgeBC, flag ) )
    {
      localMax = std::max( localMax, edgedof::macroedge::getMaxMagnitude< ValueType >( level, edge, edgeDataID_ ));
    }
  }

  for( auto& it : this->getStorage()->getFaces() )
  {
    Face &face = *it.second;
    const DoFType faceBC = this->getBoundaryCondition().getBoundaryType( face.getMeshBoundaryFlag() );
    if ( testFlag( faceBC, flag ) )
    {
      localMax = std::max( localMax, edgedof::macroface::getMaxMagnitude< ValueType >( level, face, faceDataID_ ));
    }
  }

  if( mpiReduce )
  {
    walberla::mpi::allReduceInplace( localMax, walberla::mpi::MAX, walberla::mpi::MPIManager::instance()->comm() );
  }

  return localMax;
}


}// namespace hhg
