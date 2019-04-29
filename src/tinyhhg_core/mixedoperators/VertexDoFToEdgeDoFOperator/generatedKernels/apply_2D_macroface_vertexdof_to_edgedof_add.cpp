
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "GeneratedKernelsVertexToEdgeMacroFace2D.hpp"

namespace hhg {
namespace VertexDoFToEdgeDoF {
namespace generated {

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_2(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 7];
            _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 3; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 7];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 5];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 3; ctr_1 < 4; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 5];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 3; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 5];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 7];
            _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 3 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 5];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 7];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 5];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 3 - ctr_2; ctr_1 < 4 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 5];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 5];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 3; ctr_2 < 4; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 6];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 5];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_3(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 11];
            _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 7; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 11];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 9];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 7; ctr_1 < 8; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 9];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 7; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 9];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 11];
            _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 7 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 9];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 11];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 9];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 7 - ctr_2; ctr_1 < 8 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 9];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 9];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 7; ctr_2 < 8; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 10];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 9];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_4(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 19];
            _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 15; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 19];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 17];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 15; ctr_1 < 16; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 17];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 15; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 17];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 19];
            _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 15 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 17];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 19];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 17];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 15 - ctr_2; ctr_1 < 16 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 17];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 17];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 15; ctr_2 < 16; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 18];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 17];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_5(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 35];
            _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 31; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 35];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 33];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 31; ctr_1 < 32; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 33];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 31; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 33];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 35];
            _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 31 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 33];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 35];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 33];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 31 - ctr_2; ctr_1 < 32 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 33];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 33];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 31; ctr_2 < 32; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 34];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 33];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_6(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 67];
            _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 63; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 67];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 65];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 63; ctr_1 < 64; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 65];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 63; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 65];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 67];
            _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 63 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 65];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 67];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 65];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 63 - ctr_2; ctr_1 < 64 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 65];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 65];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 63; ctr_2 < 64; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 66];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 65];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_7(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 131];
            _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 127; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 131];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 129];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 127; ctr_1 < 128; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 129];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 127; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 129];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 131];
            _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 127 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 129];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 131];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 129];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 127 - ctr_2; ctr_1 < 128 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 129];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 129];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 127; ctr_2 < 128; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 130];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 129];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_8(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 259];
            _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 255; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 259];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 257];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 255; ctr_1 < 256; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 257];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 255; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 257];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 259];
            _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 255 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 257];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 259];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 257];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 255 - ctr_2; ctr_1 < 256 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 257];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 257];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 255; ctr_2 < 256; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 258];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 257];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_9(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 515];
            _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 511; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 515];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 513];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 511; ctr_1 < 512; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 513];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 511; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 513];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 515];
            _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 511 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 513];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 515];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 513];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 511 - ctr_2; ctr_1 < 512 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 513];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 513];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 511; ctr_2 < 512; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 514];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 513];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_10(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1027];
            _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 1023; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1027];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1025];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 1023; ctr_1 < 1024; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1025];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 1023; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 1025];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1027];
            _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 1023 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 1025];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1027];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1025];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 1023 - ctr_2; ctr_1 < 1024 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 1025];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1025];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 1023; ctr_2 < 1024; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1026];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 1025];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_11(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2051];
            _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 2047; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2051];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2049];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 2047; ctr_1 < 2048; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2049];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 2047; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 2049];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2051];
            _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 2047 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 2049];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2051];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2049];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 2047 - ctr_2; ctr_1 < 2048 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 2049];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2049];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 2047; ctr_2 < 2048; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 2050];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 2049];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_12(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4099];
            _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 4095; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4099];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4097];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 4095; ctr_1 < 4096; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4097];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 4095; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 4097];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4099];
            _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 4095 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 4097];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4099];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4097];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 4095 - ctr_2; ctr_1 < 4096 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 4097];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4097];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 4095; ctr_2 < 4096; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 4098];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 4097];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_13(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8195];
            _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 8191; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8195];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8193];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 8191; ctr_1 < 8192; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8193];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 8191; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 8193];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8195];
            _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 8191 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 8193];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8195];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8193];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 8191 - ctr_2; ctr_1 < 8192 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 8193];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8193];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 8191; ctr_2 < 8192; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 8194];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 8193];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_14(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16387];
            _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 16383; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16387];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16385];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = 16383; ctr_1 < 16384; ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16385];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 16383; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 16385];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16387];
            _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 16383 - ctr_2; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 16385];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16387];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16385];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 16383 - ctr_2; ctr_1 < 16384 - ctr_2; ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 16385];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16385];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = 16383; ctr_2 < 16384; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 16386];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 - 1)) / (2)) - 16385];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}

