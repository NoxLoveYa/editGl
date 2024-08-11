/*
** EPITECH PROJECT, 2024
** Procedural-Visualizer
** File description:
** main
*/

#include "window/window.hpp"

int main(void)
{
    visualizer::Window window(640 * 2, 480 * 2, "EditGL - A Shit Text Editor");

    window.update();

    return 0;
}