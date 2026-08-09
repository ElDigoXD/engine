cmake_minimum_required(VERSION 3.25)

project(Core
    VERSION 1.0.0
    LANGUAGES CXX
)

# Archivos de la librería
set(CORE_SOURCES
    private/InputManager.cpp
)

set(CORE_HEADERS
    public/Core/InputManager.h
)

# Crear librería estática
add_library(Core ${LIB_TYPE}
    ${CORE_SOURCES}
    ${CORE_HEADERS}
)

# Alias para uso interno/externo
add_library( Engine::Core ALIAS Core)

# Includes públicos
target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/public
)

target_compile_features(Core
    PUBLIC
        cxx_std_20
)
# Opciones de compilación
target_compile_options(Core
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
target_compile_definitions(Core
    PRIVATE
        CORE_EXPORTS
)

# Dependencias (ejemplo)
target_link_libraries(Core PUBLIC 
    3rdParty::glfw
    3rdParty::Catch2
    3rdParty::glm
)
