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

namespace arcade::games::pacman {
    class PacmanGame;

    class HeadEntity;
}

class arcade::games::pacman::HeadEntity : public common::AEntity {
public:
    ~HeadEntity() override = default;

    /**
     * @brief Create the head of a pacman
     */
    explicit HeadEntity();

    /**
     * @brief Update the position of the head of the pacman
     */
    void forward();

    /**
     * @brief Direction of the pacman head
     */
    Vector2i direction;

    /**
     * @brief Position of the pacman head
     */
    Vector2i position;

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
     * when the pacman will collide with an other collidable component
     * @param ctx Context of the game
     * @param target Target component
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);

    shared::games::components::TextureProps _textureProps;
};
