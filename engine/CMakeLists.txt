
add_subdirectory("math")
add_subdirectory("core")
add_subdirectory("ecs")
add_subdirectory("modules")

add_library(Engine INTERFACE
        ecs/public/ECS/System.h
        ecs/public/ECS/WorldView.h
        ecs/UnitTests/WorldTest.cpp)

target_link_libraries(Engine INTERFACE
    Engine::Core
    Engine::Math
    Engine::ECS
)
