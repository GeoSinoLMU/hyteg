if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/vtk)
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/vtk")
endif()

if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/db)
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/db")
endif()

waLBerla_link_files_to_builddir( *.prm )
waLBerla_link_files_to_builddir( *.py )

if (HYTEG_BUILD_WITH_PETSC)
waLBerla_add_executable( NAME Benchmark_01_Cube
        FILES Benchmark_01_Cube.cpp Helpers.cpp
        DEPENDS hyteg sqlite)

waLBerla_add_executable( NAME Benchmark_02_Y-Pipe
        FILES Benchmark_02_Y-Pipe.cpp Helpers.cpp
        DEPENDS hyteg sqlite)
endif()
