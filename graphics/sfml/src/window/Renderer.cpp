/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.cpp
*/

#include <iostream>
#include "Renderer.hpp"
#include "font/Font.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::sfml::window;
using namespace arcade::graphics::common::exceptions;

Renderer::Renderer(sf::RenderWindow &window, const Vector2u &size):
    _window(window),
    _tileSize(20, 20),
    size(size.x, size.y),
    tileSize(_tileSize)
{
    _text.setFont(sf::Font());
    _sprite.setTexture(sf::Texture());
}

void Renderer::render(const shared::graphics::TextProps &props) {
    std::cout << "Rendering text inner" << std::endl;
    auto font = _castOrThrow<shared::graphics::IFont, font::Font>(props.font);

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
    _window.draw(_text);
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

void Renderer::updateTileSize() {
    if (size.x != 0)
        _tileSize.x = static_cast<float>(_window.getSize().x) / static_cast<float>(size.x);
    if (size.y != 0)
        _tileSize.y = static_cast<float>(_window.getSize().y) / static_cast<float>(size.y);
}
