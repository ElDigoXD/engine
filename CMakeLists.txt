cmake_minimum_required(VERSION 3.30)


project(engine)

set(CMAKE_CXX_STANDARD 23)


add_subdirectory("3rdParty/bgfx.cmake" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/box2d" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/Catch2" EXCLUDE_FROM_ALL)
set(SKIP_PERFORMANCE_COMPARISON 1) # to not depend from boost
add_subdirectory("3rdParty/cereal" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/enkiTS" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/glfw" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/glm" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/imgui" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/joltphysics/Build" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/miniaudio" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/simpleini" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/tinygltf" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/tinyobjloader" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/tracy" EXCLUDE_FROM_ALL)
add_subdirectory("3rdParty/zstd/build/cmake" EXCLUDE_FROM_ALL)




add_executable(test Projects/test_main.cpp)

target_link_libraries(test PRIVATE
        glfw
        glm::glm
)

