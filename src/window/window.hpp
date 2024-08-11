/*
** EPITECH PROJECT, 2024
** Procedural-Visualizer
** File description:
** window
*/

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <vector>

#include "../../lib/imgui/imgui.h"
#include "../../lib/imgui/imgui_impl_glfw.h"
#include "../../lib/imgui/imgui_impl_opengl3.h"
#include "../../lib/imgui/imgui_internal.h"

#include "window_style.hpp"
#include "../shaders/shaders.hpp"

namespace visualizer
{
    class Window
    {
    public:
    // Constructor / Destructor
        Window(int width, int height, const char *title);
        ~Window();
    // Operator
        operator GLFWwindow *() { return window; }
    // Getter
        GLFWwindow *GetWindow() { return window; }
        int GetWidth() { return width; }
        int GetHeight() { return height; }
        std::string GetContent() { return content; }
    // Setter
        void SetContent(std::string content) { this->content = content; }
        void SetCurrentDir(std::string currentDir) { this->currentDir = currentDir; }
    // Method
        bool ShouldClose() { return glfwWindowShouldClose(window); }
        void SwapBuffers() { glfwSwapBuffers(window); }
        void PollEvents() { glfwPollEvents(); }

        void ProcessInput();
        void update();
        std::vector<std::string> getFilesInDir(const std::string &dirPath);
        std::vector<std::string> getFilesInCurDir();

    // Callbacks
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
        {
            (void)window;
            glViewport(0, 0, width, height);
        }

    private:
    // Attributes
        GLFWwindow *window;
        ImGuiIO *io;
        int width, height;
        std::string content = "Je ne fais que test mon éditeur de text un peu pourris\nmais c'est pas grave, je vais le rendre plus beau et plus fonctionnel\n";
        std::string currentDir = getenv("HOME");
    // Methods
        void renderMenu();
    };
}
