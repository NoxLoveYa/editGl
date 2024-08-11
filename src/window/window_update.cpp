/*
** EPITECH PROJECT, 2024
** Procedural-Visualizer
** File description:
** window_update
*/

#include "window.hpp"

namespace visualizer
{
    void Window::ProcessInput()
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void Window::update()
    {
        while (!ShouldClose())
        {
            // Poll and handle events (inputs, window resize, etc.)
            PollEvents();
            GLint m_viewport[4];
            glGetIntegerv(GL_VIEWPORT, m_viewport);
            width = m_viewport[2];
            height = m_viewport[3];
            ProcessInput();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Render Menu
            renderMenu();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            SwapBuffers();
        }
    }
}