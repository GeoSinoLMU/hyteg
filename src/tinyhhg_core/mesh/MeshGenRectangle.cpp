
#include "tinyhhg_core/mesh/MeshInfo.hpp"

#include "core/logging/Logging.h"
#include "core/debug/CheckFunctions.h"
#include "core/debug/Debug.h"

#include <array>
#include <vector>

namespace hhg {


MeshInfo MeshInfo::meshRectangle( const Point2D lowerLeft, const Point2D upperRight,
                                  const meshFlavour flavour, uint_t nx, uint_t ny )
{

  if ( flavour == DIAMOND )
    {
      return MeshInfo::meshRectangleDiamond( lowerLeft, upperRight, nx, ny );
    }

  // map node indices to linear id
  auto rectMap = [ nx, ny ] ( uint_t i, uint_t j ) -> IDType
    {
      IDType id = (j)*(nx+1)+(i);
      WALBERLA_ASSERT_LESS( id, (nx+1)*(ny+1) );
      return id;
    };

  // split cell in criss-wise fashion
  auto splitCellCriss = [ rectMap ]( uint_t i, uint_t j, MeshInfo &meshInfo )
    {
      // lower triangle
      meshInfo.addFace( Face( { rectMap( i, j ), rectMap( i+1, j ), rectMap( i, j+1 ) }, Inner ) );

      // upper triangle
      meshInfo.addFace( Face( { rectMap( i+1, j ), rectMap( i+1, j+1 ), rectMap( i, j+1 ) }, Inner ) );
    };

  // split cell in cross-wise fashion
  auto splitCellCross = [ rectMap ]( uint_t i, uint_t j, MeshInfo &meshInfo )
    {
      // lower triangle
      meshInfo.addFace( Face( { rectMap( i, j ), rectMap( i+1, j ), rectMap( i+1, j+1 ) }, Inner ) );

      // upper triangle
      meshInfo.addFace( Face( { rectMap( i, j ), rectMap( i+1, j+1 ), rectMap( i, j+1 ) }, Inner ) );
    };

  MeshInfo meshInfo;

  // extract corner coordinates
  real_t llx = lowerLeft [ 0 ];
  real_t lly = lowerLeft [ 1 ];
  real_t urx = upperRight[ 0 ];
  real_t ury = upperRight[ 1 ];

  // check inputs
  WALBERLA_ASSERT_LESS( llx, urx );
  WALBERLA_ASSERT_LESS( lly, ury );
  WALBERLA_ASSERT_GREATER( nx, 0 );
  WALBERLA_ASSERT_GREATER( ny, 0 );

  // compute mesh spacings
  real_t hx = ( urx - llx ) / (real_t)nx;
  real_t hy = ( ury - lly ) / (real_t)ny;

  // -------------------
  //  generate vertices
  // -------------------
  IDType id;
  std::array<real_t,3> node;
  node[2] = (real_t)0.0;

  // interior nodes
  for ( uint_t i = 1; i < nx; ++i )
    {
      for ( uint_t j = 1; j < ny; ++j )
        {
          id = rectMap(i,j);
          node[0] = llx + (real_t)i * hx;
          node[1] = lly + (real_t)j * hy;
          meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), Inner );
        }
    }

  for ( uint_t i = 1; i < nx; ++i )
    {
      // nodes on lower boundary
      id = rectMap(i,0);
      node[0] = llx + (real_t)i * hx;
      node[1] = lly;
      meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );

      // nodes on upper boundary
      id = rectMap(i,ny);
      node[0] = llx + (real_t)i * hx;
      node[1] = ury;
      meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );
    }

  for ( uint_t j = 1; j < ny; ++j )
    {
      // nodes on left boundary
      id = rectMap(0,j);
      node[0] = llx;
      node[1] = lly + (real_t)j * hy;
      meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );

      // nodes on upper boundary
      id = rectMap(nx,j);
      node[0] = urx;
      node[1] = lly + (real_t)j * hy;
      meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );
    }

  // four corners
  id = rectMap(0,0);
  node[0] = llx;
  node[1] = lly;
  meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );
  id = rectMap(nx,0);
  node[0] = urx;
  node[1] = lly;
  meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );
  id = rectMap(nx,ny);
  node[0] = urx;
  node[1] = ury;
  meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );
  id = rectMap(0,ny);
  node[0] = llx;
  node[1] = ury;
  meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), DirichletBoundary );

  // --------------------
  //  generate triangles
  // --------------------
  switch( flavour )
    {
    case CRISS:
      {
        // loop over sub-cells
        for( uint_t i = 0; i < nx; ++i )
          {
            for( uint_t j = 0; j < ny; ++j )
              {
                splitCellCriss( i, j, meshInfo );
              }
          }
        break;
      }

    case CROSS:
      {
        // loop over sub-cells
        for( uint_t i = 0; i < nx; ++i )
          {
            for( uint_t j = 0; j < ny; ++j )
              {
                splitCellCross( i, j, meshInfo );
              }
          }
        break;
      }

    case CRISSCROSS:
      {
        // loop over sub-cells
        uint_t idx = rectMap( nx, ny ) + 1;
        real_t midx, midy;
        for( uint_t i = 0; i < nx; ++i )
          {
            for( uint_t j = 0; j < ny; ++j )
              {
                // add new central vertex
                midx = llx + ( (real_t)i + 0.5 ) * hx;
                midy = lly + ( (real_t)j + 0.5 ) * hy;
                meshInfo.vertices_[idx] = MeshInfo::Vertex( idx, Point3D( { midx, midy, 0.0 } ), Inner );

                meshInfo.addFace( Face( { rectMap(  i ,  j  ), idx, rectMap( i+1,  j  ) }, Inner ) );
                meshInfo.addFace( Face( { rectMap( i+1,  j  ), idx, rectMap( i+1, j+1 ) }, Inner ) );
                meshInfo.addFace( Face( { rectMap( i+1, j+1 ), idx, rectMap(  i , j+1 ) }, Inner ) );
                meshInfo.addFace( Face( { rectMap(  i , j+1 ), idx, rectMap(  i ,  j  ) }, Inner ) );

                ++idx;
              }
          }
        break;
      }

    default:
      WALBERLA_ABORT( "Meshing flavour " << flavour << " not implemented, yet!" );
    }

  // generate edges from faces
  meshInfo.deriveEdges();

  return meshInfo;
}


