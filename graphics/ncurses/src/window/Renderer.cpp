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

    int x = _textAlign(props);
    int y = _textVerticalAlign(props);
    Vector2i position = {x, y};
    for (const auto &letter : props.content) {
        _window.map[position.y][position.x + index] = letter;
        index += 1;
    }
}

int Renderer::_textVerticalAlign(const shared::graphics::TextProps &props)
{
    switch (props.verticalAlign) {
        case shared::graphics::TextVerticalAlign::TOP:
            return props.position.y;
        case shared::graphics::TextVerticalAlign::MIDDLE:
            return props.position.y + (props.size.y / 2);
        case shared::graphics::TextVerticalAlign::BOTTOM:
            return props.position.y + props.size.y;
    }
    return props.position.y;
}

int Renderer::_textAlign(const shared::graphics::TextProps &props)
{
    switch (props.align) {
        case shared::graphics::TextAlign::LEFT:
            return props.position.x;
        case shared::graphics::TextAlign::CENTER:
            return props.position.x + (props.size.x / 2) - (props.content.size() / 2);
        case shared::graphics::TextAlign::RIGHT:
            return props.position.x + props.size.x - props.content.size();
    }
    return props.position.x;
}

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
