add_subdirectory("render")
#add_subdirectory("audio")

add_library(Modules INTERFACE)

target_link_libraries(Modules INTERFACE
        Module::Render
)