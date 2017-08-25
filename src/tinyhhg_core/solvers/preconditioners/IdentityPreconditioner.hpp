#pragma once

namespace hhg {

template<class F>
class IdentityPreconditioner {
 public:

  void apply(F &x, F &y, uint_t level, DoFType flag) {
    y.assign({1.0}, {&x}, level, flag);
  }
};

}