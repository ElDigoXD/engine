set(ECS_SOURCES_UT
    WorldTest.cpp
    WorldViewTest.cpp
)

add_executable(ECS_UT ${ECS_SOURCES_UT})

target_link_libraries(ECS_UT
    PRIVATE
    Engine::ECS
    Catch2::Catch2WithMain
)

catch_discover_tests(ECS_UT)