#pragma once

#include "hyteg/composites/P2P1TaylorHoodFunction.hpp"
#include "hyteg/elementwiseoperators/DiagonalNonConstantOperator.hpp"
#include "hyteg/elementwiseoperators/P2ElementwiseOperator.hpp"

namespace hyteg {

class P2P1ElementwiseBlendingStokesBlockPreconditioner
: public Operator< P2P1TaylorHoodFunction< real_t >, P2P1TaylorHoodFunction< real_t > >
{
 public:
   typedef P2ElementwiseBlendingLaplaceOperator VelocityOperator_T;

   P2P1ElementwiseBlendingStokesBlockPreconditioner( const std::shared_ptr< PrimitiveStorage >& storage,
                                                     size_t                                     minLevel,
                                                     size_t                                     maxLevel )
   : Operator( storage, minLevel, maxLevel )
   , A( storage, minLevel, maxLevel )
   , P( storage,
        minLevel,
        maxLevel,
        storage->hasGlobalCells() ? std::make_shared< P1RowSumForm >( std::make_shared< P1Form_mass3D >() ) :
                                    std::make_shared< P1RowSumForm >( std::make_shared< P1Form_mass >() ) )
   , hasGlobalCells_( storage->hasGlobalCells() )
   {}

   P2ElementwiseBlendingLaplaceOperator A;
   P1BlendingLumpedDiagonalOperator     P;

   bool hasGlobalCells_;
};

} // namespace hyteg
