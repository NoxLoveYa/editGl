/*
** EPITECH PROJECT, 2024
** Procedural-Visualizer
** File description:
** window_style
*/

#pragma once

#include "../../lib/imgui/imgui.h"
#include "../../lib/imgui/imgui_impl_glfw.h"
#include "../../lib/imgui/imgui_impl_opengl3.h"
#include "../../lib/imgui/imgui_internal.h"

void StyleColorsCustom(ImGuiStyle* dst = NULL);
void StyleColorsTopBarCustom(ImGuiStyle* dst = NULL);
void StyleColorsSubMenusCustom(ImGuiStyle *dst = NULL);