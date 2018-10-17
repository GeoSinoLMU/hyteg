
#pragma once

#include "core/DataTypes.h"

#include <algorithm>
#include <set>

namespace hhg {
namespace algorithms {

using walberla::uint_t;

/// Returns an array concatenates all missing natural numbers of [0, OutputArraySize) in the input array to the input array in ascending order.
/// Example: input array: [2, 1], input size: 4 => output array [2, 1, 0, 3]
template< uint_t InputArraySize, uint_t OutputArraySize >
inline std::array< uint_t, OutputArraySize > getMissingIntegersAscending( const std::array< uint_t, InputArraySize > & inputArray )
{
  static_assert( InputArraySize <= OutputArraySize, "Input array must be a subset of output array!" );
  WALBERLA_ASSERT( *std::max_element( inputArray.begin(), inputArray.end() ) < OutputArraySize );
  WALBERLA_ASSERT_EQUAL( std::set< uint_t >( inputArray.begin(), inputArray.end() ).size(), InputArraySize );

  std::array< uint_t, OutputArraySize > outputArray;
  std::copy( inputArray.begin(), inputArray.end(), outputArray.begin() );

  uint_t pos = 0;
  for ( uint_t i = 0; i < OutputArraySize; i++ )
  {
    if ( std::find( inputArray.begin(), inputArray.end(), i ) == inputArray.end() )
    {
      outputArray[pos+InputArraySize] = i;
      pos++;
    }
  }
  return outputArray;
}

}
}