/*
** EPITECH PROJECT, 2024
** AppleEntity.hpp
** File description:
** AppleEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"
#include "shared/games/components/ICollidableComponent.hpp"

namespace arcade::games::pacman {
    class AppleEntity;
}

class arcade::games::pacman::AppleEntity : public common::AEntity {
public:
    ~AppleEntity() override = default;

    /**
     * @brief Create the apple entity
     * @param size Size of the map
     */
    explicit AppleEntity(shared::types::Vector2u
    size);

    /**
     * @brief Update the position of the apple on the map
     * (As a new apple reward for the player)
     */
    void generateApple();

protected:
    /**
     * @brief Create the apple components
     */
    void _create();

    /**
     * @brief Represent the function that will be executed
     * when the apple will collide with an other collidable component
     * @param ctx Context of the game
     * @param target Target component
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);


    shared::types::Vector2u _mapSize;
};
