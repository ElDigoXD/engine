set(CORE_SOURCES_UT
    AllocatorTest.cpp
)

add_executable(CORE_UT ${CORE_SOURCES_UT})

target_link_libraries(CORE_UT
    PRIVATE
    Engine::Core
    Catch2::Catch2WithMain
)

catch_discover_tests(CORE_UT)