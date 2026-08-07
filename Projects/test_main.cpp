#include <iostream>

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "../Engine/InputManager.h"


int main() {

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Test Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "glm test " << glm::degrees(1*3.14) << std::endl;


    glfwMakeContextCurrent(window);

    InputManager::get_instance()->init(window);
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        int x, y;
        glfwGetWindowPos(window, &x, &y);
        if (InputManager::get_instance()->is_key_down(Key::W)) {
            y -= 3;
        }
        if (InputManager::get_instance()->is_key_down(Key::S)) {
            y += 3;
        }
        if (InputManager::get_instance()->is_key_down(Key::A)) {
            x -= 3;
        }
        if (InputManager::get_instance()->is_key_down(Key::D)) {
            x += 3;
        }
        glfwSetWindowPos(window, x, y);


        InputManager::get_instance()->prepare_next_frame();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}