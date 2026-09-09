cmake_minimum_required(VERSION 3.25)

project(ECS
    VERSION 1.0.0
    LANGUAGES CXX
)

set(ECS_SOURCES
    private/Query.cpp
    private/Stage.cpp
)

set(ECS_PUBLIC_HEADERS
    public/ECS/World.h
    public/ECS/World.inl
    public/ECS/WorldView.h
    public/ECS/WorldView.inl
    public/ECS/System.h
    public/ECS/Query.h
)

set(ECS_PRIVATE_HEADERS
    private/Stage.h
    public/ECS/Filter.h
    public/ECS/TypeList.h
)

add_library(ECS ${LIB_TYPE}
    ${ECS_SOURCES}
    ${ECS_PUBLIC_HEADERS}
    ${ECS_PRIVATE_HEADERS}
)

# Alias para uso interno/externo
add_library(Engine::ECS ALIAS ECS)

target_include_directories(ECS
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/public
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/PRIVATE
)

target_compile_features(ECS
    PUBLIC
    cxx_std_20
)

target_compile_options(ECS
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

target_link_libraries(ECS PUBLIC
    Engine::Core
)

# Definiciones
target_compile_definitions(ECS
    PRIVATE
    ECS_EXPORTS
)

if (BUILD_TESTS)
  add_subdirectory(UnitTests)
endif ()


