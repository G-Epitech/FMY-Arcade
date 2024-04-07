/*
** EPITECH PROJECT, 2024
** PlayerEntity.hpp
** File description:
** PlayerEntity class
*/

#pragma once

#include "common/game/AGame.hpp"
#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"
#include "shared/games/components/ICollidableComponent.hpp"

namespace arcade::games::pacman {
    class PlayerEntity;
}

class arcade::games::pacman::PlayerEntity : public common::AEntity {
public:
    ~PlayerEntity() override = default;

    /**
     * @brief Create a player
     * @param defaultPosition Default position of the player
     */
    explicit PlayerEntity(shared::types::Vector2i defaultPosition);

    /**
     * @brief Update the position of the player
     */
    void forward();

    /**
     * @brief Get position of the player
     * @return the player position
     */
    shared::types::Vector2i getPosition();

    /**
     * @brief Reset player
     */
    void reset(shared::types::Vector2i defaultPosition);

    shared::games::DeltaTime lastMove;
    shared::types::Vector2i direction;
protected:
    /**
     * @brief Spawn player on the map
     */
    void _spawnPlayer();

    shared::types::Vector2i _position;
    shared::types::Vector2u _origin;

    /**
     * @brief When a player enter in contact with a point
     * @param ctx Game
     * @param target Component target
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);
};
