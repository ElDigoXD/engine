
# add_subdirectory("Math")
add_subdirectory("Core")

add_library(Engine INTERFACE)

target_link_libraries(Engine INTERFACE
    Engine::Core
)


