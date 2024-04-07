/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Rect.hpp
*/

#pragma once

#include <SDL2/SDL.h>

namespace sdl {
    typedef struct Rect {
        Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

        /**
         * @brief X position of the rectangle
         */
        int x;

        /**
         * @brief Y position of the rectangle
         */
        int y;

        /**
         * @brief Width of the rectangle
         */
        int w;

        /**
         * @brief Height of the rectangle
         */
        int h;

        /**
         * @brief Convert a Rect to SDL_Rect
         * @param rect The Rect to convert
         * @return The converted SDL_Rect
         */
        static SDL_Rect toSDLRect(const Rect &rect) {
            return { rect.x, rect.y, rect.w, rect.h };
        }
    } Rect;
    typedef struct FRect {
        FRect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

        /**
         * @brief X position of the rectangle
         */
        float x;

        /**
         * @brief Y position of the rectangle
         */
        float y;

        /**
         * @brief Width of the rectangle
         */
        float w;

        /**
         * @brief Height of the rectangle
         */
        float h;

        /**
         * @brief Convert a Rect to SDL_Rect
         * @param rect The Rect to convert
         * @return The converted SDL_Rect
         */
        static SDL_FRect toSDLRect(const FRect &rect) {
            return { rect.x, rect.y, rect.w, rect.h };
        }
    } FRect;
}
