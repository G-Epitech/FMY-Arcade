/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.cpp
*/

#include "Renderer.hpp"
#include "sdl/text/Text.hpp"
#include "sdl/types/Color.hpp"
#include "sdl/window/Window.hpp"
#include "sdl/texture/Texture.hpp"
#include "sdl/exception/Exception.hpp"

using namespace sdl;

Renderer::Renderer(const Window &window) : _window(window) {
    _renderer = nullptr;
}

SDL_Renderer *Renderer::operator()() const {
    return _renderer;
}

Renderer &Renderer::create() {
    _renderer = SDL_CreateRenderer(_window(), -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        throw SDLException("Failed to create renderer");
    return *this;
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

void Renderer::copy(Texture &texture, std::unique_ptr<Rect> srcRect, std::unique_ptr<FRect> destRect) {
    SDL_Rect src = srcRect ? Rect::toSDLRect(*srcRect) : SDL_Rect{0, 0, 0, 0};
    SDL_FRect dest = destRect ? FRect::toSDLRect(*destRect) : SDL_FRect{0, 0, 0, 0};

    auto copy = SDL_RenderCopyF(
        _safeRenderer(),
        texture(),
        srcRect ? &src : nullptr,
        destRect ? &dest : nullptr
    );

    if (copy < 0)
        throw SDLException("Failed to copy texture");
}
