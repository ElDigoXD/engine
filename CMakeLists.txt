cmake_minimum_required(VERSION 4.3)

include(${CMAKE_SOURCE_DIR}/cmake/CopyDlls.cmake)

option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_SHARED "Construir como DLL" ON)

if(BUILD_SHARED)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

project(engine)

set(CMAKE_CXX_STANDARD 20)

if(BUILD_TESTS)
    enable_testing()
endif()

add_subdirectory("3rdParty")
add_subdirectory("Engine")
add_subdirectory("Projects")







