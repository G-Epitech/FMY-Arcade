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

Texture::Texture(const std::string &path) {
    if (!_surface.load(path)) {
        throw TextureException(
            "Failed to load texture from file: " + path,
            "Texture constructor in SDL2 library"
        );
    }
}

sdl::Surface &Texture::getInnerSurface() {
    return _surface;
}
