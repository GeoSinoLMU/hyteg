#pragma once

#include "tinyhhg_core/Function.hpp"
#include "tinyhhg_core/types/pointnd.hpp"

#include "tinyhhg_core/bubblefunctionspace/BubbleMemory.hpp"

namespace hhg {


class BubbleFunction : public Function< BubbleFunction > {
 public:
  BubbleFunction(const std::string &name,
                 const std::shared_ptr<PrimitiveStorage> &storage,
                 uint_t minLevel,
                 uint_t maxLevel);

  ~BubbleFunction();

  const PrimitiveDataID<VertexBubbleFunctionMemory< real_t >, Vertex> &getVertexDataID() const { return vertexDataID_; }

  const PrimitiveDataID<EdgeBubbleFunctionMemory< real_t >, Edge> &getEdgeDataID() const { return edgeDataID_; }

  const PrimitiveDataID<FaceBubbleFunctionMemory< real_t >, Face> &getFaceDataID() const { return faceDataID_; }

 private:

  /// Interpolates a given expression to a P1Function
  void interpolate_impl(std::function<real_t(const Point3D &)> &expr, uint_t level, DoFType flag = All);

  void assign_impl(const std::vector<walberla::real_t> scalars,
              const std::vector<BubbleFunction *> functions,
              size_t level,
              DoFType flag = All);

  void add_impl(const std::vector<walberla::real_t> scalars,
           const std::vector<BubbleFunction *> functions,
           size_t level,
           DoFType flag = All);

  real_t dot_impl(BubbleFunction &rhs, size_t level, DoFType flag = All);

  void prolongate_impl(size_t level, DoFType flag = All) {
    WALBERLA_UNUSED( level );
    WALBERLA_UNUSED( flag );
    WALBERLA_ABORT("Bubble prolongate not implemented");
  }

  void prolongateQuadratic_impl(size_t level, DoFType flag = All) {
    WALBERLA_UNUSED( level );
    WALBERLA_UNUSED( flag );
    WALBERLA_ABORT("Bubble prolongate quadratic not implemented");
  }

  void restrict_impl(size_t level, DoFType flag = All) {
    WALBERLA_UNUSED( level );
    WALBERLA_UNUSED( flag );
    WALBERLA_ABORT("Bubble restrict not implemented");
  }

  void enumerate_impl(size_t level, uint_t& num);

  PrimitiveDataID<VertexBubbleFunctionMemory< real_t >, Vertex> vertexDataID_;
  PrimitiveDataID<EdgeBubbleFunctionMemory< real_t >, Edge> edgeDataID_;
  PrimitiveDataID<FaceBubbleFunctionMemory< real_t >, Face> faceDataID_;
};
}
