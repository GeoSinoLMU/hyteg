#pragma once

#include <memory>

#include "hyteg/functions/FunctionIterator.hpp"
#include "hyteg/solvers/Solver.hpp"

#include "PETScSparseMatrix.hpp"
#include "PETScVector.hpp"

#ifdef HYTEG_BUILD_WITH_PETSC

namespace hyteg {

template < class OperatorType >
class PETScBlockPreconditionedStokesSolver : public Solver< OperatorType >
{
 public:
   typedef typename OperatorType::srcType               FunctionType;
   typedef typename OperatorType::BlockPreconditioner_T BlockPreconditioner_T;

   /// \brief PETSc-based block preconditioned MinRes solver for the Stokes problem.
   ///
   /// \param velocityPreconditionerType choose from different velocity preconditioners:
   ///                                   - 0: PCGAMG
   ///                                   - 1: PCJACOBI
   ///                                   - 2: Schur complement
   ///                                   - 3: Hypre (BoomerAMG)
   ///                                   - 4: none
   /// \param pressurePreconditionerType choose from different pressure preconditioners:
   ///                                   - 0: none
   ///                                   - 1: PCJACOBI (lumped mass)
   PETScBlockPreconditionedStokesSolver( const std::shared_ptr< PrimitiveStorage >& storage,
                                         const uint_t&                              level,
                                         const real_t                               tolerance = 1e-12,
                                         const PetscInt maxIterations              = std::numeric_limits< PetscInt >::max(),
                                         const uint_t&  velocityPreconditionerType = 1,
                                         const uint_t&  pressurePreconditionerType = 1 )
   : allocatedLevel_( level )
   , petscCommunicator_( storage->getSplitCommunicatorByPrimitiveDistribution() )
   , num( "numerator", storage, level, level )
   , Amat( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ),
           numberOfGlobalDoFs< typename FunctionType::Tag >( *storage, level, petscCommunicator_ ),
           "Amat",
           petscCommunicator_ )
   , AmatNonEliminatedBC( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ),
                          numberOfGlobalDoFs< typename FunctionType::Tag >( *storage, level, petscCommunicator_ ),
                          "AmatNonEliminatedBC",
                          petscCommunicator_ )
   , Pmat( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ),
           numberOfGlobalDoFs< typename FunctionType::Tag >( *storage, level, petscCommunicator_ ),
           "Pmat",
           petscCommunicator_ )
   , xVec( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ), "xVec", petscCommunicator_ )
   , bVec( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ), "bVec", petscCommunicator_ )
   , nullspaceVec_( numberOfLocalDoFs< typename FunctionType::Tag >( *storage, level ), "nullspaceVec", petscCommunicator_ )
   , storage_( storage )
   , tolerance_( tolerance )
   , maxIterations_( maxIterations )
   , flag_( hyteg::All )
   , nullSpaceSet_( false )
   , blockPreconditioner_( storage, level, level )
   , velocityPreconditionerType_( velocityPreconditionerType )
   , pressurePreconditionerType_( pressurePreconditionerType )
   , verbose_( false )
   , reassembleMatrix_( true )
   , matrixWasAssembledOnce_( false )
   {}

   ~PETScBlockPreconditionedStokesSolver() = default;

   /// \brief If set to true, the operator is reassembled for every solve / manual assembly call.
   ///        Default is true.
   void reassembleMatrix( bool reassembleMatrix ) { reassembleMatrix_ = reassembleMatrix; }

   void setNullSpace( const FunctionType& nullspace )
   {
      nullSpaceSet_ = true;
      nullspaceVec_.createVectorFromFunction( nullspace, num, allocatedLevel_ );
      MatNullSpaceCreate( petscCommunicator_, PETSC_FALSE, 1, &nullspaceVec_.get(), &nullspace_ );
   }

   void setVerbose( bool verbose ) { verbose_ = verbose; }

   void solve( const OperatorType& A, const FunctionType& x, const FunctionType& b, const uint_t level )
   {
      WALBERLA_CHECK_EQUAL( level, allocatedLevel_ );

      walberla::WcTimer timer;

      x.getStorage()->getTimingTree()->start( "PETSc block prec MinRes Solver" );

      x.getStorage()->getTimingTree()->start( "Setup" );
      timer.start();

      num.copyBoundaryConditionFromFunction( x );
      num.enumerate( level );

      x.getStorage()->getTimingTree()->start( "Index set setup" );

      // gather index sets to split matrix into block matrix
      // therefore we need the row indices of the velocity and pressure
      std::vector< PetscInt > velocityIndices;
      std::vector< PetscInt > pressureIndices;

      gatherIndices( velocityIndices, pressureIndices, *storage_, level, num );

      std::sort( velocityIndices.begin(), velocityIndices.end() );
      std::sort( pressureIndices.begin(), pressureIndices.end() );
      ISCreateGeneral( petscCommunicator_, velocityIndices.size(), velocityIndices.data(), PETSC_COPY_VALUES, &is_[0] );
      ISCreateGeneral( petscCommunicator_, pressureIndices.size(), pressureIndices.data(), PETSC_COPY_VALUES, &is_[1] );

      x.getStorage()->getTimingTree()->stop( "Index set setup" );

      KSPCreate( petscCommunicator_, &ksp );
      KSPSetType( ksp, KSPMINRES );
      KSPSetTolerances( ksp, 1e-30, tolerance_, PETSC_DEFAULT, maxIterations_ );
      KSPSetInitialGuessNonzero( ksp, PETSC_TRUE );
      KSPSetFromOptions( ksp );

      x.getStorage()->getTimingTree()->start( "Vector copy" );
      xVec.createVectorFromFunction( x, num, level );
      bVec.createVectorFromFunction( b, num, level, All );
      x.getStorage()->getTimingTree()->stop( "Vector copy" );

      if ( reassembleMatrix_ || !matrixWasAssembledOnce_ )
      {
         x.getStorage()->getTimingTree()->start( "Matrix assembly" );
         Amat.zeroEntries();
         Pmat.zeroEntries();
         AmatNonEliminatedBC.zeroEntries();
         Amat.createMatrixFromOperator( A, level, num, All );
         AmatNonEliminatedBC.createMatrixFromOperator( A, level, num, All );
         Pmat.createMatrixFromOperator( blockPreconditioner_, level, num, All );
         x.getStorage()->getTimingTree()->stop( "Matrix assembly" );

         x.getStorage()->getTimingTree()->start( "Dirichlet BCs" );
         Amat.applyDirichletBCSymmetrically( x, num, bVec, level );
         Pmat.applyDirichletBCSymmetrically( num, level );
         x.getStorage()->getTimingTree()->stop( "Dirichlet BCs" );

         matrixWasAssembledOnce_ = true;
      }
      else
      {
         MatCopy( AmatNonEliminatedBC.get(), Amat.get(), SAME_NONZERO_PATTERN );
         x.getStorage()->getTimingTree()->start( "Dirichlet BCs" );
         Amat.applyDirichletBCSymmetrically( x, num, bVec, level );
         x.getStorage()->getTimingTree()->stop( "Dirichlet BCs" );
      }

      if ( nullSpaceSet_ )
      {
         MatSetNullSpace( Amat.get(), nullspace_ );
      }
      KSPSetOperators( ksp, Amat.get(), Pmat.get() );

      if ( velocityPreconditionerType_ == 2 )
      {
         KSPGetPC( ksp, &pc );
         PCSetType( pc, PCFIELDSPLIT );
         PCFieldSplitSetType( pc, PC_COMPOSITE_SCHUR );
         PCFieldSplitSetSchurPre( pc, PC_FIELDSPLIT_SCHUR_PRE_SELFP, NULL );
         PCFieldSplitSetIS( pc, "u", is_[0] );
         PCFieldSplitSetIS( pc, "p", is_[1] );

         PetscInt numSubKsps;

         PCSetUp( pc );
         PCFieldSplitSchurGetSubKSP( pc, &numSubKsps, &sub_ksps_ );

         KSPSetType( sub_ksps_[0], KSPCG );
         KSPSetType( sub_ksps_[1], KSPCG );

         KSPSetTolerances( sub_ksps_[0], 1e-15, 1e-15, PETSC_DEFAULT, maxIterations_ );
         KSPSetTolerances( sub_ksps_[1], 1e-15, 1e-15, PETSC_DEFAULT, maxIterations_ );
      }
      else
      {
         KSPGetPC( ksp, &pc );
         PCSetType( pc, PCFIELDSPLIT );
         PCFieldSplitSetType( pc, PC_COMPOSITE_ADDITIVE );
         PCFieldSplitSetIS( pc, "u", is_[0] );
         PCFieldSplitSetIS( pc, "p", is_[1] );

         PetscInt numSubKsps;
         PC       pc_u, pc_p;
         PCFieldSplitGetSubKSP( pc, &numSubKsps, &sub_ksps_ );

         KSPGetPC( sub_ksps_[0], &pc_u );
         KSPGetPC( sub_ksps_[1], &pc_p );

         switch ( velocityPreconditionerType_ )
         {
         case 0:
            PCSetType( pc_u, PCGAMG );
            PCGAMGSetType( pc_u, PCGAMGAGG );
            PCGAMGSetNSmooths( pc_u, 1 );
            break;
         case 1:
            PCSetType( pc_u, PCJACOBI );
            break;
         case 3:
         {
            PCSetType( pc_u, PCHYPRE );
            break;
         }
         case 4:
            PCSetType( pc_u, PCNONE );
            break;
         default:
            WALBERLA_ABORT( "Invalid velocity preconditioner for PETSc block prec MinRes solver." );
            break;
         }

         switch ( pressurePreconditionerType_ )
         {
         case 0:
            PCSetType( pc_p, PCNONE );
            break;
         case 1:
            // inv. lumped mass
            PCSetType( pc_p, PCJACOBI );
            break;
         default:
            WALBERLA_ABORT( "Invalid pressure preconditioner for PETSc block prec MinRes solver." );
            break;

         }

      }

      timer.end();
      const double hytegToPetscSetup = timer.last();
      x.getStorage()->getTimingTree()->stop( "Setup" );

      x.getStorage()->getTimingTree()->start( "Solve" );

      timer.start();
      KSPSolve( ksp, bVec.get(), xVec.get() );
      timer.end();
      const double petscKSPTimer = timer.last();

      x.getStorage()->getTimingTree()->stop( "Solve" );

      if ( verbose_ )
      {
         PetscInt numKSPIterations;
         KSPGetIterationNumber( ksp, &numKSPIterations );
         WALBERLA_LOG_INFO_ON_ROOT( "[PETScBlockPreconditionedStokesSolver] num KSP iterations: "
                                    << numKSPIterations << " | "
                                    << "PETSc KSPSolver time: " << petscKSPTimer << " | "
                                    << "HyTeG to PETSc setup: " << hytegToPetscSetup );
      }

      xVec.createFunctionFromVector( x, num, level, flag_ );

      x.getStorage()->getTimingTree()->stop( "PETSc block prec MinRes Solver" );

      PetscFree( sub_ksps_ );

      ISDestroy( &is_[0] );
      ISDestroy( &is_[1] );
      KSPDestroy( &ksp );
      if ( nullSpaceSet_ )
         MatNullSpaceDestroy( &nullspace_ );
   }

 private:
   void gatherIndices( std::vector< PetscInt >&            velocityIndices,
                       std::vector< PetscInt >&            pressureIndices,
                       const PrimitiveStorage&             storage,
                       uint_t                              level,
                       const P1StokesFunction< PetscInt >& numerator )
   {
      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.u, level ) )
      {
         velocityIndices.push_back( dof.value() );
      }

      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.v, level ) )
      {
         velocityIndices.push_back( dof.value() );
      }

      if ( storage.hasGlobalCells() )
      {
         for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.w, level ) )
         {
            velocityIndices.push_back( dof.value() );
         }
      }
      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.p, level ) )
      {
         pressureIndices.push_back( dof.value() );
      }
   }

   void gatherIndices( std::vector< PetscInt >&                  velocityIndices,
                       std::vector< PetscInt >&                  pressureIndices,
                       const PrimitiveStorage&                   storage,
                       uint_t                                    level,
                       const P2P1TaylorHoodFunction< PetscInt >& numerator )
   {
      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.u.getVertexDoFFunction(), level ) )
      {
         velocityIndices.push_back( dof.value() );
      }
      for ( auto dof : FunctionIterator< EdgeDoFFunction< PetscInt > >( numerator.uvw.u.getEdgeDoFFunction(), level ) )
      {
         velocityIndices.push_back( dof.value() );
      }
      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.v.getVertexDoFFunction(), level ) )
      {
         velocityIndices.push_back( dof.value() );
      }
      for ( auto dof : FunctionIterator< EdgeDoFFunction< PetscInt > >( numerator.uvw.v.getEdgeDoFFunction(), level ) )
      {
         velocityIndices.push_back( dof.value() );
      }
      if ( storage.hasGlobalCells() )
      {
         for ( auto dof :
               FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.uvw.w.getVertexDoFFunction(), level ) )
         {
            velocityIndices.push_back( dof.value() );
         }
         for ( auto dof : FunctionIterator< EdgeDoFFunction< PetscInt > >( numerator.uvw.w.getEdgeDoFFunction(), level ) )
         {
            velocityIndices.push_back( dof.value() );
         }
      }
      for ( auto dof : FunctionIterator< vertexdof::VertexDoFFunction< PetscInt > >( numerator.p, level ) )
      {
         pressureIndices.push_back( dof.value() );
      }
   }

   uint_t                                                                                            allocatedLevel_;
   MPI_Comm                                                                                          petscCommunicator_;
   typename OperatorType::srcType::template FunctionType< PetscInt >                                 num;
   PETScSparseMatrix< OperatorType, OperatorType::srcType::template FunctionType >                   Amat;
   PETScSparseMatrix< OperatorType, OperatorType::srcType::template FunctionType >                   AmatNonEliminatedBC;
   PETScSparseMatrix< BlockPreconditioner_T, BlockPreconditioner_T::srcType::template FunctionType > Pmat;
   PETScVector< typename FunctionType::valueType, OperatorType::srcType::template FunctionType >     xVec;
   PETScVector< typename FunctionType::valueType, OperatorType::srcType::template FunctionType >     bVec;
   PETScVector< typename FunctionType::valueType, OperatorType::srcType::template FunctionType >     nullspaceVec_;

   std::shared_ptr< PrimitiveStorage > storage_;

   real_t   tolerance_;
   PetscInt maxIterations_;

   BlockPreconditioner_T blockPreconditioner_;

   KSP          ksp;
   KSP*         sub_ksps_;
   PC           pc;
   IS           is_[2];
   MatNullSpace nullspace_;
   DoFType      flag_;
   bool         nullSpaceSet_;

   uint_t velocityPreconditionerType_;
   uint_t pressurePreconditionerType_;
   bool   verbose_;
   bool   reassembleMatrix_;
   bool   matrixWasAssembledOnce_;
};

} // namespace hyteg

#endif
