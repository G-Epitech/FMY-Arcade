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

namespace arcade::graphics::sfml::font {
    class Font;
}

class arcade::graphics::sfml::font::Font : public shared::graphics::IFont {
public:
    explicit Font(const std::string &path);
    ~Font() override = default;

    /**
     * @brief Get the inner SFML font
     * @return Reference to the inner SFML font
     */
    sf::Font &getInnerFont();

private:
    sf::Font _font;
};
