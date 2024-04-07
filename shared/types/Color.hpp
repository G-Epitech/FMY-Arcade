/*
** EPITECH PROJECT, 2024
** Color.hpp
** File description:
** Color class
*/

#pragma once

namespace shared::types
{
    /// @brief Color type
    typedef struct ColorType {
        /**
         * @brief Construct a new Color Type object
         * 
         * @param r Red color value
         * @param g Green color value
         * @param b Blue color value
         * @param a Alpha color value
         */
        ColorType(
            unsigned char r,
            unsigned char g,
            unsigned char b,
            unsigned char a
        ) : r(r), g(g), b(b), a(a) {}

        /**
         * @brief Red color value
         * 
         */
        unsigned char r;

        /**
         * @brief Green color value
         * 
         */
        unsigned char g;

        /**
         * @brief Blue color value
         * 
         */
        unsigned char b;

        /**
         * @brief Alpha color value
         * 
         */
        unsigned char a;
    } Color;
}
