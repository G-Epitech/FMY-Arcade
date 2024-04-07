/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.cpp
*/

#include <fstream>
#include "Texture.hpp"
#include "common/exceptions/TextureException.hpp"

using namespace arcade::graphics::ncurses::texture;
using namespace arcade::graphics::common::exceptions;

Texture::Texture(const std::string &path) {
    this->_loadFromFile(path);
}

std::map<int, std::map<int, char>> &Texture::getInnerTexture()
{
    return _texture;
}

void Texture::_loadFromFile(const std::string &path)
{
    std::ifstream file(path);
    std::string line;
    int x = 0;
    int y = 0;

    if (!file.is_open())
        throw TextureException(
            "Failed to open file at: " + path,
            "loadFromFile in NCURSES library"
        );
    while (std::getline(file, line)) {
        for (const auto &c : line) {
            _texture[y][x] = c;
            x++;
        }
        x = 0;
        y++;
    }
    file.close();
}
