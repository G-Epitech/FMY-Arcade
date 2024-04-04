/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Color.hpp
*/

#pragma once

namespace sdl {
    typedef struct Color {
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255)
            : r(r), g(g), b(b), a(a) {}

        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

        SDL_Color operator()() {
            return SDL_Color{r, g, b, a};
        }

        bool operator==(const Color &color) const {
            return r == color.r && g == color.g && b == color.b && a == color.a;
        }

        bool operator!=(const Color &color) const {
            return !(*this == color);
        }
    } Color;

    const Color ColorBlack = Color(0, 0, 0);
    const Color ColorWhite = Color(255, 255, 255);
    const Color ColorRed = Color(255, 0, 0);
    const Color ColorGreen = Color(0, 255, 0);
    const Color ColorBlue = Color(0, 0, 255);
    const Color ColorYellow = Color(255, 255, 0);
    const Color ColorMagenta = Color(255, 0, 255);
    const Color ColorCyan = Color(0, 255, 255);
    const Color ColorTransparent = Color(0, 0, 0, 0);
}
