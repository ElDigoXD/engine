
cmake_minimum_required(VERSION 3.25)

project(Render
        VERSION 1.0.0
        LANGUAGES CXX
)

set(RENDER_SOURCES
        private/RenderModule.cpp
)

set(RENDER_HEADERS
        public/Render/RenderLibType.h
        public/Render/RenderModule.h
)

# Crear librería estática
add_library(Render ${LIB_TYPE}
        ${RENDER_SOURCES}
        ${RENDER_HEADERS}
)

# Alias para uso interno/externo
add_library(Module::Render ALIAS Render)

# Includes públicos
target_include_directories(Render
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/public
)

target_compile_features(Render
        PUBLIC
        cxx_std_20
)
# Opciones de compilación
target_compile_options(Render
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
target_compile_definitions(Render
        PRIVATE
        RENDER_EXPORTS
)

# Dependencias (ejemplo)
target_link_libraries(Render PUBLIC
        Engine::Core
)
