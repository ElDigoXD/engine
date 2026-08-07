#include "Core/InputManager.h"

// #include "imgui.h"

InputManager *InputManager::m_instance = nullptr;

InputManager *InputManager::get_instance() {
    return !m_instance ? m_instance = new InputManager() : m_instance;
}

void InputManager::init(GLFWwindow *l_window) {
    m_window = l_window;

    // Keyboard callback
    glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        InputManager *input = InputManager::get_instance();
        assert(key >= 0 && key <= GLFW_KEY_LAST);

        // GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT.
        input->m_key_states[key] = action == GLFW_PRESS || action == GLFW_REPEAT;
    });

    // Mouse button callback
    glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods) {
        InputManager *input = InputManager::get_instance();
        assert(button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST);
        input->m_mouse_button_states[button] = action == GLFW_PRESS || action == GLFW_REPEAT;
    });

    // Mouse move callback
    glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double x, double y) {
        InputManager *input = InputManager::get_instance();
        input->m_mouse_position = glm::vec2{x, y};
        input->m_mouse_delta = input->m_mouse_position - input->m_old_mouse_position;
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow *window, double x_delta, double y_delta) {
        InputManager *input = InputManager::get_instance();
        input->m_scroll_delta = glm::vec2{x_delta, y_delta};
    });
}

void InputManager::prepare_next_frame() {
    m_old_key_states = m_key_states;
    m_old_mouse_button_states = m_mouse_button_states;

    m_mouse_delta = glm::vec2{0, 0};
    m_old_mouse_position = m_mouse_position;

    m_scroll_delta = glm::vec2{0, 0};
}

bool InputManager::is_key_down(Key key) {
    // if (ImGui::GetIO().WantCaptureKeyboard) return false;
    return m_key_states[(int) key];
}

bool InputManager::is_key_pressed(Key key) {
    // if (ImGui::GetIO().WantCaptureKeyboard) return false;
    return m_key_states[(int) key] && !m_old_key_states[(int) key];
}

bool InputManager::is_key_released(Key key) {
    // if (ImGui::GetIO().WantCaptureKeyboard) return false;
    return !m_key_states[(int) key] && m_old_key_states[(int) key];
}

bool InputManager::is_mouse_button_down(MouseButton button) {
    // if (ImGui::GetIO().WantCaptureMouse) return false;
    return m_mouse_button_states[(int) button];
}

bool InputManager::is_mouse_button_pressed(MouseButton button) {
    // if (ImGui::GetIO().WantCaptureMouse) return false;
    return m_mouse_button_states[(int) button] && !m_old_mouse_button_states[(int) button];
}

bool InputManager::is_mouse_button_released(MouseButton button) {
    // if (ImGui::GetIO().WantCaptureMouse) return false;
    return !m_mouse_button_states[(int) button] && m_old_mouse_button_states[(int) button];
}

glm::vec2 InputManager::get_mouse_position() {
    return m_mouse_position;
}

glm::vec2 InputManager::get_mouse_delta() {
    return m_mouse_delta;
}

void InputManager::hide_and_stop_cursor(bool hide_and_stop) {
    glfwSetInputMode(m_window, GLFW_CURSOR, hide_and_stop ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);

    // No acceleration if supported
    if (glfwRawMouseMotionSupported()) {
        glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, hide_and_stop ? GLFW_TRUE : GLFW_FALSE);
    }
}

glm::vec2 InputManager::get_scroll_delta() {
    return m_scroll_delta;
}