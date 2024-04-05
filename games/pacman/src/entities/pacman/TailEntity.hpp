/*
** EPITECH PROJECT, 2024
** TailEntity.hpp
** File description:
** TailEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

namespace arcade::games::pacman {
    class TailEntity;
}

class arcade::games::pacman::TailEntity : public common::AEntity {
public:
    ~TailEntity() override = default;

    explicit TailEntity();

    /**
     * @brief Set position of the tail
     * @param position
     */
    void setPosition(Vector2i position);

    /**
     * @brief Set texture origin for direction of the tail
     * @param origin
     */
    void setTextureOrigin(Vector2u origin);

    /**
     * @brief Get position of the tail
     * @return Vector of the position
     */
    Vector2i getPosition();

protected:
    /**
     * @brief Get default texture props
     * @return Texture props
     */
    static shared::games::components::TextureProps _defaultTextureProps();

    shared::games::components::TextureProps _textureProps;
    Vector2i _position;
};
