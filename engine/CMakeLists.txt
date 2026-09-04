
add_subdirectory("math")
add_subdirectory("core")
add_subdirectory("modules")

add_library(Engine INTERFACE)

target_link_libraries(Engine INTERFACE
    Engine::Core
    Engine::Math
)
