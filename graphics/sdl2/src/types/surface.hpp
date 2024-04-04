/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** surface.hpp
*/

#pragma once

#include <memory>
#include <SDL2/SDL.h>

#define SDL_DESTROY_SURFACE &SDL_FreeSurface

namespace arcade::graphics::sdl2::types {
    typedef decltype(SDL_DESTROY_SURFACE) SDLDestroySurface;
    typedef std::unique_ptr<SDL_Surface, SDLDestroySurface> SDLSurface;
}
