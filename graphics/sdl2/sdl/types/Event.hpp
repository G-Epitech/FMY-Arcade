/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** events.hpp
*/

#pragma once

#include <SDL2/SDL.h>

namespace sdl {
    typedef SDL_Event Event;
    typedef SDL_EventType EventType;
    typedef SDL_KeyboardEvent KeyboardEvent;
    typedef SDL_MouseButtonEvent MouseButtonEvent;
    typedef SDL_MouseMotionEvent MouseMotionEvent;
    typedef SDL_QuitEvent QuitEvent;
    typedef SDL_Keycode Keycode;
}
