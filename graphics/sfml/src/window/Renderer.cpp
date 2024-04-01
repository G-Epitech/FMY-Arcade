/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.cpp
*/

#include "Window.hpp"
#include "Renderer.hpp"
#include "font/Font.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::sfml::window;
using namespace arcade::graphics::common::exceptions;

Renderer::Renderer(Window &window): _window(window), _layer(_window.getInnerWindow())
{
    _text.setFont(sf::Font());
    _sprite.setTexture(sf::Texture());
}

void Renderer::render(const shared::graphics::TextProps &props) {
    auto font = _castOrThrow<shared::graphics::IFont, font::Font>(props.font);
    auto entityPosition = _entityPixelsPosition(props.position);
    auto entitySize = _window.tilesToPixels(props.size);

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
    _textAlign(props.align, entityPosition, entitySize);
    _textVerticalAlign(props.verticalAlign, entityPosition, entitySize);
    _textAdjustPosition();
    _layer.draw(_text);
}

void Renderer::_textVerticalAlign(const shared::graphics::TextVerticalAlign &align, const shared::types::Vector2f &entityPos,
                                  const shared::types::Vector2i &entitySize) {
    auto bounds = _text.getGlobalBounds();
    auto position = _text.getPosition();

    if (align == shared::graphics::MIDDLE) {
        position.y += (static_cast<float>(entitySize.y) - bounds.height) / 2;
    } else if (align == shared::graphics::BOTTOM) {
        position.y += static_cast<float>(entitySize.y) - bounds.height;
    }
    _text.setPosition(position);
}

void Renderer::_textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2f &entityPos,
                                  const shared::types::Vector2i &entitySize) {
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
    sf::FloatRect bounds = {0, 0, 0, 0 };

    _text.setPosition(0, 0);
    bounds = _text.getGlobalBounds();
    _text.setPosition(actual.x - bounds.left, actual.y - bounds.top);
}

void Renderer::render(unused const shared::graphics::TextureProps &props) {
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

Vector2f Renderer::_entityPixelsPosition(const Vector2i &position) {
    auto pixels = _window.tilesToPixels(position);

    return {
        static_cast<float>(pixels.x),
        static_cast<float>(pixels.y)
    };
}

template<class From, class To>
std::shared_ptr<To> Renderer::_castOrThrow(std::shared_ptr<From> from) {
    std::shared_ptr<To> to = std::dynamic_pointer_cast<To>(from);
    if (!to) {
        throw WindowException(
            "Failed to cast shared pointer of:" + std::string(typeid(from).name()) + " to " + typeid(to).name(),
            "SFML Library Renderer::_castOrThrow"
        );
    }
    return to;
}