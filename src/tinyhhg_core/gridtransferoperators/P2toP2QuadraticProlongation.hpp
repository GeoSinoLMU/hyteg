
#pragma once

#include "tinyhhg_core/p2functionspace/P2Function.hpp"
#include "tinyhhg_core/gridtransferoperators/ProlongationOperator.hpp"

namespace hhg {

class P2toP2QuadraticProlongation : public ProlongationOperator< P2Function< real_t > >
{
public:

    inline void prolongate( const P2Function <real_t> & function, const uint_t & sourceLevel, const DoFType & flag ) const override
    {
      prolongateAdditively( function, sourceLevel, flag );
    }

private:

    void prolongateAdditively( const P2Function <real_t> & function, const uint_t & sourceLevel, const DoFType & flag ) const;
    void prolongateStandard( const P2Function <real_t> & function, const uint_t & sourceLevel, const DoFType & flag ) const;
};

}
