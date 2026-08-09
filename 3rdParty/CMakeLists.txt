

add_subdirectory("bgfx.cmake" EXCLUDE_FROM_ALL)
add_subdirectory("box2d" EXCLUDE_FROM_ALL)

set(CATCH_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("Catch2" EXCLUDE_FROM_ALL)
add_library(3rdParty::Catch2 ALIAS Catch2)

set(SKIP_PERFORMANCE_COMPARISON 1) # to not depend from boost
add_subdirectory("cereal" EXCLUDE_FROM_ALL)

add_subdirectory("enkiTS" EXCLUDE_FROM_ALL)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WIN32 ON CACHE BOOL "" FORCE)
add_subdirectory("glfw" EXCLUDE_FROM_ALL)
add_library(3rdParty::glfw ALIAS glfw)

set(GLM_ENABLE_CXX_20 ON CACHE BOOL "" FORCE)
set(GLM_ENABLE_LANG_EXTENSIONS ON CACHE BOOL "" FORCE)
add_subdirectory("glm" EXCLUDE_FROM_ALL)
add_library(3rdParty::glm ALIAS glm)
# add_subdirectory("imgui" EXCLUDE_FROM_ALL)
# add_subdirectory("joltphysics/Build" EXCLUDE_FROM_ALL)
# add_subdirectory("miniaudio" EXCLUDE_FROM_ALL)
# add_subdirectory("simpleini" EXCLUDE_FROM_ALL)
# add_subdirectory("tinygltf" EXCLUDE_FROM_ALL)
# add_subdirectory("tinyobjloader" EXCLUDE_FROM_ALL)
# add_subdirectory("tracy" EXCLUDE_FROM_ALL)
# add_subdirectory("zstd/build/cmake" EXCLUDE_FROM_ALL)