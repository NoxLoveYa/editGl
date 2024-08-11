/*
** EPITECH PROJECT, 2024
** Procedural-Visualizer
** File description:
** main
*/

#include "window/window.hpp"

int main(void)
{
    visualizer::Window window(640 * 2, 480 * 2, "RaveGl - A Procedural Visualizer");

    window.update();

    return 0;
}