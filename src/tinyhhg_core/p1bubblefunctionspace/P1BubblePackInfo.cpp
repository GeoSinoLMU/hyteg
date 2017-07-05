#include "P1BubblePackInfo.hpp"

namespace hhg {
namespace communication {

void P1BubblePackInfo::packVertexForEdge(const Vertex *sender, const PrimitiveID &/*receiver*/,
                                         walberla::mpi::SendBuffer &buffer) {
  auto &edge_data = sender->getData(dataIDVertex_)->data[level_];
  uint_t rowsize = levelinfo::num_microvertices_per_edge(level_);
  //TODO change to index function
  for (uint_t i = 0; i < rowsize; ++i) {
    buffer << edge_data[i];
  }
}



} //namespace communication
} //namespace hhg