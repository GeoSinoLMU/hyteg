
#pragma once

#include <array>
#include <tinyhhg_core/Operator.hpp>

#include "tinyhhg_core/types/pointnd.hpp"

#include "P1DataHandling.hpp"

#ifdef _MSC_VER
#pragma warning( push, 0 )
#endif

#include "blending/VertexDoFBlending.hpp"

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#include "tinyhhg_core/p1functionspace/VertexDoFMemory.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormMass.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormDiv.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormDivT.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormEpsilon.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormLaplace.hpp"
#include "tinyhhg_core/p1functionspace/generated_new/P1FormPSPG.hpp"
#include "tinyhhg_core/polynomial/LSQPInterpolator.hpp"

#include "VertexDoFMacroEdge.hpp"
#include "VertexDoFMacroFace.hpp"
#include "VertexDoFMacroVertex.hpp"
#include "polynomial/VertexDoFMacroFacePolynomial.hpp"

namespace hhg {

template< class P1Form, bool Symmetric >
class P1PolynomialBlendingOperator : public Operator< P1Function< real_t >, P1Function< real_t > >
{
 public:
   typedef LSQPInterpolator< MonomialBasis2D, LSQPType::EDGE > EdgeInterpolator;
   typedef LSQPInterpolator< MonomialBasis2D, LSQPType::VERTEX > VertexInterpolator;

   P1PolynomialBlendingOperator( const std::shared_ptr< PrimitiveStorage >& storage,
                                    uint_t                                     minLevel,
                                    uint_t                                     maxLevel,
                                    uint_t                                     interpolationLevel )
   : Operator( storage, minLevel, maxLevel )
   , interpolationLevel_( interpolationLevel )
   {
      for (uint_t level = minLevel_; level <= maxLevel_; ++level)
      {
         PrimitiveDataID< FaceP1PolynomialMemory, Face > facePolynomialID;
         auto faceP1PolynomialMemoryDataHandling = std::make_shared< FaceP1PolynomialMemoryDataHandling >(polyDegree_);
         storage_->addFaceData(facePolynomialID, faceP1PolynomialMemoryDataHandling, "P1OperatorFacePolynomial");
         facePolynomialIDs_[level] = facePolynomialID;
      }
   }

   ~P1PolynomialBlendingOperator() {}

   void interpolateStencils( uint_t polyDegree )
   {
      if(Symmetric) {
         interpolateStencilsSymmetric( polyDegree );
      } else {
         interpolateStencilsAsymmetric( polyDegree );
      }
   }

