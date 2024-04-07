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

using namespace arcade::graphics::sfml::window;
using namespace arcade::graphics::common::exceptions;

Renderer::Renderer(Window &window) : _window(window), _layer(_window.getInnerWindow()) {
    _text.setFont(sf::Font());
    _sprite.setTexture(sf::Texture());
}

void Renderer::render(const shared::graphics::TextProps &props) {
    auto font = _castOrThrow<shared::graphics::IFont, font::Font>(props.font);
    auto entityPosition = _entityPixels(props.position);
    auto entitySize = _entityPixels(props.size);

    _reset(_text);
    _text.setFont(font->getInnerFont());
    _text.setString(props.content);
    _text.setCharacterSize(props.fontSize);
    _text.setFillColor(sf::Color(
        props.color.r,
        props.color.g,
        props.color.b,
        props.color.a)
    );
    _text.setPosition(entityPosition.x, entityPosition.y);
    _textAlign(props.align, entitySize);
    _textVerticalAlign(props.verticalAlign, entitySize);
    _textAdjustPosition();
    _layer.draw(_text);
}

void
Renderer::_textVerticalAlign(const shared::graphics::TextVerticalAlign &align, const shared::types::Vector2i &entitySize
) {
    auto bounds = _text.getGlobalBounds();
    auto position = _text.getPosition();

    if (align == shared::graphics::MIDDLE) {
        position.y += (static_cast<float>(entitySize.y) - bounds.height) / 2;
    } else if (align == shared::graphics::BOTTOM) {
        position.y += static_cast<float>(entitySize.y) - bounds.height;
    }
    _text.setPosition(position);
}

void Renderer::_textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2i &entitySize) {
    auto bounds = _text.getGlobalBounds();
    auto position = _text.getPosition();

    if (align == shared::graphics::CENTER) {
        position.x += (static_cast<float>(entitySize.x) - bounds.width) / 2;
    } else if (align == shared::graphics::RIGHT) {
        position.x += static_cast<float>(entitySize.x) - bounds.width;
    }
    _text.setPosition(position);
}

void Renderer::_textAdjustPosition() {
    auto actual = _text.getPosition();
    sf::FloatRect bounds;

    _text.setPosition(0, 0);
    bounds = _text.getGlobalBounds();
    _text.setPosition(actual.x - bounds.left, actual.y - bounds.top);
}

void Renderer::render(const shared::graphics::TextureProps &props) {
    auto texture = _castOrThrow<shared::graphics::ITexture, texture::Texture>(props.texture);
    auto entityPosition = _entityPixels(props.position);

    _reset(_sprite);
    _sprite.setTexture(texture->getInnerTexture());
    _sprite.setPosition(entityPosition.x, entityPosition.y);
    _setTextureRectAndScale(props);
    _layer.draw(_sprite);
}

void Renderer::_setTextureRectAndScale(const shared::graphics::TextureProps &props) {
    auto size = _entityPixels(props.size);
    float width = static_cast<float>(props.size.x) * props.binTileSize.x;
    float height = static_cast<float>(props.size.y) * props.binTileSize.y;
    float left = static_cast<float>(props.origin.x) * props.binTileSize.x;
    float top = static_cast<float>(props.origin.y) * props.binTileSize.y;
    sf::IntRect rectangle = {
        static_cast<int>(left),
        static_cast<int>(top),
        static_cast<int>(width),
        static_cast<int>(height)
    };

    _sprite.setTextureRect(rectangle);
    _sprite.setScale(
        static_cast<float>(size.x) / width,
        static_cast<float>(size.y) / height
    );
}

void Renderer::_reset(sf::Text &text) {
    text.setString("");
    text.setCharacterSize(0);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular);
    text.setPosition(0, 0);
    text.setScale(1, 1);
    text.setOrigin(0, 0);
}

void Renderer::_reset(sf::Sprite &sprite) {
    sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
    sprite.setColor(sf::Color::White);
    sprite.setScale(1, 1);
    sprite.setPosition(0, 0);
    sprite.setOrigin(0, 0);
}

Vector2f Renderer::_entityPixels(const Vector2f &position) {
    auto realSize = this->_window.getSize();
    Vector2u originalPixels = this->_window.getPixelSizeFromTiles(realSize);

    return {
        static_cast<float>(position.x * originalPixels.x / realSize.x),
        static_cast<float>(position.y * originalPixels.y / realSize.y)
    };
}

Vector2i Renderer::_entityPixels(const Vector2u &position) {
    auto realSize = this->_window.getSize();
    Vector2u originalPixels = this->_window.getPixelSizeFromTiles(realSize);

    return {
        static_cast<int>(position.x * originalPixels.x / realSize.x),
        static_cast<int>(position.y * originalPixels.y / realSize.y)
    };
}
