/*
** EPITECH PROJECT, 2024
** GhostEntity.hpp
** File description:
** GhostEntity class
*/

#pragma once

#include "common/game/AGame.hpp"
#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"
#include "shared/games/components/ICollidableComponent.hpp"

namespace arcade::games::pacman {
    class GhostEntity;
}

class arcade::games::pacman::GhostEntity : public common::AEntity {
public:
    ~GhostEntity() override = default;

    /**
     * @brief Create a ghost
     * @param asset Index of the ghost
     */
    GhostEntity(unsigned int asset);

    /**
     * @brief Update the position of the ghost
     */
    void forward();

    /**
     * @brief Reset ghost position
     */
    void reset(unsigned int index);

    /**
     * @brief set ghost can be eat
     */
    void enableCanBeEat();

    /**
     * @brief set ghost cant be eat
     */
    void disableCanBeEat();

    shared::games::DeltaTime lastMove;
    shared::types::Vector2i direction;
    shared::types::Vector2i position;

protected:
    bool _canBeEat;
    shared::types::Vector2u _defaultOrigin;

    /**
     * @brief Spawn player on the map
     * @param asset Index of the ghost
     */
    void _spawnGhost(unsigned int asset);

    /**
     * @brief When a ghost enter in contact with a player
     * @param ctx Game
     * @param target Component target
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);
};
