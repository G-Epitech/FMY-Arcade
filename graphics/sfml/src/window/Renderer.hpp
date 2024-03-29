/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "shared/graphics/ITexture.hpp"
#include "shared/graphics/types/TextureProps.hpp"
#include "shared/graphics/types/TextProps.hpp"

namespace arcade::graphics::sfml::window {
    class Renderer;
    class Window;
}

class arcade::graphics::sfml::window::Renderer {
public:
    Renderer(sf::RenderWindow &window, const Vector2u &size);
    ~Renderer() = default;

    /**
     * @brief Render a texture on the window
     * @param props Texture properties
     */
    void render(const shared::graphics::TextureProps &props);

    /**
     * @brief Render a text on the window
     * @param props Text properties
     */
    void render(const shared::graphics::TextProps &props);

    /**
     * @brief Get the size of a tile
     * @return Size of a tile
     */
    const Vector2f &tileSize;

private:
    Vector2f            _tileSize;
    sf::RenderWindow    &_window;
    sf::Text            _text;
    sf::Sprite          _sprite;

    template<class From, class To>
    static std::shared_ptr<To> _castOrThrow(std::shared_ptr<From> from);

    /**
     * @brief Reset the text properties
     * @param text Text to reset
     */
    static void _reset(sf::Text &text);

    /**
     * @brief Reset the sprite properties
     * @param sprite Sprite to reset
     */
    static void _reset(sf::Sprite &sprite);
};
