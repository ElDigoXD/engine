cmake_minimum_required(VERSION 3.25)

project(Math
    VERSION 1.0.0
    LANGUAGES CXX
)

set(MATH_SOURCES
    private/Vector2.cpp
)

set(MATH_HEADERS
    public/Math/Vector2.h
    public/Math/Vector2.inl
    public/Math/Vector3.h
    public/Math/Vector3.inl
    public/Math/Vector4.h
    public/Math/Vector4.inl
)

add_library(Math ${LIB_TYPE}
    ${MATH_SOURCES}
    ${MATH_HEADERS}
 "public/Math/Vector4.inl")

# Alias para uso interno/externo
add_library(Engine::Math ALIAS Math)

target_include_directories(Math
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/public
)

target_compile_features(Math
    PUBLIC
        cxx_std_20
)

target_compile_options(Math
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
target_compile_definitions(Math
    PRIVATE
        MATH_EXPORTS
)

if(BUILD_TESTS)
    add_subdirectory(UnitTests)
endif()


