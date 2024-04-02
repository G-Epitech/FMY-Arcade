/*
** EPITECH PROJECT, 2024
** HeadEntity.hpp
** File description:
** HeadEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

namespace arcade::games::snake {
    class SnakeGame;

    class HeadEntity;
}

class arcade::games::snake::HeadEntity : public common::AEntity {
public:
    ~HeadEntity() override = default;

    /**
     * @brief Create the head of a snake
     */
    explicit HeadEntity();

    /**
     * @brief Update the position of the head of the snake
     */
    void forward();

    /**
     * @brief Direction of the snake
     */
    Vector2i direction;

    /**
     * @brief Set the head at default position
     */
    void reset();

protected:
    /**
     * @brief Get default texture props
     * @return Texture props
     */
    static shared::games::components::TextureProps _defaultTextureProps();

    /**
     * @brief Represent the function that will be executed
     * when the snake will collide with an other collidable component
     * @param ctx Context of the game
     * @param target Target component
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);

    shared::games::components::TextureProps _textureProps;
};
