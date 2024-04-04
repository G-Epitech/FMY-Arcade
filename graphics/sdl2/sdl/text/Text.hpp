/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Text.hpp
*/

#pragma once

#include "Font.hpp"
#include <SDL2/SDL.h>
#include "sdl/surface/Surface.hpp"
#include "shared/types/Vector.hpp"
#include "sdl/types/Color.hpp"
#include "sdl/texture/Texture.hpp"
#include "sdl/types/Rect.hpp"

namespace sdl {
    class Text;
    class Renderer;
}

class sdl::Text {
public:
    Text();

    explicit Text(const std::string &content);

    ~Text() = default;

    /**
     * @brief Get font of the text
     * @return Font of the text
     */
    SharedFont getFont() const;

    /**
     * @brief Set font of the text
     * @param font Font to set
     */
    void setFont(SharedFont font);

    /**
     * @brief Set content of the text
     * @param content Content to set
     */
    void setContent(const std::string &content);

    /**
     * @brief Get content of the text
     * @return Current text content
     */
    const std::string &getContent() const;

    /**
     * @brief Set position of the text
     * @param position Position to set
     */
    void setPosition(const shared::types::Vector2f &position);

    /**
     * @brief Get position of the text
     * @return Current text position
     */
    const shared::types::Vector2f &getPosition() const;

    /**
     * @brief Set the color of the font
     * @param color Color
     */
    void setColor(const Color &color);

    /**
     * @brief Get the color of the font
     * @return Color
     */
    const Color &getColor() const;

    /**
     * @brief Set the size of the font
     * @param size Font size
     */
    void setFontSize(unsigned int size);

    /**
     * @brief Get the size of the font
     * @return Font size
     */
    unsigned int getFontSize() const;

    /**
     * @brief Render the text
     * @param renderer Renderer to use
     */
    void render(Renderer &renderer);

    /**
     * @brief Get the texture of the text
     * @return Texture of the text
     */
    Texture &toTexture(Renderer &renderer);

    /**
     * @brief Get the texture of the text
     * @return Texture of the text
     */
     FRect getGlobalBounds() const;

private:
    SharedFont _font;
    unsigned int _fontSize;
    std::string _content;
    shared::types::Vector2f _position;
    Color _color;
    Texture _texture;
    bool _rendered;
};
