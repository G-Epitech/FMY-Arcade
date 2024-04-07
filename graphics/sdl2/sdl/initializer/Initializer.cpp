/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Initializer.cpp
*/

#include "Initializer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "sdl/exception/Exception.hpp"

using namespace sdl;

void Initializer::init() {
    _initSDL();
    _initIMG();
    _initTTF();
}

void Initializer::quit() {
    _quitTTF();
    _quitIMG();
    _quitSDL();
}

void Initializer::_initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw SDLException("Failed to initialize SDL2");
}

void Initializer::_quitSDL() {
    if (SDL_WasInit(SDL_INIT_EVERYTHING))
        SDL_Quit();
}

void Initializer::_initIMG() {
    auto flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    if ((IMG_Init(flags) & flags) != flags)
        throw SDLException("Failed to initialize SDL2_image");
}

void Initializer::_quitIMG() {
    IMG_Quit();
}

void Initializer::_initTTF() {
    if (TTF_Init() != 0)
        throw SDLException("Failed to initialize SDL2_ttf");
}

void Initializer::_quitTTF() {
    if (TTF_WasInit())
        TTF_Quit();
}
