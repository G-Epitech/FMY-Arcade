/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.cpp
*/

#include "Font.hpp"
#include "common/exceptions/FontException.hpp"

using namespace arcade::graphics::sdl2::font;
using namespace arcade::graphics::common::exceptions;

Font::Font(const std::string &path)
{
    try {
        _font = std::make_shared<sdl::Font>(path);
    } catch (const std::exception &e) {
        throw FontException(
            "Failed to load font at: " + path,
            "Font constructor in SDL2 library"
        );
    }
}

sdl::SharedFont Font::getInnerFont()
{
    return _font;
}
