/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Text.cpp
*/

#include <iostream>
#include "Text.hpp"
#include "sdl/renderer/Renderer.hpp"
#include "sdl/exception/Exception.hpp"

using namespace sdl;

Text::Text(): _font(nullptr), _position({0, 0}), _color(ColorWhite), _fontSize(12), _rendered(false)
{
}

Text::Text(const std::string &content): Text()
{
    _content = content;
}

void Text::setFont(SharedFont font)
{
    _font = std::move(font);
    _rendered = false;
}

SharedFont Text::getFont() const
{
    return _font;
}

void Text::setFontSize(unsigned int size)
{
    if (_fontSize != size)
        _rendered = false;
    _fontSize = size;
}

unsigned int Text::getFontSize() const
{
    return _fontSize;
}

void Text::setPosition(const shared::types::Vector2f &position) {
    _position = position;
}

const shared::types::Vector2f &Text::getPosition() const {
    return _position;
}

void Text::setContent(const std::string &content) {
    if (_content != content)
        _rendered = false;
    _content = content;
}

const std::string &Text::getContent() const {
    return _content;
}

const Color &Text::getColor() const {
    return _color;
}

void Text::setColor(const Color &color) {
    if (_color != color)
        _rendered = false;
    _color = color;
}

void Text::render(Renderer &renderer) {
    if (!_font)
        throw SDLException("Unable to render text of which font is not set");
    auto surface = _font->renderText(
        _content,
        _fontSize,
        _color
    );
    _texture = surface.toTexture(renderer);
    _rendered = true;
}

Texture &Text::toTexture(Renderer &renderer) {
    render(renderer);
    return _texture;
}

FRect Text::getGlobalBounds() const {
    if (!_rendered)
        throw SDLException("Unable to get global bounds of text that is not rendered");
    return {
        _position.x,
        _position.y,
        static_cast<float>(_texture.getSize().x),
        static_cast<float>(_texture.getSize().y)
    };
}
