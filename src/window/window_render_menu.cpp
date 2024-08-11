/*
** EPITECH PROJECT, 2024
** editGl
** File description:
** window_render_menu
*/

#include "window.hpp"

namespace visualizer
{
    namespace Menuvar
    {
        static bool fileMenuOpen = false;
        static bool helpMenuOpen = true;
    }

    using namespace ImGui;

    static void renderTopBar(visualizer::Window *window)
    {
        // Update style
        StyleColorsTopBarCustom();
        // Render top bar
        SetNextWindowPos(ImVec2(0, 0));
        SetNextWindowSize(ImVec2(window->GetWidth(), 28));
        Begin(
            "Menu",
            NULL,
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
        // File button
        SetCursorPos(ImVec2(0, 0));
        if (Button("File", ImVec2(60, 28))) {
            Menuvar::fileMenuOpen = !Menuvar::fileMenuOpen;
            Menuvar::helpMenuOpen = false;
        }
        SetCursorPos(ImVec2(60, 0));
        if (Button(("Help"), ImVec2(60, 28))) {
            Menuvar::fileMenuOpen = false;
            Menuvar::helpMenuOpen = !Menuvar::helpMenuOpen;
        }
        End();
        if (Menuvar::fileMenuOpen)
        {
            SetNextWindowPos(ImVec2(0, 28));
            SetNextWindowSize(ImVec2(60, 48));
            Begin(
                "FileMenu",
                NULL,
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
            SetCursorPos(ImVec2(0, 0));
            if (Button("Open", ImVec2(60, 24)))
                Menuvar::fileMenuOpen = false;
            SetCursorPos(ImVec2(0, 24));
            if (Button("Save", ImVec2(60, 24)))
                Menuvar::fileMenuOpen = false;
            End();
        } else if (Menuvar::helpMenuOpen)
        {
            SetNextWindowPos(ImVec2(60, 28));
            SetNextWindowSize(ImVec2(60, 48));
            Begin(
                "HelpMenu",
                NULL,
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
            SetCursorPos(ImVec2(0, 0));
            if (Button("About", ImVec2(60, 24)))
                Menuvar::helpMenuOpen = false;
            SetCursorPos(ImVec2(0, 24));
            if (Button("Help", ImVec2(60, 24)))
                Menuvar::helpMenuOpen = false;
            End();
        }
    }

    void Window::renderMenu()
    {
        renderTopBar(this);
    }
}