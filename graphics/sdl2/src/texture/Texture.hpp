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
#include "sdl/texture/Texture.hpp"

namespace arcade::graphics::sdl2::texture {
    class Texture;
}

class arcade::graphics::sdl2::texture::Texture: public shared::graphics::ITexture {
public:
    explicit Texture(const std::string &path);
    ~Texture() override = default;

    /**
     * @brief Get the inner SDL2 surface
     * @return Reference to the inner SDL2 surface
     */
    sdl::Surface &getInnerSurface();

private:
    sdl::Surface _surface;
};
