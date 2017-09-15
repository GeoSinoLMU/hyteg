#pragma once

#include "tinyhhg_core/levelinfo.hpp"
#include "tinyhhg_core/macros.hpp"
#include "BubbleToP1Memory.hpp"
#include "tinyhhg_core/bubblefunctionspace/BubbleFaceIndex.hpp"

#include "tinyhhg_core/p1functionspace/P1FaceIndex.hpp"

namespace hhg {
namespace BubbleToP1Face {
template<size_t Level>
inline void apply_tmpl(Face &face, const PrimitiveDataID<FaceBubbleToP1StencilMemory, Face> &operatorId,
                       const PrimitiveDataID<FaceBubbleFunctionMemory< real_t >, Face> &srcId,
                       const PrimitiveDataID<FaceP1FunctionMemory< real_t >, Face> &dstId, UpdateType update) {
  size_t rowsize = levelinfo::num_microvertices_per_edge(Level);
  size_t inner_rowsize = rowsize;

  auto& opr_data = face.getData(operatorId)->data[Level];
  auto src = face.getData(srcId)->getPointer( Level );
  auto dst = face.getData(dstId)->getPointer( Level );

  real_t tmp;

  for (size_t i = 1; i < rowsize - 2; ++i) {
    for (size_t j = 1; j < inner_rowsize - 2; ++j) {
      tmp = 0.0;

      for (auto neighbor : BubbleFace::FaceCoordsVertex::neighbors) {
        tmp += opr_data[neighbor]*src[BubbleFace::FaceCoordsVertex::index<Level>(i, j, neighbor)];
      }

      if (update==Replace) {
        dst[P1Face::FaceCoordsVertex::index<Level>(i, j, P1Face::FaceCoordsVertex::VERTEX_C)] = tmp;
      } else if (update==Add) {
        dst[P1Face::FaceCoordsVertex::index<Level>(i, j, P1Face::FaceCoordsVertex::VERTEX_C)] += tmp;
      }
    }
    --inner_rowsize;
  }
}

SPECIALIZE(void, apply_tmpl, apply)

template<size_t Level>
inline void saveOperator_tmpl(Face &face, const PrimitiveDataID<FaceBubbleToP1StencilMemory, Face> &operatorId,
                              const PrimitiveDataID<FaceBubbleFunctionMemory< real_t >, Face> &srcId,
                              const PrimitiveDataID<FaceP1FunctionMemory< real_t >, Face> &dstId, std::ostream& out) {
  size_t rowsize = levelinfo::num_microvertices_per_edge(Level);
  size_t inner_rowsize = rowsize;

  auto& opr_data = face.getData(operatorId)->data[Level];
  auto src = face.getData(srcId)->getPointer( Level );
  auto dst = face.getData(dstId)->getPointer( Level );

  for (size_t i = 1; i < rowsize - 2; ++i) {
    for (size_t j = 1; j < inner_rowsize - 2; ++j) {

      uint_t dst_id = dst[P1Face::FaceCoordsVertex::index<Level>(i, j, P1Face::FaceCoordsVertex::VERTEX_C)];

      for (auto neighbor : BubbleFace::FaceCoordsVertex::neighbors) {
        out << fmt::format("{}\t{}\t{}\n", dst_id, src[BubbleFace::FaceCoordsVertex::index<Level>(i, j, neighbor)], opr_data[neighbor]);
      }
    }
    --inner_rowsize;
  }
}

SPECIALIZE(void, saveOperator_tmpl, saveOperator)
}
}
