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
    _layer.draw(_text);
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
