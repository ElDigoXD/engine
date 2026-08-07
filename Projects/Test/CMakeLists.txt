project(Test)

add_executable(Test test_main.cpp)

target_link_libraries(Test PRIVATE
        Engine
)