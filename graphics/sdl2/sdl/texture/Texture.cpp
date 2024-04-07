/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.cpp
*/

#include "Texture.hpp"
#include "sdl/renderer/Renderer.hpp"
#include "sdl/exception/Exception.hpp"

using namespace sdl;

Texture::Texture() {
    _texture = nullptr;
}

Texture::Texture(SDL_Texture *texture) {
    _texture = texture;
}

Texture::Texture(Renderer &renderer, Surface &surface) {
    _texture = SDL_CreateTextureFromSurface(renderer(), surface());
    if (!_texture)
        throw SDLException("Failed to create texture from surface");
}

Texture::~Texture() {
    if (_texture)
        SDL_DestroyTexture(_texture);
}

SDL_Texture *Texture::operator()() const {
    return _texture;
}

Texture &Texture::operator=(Texture &&texture)  noexcept {
    if (_texture)
        SDL_DestroyTexture(_texture);
    _texture = texture._texture;
    texture._texture = nullptr;
    return *this;
}

Vector2i Texture::getSize() const {
    Vector2i size(0, 0);

    SDL_QueryTexture(_texture, nullptr, nullptr, &size.x, &size.y);
    return size;
}
