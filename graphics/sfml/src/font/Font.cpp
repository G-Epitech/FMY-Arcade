/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.cpp
*/

#include "Font.hpp"
#include "common/exceptions/FontException.hpp"

using namespace arcade::graphics::sfml::font;
using namespace arcade::graphics::common::exceptions;

Font::Font(const std::string &path)
{
    if (!_font.loadFromFile(path))
        throw FontException(
            "Failed to load font at: " + path,
            "Font constructor in SFML library"
        );
}

sf::Font &Font::getInnerFont()
{
    return _font;
}
