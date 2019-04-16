#include "core/Environment.h"
#include "core/logging/Logging.h"
#include "core/math/Random.h"
#include "core/timing/Timer.h"

#include "tinyhhg_core/VTKWriter.hpp"
#include "tinyhhg_core/mesh/MeshInfo.hpp"
#include "tinyhhg_core/misc/ExactStencilWeights.hpp"
#include "tinyhhg_core/p1functionspace/P1ConstantOperator.hpp"
#include "tinyhhg_core/p1functionspace/P1Function.hpp"
#include "tinyhhg_core/petsc/PETScCGSolver.hpp"
#include "tinyhhg_core/petsc/PETScManager.hpp"
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"
#include "tinyhhg_core/primitivestorage/Visualization.hpp"
#include "tinyhhg_core/primitivestorage/loadbalancing/SimpleBalancer.hpp"
#include "tinyhhg_core/FunctionProperties.hpp"

#ifndef HHG_BUILD_WITH_PETSC
WALBERLA_ABORT( "This test only works with PETSc enabled. Please enable it via -DHHG_BUILD_WITH_PETSC=ON" )
#endif

using walberla::real_t;
using walberla::uint_c;
using walberla::uint_t;

namespace hhg {

    void CGSolveTest(const uint_t &level, const std::string &meshFileName, const real_t &errEps) {
        WALBERLA_LOG_INFO_ON_ROOT("##### Mesh file: " << meshFileName << " / level: " << level << " #####")

        PETScManager petscManager;

        MeshInfo meshInfo = MeshInfo::fromGmshFile(meshFileName);
        SetupPrimitiveStorage setupStorage(meshInfo, uint_c(walberla::mpi::MPIManager::instance()->numProcesses()));

        setupStorage.setMeshBoundaryFlagsOnBoundary(1, 0, true);

        hhg::loadbalancing::roundRobin(setupStorage);

        std::shared_ptr<PrimitiveStorage> storage = std::make_shared<PrimitiveStorage>(setupStorage);
        writeDomainPartitioningVTK(storage, "../../output", "P1PetscSolve_Domain");

        hhg::P1Function<real_t> x("x", storage, level, level + 1);
        hhg::P1Function<real_t> x_exact("x_exact", storage, level, level + 1);
        hhg::P1Function<real_t> b("x", storage, level, level + 1);
        hhg::P1Function<real_t> err("err", storage, level, level + 1);
        hhg::P1Function<real_t> residuum("err", storage, level, level + 1);

        hhg::P1ConstantLaplaceOperator A(storage, level, level + 1);

        std::function<real_t(const hhg::Point3D &)> exact = [](const hhg::Point3D &xx) {
            return sin(xx[0]) * sinh(xx[1]);
        };
        walberla::math::seedRandomGenerator(0);
        std::function<real_t(const Point3D &)> rand = [](const Point3D &) {
            return walberla::math::realRandom(0.0, 1.0);
        };

        x.interpolate(exact, level, hhg::DirichletBoundary);
        x.interpolate(rand, level, hhg::Inner);
        //b.interpolate( exact, level, hhg::DirichletBoundary );
        x_exact.interpolate(exact, level);

        uint_t localDoFs1 = hhg::numberOfLocalDoFs<P1FunctionTag>(*storage, level);
        uint_t globalDoFs1 = hhg::numberOfGlobalDoFs<P1FunctionTag>(*storage, level);

        WALBERLA_LOG_INFO("localDoFs1: " << localDoFs1 << " globalDoFs1: " << globalDoFs1);

        PETScCGSolver<hhg::P1ConstantLaplaceOperator> solver_1(storage, level);

        walberla::WcTimer timer;
        solver_1.solve(A, x, b, level);
        timer.end();
        WALBERLA_LOG_INFO_ON_ROOT(" time was: " << timer.last());

        A.apply(x, residuum, level, hhg::Inner);

        err.assign({1.0, -1.0}, {x, x_exact}, level);

        real_t discr_l2_err_1 = std::sqrt(err.dotGlobal(err, level) / (real_t) globalDoFs1);
        real_t residuum_l2_1 = std::sqrt(residuum.dotGlobal(residuum, level) / (real_t) globalDoFs1);

        WALBERLA_LOG_INFO_ON_ROOT("discrete L2 error 1 = " << discr_l2_err_1);
        WALBERLA_LOG_INFO_ON_ROOT("residuum 1 = " << residuum_l2_1);

//        VTKOutput vtkOutput("../../output", "P1PetscSolve", storage);
//        vtkOutput.add( x );
//        vtkOutput.add( x_exact );
//        vtkOutput.add( err );
//        vtkOutput.add( residuum );
//        vtkOutput.write( level );

        WALBERLA_CHECK_FLOAT_EQUAL_EPSILON(residuum_l2_1, 0.0, 1e-15);
        WALBERLA_CHECK_LESS(discr_l2_err_1, errEps);
    }

}

using namespace hhg;

int main(int argc, char *argv[]) {
    walberla::Environment walberlaEnv(argc, argv);
    walberla::MPIManager::instance()->useWorldComm();

    CGSolveTest(3, "../../data/meshes/quad_2el.msh", 2.5e-05);
    CGSolveTest(3, "../../data/meshes/quad_4el.msh", 1.4e-05);
    CGSolveTest(3, "../../data/meshes/3D/tet_1el.msh", 4.9e-07);
    CGSolveTest(3, "../../data/meshes/3D/pyramid_2el.msh", 4.9e-05);
    CGSolveTest(3, "../../data/meshes/3D/pyramid_4el.msh", 1.5e-05);
    CGSolveTest(3, "../../data/meshes/3D/regular_octahedron_8el.msh", 2.3e-04);

    return EXIT_SUCCESS;
}