static void apply_2D_macroface_vertexdof_to_edgedof_add_level_any(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil, int64_t level)
{
   const double xi_31 = _data_vertexToDiagonalEdgeFaceStencil[3];
   const double xi_32 = _data_vertexToDiagonalEdgeFaceStencil[2];
   const double xi_33 = _data_vertexToDiagonalEdgeFaceStencil[0];
   const double xi_34 = _data_vertexToDiagonalEdgeFaceStencil[1];
   const double xi_78 = _data_vertexToVerticalEdgeFaceStencil[3];
   const double xi_79 = _data_vertexToVerticalEdgeFaceStencil[0];
   const double xi_80 = _data_vertexToVerticalEdgeFaceStencil[2];
   const double xi_81 = _data_vertexToVerticalEdgeFaceStencil[1];
   const double xi_118 = _data_vertexToHorizontalEdgeFaceStencil[1];
   const double xi_119 = _data_vertexToHorizontalEdgeFaceStencil[3];
   const double xi_120 = _data_vertexToHorizontalEdgeFaceStencil[2];
   const double xi_121 = _data_vertexToHorizontalEdgeFaceStencil[0];
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_42 = _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_38 = xi_31*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_39 = xi_32*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_40 = xi_33*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_41 = xi_34*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_38 + xi_39 + xi_40 + xi_41 + xi_42;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_89 = _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_94 = _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_85 = xi_31*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_86 = xi_32*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_87 = xi_33*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_88 = xi_34*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1];
            const double xi_90 = xi_78*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - 1];
            const double xi_91 = xi_79*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_92 = xi_80*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_93 = xi_81*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89;
            _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_90 + xi_91 + xi_92 + xi_93 + xi_94;
         }
         // bottom right vertex
         for (int ctr_1 = (1 << (level)) - 1; ctr_1 < (1 << (level)); ctr_1 += 1)
         {
            const double xi_55 = _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_51 = xi_78*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - 1];
            const double xi_52 = xi_79*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_53 = xi_80*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_54 = xi_81*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55;
         }
      }
      for (int ctr_2 = 1; ctr_2 < (1 << (level)) - 1; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_133 = _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_138 = _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_129 = xi_118*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_130 = xi_119*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_131 = xi_120*_data_vertexFaceSrc[ctr_1 + (ctr_2 - 1)*((1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + 1];
            const double xi_132 = xi_121*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_134 = xi_31*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_135 = xi_32*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_136 = xi_33*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_137 = xi_34*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_129 + xi_130 + xi_131 + xi_132 + xi_133;
            _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_134 + xi_135 + xi_136 + xi_137 + xi_138;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < -ctr_2 + (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_19 = _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_24 = _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_29 = _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_15 = xi_118*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_16 = xi_119*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_17 = xi_120*_data_vertexFaceSrc[ctr_1 + (ctr_2 - 1)*((1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + 1];
            const double xi_18 = xi_121*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = xi_31*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_21 = xi_32*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_22 = xi_33*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = xi_34*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + 1];
            const double xi_27 = xi_78*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - 1];
            const double xi_28 = xi_79*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_25 = xi_80*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_26 = xi_81*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_15 + xi_16 + xi_17 + xi_18 + xi_19;
            _data_edgeFaceDst_XY[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_20 + xi_21 + xi_22 + xi_23 + xi_24;
            _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = -ctr_2 + (1 << (level)) - 1; ctr_1 < -ctr_2 + (1 << (level)); ctr_1 += 1)
         {
            const double xi_111 = _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_116 = _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_107 = xi_118*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_108 = xi_119*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_109 = xi_120*_data_vertexFaceSrc[ctr_1 + (ctr_2 - 1)*((1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + 1];
            const double xi_110 = xi_121*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            const double xi_112 = xi_78*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - 1];
            const double xi_113 = xi_79*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_114 = xi_80*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_115 = xi_81*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_107 + xi_108 + xi_109 + xi_110 + xi_111;
            _data_edgeFaceDst_Y[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_112 + xi_113 + xi_114 + xi_115 + xi_116;
         }
      }
      for (int ctr_2 = (1 << (level)) - 1; ctr_2 < (1 << (level)); ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_68 = _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_64 = xi_118*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))];
            const double xi_65 = xi_119*_data_vertexFaceSrc[ctr_1 + (ctr_2 + 1)*((1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2))];
            const double xi_66 = xi_120*_data_vertexFaceSrc[ctr_1 + (ctr_2 - 1)*((1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + 1];
            const double xi_67 = xi_121*_data_vertexFaceSrc[ctr_1 + ctr_2*((1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + 1];
            _data_edgeFaceDst_X[ctr_1 + ctr_2*((1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
         }
      }
   }
}


void apply_2D_macroface_vertexdof_to_edgedof_add(double * RESTRICT _data_edgeFaceDst_X, double * RESTRICT _data_edgeFaceDst_XY, double * RESTRICT _data_edgeFaceDst_Y, double const * RESTRICT const _data_vertexFaceSrc, double const * RESTRICT const _data_vertexToDiagonalEdgeFaceStencil, double const * RESTRICT const _data_vertexToHorizontalEdgeFaceStencil, double const * RESTRICT const _data_vertexToVerticalEdgeFaceStencil, int64_t level)
{
    switch( level )
    {
    case 2:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_2(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 3:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_3(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 4:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_4(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 5:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_5(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 6:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_6(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 7:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_7(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 8:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_8(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 9:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_9(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 10:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_10(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 11:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_11(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 12:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_12(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 13:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_13(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    case 14:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_14(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil);
        break;
    default:
        apply_2D_macroface_vertexdof_to_edgedof_add_level_any(_data_edgeFaceDst_X, _data_edgeFaceDst_XY, _data_edgeFaceDst_Y, _data_vertexFaceSrc, _data_vertexToDiagonalEdgeFaceStencil, _data_vertexToHorizontalEdgeFaceStencil, _data_vertexToVerticalEdgeFaceStencil, level);
        break;
    }
}
    

} // namespace generated
} // namespace VertexDoFToEdgeDoF
} // namespace hhg