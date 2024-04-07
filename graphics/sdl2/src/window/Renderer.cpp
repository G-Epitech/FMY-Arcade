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

using namespace arcade::graphics::sdl2::window;;
using namespace arcade::graphics::common::exceptions;

Renderer::Renderer(Window &window) : _window(window), _renderer(window.getInnerWindow().getRenderer()) {}

void Renderer::render(const shared::graphics::TextProps &props) {
    auto font = _castOrThrow<shared::graphics::IFont, font::Font>(props.font);
    auto entityPosition = _entityPixelsPosition(props.position);
    auto entitySize = _window.tilesToPixels(props.size);
    sdl::Texture texture;

    _reset(_text);
    _text.setFont(font->getInnerFont());
    _text.setContent(props.content);
    _text.setFontSize(props.fontSize);
    _text.setColor({
        props.color.r,
        props.color.g,
        props.color.b,
        props.color.a
    });
    _text.setPosition(entityPosition);
    _text.render(_renderer);
    _textAlign(props.align, entitySize);
    _textVerticalAlign(props.verticalAlign, entitySize);
    _renderer.copy(_text);
}

void Renderer::_textVerticalAlign(const shared::graphics::TextVerticalAlign &align,
                                  const shared::types::Vector2i &entitySize)
{
    auto bounds = _text.getGlobalBounds();
    auto position = _text.getPosition();

    if (align == shared::graphics::MIDDLE) {
        position.y += (static_cast<float>(entitySize.y) - bounds.h) / 2;
    } else if (align == shared::graphics::BOTTOM) {
        position.y += static_cast<float>(entitySize.y) - bounds.h;
    }
    _text.setPosition(position);
}

void Renderer::_textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2i &entitySize) {
    auto bounds = _text.getGlobalBounds();
    auto position = _text.getPosition();

    if (align == shared::graphics::CENTER) {
        position.x += (static_cast<float>(entitySize.x) - bounds.w) / 2;
    } else if (align == shared::graphics::RIGHT) {
        position.x += static_cast<float>(entitySize.x) - bounds.w;
    }
    _text.setPosition(position);
}

void Renderer::render(const shared::graphics::TextureProps &props) {
    auto texture = _castOrThrow<shared::graphics::ITexture, texture::Texture>(props.texture);
    auto entityPosition = _entityPixelsPosition(props.position);

    _reset(_sprite);
    _setTextureRect(props);
    _sprite.setPosition(entityPosition);
    _renderer.copy(_sprite, texture->getInnerTexture(_renderer));
}

void Renderer::_setTextureRect(const shared::graphics::TextureProps &props) {
    auto size = _window.tilesToPixels(props.size);
    float width = static_cast<float>(props.size.x) * props.binTileSize.x;
    float height = static_cast<float>(props.size.y) * props.binTileSize.y;
    float left = static_cast<float>(props.origin.x) * props.binTileSize.x;
    float top = static_cast<float>(props.origin.y) * props.binTileSize.y;
    sdl::Rect rectangle = {
        static_cast<int>(left),
        static_cast<int>(top),
        static_cast<int>(width),
        static_cast<int>(height)
    };

    _sprite.setTextureRect(rectangle);
    _sprite.setScale({
         static_cast<float>(size.x) / width,
         static_cast<float>(size.y) / height
    });
}

void Renderer::_reset(sdl::Text &text) {
    text.setContent("");
    text.setFont(nullptr);
    text.setPosition({0, 0});
    text.setColor(sdl::ColorWhite);
    text.setFontSize(12);
}

void Renderer::_reset(sdl::Sprite &sprite) {
    sprite.setTextureRect(sdl::Rect(0, 0, 0, 0));
    sprite.setScale({1, 1});
    sprite.setPosition({0, 0});
}

Vector2f Renderer::_entityPixelsPosition(const Vector2i &position) {
    auto pixels = _window.tilesToPixels(position);

    return {
        static_cast<float>(pixels.x),
        static_cast<float>(pixels.y)
    };
}