MeshInfo MeshInfo::meshRectangleDiamond( const Point2D lowerLeft, const Point2D upperRight,
                                         uint_t unx, uint_t uny )
{
  // -------
  //  setup
  // -------

  MeshInfo meshInfo;

  // using signed integers in this methods (because of loop down to zero below)
  int32_t nx = (int32_t)unx;
  int32_t ny = (int32_t)uny;

  // extract corner coordinates
  real_t llx = lowerLeft [ 0 ];
  real_t lly = lowerLeft [ 1 ];
  real_t urx = upperRight[ 0 ];
  real_t ury = upperRight[ 1 ];

  // check inputs
  WALBERLA_ASSERT_LESS( llx, urx );
  WALBERLA_ASSERT_LESS( lly, ury );
  WALBERLA_ASSERT_GREATER( nx, 0 );
  WALBERLA_ASSERT_GREATER( ny, 0 );

  // compute mesh spacings (we virtually refine once!)
  real_t hx = 0.5 * ( urx - llx ) / (real_t)nx;
  real_t hy = 0.5 * ( ury - lly ) / (real_t)ny;

  // --------------------
  //  generate mesh info
  // --------------------

  IDType id = 0;
  int32_t i, j;
  DoFType dofType;
  std::array<real_t,3> node;
  node[2] = (real_t)0.0;
  std::map< std::array<int32_t,2>, IDType > indices2id;

  // vertices
  for ( j = 0; j <= 2*ny; ++j )
    {
      for ( i = j%2; i <= 2*nx - j%2; i += 2 )
        {
          dofType = ( i == 0 || i == 2*nx || j == 0 || j == 2*ny ) ? DirichletBoundary : Inner;
          node[0] = llx + (real_t)i * hx;
          node[1] = lly + (real_t)j * hy;
          meshInfo.vertices_[id] = MeshInfo::Vertex( id, Point3D( node ), dofType );
          indices2id.insert( { {i,j}, id } );
          ++id;
        }
    }

  // map node indices to linear id
  auto getIDX = [ indices2id ] ( int32_t ii, int32_t jj ) -> IDType
    {
      std::map< std::array<int32_t,2>, IDType >::const_iterator found = indices2id.find( { ii, jj } );
      WALBERLA_CHECK( found != indices2id.end(), "Could not map tupled to index!" );
      return found->second;
    };

  // triangular faces
  std::array< IDType, 3 > iNode;
  int32_t nmin = nx > ny ? ny : nx;
  int32_t nmax = nx > ny ? nx : ny;
  int32_t lenMin, len;
  lenMin = nx > ny ? nmax - nmin : 1;

  for ( len = nx, j = 0; len >= lenMin; ++j, --len )
    {
      for ( i = j; i < j + 2*len; i += 2 )
        {
          // from bottom: upward face
          iNode[0] = getIDX(  i ,  j  );
          iNode[1] = getIDX( i+2,  j  );
          iNode[2] = getIDX( i+1, j+1 );
          meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

          // from top: downward face
          iNode[0] = getIDX(  i , 2*ny-( j ) );
          iNode[1] = getIDX( i+2, 2*ny-( j ) );
          iNode[2] = getIDX( i+1, 2*ny-(j+1) );
          meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

          if( j > 0 )
            {
              // from bottom: downward face
              iNode[0] = getIDX(  i ,  j  );
              iNode[1] = getIDX( i+2,  j  );
              iNode[2] = getIDX( i+1, j-1 );
              meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

              // from top: upward face
              iNode[0] = getIDX(  i , 2*ny-( j ) );
              iNode[1] = getIDX( i+2, 2*ny-( j ) );
              iNode[2] = getIDX( i+1, 2*ny-(j-1) );
              meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );
            }
        }
    }

  lenMin = nx > ny ? 1 : nmax - nmin;
  for ( len = ny, i = 0; len >= lenMin; ++i, --len )
    {
      for ( j = i; j < i + 2*len; j += 2 )
        {
          // from left: rightward face
          iNode[0] = getIDX(  i ,  j  );
          iNode[1] = getIDX( i+1, j+1 );
          iNode[2] = getIDX(  i , j+2 );
          meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

          // from right: leftward face
          iNode[0] = getIDX( 2*nx-( i ),  j  );
          iNode[1] = getIDX( 2*nx-(i+1), j+1 );
          iNode[2] = getIDX( 2*nx-( i ), j+2 );
          meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

          if( i > 0 )
            {
              // from left: leftward face
              iNode[0] = getIDX(  i ,  j  );
              iNode[1] = getIDX( i-1, j+1 );
              iNode[2] = getIDX(  i , j+2 );
              meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );

              // from right: rightward face
              iNode[0] = getIDX( 2*nx-( i ),  j  );
              iNode[1] = getIDX( 2*nx-(i-1), j+1 );
              iNode[2] = getIDX( 2*nx-( i ), j+2 );
              meshInfo.addFace( Face( { iNode[0], iNode[1], iNode[2] }, Inner ) );
            }
        }
    }

  // generate edges from faces
  meshInfo.deriveEdges();

  return meshInfo;
}

} // namespace hhg