   void interpolateStencilsSymmetric( uint_t polyDegree )
   {
      typedef stencilDirection SD;
      using namespace P1Elements;

      std::vector< real_t > faceStencil( 7 );

      for( auto& it : storage_->getFaces() )
      {
         Face& face = *it.second;
         form.geometryMap = face.getGeometryMap();

         for (uint_t level = minLevel_; level <= maxLevel_; ++level)
         {
            auto facePolynomials = face.getData( facePolynomialIDs_[level] );
            facePolynomials->addDegree(polyDegree);

            uint_t rowsize = levelinfo::num_microvertices_per_edge(interpolationLevel_);
            uint_t rowsizeFine = levelinfo::num_microvertices_per_edge(level);
            uint_t inner_rowsize = rowsize;

            VertexInterpolator centerInterpolator(polyDegree, interpolationLevel_);
            EdgeInterpolator horiInterpolator(polyDegree, interpolationLevel_);
            EdgeInterpolator vertInterpolator(polyDegree, interpolationLevel_);
            EdgeInterpolator diagInterpolator(polyDegree, interpolationLevel_);

            Point3D x, x0;
            x0 = face.coords[0];

            real_t ref_H = 1.0 / ( walberla::real_c( rowsize - 1 ) );
            real_t ref_h = 1.0 / ( walberla::real_c( rowsizeFine - 1 ) );

            Point3D d0 = ref_H * ( face.coords[1] - face.coords[0] );
            Point3D d2 = ref_H * ( face.coords[2] - face.coords[0] );

            // fine directions
            Point3D d0f = ref_h * ( face.coords[1] - face.coords[0] );
            Point3D d2f = ref_h * ( face.coords[2] - face.coords[0] );

            Point2D ref_x;

            Point3D dirS  = -1.0 * d2f;
            Point3D dirSE = d0f - 1.0 * d2f;
            Point3D dirE  = d0f;
            Point3D dirW  = -1.0 * d0f;
            Point3D dirNW = -1.0 * d0f + d2f;
            Point3D dirN  = d2f;

            for( uint_t j = 1; j < rowsize - 2; ++j )
            {
               ref_x[1] = j * ref_H;

               x = x0;
               x += walberla::real_c( j ) * d2 + d0;

               uint_t i;
               for( i = 1; i < inner_rowsize - 2; ++i )
               {
                  ref_x[0] = i * ref_H;

                  std::fill( faceStencil.begin(), faceStencil.end(), 0.0 );

                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirW, x + dirS}, P1Elements::FaceVertexDoF::elementSW, faceStencil );
                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirS, x + dirSE}, P1Elements::FaceVertexDoF::elementS, faceStencil );
                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirSE, x + dirE}, P1Elements::FaceVertexDoF::elementSE, faceStencil );
                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirE, x + dirN}, P1Elements::FaceVertexDoF::elementNE, faceStencil );
                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirN, x + dirNW}, P1Elements::FaceVertexDoF::elementN, faceStencil );
                  vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirNW, x + dirW}, P1Elements::FaceVertexDoF::elementNW, faceStencil );

                  //if (i == 1 && j == 1) {
                  //   PointND<real_t, 7> test(faceStencil.data());
                  //   WALBERLA_LOG_INFO("stencil = " << test);
                  //}

                  centerInterpolator.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_C )] );

                  horiInterpolator.addInterpolationPoint( ref_x + Point2D{{-0.5 * ref_h, 0.0}},
                                                          faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_W )] );

                  vertInterpolator.addInterpolationPoint( ref_x + Point2D{{0.0, -0.5 * ref_h}},
                                                          faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_S )] );

                  diagInterpolator.addInterpolationPoint( ref_x + Point2D{{0.5 * ref_h, -0.5 * ref_h}},
                                                          faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_SE )] );

                  if( i == 1 )
                  {
                     diagInterpolator.addInterpolationPoint( ref_x + Point2D{{-0.5 * ref_h, 0.5 * ref_h}},
                                                             faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_NW )] );
                  }

                  if( i == inner_rowsize - 2 - 1 )
                  {
                     horiInterpolator.addInterpolationPoint( ref_x + Point2D{{0.5 * ref_h, 0.0}},
                                                             faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_E )] );
                  }

                  x += d0;
               }

               vertInterpolator.addInterpolationPoint( ref_x + Point2D{{0.0, 0.5 * ref_h}},
                                                    faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_N )] );

               --inner_rowsize;
            }

            centerInterpolator.interpolate( facePolynomials->getPolynomialC( polyDegree ) );
            horiInterpolator.interpolate( facePolynomials->getPolynomialW( polyDegree ) );
            vertInterpolator.interpolate( facePolynomials->getPolynomialS( polyDegree ) );
            diagInterpolator.interpolate( facePolynomials->getPolynomialSE( polyDegree ) );
         }
      }
   }

  void interpolateStencilsAsymmetric( uint_t polyDegree )
  {
     typedef stencilDirection SD;
     using namespace P1Elements;

     std::vector< real_t > faceStencil( 7 );

     for( auto& it : storage_->getFaces() )
     {
        Face& face = *it.second;
        form.geometryMap = face.getGeometryMap();

        for (uint_t level = minLevel_; level <= maxLevel_; ++level)
        {
           auto facePolynomials = face.getData( facePolynomialIDs_[level] );
           facePolynomials->addDegree(polyDegree);

           uint_t rowsize = levelinfo::num_microvertices_per_edge(interpolationLevel_);
           uint_t rowsizeFine = levelinfo::num_microvertices_per_edge(level);
           uint_t inner_rowsize = rowsize;

           VertexInterpolator interpolatorS(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorSE(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorW(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorC(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorE(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorNW(polyDegree, interpolationLevel_);
           VertexInterpolator interpolatorN(polyDegree, interpolationLevel_);

           Point3D x, x0;
           x0 = face.coords[0];

           real_t ref_H = 1.0 / ( walberla::real_c( rowsize - 1 ) );
           real_t ref_h = 1.0 / ( walberla::real_c( rowsizeFine - 1 ) );

           Point3D d0 = ref_H * ( face.coords[1] - face.coords[0] );
           Point3D d2 = ref_H * ( face.coords[2] - face.coords[0] );

           // fine directions
           Point3D d0f = ref_h * ( face.coords[1] - face.coords[0] );
           Point3D d2f = ref_h * ( face.coords[2] - face.coords[0] );

           Point2D ref_x;

           Point3D dirS  = -1.0 * d2f;
           Point3D dirSE = d0f - 1.0 * d2f;
           Point3D dirE  = d0f;
           Point3D dirW  = -1.0 * d0f;
           Point3D dirNW = -1.0 * d0f + d2f;
           Point3D dirN  = d2f;

           for( uint_t j = 1; j < rowsize - 2; ++j )
           {
              ref_x[1] = j * ref_H;

              x = x0;
              x += walberla::real_c( j ) * d2 + d0;

              uint_t i;
              for( i = 1; i < inner_rowsize - 2; ++i )
              {
                 ref_x[0] = i * ref_H;

                 std::fill( faceStencil.begin(), faceStencil.end(), 0.0 );

                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirW, x + dirS}, P1Elements::FaceVertexDoF::elementSW, faceStencil );
                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirS, x + dirSE}, P1Elements::FaceVertexDoF::elementS, faceStencil );
                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirSE, x + dirE}, P1Elements::FaceVertexDoF::elementSE, faceStencil );
                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirE, x + dirN}, P1Elements::FaceVertexDoF::elementNE, faceStencil );
                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirN, x + dirNW}, P1Elements::FaceVertexDoF::elementN, faceStencil );
                 vertexdof::blending::assembleLocalStencil< P1Form >( form, {x, x + dirNW, x + dirW}, P1Elements::FaceVertexDoF::elementNW, faceStencil );

                 //if (i == 1 && j == 1) {
                 //   PointND<real_t, 7> test(faceStencil.data());
                 //   WALBERLA_LOG_INFO("stencil = " << test);
                 //}

                 interpolatorS.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_S )] );
                 interpolatorSE.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_SE )] );
                 interpolatorW.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_W )] );
                 interpolatorC.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_C )] );
                 interpolatorE.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_E )] );
                 interpolatorNW.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_NW )] );
                 interpolatorN.addInterpolationPoint( ref_x, faceStencil[vertexdof::stencilIndexFromVertex( SD::VERTEX_N )] );

                 x += d0;
              }
              --inner_rowsize;
           }

           interpolatorS.interpolate( facePolynomials->getPolynomialS( polyDegree ) );
           interpolatorSE.interpolate( facePolynomials->getPolynomialSE( polyDegree ) );
           interpolatorW.interpolate( facePolynomials->getPolynomialW( polyDegree ) );
           interpolatorC.interpolate( facePolynomials->getPolynomialC( polyDegree ) );
           interpolatorE.interpolate( facePolynomials->getPolynomialE( polyDegree ) );
           interpolatorNW.interpolate( facePolynomials->getPolynomialNW( polyDegree ) );
           interpolatorN.interpolate( facePolynomials->getPolynomialN( polyDegree ) );
        }
     }
  }

   void useDegree( uint_t degree ) { polyDegree_ = degree; }

 private:
   void apply_impl( P1Function< real_t >& src,
                    P1Function< real_t >& dst,
                    size_t                level,
                    DoFType               flag,
                    UpdateType            updateType = Replace )
   {
      checkForMissingPolynomial(level, polyDegree_);

      // start pulling vertex halos
      src.getCommunicator(level)->startCommunication<Edge, Vertex>();

      // start pulling edge halos
      src.getCommunicator(level)->startCommunication<Face, Edge>();

      src.getCommunicator(level)->endCommunication<Edge, Vertex>();

      for (auto& it : storage_->getVertices()) {
         Vertex& vertex = *it.second;

         if (testFlag(vertex.getDoFType(), flag))
         {
            vertexdof::blending::macrovertex::applyBlending< real_t, P1Form >(level, vertex, form, storage_, src.getVertexDataID(), dst.getVertexDataID(), updateType);
         }
      }

      dst.getCommunicator(level)->startCommunication<Vertex, Edge>();

      // end pulling edge halos
      src.getCommunicator(level)->endCommunication<Face, Edge>();

      for (auto& it : storage_->getEdges()) {
         Edge& edge = *it.second;

         if (testFlag(edge.getDoFType(), flag))
         {
            vertexdof::blending::macroedge::applyBlending< real_t, P1Form >(level, edge, form, storage_, src.getEdgeDataID(), dst.getEdgeDataID(), updateType);
         }
      }

      dst.getCommunicator(level)->endCommunication<Vertex, Edge>();

      dst.getCommunicator(level)->startCommunication<Edge, Face>();

      for (auto& it : storage_->getFaces()) {
         Face& face = *it.second;

         if (testFlag(face.type, flag))
         {
            if (Symmetric) {
               vertexdof::macroface::applyPolynomial<real_t>(
                   polyDegree_, level, face, facePolynomialIDs_[level], src.getFaceDataID(), dst.getFaceDataID(),
                   updateType);
            } else {
               vertexdof::macroface::applyPolynomialFull<real_t>(
                   polyDegree_, level, face, facePolynomialIDs_[level], src.getFaceDataID(), dst.getFaceDataID(),
                   updateType);
            }
         }
      }

      dst.getCommunicator(level)->endCommunication<Edge, Face>();
   }

   void smooth_gs_impl( P1Function< real_t >& dst, P1Function< real_t >& rhs, size_t level, DoFType flag )
   {
      checkForMissingPolynomial(level, polyDegree_);

      // start pulling vertex halos
      dst.getCommunicator(level)->startCommunication<Edge, Vertex>();

      // start pulling edge halos
      dst.getCommunicator(level)->startCommunication<Face, Edge>();

      // end pulling vertex halos
      dst.getCommunicator(level)->endCommunication<Edge, Vertex>();

      for (auto& it : storage_->getVertices()) {
         Vertex& vertex = *it.second;

         if (testFlag(vertex.getDoFType(), flag))
         {
            vertexdof::blending::macrovertex::smoothGSBlending(level, vertex, form, storage_, dst.getVertexDataID(), rhs.getVertexDataID());
         }
      }

      dst.getCommunicator(level)->startCommunication<Vertex, Edge>();

      // end pulling edge halos
      dst.getCommunicator(level)->endCommunication<Face, Edge>();

      for (auto& it : storage_->getEdges()) {
         Edge& edge = *it.second;

         if (testFlag(edge.getDoFType(), flag))
         {
            vertexdof::blending::macroedge::smoothGSBlending<real_t>(level, edge, form, storage_, dst.getEdgeDataID(), rhs.getEdgeDataID());
         }
      }

      dst.getCommunicator(level)->endCommunication<Vertex, Edge>();

      dst.getCommunicator(level)->startCommunication<Edge, Face>();

      for (auto& it : storage_->getFaces()) {
         Face& face = *it.second;

         if (testFlag(face.type, flag))
         {
            if (Symmetric) {
               vertexdof::macroface::smooth_gs_polynomial<real_t>(
                   polyDegree_, level, face, facePolynomialIDs_[level], dst.getFaceDataID(), rhs.getFaceDataID());
            } else {
               vertexdof::macroface::smooth_gs_polynomial_full<real_t>(
                   polyDegree_, level, face, facePolynomialIDs_[level], dst.getFaceDataID(), rhs.getFaceDataID());
            }
         }
      }

      dst.getCommunicator(level)->endCommunication<Edge, Face>();
   }

   void smooth_jac_impl( P1Function< real_t >& dst,
                         P1Function< real_t >& rhs,
                         P1Function< real_t >& tmp,
                         size_t                level,
                         DoFType               flag )
   {
      checkForMissingPolynomial(level, polyDegree_);

      // start pulling vertex halos
      tmp.getCommunicator( level )->startCommunication< Edge, Vertex >();

      // start pulling edge halos
      tmp.getCommunicator( level )->startCommunication< Face, Edge >();

      // end pulling vertex halos
      tmp.getCommunicator( level )->endCommunication< Edge, Vertex >();

      for( auto& it : storage_->getVertices() )
      {
         Vertex& vertex = *it.second;

         if( testFlag( vertex.getDoFType(), flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Vertex::smooth_jac(vertex, vertexLocalMatrixID_, dst.getVertexDataID(), rhs.getVertexDataID(), tmp.getVertexDataID(), level);
         }
      }

      dst.getCommunicator( level )->startCommunication< Vertex, Edge >();

      // end pulling edge halos
      tmp.getCommunicator( level )->endCommunication< Face, Edge >();

      for( auto& it : storage_->getEdges() )
      {
         Edge& edge = *it.second;

         if( testFlag( edge.getDoFType(), flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Edge::smooth_jac(level, edge, edgeLocalMatrixID_, dst.getEdgeDataID(), rhs.getEdgeDataID(), tmp.getEdgeDataID());
         }
      }

      dst.getCommunicator( level )->endCommunication< Vertex, Edge >();

      dst.getCommunicator( level )->startCommunication< Edge, Face >();

      for( auto& it : storage_->getFaces() )
      {
         Face& face = *it.second;

         if( testFlag( face.type, flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Face::smooth_jac(level, face, faceLocalMatrixID_, dst.getFaceDataID(), rhs.getFaceDataID(), tmp.getFaceDataID());
         }
      }

      dst.getCommunicator( level )->endCommunication< Edge, Face >();
   }

#ifdef HHG_BUILD_WITH_PETSC
   void createMatrix_impl( P1Function< real_t >& src, P1Function< real_t >& dst, Mat& mat, size_t level, DoFType flag )
   {
      checkForMissingPolynomial(level, polyDegree_);

      for( auto& it : storage_->getVertices() )
      {
         Vertex& vertex = *it.second;

         if( testFlag( vertex.getDoFType(), flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Vertex::saveOperator(vertex, vertexLocalMatrixID_, src.getVertexDataID(), dst.getVertexDataID(), mat, level);
         }
      }

      for( auto& it : storage_->getEdges() )
      {
         Edge& edge = *it.second;

         if( testFlag( edge.getDoFType(), flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Edge::saveOperator(level, edge, edgeLocalMatrixID_, src.getEdgeDataID(), dst.getEdgeDataID(), mat);
         }
      }

      for( auto& it : storage_->getFaces() )
      {
         Face& face = *it.second;

         if( testFlag( face.type, flag ) )
         {
            WALBERLA_ABORT( "To be implemented" )
            //        P1Face::saveOperator(level, face, faceLocalMatrixID_, src.getFaceDataID(), dst.getFaceDataID(), mat);
         }
      }
   }
#endif
   std::map<uint_t, PrimitiveDataID< FaceP1PolynomialMemory, Face > >                   facePolynomialIDs_;

 private:

   void checkForMissingPolynomial(uint_t level, uint_t degree)
   {
      WALBERLA_ASSERT(facePolynomialIDs_.count(level) > 0, "Polynomial for level " << level << " has not been interpolated");
   }

   uint_t polyDegree_;
   uint_t interpolationLevel_;
   P1Form form;
};

typedef P1PolynomialBlendingOperator< P1Form_laplace, true > P1PolynomialBlendingLaplaceOperator;
typedef P1PolynomialBlendingOperator< P1Form_mass, true > P1PolynomialBlendingMassOperator;

typedef P1PolynomialBlendingOperator< P1Form_epsilon_11, true > P1PolynomialBlendingEpsilonOperator_11;
typedef P1PolynomialBlendingOperator< P1Form_epsilon_12, false > P1PolynomialBlendingEpsilonOperator_12;
typedef P1PolynomialBlendingOperator< P1Form_epsilon_21, false > P1PolynomialBlendingEpsilonOperator_21;
typedef P1PolynomialBlendingOperator< P1Form_epsilon_22, true > P1PolynomialBlendingEpsilonOperator_22;

typedef P1PolynomialBlendingOperator< P1Form_divT_1, false > P1PolynomialBlendingDivTOperator_1;
typedef P1PolynomialBlendingOperator< P1Form_divT_2, false > P1PolynomialBlendingDivTOperator_2;

typedef P1PolynomialBlendingOperator< P1Form_div_1, false > P1PolynomialBlendingDivOperator_1;
typedef P1PolynomialBlendingOperator< P1Form_div_2, false > P1PolynomialBlendingDivOperator_2;

typedef P1PolynomialBlendingOperator< P1Form_pspg, true > P1PolynomialBlendingPSPGOperator;

} // namespace hhg