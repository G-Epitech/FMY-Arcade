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
    if (!_texture.loadFromFile(path))
        throw TextureException(
            "Failed to load texture at: " + path,
            "Texture constructor in SDL2 library"
        );
}

sf::Texture &Texture::getInnerTexture()
{
    return _texture;
}
