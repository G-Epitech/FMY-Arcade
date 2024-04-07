/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.hpp
*/

#pragma once

#include <string>
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
     * @brief Get the inner SDL2 texture
     * @param renderer Renderer to create the texture
     * @return Rendered texture
     */
    const sdl::Texture &getInnerTexture(sdl::Renderer &renderer);

    /**
     * @brief Get the size of the texture
     * @return Texture size
     */
    shared::types::Vector2i getSize() const;

private:
    sdl::Surface _surface;
    sdl::Texture _texture;
    bool _textured;
};
