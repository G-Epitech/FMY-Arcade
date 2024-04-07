/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sprite.hpp
*/

#pragma once

#include "sdl/texture/Texture.hpp"
#include "sdl/types/Rect.hpp"

namespace sdl {
    class Sprite;
    class Texture;
}

class sdl::Sprite {
public:
    Sprite();
    ~Sprite();

    /**
     * @brief Set the position of the sprite
     * @param position Position to set
     */
    void setPosition(const Vector2f &position);

    /**
     * @brief Get the position of the sprite
     * @return Position of the sprite
     */
    const Vector2f &getPosition() const;

    /**
     * @brief Set the texture rect of the sprite
     * @param textureRect Texture rect to set
     */
    void setTextureRect(const Rect &textureRect);

    /**
     * @brief Get the texture rect of the sprite
     * @return Texture rect of the sprite
     */
    const Rect &getTextureRect() const;

    /**
     * @brief Get the scale of the sprite
     * @return Scale of the sprite
     */
    const Vector2f &getScale() const;

    /**
     * @brief Set the scale of the sprite
     * @param scale Scale to set
     */
    void setScale(const Vector2f &scale);

    /**
     * @brief Get the global bounds of the sprite
     * @return Sprite global bounds
     */
    FRect getGlobalBounds() const;

private:
    Vector2f _position;
    Rect _textureRect;
    Vector2f _scale;
};
