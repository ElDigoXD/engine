cmake_minimum_required(VERSION 3.25)

project(Framework
    VERSION 1.0.0
    LANGUAGES CXX
)

set(FRAMEWORK_SOURCES
    private/PlatformDefines.cpp
)

set(FRAMEWORK_HEADERS
    public/Framework/PlatformDefines.h
)

add_library(Framework ${LIB_TYPE}
    ${FRAMEWORK_SOURCES}
    ${FRAMEWORK_HEADERS}
)

target_include_directories(Framework
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public
)

target_compile_features(Framework
    PUBLIC
    cxx_std_20
)

target_compile_options(Framework
    PRIVATE
    $<$<CONFIG:Debug>:
    $<$<CXX_COMPILER_ID:Clang>:-Wno-unused-parameter>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    >
    $<$<CONFIG:Release>:
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    >
)

# Definiciones
target_compile_definitions(Framework
    PRIVATE
    FRAMEWORK_EXPORTS
)

# add_subdirectory(UnitTests)



