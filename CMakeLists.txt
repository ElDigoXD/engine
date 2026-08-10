cmake_minimum_required(VERSION 3.30)

option(BUILD_TESTS "Build unit tests" ON)

project(engine)

set(CMAKE_CXX_COMPILE_FEATURES
        cxx_std_98 cxx_std_11 cxx_std_14 cxx_std_17 cxx_std_20 cxx_std_23
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("3rdParty")
add_subdirectory("Engine")
add_subdirectory("Projects")




