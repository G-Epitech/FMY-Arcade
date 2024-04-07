/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.cpp
*/

#include "Window.hpp"
#include "Renderer.hpp"
#include "font/Font.hpp"
#include "texture/Texture.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::ncurses::window;
using namespace arcade::graphics::common::exceptions;

Renderer::Renderer(Window &window) : _window(window)
{
}

void Renderer::render(const shared::graphics::TextProps &props)
{
    int index = 0;

    for (const auto &letter : props.content) {
        _window.map[props.position.y][props.position.x + index] = letter;
        index += 1;
    }
}

void Renderer::_textVerticalAlign(const shared::graphics::TextVerticalAlign &align, const shared::types::Vector2u &entitySize)
{
}

void Renderer::_textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2i &entitySize)
{
}

#include <iostream>
void Renderer::render(const shared::graphics::TextureProps &props)
{
    auto texture = _castOrThrow<shared::graphics::ITexture, texture::Texture>(props.texture);
    auto map = texture->getInnerTexture();

    int x = props.size.x;
    int y = props.size.y;

    for (int j = 0; j < y ; j++) {
        for (int i = 0; i < x; i++) {
            auto securedChar = _getRightChar(props, Vector2i(i, j));
                _window.map[props.position.y + j][props.position.x + i] = securedChar;
        }
    }
}

char Renderer::_getRightChar(const shared::graphics::TextureProps &props, const Vector2i &tilePosition)
{
    auto texture = _castOrThrow<shared::graphics::ITexture, arcade::graphics::ncurses::texture::Texture>(props.texture);
    auto map = texture->getInnerTexture();

    auto newPos = Vector2i(props.origin.x + tilePosition.x, props.origin.y + tilePosition.y);
    if (newPos.y < map.size() && newPos.x < map[newPos.y].size()) {
        return map[newPos.y][newPos.x];
    } else {
        return ' ';
    }
}