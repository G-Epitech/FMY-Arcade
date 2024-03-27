/*
** EPITECH PROJECT, 2024
** Color.hpp
** File description:
** Color class
*/

#pragma once

namespace shared::types {
    typedef struct ColorType {
        ColorType(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}

        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    } Color;
}
