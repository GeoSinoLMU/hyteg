
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include "all.hpp"
#include "core/Macros.h"
#include "tinyhhg_core/edgedofspace/EdgeDoFOrientation.hpp"
#include "tinyhhg_core/indexing/Common.hpp"
#include <map>
#define RESTRICT WALBERLA_RESTRICT

namespace hhg {
namespace vertexdof {
namespace macroface {
namespace generated {

void gaussseidel_2D_macroface_vertexdof_to_vertexdof_backwards(double * RESTRICT _data_p1FaceDst, double * RESTRICT _data_p1FaceRhs, double const * RESTRICT const _data_p1FaceStencil, int32_t level);

} // namespace generated
} // namespace macroface
} // namespace vertexdof
} // namespace hhg