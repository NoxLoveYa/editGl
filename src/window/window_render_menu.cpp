/*
** EPITECH PROJECT, 2024
** editGl
** File description:
** window_render_menu
*/

#include "window.hpp"

namespace visualizer
{
    void Window::renderMenu()
    {
        using namespace ImGui;
        SetNextWindowPos(ImVec2(0, 0));
        SetNextWindowSize(ImVec2(width, height));
        Begin("Menu", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        End();
    }
}