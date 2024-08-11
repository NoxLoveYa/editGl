/*
** EPITECH PROJECT, 2024
** editGl
** File description:
** window_render_menu
*/

#include "window.hpp"
#include <iostream>
#include <fstream>

namespace visualizer
{
    namespace Menuvar
    {
        // Top bar
        static bool fileMenuOpen = false;
        static bool helpMenuOpen = true;

        // File menu
        static bool openMenuOpen = false;
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
        if (Button("File", ImVec2(60, 28)))
        {
            Menuvar::fileMenuOpen = !Menuvar::fileMenuOpen;
            Menuvar::helpMenuOpen = false;
        }
        // Help button
        SetCursorPos(ImVec2(60, 0));
        if (Button(("Help"), ImVec2(60, 28)))
        {
            Menuvar::fileMenuOpen = false;
            Menuvar::helpMenuOpen = !Menuvar::helpMenuOpen;
        }
        End();
        // Render file menu
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
            {
                Menuvar::fileMenuOpen = false;
                Menuvar::openMenuOpen = true;
            }
            SetCursorPos(ImVec2(0, 24));
            if (Button("Save", ImVec2(60, 24)))
                Menuvar::fileMenuOpen = false;
            End();
            // Render help menu
        }
        else if (Menuvar::helpMenuOpen)
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

    static void renderOpenMenu(visualizer::Window *window)
    {
        StyleColorsSubMenusCustom();
        SetNextWindowSize(ImVec2(200, 200));
        Begin(
            "Open A File",
            NULL,
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
        std::vector<std::string> files = window->getFilesInCurDir();
        for (auto &file : files)
        {
            std::string filename = std::filesystem::is_directory(file) ?
                file.substr(file.find_last_of("/\\")) : file.substr(file.find_last_of("/\\") + 1);

            if (Button(filename.c_str()))
            {
                if (std::filesystem::is_directory(file))
                {
                    window->SetCurrentDir(file);
                }
                else
                {
                    std::ifstream ifs(file);
                    std::string content((std::istreambuf_iterator<char>(ifs)),
                                        (std::istreambuf_iterator<char>()));
                    window->SetContent(content);
                    Menuvar::openMenuOpen = false;
                }
            }
        }
        End();
    }

    static void renderContent(visualizer::Window *window)
    {
        StyleColorsCustom();
        SetNextWindowPos(ImVec2(0, 28));
        SetNextWindowSize(ImVec2(window->GetWidth(), window->GetHeight() - 28));
        Begin(
            "Content",
            NULL,
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
        Text(window->GetContent().c_str());
        End();
    }

    void Window::renderMenu()
    {
        renderContent(this);
        if (Menuvar::openMenuOpen)
            renderOpenMenu(this);
        renderTopBar(this);
    }
}