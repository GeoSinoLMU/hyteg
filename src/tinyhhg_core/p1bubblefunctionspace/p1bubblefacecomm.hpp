#pragma once

#include "tinyhhg_core/p1bubblefunctionspace/p1bubblememory.hpp"
#include "p1bubblefaceindex.hpp"
#include "core/mpi/RecvBuffer.h"

namespace hhg {
namespace P1BubbleFace {

using walberla::real_t;
using walberla::uint_t;
using walberla::uint_c;

template<size_t Level>
inline void packData_tmpl(Face &face, uint_t memory_id, walberla::mpi::SendBuffer &sendBuffer, const Edge &edge){
  auto& face_data = P1Bubble::getFaceFunctionMemory(face, memory_id)->data[Level];
  uint_t edgeIndex = face.edge_index(edge);
  for(auto it = indexIterator(edgeIndex, face.edge_orientation[edgeIndex], VERTEX_INNER, Level); it != indexIterator(); ++it){
    sendBuffer << face_data[*it];
  }
}
SPECIALIZE(void, packData_tmpl, packData)

/*!
 * Unpacks data from \ref edge into the \ref face from \ref recvBuffer.
 * Only unpacks data owned by edge but not halo data
 * @param face Face to unpack to
 * @param recvBuffer Buffer to unpack from
 * @param memory_id Memory id of the data
 * @param level Multigrid level
 * @param edge corresponding Edge
 */
template<size_t Level>
inline void unpackEdgeData_tmpl(Face &face, uint_t memory_id, walberla::mpi::RecvBuffer &recvBuffer, const Edge &edge){
  auto& face_data = P1Bubble::getFaceFunctionMemory(face, memory_id)->data[Level];
  uint_t edgeIndex = face.edge_index(edge);
  for(auto it = indexIterator(edgeIndex, face.edge_orientation[edgeIndex], VERTEX, Level); it != indexIterator(); ++it){
    recvBuffer >> face_data[*it];
  }
  auto it = indexIterator(edgeIndex, face.edge_orientation[edgeIndex], CELL_GRAY, Level);
  real_t tmp;
  recvBuffer >> tmp;
  face_data[*it] = tmp;
  uint_t lastGray = 0;
  while(it != indexIterator()){
    lastGray = *it;
    ++it;
  }
  recvBuffer >> face_data[lastGray];
}
SPECIALIZE(void, unpackEdgeData_tmpl, unpackEdgeData)


}// namespace P1BubbleFace
}// namespace hhg