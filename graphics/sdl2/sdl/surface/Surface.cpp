/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Image.cpp
*/

#include "Surface.hpp"
#include "sdl/exception/Exception.hpp"
#include "sdl/texture/Texture.hpp"
#include "sdl/renderer/Renderer.hpp"

using namespace sdl;

Surface::Surface() {
    _surface = nullptr;
}

Surface::Surface(SDL_Surface *surface) {
    _surface = surface;
}

Surface::Surface(const std::string &path): _surface(nullptr) {
    if (!load(path))
        throw SDLException("Failed to load image at: " + path);
}

bool Surface::load(const std::string &path) {
    if (_surface)
        SDL_FreeSurface(_surface);
    _surface = IMG_Load(path.c_str());
    return _surface != nullptr;
}

Surface::Surface(const Surface &other) {
    if (!other._surface) {
        _surface = nullptr;
        return;
    }
    _surface = SDL_DuplicateSurface(other._surface);
    if (!_surface)
        throw SDLException("Failed to duplicate SDL surface");
}

Surface::~Surface() {
    if (_surface)
        SDL_FreeSurface(_surface);
}

Vector2i Surface::getSize() const {
    return {_surface->w, _surface->h };
}

SDL_Surface *Surface::operator()() const {
    return _surface;
}

Texture Surface::toTexture(Renderer &renderer) const {
    auto raw = SDL_CreateTextureFromSurface(renderer(), _surface);

    if (!raw)
        throw SDLException("Failed to create texture from surface");
    return Texture(raw);
}
