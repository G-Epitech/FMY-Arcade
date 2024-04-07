/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.cpp
*/

#include <iostream>
#include "Renderer.hpp"
#include "sdl/text/Text.hpp"
#include "sdl/types/Color.hpp"
#include "sdl/window/Window.hpp"
#include "sdl/texture/Texture.hpp"
#include "sdl/exception/Exception.hpp"
#include "sdl/sprite/Sprite.hpp"

using namespace sdl;

Renderer::Renderer(const Window &window, unsigned int fps) : _window(window), _fps(fps) {
    _renderer = nullptr;
}

SDL_Renderer *Renderer::operator()() const {
    return _renderer;
}

Renderer &Renderer::create() {
    reset();
    _renderer = SDL_CreateRenderer(_window(), -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        throw SDLException("Failed to create renderer");
    return *this;
}

void Renderer::reset() {
    if (_renderer) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }
}

void Renderer::drawColor(Color color) {
    if (SDL_SetRenderDrawColor(_safeRenderer(), color.r, color.g, color.b, color.a) < 0)
        throw SDLException("Failed to set draw color");
}

void Renderer::clear() {
    if (SDL_RenderClear(_safeRenderer()) < 0)
        throw SDLException("Failed to clear renderer");
}

void Renderer::present() {
    SDL_RenderPresent(_safeRenderer());
    SDL_Delay(1000 / _fps);
}

Renderer::~Renderer() {
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
}

SDL_Renderer *Renderer::_safeRenderer() {
    if (!_renderer)
        throw SDLException("Renderer is not created");
    return _renderer;
}

void Renderer::copy(Text &text) {
    SDL_FRect dest = FRect::toSDLRect(text.getGlobalBounds());

    _copy(
        text.toTexture(*this),
        nullptr,
        &dest
    );
}

void Renderer::copy(const Sprite &sprite, const Texture &texture) {
    SDL_Rect src = Rect::toSDLRect(sprite.getTextureRect());
    SDL_FRect dest = FRect::toSDLRect(sprite.getGlobalBounds());

    _copy(texture, &src, &dest);
}

void Renderer::_copy(const Texture &texture, SDL_Rect *srcRect, SDL_FRect *destRect)
{
    auto copy = SDL_RenderCopyF(
        _safeRenderer(),
        texture(),
        srcRect,
        destRect
    );

    if (copy < 0) {
        throw SDLException("Failed to copy texture: " + std::string(SDL_GetError()));
    }
}

void Renderer::setFramerateLimit(unsigned int fps) {
    _fps = fps;
}

unsigned int Renderer::getFramerateLimit() const {
    return _fps;
}
