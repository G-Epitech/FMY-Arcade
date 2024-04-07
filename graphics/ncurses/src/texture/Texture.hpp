/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.hpp
*/

#pragma once

#include <map>
#include <string>
#include "shared/graphics/ITexture.hpp"

namespace arcade::graphics::ncurses::texture {
    class Texture;
}

class arcade::graphics::ncurses::texture::Texture: public shared::graphics::ITexture {
public:
    explicit Texture(const std::string &path);
    ~Texture() override = default;

    /**
     * @brief Get the inner NCURSES texture
     * @return Reference to the inner NCURSES texture
     */
    std::map<int, std::map<int, char>> &getInnerTexture();

private:
    std::map<int, std::map<int, char>> _texture;

    /**
     * @brief Load a texture from a file
     * @param path Path to the file
     */
    void _loadFromFile(const std::string &path);
};
