
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include "all.hpp"
#include "core/Macros.h"
#include "hyteg/edgedofspace/EdgeDoFOrientation.hpp"
#include "hyteg/indexing/Common.hpp"
#include <map>
#define RESTRICT WALBERLA_RESTRICT

namespace hyteg {
namespace edgedof {
namespace comm {
namespace generated {

void communicate_directly_edgedof_cell_to_face_part_2_impl_301(double const * RESTRICT const _data_edge_cell_src_XY, double const * RESTRICT const _data_edge_cell_src_Y, double const * RESTRICT const _data_edge_cell_src_YZ, double * RESTRICT _data_edge_face_dst_gl0_XZ, double * RESTRICT _data_edge_face_dst_gl0_YZ, double * RESTRICT _data_edge_face_dst_gl0_Z, int32_t level);

} // namespace generated
} // namespace comm
} // namespace edgedof
} // namespace hyteg