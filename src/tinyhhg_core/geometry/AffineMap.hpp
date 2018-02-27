#pragma once

#include "FaceMap.hpp"

namespace hhg {

class AffineMap : public FaceMap {
public:

  AffineMap(const std::array<Point3D, 3>& fromCoords, const std::array<Point3D, 3>& toCoords) {
    x1_ = fromCoords[0];
    x2_ = fromCoords[1];
    x3_ = fromCoords[2];

    xb1_ = toCoords[0];
    xb2_ = toCoords[1];
    xb3_ = toCoords[2];
  }

  AffineMap(walberla::mpi::RecvBuffer& recvBuffer) {
    recvBuffer >> x1_;
    recvBuffer >> x2_;
    recvBuffer >> x3_;
    recvBuffer >> xb1_;
    recvBuffer >> xb2_;
    recvBuffer >> xb3_;
  }

  void evalF(const Point3D& x, Point3D& Fx) {
    Fx[0] =  (xb1_[0]*((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1])) + (xb1_[0] - xb2_[0])*((x[0] - x1_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x[1] - x1_[1])) - (xb1_[0] - xb3_[0])*((x[0] - x1_[0])*(x1_[1] - x2_[1]) - (x1_[0] - x2_[0])*(x[1] - x1_[1])))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
    Fx[1] =  (xb1_[1]*((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1])) + (xb1_[1] - xb2_[1])*((x[0] - x1_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x[1] - x1_[1])) - (xb1_[1] - xb3_[1])*((x[0] - x1_[0])*(x1_[1] - x2_[1]) - (x1_[0] - x2_[0])*(x[1] - x1_[1])))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
  }

  void evalDF(const Point3D&, Matrix2r& DFx) {
    DFx(0,0) =  ((xb1_[0] - xb2_[0])*(x1_[1] - x3_[1]) - (xb1_[0] - xb3_[0])*(x1_[1] - x2_[1]))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
    DFx(0,1) =  ((x1_[0] - x2_[0])*(xb1_[0] - xb3_[0]) - (x1_[0] - x3_[0])*(xb1_[0] - xb2_[0]))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
    DFx(1,0) =  (-(x1_[1] - x2_[1])*(xb1_[1] - xb3_[1]) + (x1_[1] - x3_[1])*(xb1_[1] - xb2_[1]))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
    DFx(1,1) =  ((x1_[0] - x2_[0])*(xb1_[1] - xb3_[1]) - (x1_[0] - x3_[0])*(xb1_[1] - xb2_[1]))/((x1_[0] - x2_[0])*(x1_[1] - x3_[1]) - (x1_[0] - x3_[0])*(x1_[1] - x2_[1]));
  }

  void evalDFinv(const Point3D&, Matrix2r& DFxInv) {
    DFxInv(0,0) =  (x1_[0]*xb2_[1] - x1_[0]*xb3_[1] - x2_[0]*xb1_[1] + x2_[0]*xb3_[1] + x3_[0]*xb1_[1] - x3_[0]*xb2_[1])/(xb1_[0]*xb2_[1] - xb1_[0]*xb3_[1] - xb2_[0]*xb1_[1] + xb2_[0]*xb3_[1] + xb3_[0]*xb1_[1] - xb3_[0]*xb2_[1]);
    DFxInv(0,1) =  (-x1_[0]*xb2_[0] + x1_[0]*xb3_[0] + x2_[0]*xb1_[0] - x2_[0]*xb3_[0] - x3_[0]*xb1_[0] + x3_[0]*xb2_[0])/(xb1_[0]*xb2_[1] - xb1_[0]*xb3_[1] - xb2_[0]*xb1_[1] + xb2_[0]*xb3_[1] + xb3_[0]*xb1_[1] - xb3_[0]*xb2_[1]);
    DFxInv(1,0) =  (x1_[1]*xb2_[1] - x1_[1]*xb3_[1] - x2_[1]*xb1_[1] + x2_[1]*xb3_[1] + x3_[1]*xb1_[1] - x3_[1]*xb2_[1])/(xb1_[0]*xb2_[1] - xb1_[0]*xb3_[1] - xb2_[0]*xb1_[1] + xb2_[0]*xb3_[1] + xb3_[0]*xb1_[1] - xb3_[0]*xb2_[1]);
    DFxInv(1,1) =  (xb1_[0]*x2_[1] - xb1_[0]*x3_[1] - xb2_[0]*x1_[1] + xb2_[0]*x3_[1] + xb3_[0]*x1_[1] - xb3_[0]*x2_[1])/(xb1_[0]*xb2_[1] - xb1_[0]*xb3_[1] - xb2_[0]*xb1_[1] + xb2_[0]*xb3_[1] + xb3_[0]*xb1_[1] - xb3_[0]*xb2_[1]);
  }

  void serialize(walberla::mpi::SendBuffer& sendBuffer) {
    sendBuffer << Type::AFFINE;
    sendBuffer << x1_;
    sendBuffer << x2_;
    sendBuffer << x3_;
    sendBuffer << xb1_;
    sendBuffer << xb2_;
    sendBuffer << xb3_;
  }

private:
  Point3D x1_;
  Point3D x2_;
  Point3D x3_;
  Point3D xb1_;
  Point3D xb2_;
  Point3D xb3_;
};

}
