cmake_minimum_required(VERSION 4.3)

include(${CMAKE_SOURCE_DIR}/cmake/CopyDlls.cmake)

option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_SHARED "Construir como DLL" ON)

if (BUILD_SHARED)
  set(LIB_TYPE SHARED)
else ()
  set(LIB_TYPE STATIC)
endif ()

project(engine)

set(CMAKE_CXX_COMPILE_FEATURES
    cxx_std_98 cxx_std_11 cxx_std_14 cxx_std_17 cxx_std_20 cxx_std_23
)

set(CMAKE_CXX_STANDARD 20)

if (BUILD_TESTS)
  enable_testing()
endif ()

add_subdirectory("3rdParty")
add_subdirectory("framework")
add_subdirectory("engine")
add_subdirectory("projects")







