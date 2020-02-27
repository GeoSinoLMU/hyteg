/*
 * Copyright (c) 2017-2019 Dominik Thoennes, Marcus Mohr.
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

#include <cmath>

#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "GeometryMap.hpp"

// #define ANNULUS_MAP_DEBUG

namespace hyteg {

/// Class providing geometry mapping for an annulus
///
/// This class takes an annulus mesh generated using MeshInfo::meshAnnulus()
/// with the CRISS or CROSS flavour and maps nodes on refined mesh levels to
/// corresponding radial layers. The mapping is performed with local
/// information from the individual macro face (as we did in 3D in HHG).
/// Note that the resulting mesh is different from the one we get using
/// MeshInfo::meshRectangle() in combination with the PolarCoordsMap.
class AnnulusMap : public GeometryMap
{
 public:
   AnnulusMap( const Face& face )
   {
#ifdef ANNULUS_MAP_DEBUG
      WALBERLA_LOG_INFO_ON_ROOT( "---------------------------------------------" );
      WALBERLA_LOG_INFO_ON_ROOT( "Initialising Annulus map for faceID: " << face.getID() );
      WALBERLA_LOG_INFO_ON_ROOT( "---------------------------------------------" );
#endif
      classifyVertices( face.getCoordinates() );
   }

   AnnulusMap( const Edge& edge, const SetupPrimitiveStorage& storage )
   {
#ifdef ANNULUS_MAP_DEBUG
      WALBERLA_LOG_INFO_ON_ROOT( "---------------------------------------------" );
      WALBERLA_LOG_INFO_ON_ROOT( "Initialising Annulus map for edgeID: " << edge.getID() );
      WALBERLA_LOG_INFO_ON_ROOT( "---------------------------------------------" );
#endif
      std::vector< PrimitiveID > neighborFaces;
      edge.getNeighborFaces( neighborFaces );
      WALBERLA_ASSERT_GREATER( neighborFaces.size(), 0 );
      const Face& face = *storage.getFace( neighborFaces[0] );
      classifyVertices( face.getCoordinates() );
   }

   void evalF( const Point3D& xold, Point3D& xnew ) const
   {
      // determine barycentric coordinate w.r.t. vertex refVertex_
      real_t areaT = ( refVertex_[0] - rayVertex_[0] ) * ( thrVertex_[1] - rayVertex_[1] ) -
                     ( refVertex_[1] - rayVertex_[1] ) * ( thrVertex_[0] - rayVertex_[0] );
      real_t areaX = ( xold[0] - rayVertex_[0] ) * ( thrVertex_[1] - rayVertex_[1] ) -
                     ( xold[1] - rayVertex_[1] ) * ( thrVertex_[0] - rayVertex_[0] );
      real_t factor = areaX / areaT;

      // compute new coordinates
      real_t oldRad = std::sqrt( xold[0] * xold[0] + xold[1] * xold[1] );
      real_t newRad = radRayVertex_ + factor * ( radRefVertex_ - radRayVertex_ );
      xnew[0]       = xold[0] * newRad / oldRad;
      xnew[1]       = xold[1] * newRad / oldRad;

#ifdef ANNULUS_MAP_DEBUG
      WALBERLA_LOG_INFO_ON_ROOT( "Mapped: " << xold << " --> " << xnew );
#endif
   }

   // note: we could save computations by fusing evalF with evalDF!
   void evalDF( const Point3D& x, Matrix2r& DFx ) const
   {
      real_t dist  = radRayVertex_ - radRefVertex_;
      real_t areaT = ( refVertex_[0] - rayVertex_[0] ) * ( thrVertex_[1] - rayVertex_[1] ) -
                     ( refVertex_[1] - rayVertex_[1] ) * ( thrVertex_[0] - rayVertex_[0] );
      real_t areaX = ( x[0] - rayVertex_[0] ) * ( thrVertex_[1] - rayVertex_[1] ) -
                     ( x[1] - rayVertex_[1] ) * ( thrVertex_[0] - rayVertex_[0] );
      real_t bary   = areaX / areaT;
      real_t oldRad = std::sqrt( x[0] * x[0] + x[1] * x[1] );
      real_t newRad = radRefVertex_ + bary * dist;

      real_t invNorm  = 1.0 / oldRad;
      real_t invNorm3 = invNorm * invNorm * invNorm;
      real_t tmp0     = invNorm * dist / areaT;
      real_t tmp1     = x[0] * tmp0;
      real_t tmp2     = x[1] * tmp0;
      real_t tmp3     = thrVertex_[1] - rayVertex_[1];
      real_t tmp4     = thrVertex_[0] - rayVertex_[0];
      real_t tmp5     = x[0] * invNorm3 * newRad;
      real_t tmp6     = x[1] * invNorm3 * newRad;

      DFx( 0, 0 ) = x[1] * tmp6 + tmp1 * tmp3;
      DFx( 0, 1 ) = -x[0] * tmp6 - tmp1 * tmp4;
      DFx( 1, 0 ) = -x[1] * tmp5 + tmp2 * tmp3;
      DFx( 1, 1 ) = x[0] * tmp5 - tmp2 * tmp4;
   }

   void evalDFinv( const Point3D& x, Matrix2r& DFinvx ) const
   {
      Matrix2r tmp;
      evalDF( x, tmp );
      real_t invDet = 1.0 / tmp.det();
      DFinvx        = tmp.adj();
      DFinvx *= invDet;
   }

   void serializeSubClass( walberla::mpi::SendBuffer& sendBuffer ) const
   {
      sendBuffer << Type::ANNULUS_MAP << rayVertex_ << refVertex_ << thrVertex_ << radRefVertex_ << radRayVertex_;
   }

 private:
   /// \name Classified vertices of macro triangle
   ///
   /// Each macro triangle of the annulus has two vertices which lie on a ray coming from the origin and
   /// two with the same distance from the origin. The vertex opposite to the edge formed by the latter
   /// two is stored as rayVertex_, the one on the ray with the rayVertex_ is stored as refVertex_.
   /// The third vertex then is stored as thrVertex_.
   ///@{
   Point3D rayVertex_;
   Point3D refVertex_;
   Point3D thrVertex_;
   ///@}

   /// distance from origin of vertex rayVertex_
   real_t radRefVertex_;

   /// distance from origin of vertex refVertex_
   real_t radRayVertex_;

   /// method for classifying the vertices of the macro triangle
   void classifyVertices( const std::array< Point3D, 3 >& coords )
   {
      std::array< real_t, 3 > radius;
      for ( uint_t k = 0; k < 3; k++ )
      {
         radius[k] = std::sqrt( coords[k].normSq() );
#ifdef ANNULUS_MAP_DEBUG
         WALBERLA_LOG_INFO_ON_ROOT( "Vertex " << k << ": (" // << std::scientific
                                              << coords[k][0] << ", " << coords[k][1] << ", " << coords[k][2] << ")\n"
                                              << " radius = " << radius[k] );
#endif
      }
      real_t cross01 = coords[0][0] * coords[1][1] - coords[0][1] * coords[1][0];
      real_t cross02 = coords[0][0] * coords[2][1] - coords[0][1] * coords[2][0];
      real_t cross12 = coords[1][0] * coords[2][1] - coords[1][1] * coords[2][0];

#ifdef ANNULUS_MAP_DEBUG
      WALBERLA_LOG_INFO_ON_ROOT( "r0 x r1 = " << std::showpos << std::scientific << cross01 );
      WALBERLA_LOG_INFO_ON_ROOT( "r0 x r2 = " << std::showpos << std::scientific << cross02 );
      WALBERLA_LOG_INFO_ON_ROOT( "r1 x r2 = " << std::showpos << std::scientific << cross12 );
#endif

      real_t tol    = 1e-14;
      uint_t intRay = 99;
      uint_t intRef = 99;

      // classify assuming we have a triangle pointing outwards from the origin
      if ( std::abs( cross01 ) < tol )
      {
         thrVertex_ = coords[2];
         if ( radius[0] < radius[1] )
         {
            intRay = 0;
            intRef = 1;
         }
         else
         {
            intRay = 1;
            intRef = 0;
         }
      }
      else if ( std::abs( cross02 ) < tol )
      {
         thrVertex_ = coords[1];
         if ( radius[0] < radius[2] )
         {
            intRay = 0;
            intRef = 2;
         }
         else
         {
            intRay = 2;
            intRef = 0;
         }
      }
      else if ( std::abs( cross12 ) < tol )
      {
         thrVertex_ = coords[0];
         if ( radius[1] < radius[2] )
         {
            intRay = 1;
            intRef = 2;
         }
         else
         {
            intRay = 2;
            intRef = 1;
         }
      }
      else
      {
         WALBERLA_ABORT( "Classification error in classifyVertices! Did you use CRISSCROSS maybe?" );
      }

      // swap classes in case we have a triangle pointing towards the origin
      if ( std::abs( coords[intRef].normSq() - thrVertex_.normSq() ) < tol )
      {
         uint_t aux = intRay;
         intRay     = intRef;
         intRef     = aux;
      }

      rayVertex_ = coords[intRay];
      refVertex_ = coords[intRef];

      radRayVertex_ = radius[intRay];
      radRefVertex_ = radius[intRef];

#ifdef ANNULUS_MAP_DEBUG
      WALBERLA_LOG_INFO_ON_ROOT( "refVertex: (" << refVertex_[0] << ", " << refVertex_[1] << ")" );
      WALBERLA_LOG_INFO_ON_ROOT( "rayVertex: (" << rayVertex_[0] << ", " << rayVertex_[1] << ")" );
      WALBERLA_LOG_INFO_ON_ROOT( "thrVertex: (" << thrVertex_[0] << ", " << thrVertex_[1] << ")" );
#endif
   }
};

} // namespace hyteg
