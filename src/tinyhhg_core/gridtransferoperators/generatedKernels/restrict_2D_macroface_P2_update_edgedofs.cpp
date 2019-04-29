
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "GeneratedKernelsP2MacroFace2D.hpp"

namespace hhg {
namespace P2 {
namespace macroface {
namespace generated {

static void restrict_2D_macroface_P2_update_edgedofs_level_2(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 3; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 3; ctr_1 < 4; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 3; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 3 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 3 - ctr_2; ctr_1 < 4 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 3; ctr_2 < 4; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 11];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 10];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
            _data_edgeCoarseDst_X[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 5*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_3(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 7; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 7; ctr_1 < 8; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 7; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 7 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 7 - ctr_2; ctr_1 < 8 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 7; ctr_2 < 8; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 19];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 18];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
            _data_edgeCoarseDst_X[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 9*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_4(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 15; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 15; ctr_1 < 16; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 15; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 15 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 15 - ctr_2; ctr_1 < 16 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 15; ctr_2 < 16; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 35];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 34];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
            _data_edgeCoarseDst_X[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 17*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_5(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 31; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 31; ctr_1 < 32; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 31; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 31 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 31 - ctr_2; ctr_1 < 32 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 31; ctr_2 < 32; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 67];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 66];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
            _data_edgeCoarseDst_X[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 33*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_6(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 63; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 63; ctr_1 < 64; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 63; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 63 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 63 - ctr_2; ctr_1 < 64 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 63; ctr_2 < 64; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 131];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 130];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
            _data_edgeCoarseDst_X[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 65*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_7(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 127; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 127; ctr_1 < 128; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 127; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 127 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 127 - ctr_2; ctr_1 < 128 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 127; ctr_2 < 128; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 259];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 258];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
            _data_edgeCoarseDst_X[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 129*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_8(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 255; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 255; ctr_1 < 256; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 255; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 255 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 255 - ctr_2; ctr_1 < 256 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 255; ctr_2 < 256; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 515];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 514];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
            _data_edgeCoarseDst_X[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 257*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_9(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 511; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 511; ctr_1 < 512; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 511; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 511 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 511 - ctr_2; ctr_1 < 512 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 511; ctr_2 < 512; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1027];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1026];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
            _data_edgeCoarseDst_X[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 513*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_10(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 1023; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 1023; ctr_1 < 1024; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 1023; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 1023 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 1023 - ctr_2; ctr_1 < 1024 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 1023; ctr_2 < 1024; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2051];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2050];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
            _data_edgeCoarseDst_X[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 1025*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_11(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 2047; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 2047; ctr_1 < 2048; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 2047; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 2047 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 2047 - ctr_2; ctr_1 < 2048 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 2047; ctr_2 < 2048; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4099];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4098];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
            _data_edgeCoarseDst_X[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 2049*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_12(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 4095; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 4095; ctr_1 < 4096; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 4095; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 4095 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 4095 - ctr_2; ctr_1 < 4096 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 4095; ctr_2 < 4096; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8195];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8194];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
            _data_edgeCoarseDst_X[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 4097*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_13(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 8191; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 8191; ctr_1 < 8192; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 8191; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 8191 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 8191 - ctr_2; ctr_1 < 8192 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 8191; ctr_2 < 8192; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16387];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16386];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
            _data_edgeCoarseDst_X[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 8193*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_14(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < 16383; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = 16383; ctr_1 < 16384; ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < 16383; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < 16383 - ctr_2; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = 16383 - ctr_2; ctr_1 < 16384 - ctr_2; ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = 16383; ctr_2 < 16384; ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32771];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32770];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
            _data_edgeCoarseDst_X[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + 16385*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}

static void restrict_2D_macroface_P2_update_edgedofs_level_any(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, int64_t coarse_level, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
   const double xi_33 = 1 / (num_neighbor_faces_edge0);
   const double xi_34 = 1 / (num_neighbor_faces_edge2);
   const double xi_61 = 1 / (num_neighbor_faces_edge1);
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // bottom left vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_36 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_52 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_46 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_42 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_43 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_53 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_45 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_47 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_48 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_49 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_50 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_51 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_39 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_40 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_41 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_54 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_55 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_56 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_36 + xi_39 + xi_40 + xi_41 + xi_46 + xi_52;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_42 + xi_43 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_53;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_51 + xi_52 + xi_53 + xi_54 + xi_55 + xi_56;
         }
         // bottom edge
         for (int ctr_1 = 1; ctr_1 < (1 << (coarse_level)) - 1; ctr_1 += 1)
         {
            const double xi_141 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_159 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_151 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_147 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_148 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_161 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_150 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_152 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_153 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_154 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_155 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_156 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_157 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_158 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_160 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_162 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_163 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_164 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_144 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_145 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_146 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_144 + xi_145 + xi_146 + xi_151 + xi_159;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_147 + xi_148 + xi_150 + xi_151 + xi_152 + xi_153 + xi_154 + xi_155 + xi_161;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_156 + xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164;
         }
         // bottom right vertex
         for (int ctr_1 = (1 << (coarse_level)) - 1; ctr_1 < (1 << (coarse_level)); ctr_1 += 1)
         {
            const double xi_63 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_78 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_71 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_69 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_80 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_75 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_76 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_77 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_79 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_81 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_82 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_83 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_66 = 1.0*xi_33*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_67 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_68 = xi_33*0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_72 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_73 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_74 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_63 + xi_66 + xi_67 + xi_68 + xi_71 + xi_78;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_69 + xi_71 + xi_72 + xi_73 + xi_74 + xi_80;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_75 + xi_76 + xi_77 + xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83;
         }
      }
      for (int ctr_2 = 1; ctr_2 < (1 << (coarse_level)) - 1; ctr_2 += 1)
      {
         // left edge
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_199 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_200 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_218 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_202 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_203 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_212 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_205 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_206 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_207 = _data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_208 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_209 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_219 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_211 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_213 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_214 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_215 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_216 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_217 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_220 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_221 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_222 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_199 + xi_200 + xi_202 + xi_203 + xi_205 + xi_206 + xi_207 + xi_212 + xi_218;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_208 + xi_209 + xi_211 + xi_212 + xi_213 + xi_214 + xi_215 + xi_216 + xi_219;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222;
         }
         // inner triangle
         for (int ctr_1 = 1; ctr_1 < -ctr_2 + (1 << (coarse_level)) - 1; ctr_1 += 1)
         {
            const double xi_3 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_4 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_24 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_6 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_7 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_16 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_9 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_10 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_11 = _data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_12 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_13 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_26 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_15 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_17 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_18 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_19 = 0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_20 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_21 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_22 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_23 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_25 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_27 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_28 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_29 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_16 + xi_24 + xi_3 + xi_4 + xi_6 + xi_7 + xi_9;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_12 + xi_13 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_26;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_28 + xi_29;
         }
         // diagonal edge
         for (int ctr_1 = -ctr_2 + (1 << (coarse_level)) - 1; ctr_1 < -ctr_2 + (1 << (coarse_level)); ctr_1 += 1)
         {
            const double xi_170 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_171 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_188 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_173 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_174 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_181 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_176 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_177 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_178 = _data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_179 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_190 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_185 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_186 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_187 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_189 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
            const double xi_191 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_192 = 0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_193 = _data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_182 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_183 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_184 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_170 + xi_171 + xi_173 + xi_174 + xi_176 + xi_177 + xi_178 + xi_181 + xi_188;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_179 + xi_181 + xi_182 + xi_183 + xi_184 + xi_190;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_185 + xi_186 + xi_187 + xi_188 + xi_189 + xi_190 + xi_191 + xi_192 + xi_193;
         }
      }
      for (int ctr_2 = (1 << (coarse_level)) - 1; ctr_2 < (1 << (coarse_level)); ctr_2 += 1)
      {
         // top vertex
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_90 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_91 = 0.25*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_106 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_93 = 0.5*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_94 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
            const double xi_101 = 0.5*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_96 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_97 = 0.75*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_98 = _data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_99 = 0.25*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_107 = 0.5*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_105 = 0.25*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_102 = 1.0*xi_61*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1];
            const double xi_103 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_104 = xi_61*0.75*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
            const double xi_108 = 1.0*xi_34*_data_vertexFineSrc[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 2) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            const double xi_109 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
            const double xi_110 = xi_34*0.75*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
            _data_edgeCoarseDst_X[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_106 + xi_90 + xi_91 + xi_93 + xi_94 + xi_96 + xi_97 + xi_98;
            _data_edgeCoarseDst_XY[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_101 + xi_102 + xi_103 + xi_104 + xi_107 + xi_99;
            _data_edgeCoarseDst_Y[ctr_1 + ctr_2*((1 << (coarse_level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_105 + xi_106 + xi_107 + xi_108 + xi_109 + xi_110;
         }
      }
   }
}


void restrict_2D_macroface_P2_update_edgedofs(double * RESTRICT _data_edgeCoarseDst_X, double * RESTRICT _data_edgeCoarseDst_XY, double * RESTRICT _data_edgeCoarseDst_Y, double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexFineSrc, int64_t coarse_level, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2)
{
    switch( coarse_level )
    {
    case 2:
        restrict_2D_macroface_P2_update_edgedofs_level_2(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 3:
        restrict_2D_macroface_P2_update_edgedofs_level_3(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 4:
        restrict_2D_macroface_P2_update_edgedofs_level_4(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 5:
        restrict_2D_macroface_P2_update_edgedofs_level_5(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 6:
        restrict_2D_macroface_P2_update_edgedofs_level_6(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 7:
        restrict_2D_macroface_P2_update_edgedofs_level_7(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 8:
        restrict_2D_macroface_P2_update_edgedofs_level_8(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 9:
        restrict_2D_macroface_P2_update_edgedofs_level_9(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 10:
        restrict_2D_macroface_P2_update_edgedofs_level_10(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 11:
        restrict_2D_macroface_P2_update_edgedofs_level_11(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 12:
        restrict_2D_macroface_P2_update_edgedofs_level_12(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 13:
        restrict_2D_macroface_P2_update_edgedofs_level_13(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    case 14:
        restrict_2D_macroface_P2_update_edgedofs_level_14(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    default:
        restrict_2D_macroface_P2_update_edgedofs_level_any(_data_edgeCoarseDst_X, _data_edgeCoarseDst_XY, _data_edgeCoarseDst_Y, _data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexFineSrc, coarse_level, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2);
        break;
    }
}
    

} // namespace generated
} // namespace macroface
} // namespace P2
} // namespace hhg