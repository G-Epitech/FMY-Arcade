/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** window.hpp
*/

#pragma once

#include <memory>
#include <SDL2/SDL.h>

#define SDL_DESTROY_WINDOW &SDL_DestroyWindow

namespace arcade::graphics::sdl2::types {
    typedef decltype(SDL_DESTROY_WINDOW) SDLDestroyWindow;
    typedef std::unique_ptr<SDL_Window, SDLDestroyWindow> SDLWindow;
}
