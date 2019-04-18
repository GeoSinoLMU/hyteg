
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "core/DataTypes.h"

#include "core/Macros.h"

#include "tinyhhg_core/edgedofspace/EdgeDoFIndexing.hpp"

#include <map>

#define RESTRICT WALBERLA_RESTRICT

namespace hhg {
namespace P2 {
namespace macrocell {
namespace generated {

void sor_3D_macrocell_P2_update_vertexdofs(double const * RESTRICT const _data_edgeCellDst_X, double const * RESTRICT const _data_edgeCellDst_XY, double const * RESTRICT const _data_edgeCellDst_XYZ, double const * RESTRICT const _data_edgeCellDst_XZ, double const * RESTRICT const _data_edgeCellDst_Y, double const * RESTRICT const _data_edgeCellDst_YZ, double const * RESTRICT const _data_edgeCellDst_Z, double * RESTRICT _data_vertexCellDst, double const * RESTRICT const _data_vertexCellRhs, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > e2vStencilMap, int64_t level, double relax, std::map< hhg::indexing::IndexIncrement, double > v2vStencilMap);

void sor_3D_macrocell_P2_update_edgedofs(double * RESTRICT _data_edgeCellDst_X, double * RESTRICT _data_edgeCellDst_XY, double * RESTRICT _data_edgeCellDst_XYZ, double * RESTRICT _data_edgeCellDst_XZ, double * RESTRICT _data_edgeCellDst_Y, double * RESTRICT _data_edgeCellDst_YZ, double * RESTRICT _data_edgeCellDst_Z, double const * RESTRICT const _data_edgeCellRhs_X, double const * RESTRICT const _data_edgeCellRhs_XY, double const * RESTRICT const _data_edgeCellRhs_XYZ, double const * RESTRICT const _data_edgeCellRhs_XZ, double const * RESTRICT const _data_edgeCellRhs_Y, double const * RESTRICT const _data_edgeCellRhs_YZ, double const * RESTRICT const _data_edgeCellRhs_Z, double const * RESTRICT const _data_vertexCellDst, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > > e2eStencilMap, int64_t level, double relax, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > v2eStencilMap);

} // namespace generated
} // namespace macrocell
} // namespace P2
} // namespace hhg