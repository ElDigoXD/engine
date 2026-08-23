set(MATH_SOURCES_UT
    Vector2Test.cpp
    Vector3Test.cpp
    Vector4Test.cpp
    Matrix3x3Test.cpp
    UtilsTest.cpp
    CommonTest.cpp
)

add_executable(Math_UT ${MATH_SOURCES_UT})

target_link_libraries(Math_UT
    PRIVATE
    Engine::Math
    Catch2::Catch2WithMain
)

catch_discover_tests(Math_UT)