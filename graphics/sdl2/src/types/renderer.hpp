/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** renderer.hpp
*/

#pragma once

#include <memory>
#include <SDL2/SDL.h>

#define SDL_DESTROY_RENDERER &SDL_DestroyRenderer

namespace arcade::graphics::sdl2::types {
    typedef decltype(SDL_DESTROY_RENDERER) SDLDestroyRenderer;
    typedef std::unique_ptr<SDL_Renderer, SDLDestroyRenderer> SDLRenderer;
}