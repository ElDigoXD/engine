project(Math_UT)

set(MATH_SOURCES_UT
    Vector2Test.cpp
)

add_executable(Math_UT ${MATH_SOURCES_UT})

target_link_libraries(Math_UT 
	PRIVATE
		Engine::Math
		Catch2::Catch2WithMain
)
