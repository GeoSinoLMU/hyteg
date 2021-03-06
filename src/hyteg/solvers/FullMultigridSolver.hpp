/*
 * Copyright (c) 2017-2019 Dominik Thoennes, Nils Kohl.
 *
 * This file is part of HyTeG
 * (see https://i10git.cs.fau.de/hyteg/hyteg).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "hyteg/solvers/GeometricMultigridSolver.hpp"
#include "hyteg/solvers/Solver.hpp"

namespace hyteg {

template < class OperatorType >
class FullMultigridSolver : public Solver< OperatorType >
{
 public:
   typedef typename OperatorType::srcType FunctionType;

   FullMultigridSolver( const std::shared_ptr< PrimitiveStorage >&                         storage,
                        const std::shared_ptr< GeometricMultigridSolver< OperatorType > >& gmgSolver,
                        const std::shared_ptr< ProlongationOperator< FunctionType > >&     fmgProlongation,
                        const uint_t&                                                      minLevel,
                        const uint_t&                                                      maxLevel,
                        const uint_t&                                                      cyclesPerLevel = 1,
                        const std::function< void( uint_t currentLevel ) >&                postCycleCallback = []( uint_t ){} )
   : gmgSolver_( gmgSolver )
   , fmgProlongation_( fmgProlongation )
   , minLevel_( minLevel )
   , maxLevel_( maxLevel )
   , cyclesPerLevel_( cyclesPerLevel )
   , flag_( Inner | NeumannBoundary )
   , postCycleCallback_( postCycleCallback )
   , timingTree_( storage->getTimingTree() )
   {}

   void solve( const OperatorType& A, const FunctionType& x, const FunctionType& b, const uint_t level ) override
   {
      timingTree_->start( "FMG Solver" );
      for ( uint_t currentLevel = minLevel_; currentLevel <= level; currentLevel++ )
      {
         timingTree_->start( "GMG Solver" );
         for ( uint_t cycle = 0; cycle < cyclesPerLevel_; cycle++ )
         {
            gmgSolver_->solve( A, x, b, currentLevel );
         }
         timingTree_->stop( "GMG Solver" );

         timingTree_->start( "Post-cycle callback" );
         postCycleCallback_( currentLevel );
         timingTree_->stop( "Post-cycle callback" );

         timingTree_->start( "FMG Prolongation" );
         if ( currentLevel < maxLevel_ )
         {
            fmgProlongation_->prolongate( x, currentLevel, flag_ );
         }
         timingTree_->stop( "FMG Prolongation" );
      }
      timingTree_->stop( "FMG Solver" );
   }

 private:
   std::shared_ptr< GeometricMultigridSolver< OperatorType > > gmgSolver_;
   std::shared_ptr< ProlongationOperator< FunctionType > >     fmgProlongation_;

   uint_t minLevel_;
   uint_t maxLevel_;

   uint_t cyclesPerLevel_;

   DoFType      flag_;

   std::function< void( uint_t currentLevel ) > postCycleCallback_;

   std::shared_ptr< walberla::WcTimingTree > timingTree_;
};

} // namespace hyteg