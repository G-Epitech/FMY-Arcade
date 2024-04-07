/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.hpp
*/

#pragma once

#include <ncurses.h>
#include "shared/graphics/ITexture.hpp"
#include "shared/graphics/types/TextureProps.hpp"
#include "shared/graphics/types/TextProps.hpp"
#include "common/exceptions/WindowException.hpp"
#include "texture/Texture.hpp"

namespace arcade::graphics::ncurses::window {
    class Renderer;

    class Window;
}

class arcade::graphics::ncurses::window::Renderer {
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

    /**
     * @brief Align vertically the text
     * @param align Text alignment
     * @param entityPos Entity position
     * @param entitySize Entity size
     */
    void _textVerticalAlign(
        const shared::graphics::TextVerticalAlign &align,
        const shared::types::Vector2u &entitySize
    );

    /**
     * @brief Align the text
     * @param align Text alignment
     * @param entitySize Entity size
     */
    void _textAlign(const shared::graphics::TextAlign &align, const shared::types::Vector2i &entitySize);

    /**
     * @brief Get the right character in the texture
     * It manage origin of the texture, of course its size
     * @param props Texture properties
     * @param tilePosition Position of the tile
     * @return Right character
     */
    char _getRightChar(const shared::graphics::TextureProps &props, const Vector2i &tilePosition);

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
                "NCURSES Library Renderer::_castOrThrow"
            );
        }
        return to;
    };
};
