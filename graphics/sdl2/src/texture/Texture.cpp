/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.cpp
*/

#include "Texture.hpp"
#include "common/exceptions/TextureException.hpp"

using namespace arcade::graphics::sdl2::texture;
using namespace arcade::graphics::common::exceptions;

Texture::Texture(const std::string &path): _textured(false) {
    if (!_surface.load(path)) {
        throw TextureException(
            "Failed to load texture from file: " + path,
            "Texture constructor in SDL2 library"
        );
    }
}

const sdl::Texture &Texture::getInnerTexture(sdl::Renderer &renderer) {
    if (!_textured) {
        _texture = _surface.toTexture(renderer);
        _textured = true;
    }
    return _texture;
}

shared::types::Vector2i Texture::getSize() const {
    return _surface.getSize();
}
