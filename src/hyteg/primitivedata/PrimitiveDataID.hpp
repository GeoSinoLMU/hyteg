
#pragma once

#include "core/DataTypes.h"
#include "core/mpi/SendBuffer.h"
#include "core/mpi/RecvBuffer.h"


namespace hyteg {

using walberla::mpi::SendBuffer;
using walberla::mpi::RecvBuffer;
using walberla::uint_t;

/// \brief Identifier for data attached to \ref Primitive instances
/// \author Nils Kohl (nils.kohl@fau.de)
///
/// Identifies a data item attached to a \ref Primitive.
/// The data can be obtained by passing the respective \ref PrimitiveDataID to
/// the corresponding getter methods.
///
/// Since this class is templated with the data type of the passed data,
/// retrieving the data from primitives is more type-safe and checked via static casts
/// during compile-time.
///
/// \ref PrimitiveDataIDs are generated when data is added to primitives via a storage instance
/// like \ref PrimitiveStorage.
template< typename DataType, typename PrimitiveType >
class PrimitiveDataID
{
public:

  friend class PrimitiveStorage;

  PrimitiveDataID()                            : id_( std::numeric_limits< uint_t >::max() ) {}
  explicit PrimitiveDataID( const walberla::uint_t id ) : id_( id ) {}

  /// Copy-constructor
  PrimitiveDataID( const PrimitiveDataID& id ) : id_( id.id_ ) {}

  void pack( SendBuffer & buffer ) const { buffer << id_; }
  void unpack( RecvBuffer & buffer )     { buffer >> id_; }

  /// Copy-assignment
  PrimitiveDataID& operator=( const PrimitiveDataID& id ) { id_ = id.id_; return *this; }

  bool operator==( const PrimitiveDataID& id ) const { return id_ == id.id_; }
  bool operator!=( const PrimitiveDataID& id ) const { return id_ != id.id_; }
  bool operator< ( const PrimitiveDataID& id ) const { return id_ <  id.id_; }

  /// Cast-operator
  operator uint_t() const { return id_; }

private:

  uint_t id_;

}; // class DataID

}
