/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.hpp
*/

#pragma once

#include <string>
#include "shared/graphics/IFont.hpp"
#include "utils/compiler.hpp"

namespace arcade::graphics::ncurses::font {
    class Font;
}

class arcade::graphics::ncurses::font::Font : public shared::graphics::IFont {
public:
    explicit Font(const std::string &path);
    ~Font() override = default;
};
