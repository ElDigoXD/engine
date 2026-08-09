cmake_minimum_required(VERSION 3.30)

option(BUILD_TESTS "Build unit tests" ON)

project(engine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("3rdParty")
add_subdirectory("Engine")
add_subdirectory("Projects")




