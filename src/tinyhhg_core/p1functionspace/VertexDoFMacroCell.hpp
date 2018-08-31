
#pragma once

#include "core/debug/all.h"
#include "core/DataTypes.h"

#include "tinyhhg_core/primitives/Cell.hpp"
#include "tinyhhg_core/Levelinfo.hpp"
#include "tinyhhg_core/indexing/Common.hpp"
#include "tinyhhg_core/p1functionspace/VertexDoFIndexing.hpp"
#include "tinyhhg_core/FunctionMemory.hpp"
#include "tinyhhg_core/StencilMemory.hpp"
#include "tinyhhg_core/types/flags.hpp"
#include "tinyhhg_core/petsc/PETScWrapper.hpp"

namespace hhg {
namespace vertexdof {
namespace macrocell {

using walberla::uint_t;
using walberla::real_t;
using walberla::real_c;

using indexing::Index;

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
                         const std::function< ValueType( const hhg::Point3D &, const std::vector< ValueType > & )> & expr)
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
inline real_t dot( const uint_t & level,
                   const Cell & cell,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & lhsId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & rhsId)
{
  real_t sp = 0.0;

  const ValueType * lhsPtr = cell.getData( lhsId )->getPointer( level );
  const ValueType * rhsPtr = cell.getData( rhsId )->getPointer( level );

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::indexFromVertex( level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C );
    sp += lhsPtr[ idx ] * rhsPtr[ idx ];
  }

  return sp;
}


template< typename ValueType >
inline void apply( const uint_t & level,
                   Cell & cell,
                   const PrimitiveDataID< StencilMemory< ValueType >,  Cell > & operatorId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & srcId,
                   const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId,
                   const UpdateType update )
{
  typedef stencilDirection sd;

  const ValueType * operatorData = cell.getData( operatorId )->getPointer( level );
  const ValueType * src          = cell.getData( srcId )->getPointer( level );
        ValueType * dst          = cell.getData( dstId )->getPointer( level );

  ValueType tmp;

  if( update == Replace )
  {
    for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
    {
      const uint_t x = it.x();
      const uint_t y = it.y();
      const uint_t z = it.z();

      const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

      tmp = operatorData[ vertexdof::stencilIndexFromVertex( stencilDirection::VERTEX_C ) ] * src[ centerIdx ];

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
      {
        const uint_t stencilIdx = vertexdof::stencilIndexFromVertex( neighbor );
        const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
        tmp += operatorData[ stencilIdx ] * src[ idx ];
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

      tmp = operatorData[ vertexdof::stencilIndexFromVertex( stencilDirection::VERTEX_C ) ] * src[ centerIdx ];

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
      {
        const uint_t stencilIdx = vertexdof::stencilIndexFromVertex( neighbor );
        const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
        tmp += operatorData[ stencilIdx ] * src[ idx ];
      }

      dst[ centerIdx ] += tmp;
    }
  }
}


template< typename ValueType >
inline void smooth_gs( const uint_t & level,
                       Cell & cell,
                       const PrimitiveDataID< StencilMemory< ValueType >,  Cell > & operatorId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & dstId,
                       const PrimitiveDataID< FunctionMemory< ValueType >, Cell > & rhsId )
{
  typedef stencilDirection sd;

  const ValueType * operatorData = cell.getData( operatorId )->getPointer( level );
  const ValueType * rhs          = cell.getData( rhsId )->getPointer( level );
        ValueType * dst          = cell.getData( dstId )->getPointer( level );

  ValueType tmp;

  const auto inverseCenterWeight = 1.0 / operatorData[ vertexdof::stencilIndexFromVertex( sd::VERTEX_C ) ];

  for ( const auto & it : vertexdof::macrocell::Iterator( level, 1 ) )
  {
    const uint_t x = it.x();
    const uint_t y = it.y();
    const uint_t z = it.z();

    const uint_t centerIdx = vertexdof::macrocell::indexFromVertex( level, x, y, z, sd::VERTEX_C );

    tmp = rhs[ centerIdx ];

    for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter )
    {
      const uint_t stencilIdx = vertexdof::stencilIndexFromVertex( neighbor );
      const uint_t idx        = vertexdof::macrocell::indexFromVertex( level, x, y, z, neighbor );
      tmp -= operatorData[ stencilIdx ] * dst[ idx ];
    }

    dst[ centerIdx ] = tmp * inverseCenterWeight;
  }
}


template< typename ValueType >
inline void enumerate(const uint_t & Level, Cell & cell, const PrimitiveDataID<FunctionMemory< ValueType >, Cell> &dstId, ValueType& num) {

  ValueType* dstPtr = cell.getData(dstId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
    const uint_t idx = vertexdof::macrocell::index( Level, it.x(), it.y(), it.z() );
    dstPtr[idx] = num;
    num++;
  }
}


#ifdef HHG_BUILD_WITH_PETSC

inline void saveOperator(const uint_t & Level, Cell & cell, const PrimitiveDataID<StencilMemory< real_t >, Cell>& operatorId,
                              const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &srcId,
                              const PrimitiveDataID<FunctionMemory< PetscInt >, Cell> &dstId, Mat& mat)
{

  auto opr_data = cell.getData(operatorId)->getPointer( Level );
  auto src = cell.getData(srcId)->getPointer( Level );
  auto dst = cell.getData(dstId)->getPointer( Level );

  for ( const auto & it : vertexdof::macrocell::Iterator( Level, 1 ) )
  {
      PetscInt srcInt = src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];
      PetscInt dstInt = dst[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), stencilDirection::VERTEX_C)];

      MatSetValues(mat,1,&dstInt,1,&srcInt,&opr_data[vertexdof::stencilIndexFromVertex(stencilDirection::VERTEX_C)] ,INSERT_VALUES);

      for ( const auto & neighbor : vertexdof::macrocell::neighborsWithoutCenter ) {
        srcInt = src[vertexdof::macrocell::indexFromVertex( Level, it.x(), it.y(), it.z(), neighbor)];

        MatSetValues(mat,1,&dstInt,1,&srcInt,&opr_data[vertexdof::stencilIndexFromVertex(neighbor)] ,INSERT_VALUES);
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
} // namespace hhg
