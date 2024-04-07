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
#include "common/exceptions/WindowException.hpp"

namespace arcade::graphics::sfml::window {
    class Renderer;

    class Window;
}

class arcade::graphics::sfml::window::Renderer {
public:
    explicit Renderer(Window &window);

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

private:
    Window &_window;
    sf::RenderWindow &_layer;
    sf::Text _text;
    sf::Sprite _sprite;

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

    /**
     * @brief Convert a tile position to pixel position
     * @param position Tile position
     * @return Pixel position
     */
    Vector2f _entityPixels(const Vector2f &position);

    /**
     * @brief Convert a tile size to pixel size
     * @param size Tile size
     * @return Pixel size
     */
    Vector2i _entityPixels(const Vector2u &position);

    /**
     * @brief Align vertically the text
     * @param align Text alignment
     * @param entityPos Entity position
     * @param entitySize Entity size
     */
    void _textVerticalAlign(
        const shared::graphics::TextVerticalAlign &align,
        const shared::types::Vector2i &entitySize
    );

    /**
     * @brief Align the text
     * @param align Text alignment
     * @param entitySize Entity size
     */
    void _textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2i &entitySize);

    /**
     * @brief Adjust the text position
     */
    void _textAdjustPosition();

    /**
     * @brief Set texture rect depending on the texture properties
     * @param props Texture properties
     */
    void _setTextureRectAndScale(const shared::graphics::TextureProps &props);

    /**
     * @brief Cast a shared pointer from a type to another
     * @tparam From Type from which to cast
     * @tparam To Type to which cast
     * @param from Value to cast
     * @return Casted value
     */
    template<class From, class To>
    static std::shared_ptr<To> _castOrThrow(std::shared_ptr<From> from) {
        std::shared_ptr<To> to = std::dynamic_pointer_cast<To>(from);
        if (!to) {
            throw common::exceptions::WindowException(
                "Failed to cast shared pointer of:" + std::string(typeid(from).name()) + " to " + typeid(to).name(),
                "SFML Library Renderer::_castOrThrow"
            );
        }
        return to;
    };
};
