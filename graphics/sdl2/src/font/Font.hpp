/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.hpp
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "shared/graphics/IFont.hpp"
#include "utils/compiler.hpp"

namespace arcade::graphics::sdl2::font {
    class Font;
}

class arcade::graphics::sdl2::font::Font : public shared::graphics::IFont {
public:
    explicit Font(const std::string &path);
    ~Font() override = default;

    /**
     * @brief Get the inner SDL2 font
     * @return Reference to the inner SDL2 font
     */
    sf::Font &getInnerFont();

private:
    sf::Font _font;
};
