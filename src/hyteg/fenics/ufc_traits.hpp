/*
 * Copyright (c) 2017-2019 Dominik Thoennes, Nils Kohl.
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

#include "hyteg/types/matrix.hpp"

class p1_tet_diffusion_cell_integral_0_otherwise;
class p1_tet_div_tet_cell_integral_0_otherwise;
class p1_tet_div_tet_cell_integral_1_otherwise;
class p1_tet_div_tet_cell_integral_2_otherwise;
class p1_tet_divt_tet_cell_integral_0_otherwise;
class p1_tet_divt_tet_cell_integral_1_otherwise;
class p1_tet_divt_tet_cell_integral_2_otherwise;
class p1_tet_mass_cell_integral_0_otherwise;
class p1_tet_pspg_tet_cell_integral_0_otherwise;

class p2_tet_diffusion_cell_integral_0_otherwise;
class p2_tet_mass_cell_integral_0_otherwise;
class p2_tet_pspg_tet_cell_integral_0_otherwise;
class p2_tet_div_tet_cell_integral_0_otherwise;
class p2_tet_div_tet_cell_integral_1_otherwise;
class p2_tet_div_tet_cell_integral_2_otherwise;
class p2_tet_divt_tet_cell_integral_0_otherwise;
class p2_tet_divt_tet_cell_integral_1_otherwise;
class p2_tet_divt_tet_cell_integral_2_otherwise;

class p2_to_p1_tet_div_tet_cell_integral_0_otherwise;
class p2_to_p1_tet_div_tet_cell_integral_1_otherwise;
class p2_to_p1_tet_div_tet_cell_integral_2_otherwise;

class p1_to_p2_tet_divt_tet_cell_integral_0_otherwise;
class p1_to_p2_tet_divt_tet_cell_integral_1_otherwise;
class p1_to_p2_tet_divt_tet_cell_integral_2_otherwise;

namespace hyteg {
namespace fenics {

class UndefinedAssembly;
class NoAssemble;
class Dummy10x10Assembly;

template< typename UFCOperator >
struct UFCTrait;

template<> struct UFCTrait< p1_tet_diffusion_cell_integral_0_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_div_tet_cell_integral_0_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_div_tet_cell_integral_1_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_div_tet_cell_integral_2_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_divt_tet_cell_integral_0_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_divt_tet_cell_integral_1_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_divt_tet_cell_integral_2_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_mass_cell_integral_0_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_tet_pspg_tet_cell_integral_0_otherwise > { typedef Matrix4r LocalStiffnessMatrix_T; };

template<> struct UFCTrait< p2_tet_diffusion_cell_integral_0_otherwise > { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_mass_cell_integral_0_otherwise >      { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_pspg_tet_cell_integral_0_otherwise >  { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_div_tet_cell_integral_0_otherwise >   { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_div_tet_cell_integral_1_otherwise >   { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_div_tet_cell_integral_2_otherwise >   { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_divt_tet_cell_integral_0_otherwise >  { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_divt_tet_cell_integral_1_otherwise >  { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_tet_divt_tet_cell_integral_2_otherwise >  { typedef Matrix10r LocalStiffnessMatrix_T; };

template<> struct UFCTrait< p2_to_p1_tet_div_tet_cell_integral_0_otherwise > { typedef Matrixr<4, 10> LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_to_p1_tet_div_tet_cell_integral_1_otherwise > { typedef Matrixr<4, 10> LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p2_to_p1_tet_div_tet_cell_integral_2_otherwise > { typedef Matrixr<4, 10> LocalStiffnessMatrix_T; };

template<> struct UFCTrait< p1_to_p2_tet_divt_tet_cell_integral_0_otherwise > { typedef Matrixr<10, 4> LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_to_p2_tet_divt_tet_cell_integral_1_otherwise > { typedef Matrixr<10, 4> LocalStiffnessMatrix_T; };
template<> struct UFCTrait< p1_to_p2_tet_divt_tet_cell_integral_2_otherwise > { typedef Matrixr<10, 4> LocalStiffnessMatrix_T; };

template<> struct UFCTrait< UndefinedAssembly > { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< NoAssemble > { typedef Matrix10r LocalStiffnessMatrix_T; };
template<> struct UFCTrait< Dummy10x10Assembly > { typedef Matrix10r LocalStiffnessMatrix_T; };

}
}