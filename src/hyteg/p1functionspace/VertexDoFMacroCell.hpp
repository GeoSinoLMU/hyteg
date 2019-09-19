/*
 * Copyright (c) 2017-2019 Daniel Drzisga, Dominik Thoennes, Marcus Mohr, Nils Kohl.
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

#pragma once

#include "core/debug/all.h"
#include "core/DataTypes.h"

#include "hyteg/primitives/Cell.hpp"
#include "hyteg/Levelinfo.hpp"
#include "hyteg/indexing/Common.hpp"
#include "hyteg/p1functionspace/VertexDoFIndexing.hpp"
#include "hyteg/FunctionMemory.hpp"
#include "hyteg/StencilMemory.hpp"
#include "hyteg/types/flags.hpp"
#include "hyteg/petsc/PETScWrapper.hpp"
#include "hyteg/Algorithms.hpp"
#include "hyteg/indexing/DistanceCoordinateSystem.hpp"
#include "hyteg/LevelWiseMemory.hpp"

namespace hyteg {
namespace vertexdof {
namespace macrocell {

using walberla::uint_t;
using walberla::real_t;
using walberla::real_c;

using indexing::Index;

inline indexing::Index getIndexInNeighboringMacroFace( const indexing::Index  & vertexDoFIndexInMacroCell,
                                                       const Cell             & cell,
                                                       const uint_t           & neighborFaceID,
                                                       const PrimitiveStorage & storage,
                                                       const uint_t           & level )
{
  const std::array< uint_t, 4 > localVertexIDsAtCell = algorithms::getMissingIntegersAscending< 3, 4 >(
  { cell.getFaceLocalVertexToCellLocalVertexMaps().at(neighborFaceID).at(0),
    cell.getFaceLocalVertexToCellLocalVertexMaps().at(neighborFaceID).at(1),
    cell.getFaceLocalVertexToCellLocalVertexMaps().at(neighborFaceID).at(2) } );

  const auto indexInMacroFace = indexing::basisConversion( vertexDoFIndexInMacroCell, {0, 1, 2, 3},
                                                           localVertexIDsAtCell, levelinfo::num_microvertices_per_edge( level ) );
  return indexInMacroFace;
}

inline Point3D coordinateFromIndex( const uint_t & level, const Cell & cell, const Index & index )
{
  const real_t  stepFrequency = 1.0 / levelinfo::num_microedges_per_edge( level );
  const Point3D xStep         = ( cell.getCoordinates()[1] - cell.getCoordinates()[0] ) * stepFrequency;
  const Point3D yStep         = ( cell.getCoordinates()[2] - cell.getCoordinates()[0] ) * stepFrequency;
  const Point3D zStep         = ( cell.getCoordinates()[3] - cell.getCoordinates()[0] ) * stepFrequency;
  return cell.getCoordinates()[0] + xStep * real_c( index.x() ) + yStep * real_c( index.y() ) + zStep * real_c( index.z() );
}

template< typename ValueType >
inline void interpolate( const uint_t & level,
                         const Cell & cell,
                         const PrimitiveDataID< FunctionMemory< ValueType >, Cell >& cellMemoryId,
                         const ValueType & scalar )
{
  ValueType * cellData = cell.getData( cellMemoryId )->getPointer( level );

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );
    cellData[ idx ] = scalar;
  }
}


template< typename ValueType >
inline void interpolate( const uint_t & level,
                         const Cell & cell,
                         const PrimitiveDataID< FunctionMemory< ValueType >, Cell >& cellMemoryId,
                         const std::vector< PrimitiveDataID< FunctionMemory< ValueType >, Cell > > & srcIds,
                         const std::function< ValueType( const hyteg::Point3D &, const std::vector< ValueType > & )> & expr)
{
  ValueType * cellData = cell.getData( cellMemoryId )->getPointer( level );

  std::vector< ValueType * > srcPtr;
  for( const auto & src : srcIds )
  {
    srcPtr.push_back( cell.getData(src)->getPointer( level ) );
  }

  std::vector<ValueType> srcVector( srcIds.size() );

  Point3D xBlend;

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const Point3D coordinate = coordinateFromIndex( level, cell, it );
    const uint_t  idx        = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );

    for ( uint_t k = 0; k < srcPtr.size(); ++k )
    {
      srcVector[ k ] = srcPtr[ k ][ idx ];
    }
    cell.getGeometryMap()->evalF( coordinate, xBlend );
    cellData[ idx ] = expr( xBlend, srcVector );
  }
}

template< typename ValueType >
inline void swap( const uint_t & level, Cell & cell,
                  const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & srcID,
                  const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstID )
{
  auto srcData = cell.getData( srcID );
  auto dstData = cell.getData( dstID );
  srcData->swap( *dstData, level );
}

template< typename ValueType >
inline void assign( const uint_t & level,
                    const Cell & cell,
                    const std::vector< ValueType > & scalars,
                    const std::vector< PrimitiveDataID< FunctionMemory< ValueType >, Cell > > & srcIds,
                    const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId )
{
  ValueType * dst = cell.getData( dstId )->getPointer( level );

  std::vector< ValueType * > srcPtr;
  for( const auto & src : srcIds )
  {
    srcPtr.push_back( cell.getData( src )->getPointer( level ));
  }

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );

    ValueType tmp = scalars[0] * srcPtr[0][ idx ];

    for ( uint_t k = 1; k < srcIds.size(); ++k )
    {
      tmp += scalars[k] * srcPtr[k][ idx ];
    }
    dst[ idx ] = tmp;
  }
}


template< typename ValueType >
inline void add( const uint_t & level,
                 const Cell & cell,
                 const ValueType & scalar,
                 const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId )
{
  ValueType * dst = cell.getData( dstId )->getPointer( level );

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );
    dst[ idx ] += scalar;
  }
}


template< typename ValueType >
inline void add( const uint_t & level,
                 const Cell & cell,
                 const std::vector< ValueType > & scalars,
                 const std::vector< PrimitiveDataID< FunctionMemory< ValueType >, Cell > > & srcIds,
                 const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId )
{
  ValueType * dst = cell.getData( dstId )->getPointer( level );

  std::vector< ValueType * > srcPtr;
  for( const auto & src : srcIds )
  {
    srcPtr.push_back( cell.getData( src )->getPointer( level ));
  }

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );

    ValueType tmp = scalars[0] * srcPtr[0][ idx ];

    for ( uint_t k = 1; k < srcIds.size(); ++k )
    {
      tmp += scalars[k] * srcPtr[k][ idx ];
    }
    dst[ idx ] += tmp;
  }
}


template< typename ValueType >
inline void multElementwise( const uint_t & level,
                               const Cell & cell,
                               const std::vector< PrimitiveDataID< FunctionMemory< ValueType >, Cell > > & srcIds,
                               const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId )
{
  ValueType * dst = cell.getData( dstId )->getPointer( level );

  std::vector< ValueType * > srcPtr;
  for( const auto & src : srcIds )
  {
    srcPtr.push_back( cell.getData( src )->getPointer( level ));
  }

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );

    ValueType tmp = srcPtr[0][ idx ];

    for ( uint_t k = 1; k < srcIds.size(); ++k )
    {
      tmp *= srcPtr[k][ idx ];
    }
    dst[ idx ] = tmp;
  }

}

template< typename ValueType >
inline ValueType dot( const uint_t & level,
                   const Cell & cell,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & lhsId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & rhsId)
{
   auto sp = ValueType( 0 );

  const ValueType * lhsPtr = cell.getData( lhsId )->getPointer( level );
  const ValueType * rhsPtr = cell.getData( rhsId )->getPointer( level );

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );
    sp += lhsPtr[ idx ] * rhsPtr[ idx ];
  }

  return sp;
}

template < typename ValueType >
inline ValueType sum( const uint_t&                                               level,
                      const Cell&                                                 cell,
                      const PrimitiveDataID< FunctionMemory< ValueType >, Cell >& dataID,
                      const bool&                                                 absolute )
{
   auto sum = ValueType( 0 );

   const ValueType* data = cell.getData( dataID )->getPointer( level );

   for ( const auto& it : vertexdof::macrocell::Iterator( level, 1 ) )
   {
      const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );
      if ( absolute )
      {
         sum += std::abs( data[idx] );
      }
      else
      {
         sum += data[idx];
      }
   }

   return sum;
}

template< typename ValueType >
inline void apply( const uint_t & level,
                   Cell & cell,
                   const PrimitiveDataID< LevelWiseMemory< StencilMap_T >,  Cell > & operatorId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & srcId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId,
                   const UpdateType update )
{
  typedef stencilDirection sd;

  auto operatorData     = cell.getData( operatorId )->getData( level );
  const ValueType * src = cell.getData( srcId )->getPointer( level );
        ValueType * dst = cell.getData( dstId )->getPointer( level );

  ValueType tmp;

  if( update == Replace )
  {
    for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
    {
      const uint_t x = it.x();
      const uint_t y = it.y();
      const uint_t z = it.z();

      const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

      tmp = operatorData.at({0, 0, 0}) * src[ centerIdx ];

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
      {
        const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
        WALBERLA_ASSERT_GREATER( operatorData.count( vertexdof::logicalIndexOffsetFromVertex( neighbor ) ), 0 );
        tmp += operatorData.at( vertexdof::logicalIndexOffsetFromVertex( neighbor ) ) * src[ idx ];
      }

      dst[ centerIdx ] = tmp;
    }
  }
  else
  {
    for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
    {
      const uint_t x = it.x();
      const uint_t y = it.y();
      const uint_t z = it.z();

      const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

      tmp = operatorData.at( {0, 0, 0} ) * src[ centerIdx ];

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
      {
        const uint_t stencilIdx = vertexdof::stencilIndexFromVertex( neighbor );
        const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
        tmp += operatorData.at( logicalIndexOffsetFromVertex( neighbor ) ) * src[ idx ];
      }

      dst[ centerIdx ] += tmp;
    }
  }
}


template< typename ValueType >
inline void smooth_gs( const uint_t & level,
                       Cell & cell,
                       const PrimitiveDataID<LevelWiseMemory< StencilMap_T >,  Cell > & operatorId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & rhsId )
{
  typedef stencilDirection sd;

  auto operatorData = cell.getData( operatorId )->getData( level );
  const ValueType * rhs          = cell.getData( rhsId )->getPointer( level );
        ValueType * dst          = cell.getData( dstId )->getPointer( level );

  ValueType tmp;

  const auto inverseCenterWeight = 1.0 / operatorData[ { 0, 0, 0 } ];

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t x = it.x();
    const uint_t y = it.y();
    const uint_t z = it.z();

    const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

    tmp = rhs[ centerIdx ];

    for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
    {
      const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
      tmp -= operatorData[ logicalIndexOffsetFromVertex( neighbor ) ] * dst[ idx ];
    }

    dst[ centerIdx ] = tmp * inverseCenterWeight;
  }
}

template< typename ValueType >
inline void smooth_sor( const uint_t & level,
                       Cell & cell,
                       const PrimitiveDataID< LevelWiseMemory< StencilMap_T >,  Cell > & operatorId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & rhsId,
                       ValueType                                                    relax )
{
  typedef stencilDirection sd;

  auto operatorData = cell.getData( operatorId )->getData( level );
  const ValueType * rhs          = cell.getData( rhsId )->getPointer( level );
  ValueType * dst          = cell.getData( dstId )->getPointer( level );

  ValueType tmp;

  const auto inverseCenterWeight = 1.0 / operatorData[ { 0, 0, 0 } ];

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t x = it.x();
    const uint_t y = it.y();
    const uint_t z = it.z();

    const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

    tmp = rhs[ centerIdx ];

    for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
    {
      const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
      tmp -= operatorData[ logicalIndexOffsetFromVertex( neighbor ) ] * dst[ idx ];
    }

    dst[ centerIdx ] = ( 1.0 - relax ) * dst[ centerIdx ] + tmp * relax * inverseCenterWeight;
  }
}


template< typename ValueType >
inline void enumerate(const uint_t & Level, Cell & cell, const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &dstId, ValueType& num, std::array< uint_t, 4 > enumerationDirection ) {

  ValueType* dstPtr = cell.getData(dstId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
    auto convertedIndex = indexing::basisConversion( it, enumerationDirection, {0, 1, 2, 3}, levelinfo::num_microvertices_per_edge( Level ) );
    const uint_t idx = vertexdof::macrocell::index( Level, convertedIndex.x(), convertedIndex.y(), convertedIndex.z() );
    dstPtr[idx] = num;
    num++;
  }
}


template< typename ValueType >
inline ValueType getMaxValue( const uint_t & level, Cell &cell, const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &srcId ) {

  auto src = cell.getData( srcId )->getPointer( level );
  auto localMax = -std::numeric_limits< ValueType >::max();

  for ( const auto& it : vertexdof::macrocell::Iterator( level, 1 ) ) {
    localMax = std::max( localMax, src[vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C ) ] );
  }

  return localMax;
}


template< typename ValueType >
inline ValueType getMinValue( const uint_t & level, Cell &cell, const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &srcId ) {

  auto src = cell.getData( srcId )->getPointer( level );
  auto localMin = std::numeric_limits< ValueType >::max();

  for ( const auto& it : vertexdof::macrocell::Iterator( level, 1 ) ) {
    localMin = std::min( localMin, src[vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C ) ] );
  }

  return localMin;
}


template< typename ValueType >
inline ValueType getMaxMagnitude( const uint_t & level, Cell &cell, const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &srcId ) {

  auto src = cell.getData( srcId )->getPointer( level );
  auto localMax = ValueType(0.0);

  for ( const auto& it : vertexdof::macrocell::Iterator( level, 1 ) ) {
    localMax = std::max( localMax, std::abs( src[vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C ) ] ));
  }

  return localMax;
}


#ifdef HYTEG_BUILD_WITH_PETSC

inline void saveOperator(const uint_t & Level, Cell & cell, const PrimitiveDataID< LevelWiseMemory< vertexdof::macrocell::StencilMap_T > , Cell>& operatorId,
                              const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &srcId,
                              const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &dstId, Mat& mat)
{

  auto opr_data = cell.getData(operatorId)->getData( Level );
  auto src = cell.getData(srcId)->getPointer( Level );
  auto dst = cell.getData(dstId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
      PetscInt srcInt = src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];
      PetscInt dstInt = dst[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];

      MatSetValues(mat,1,&dstInt,1,&srcInt,&opr_data[ { 0, 0, 0 } ] ,ADD_VALUES);

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter ) {
        srcInt = src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), neighbor)];

        MatSetValues(mat,1,&dstInt,1,&srcInt,&opr_data[vertexdof::logicalIndexOffsetFromVertex(neighbor)] ,ADD_VALUES);
      }
  }
}



template< typename ValueType >
inline void createVectorFromFunction(const uint_t & Level, Cell & cell,
                              const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &srcId,
                              const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &numeratorId,
                              Vec& vec)
{

  auto src = cell.getData(srcId)->getPointer( Level );
  auto numerator = cell.getData(numeratorId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
      PetscInt numeratorInt = numerator[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];
      VecSetValues(vec,1,&numeratorInt,&src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)],INSERT_VALUES);
  }
}


template< typename ValueType >
inline void createFunctionFromVector(const uint_t & Level, Cell & cell,
                                         const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &srcId,
                                         const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &numeratorId,
                                         Vec& vec)
{
  auto src = cell.getData(srcId)->getPointer( Level );
  auto numerator = cell.getData(numeratorId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
      PetscInt numeratorInt = numerator[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];
      VecGetValues(vec,1,&numeratorInt,&src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)]);
  }
}

#endif


} // namespace macrocell
} // namespace vertexdof
} // namespace hyteg
