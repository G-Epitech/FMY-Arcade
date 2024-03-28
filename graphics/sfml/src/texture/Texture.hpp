/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.hpp
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "shared/graphics/ITexture.hpp"

using namespace shared::graphics;

namespace arcade::graphics::sfml::texture {
    class Texture;
}

class arcade::graphics::sfml::texture::Texture: public ITexture {
public:
    explicit Texture(const std::string &path);
    ~Texture() override = default;

    /**
     * @brief Get the inner SFML texture
     * @return Reference to the inner SFML texture
     */
    sf::Texture &getInnerTexture();

private:
    sf::Texture _texture;
};
