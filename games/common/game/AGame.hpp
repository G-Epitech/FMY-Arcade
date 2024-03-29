/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGame.hpp
*/

#pragma once

#include <map>
#include "shared/games/IGame.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::common {
    class AGame;
}

class arcade::games::common::AGame : public shared::games::IGame {
public:
    ~AGame() override = default;

    /**
     * @brief Get map of entity
     *
     * @return Map of entity
     */
    const shared::games::entity::EntitiesMap &getEntities() const override;

    /**
     * @brief Get game size (in tiles)
     *
     * @return Size of the game
     */
    const shared::types::Vector2u getSize() const noexcept override;

    /**
     * @brief Get fps of the game
     *
     * @return The number of frame per seconds of the game
     */
    const unsigned int getFps() const noexcept override;

protected:
    /**
     * @brief Construct a new AGame object
     *
     * @param size Size of the game
     * @param fps Fps of the game
     */
    explicit AGame(shared::types::Vector2u size, unsigned int fps);

    /**
     * @brief List of game entity
     */
    shared::games::entity::EntitiesMap _entities;

    /**
     * @brief Game size
     */
    shared::types::Vector2u _size;

    /**
     * @brief Game frame per seconds
     */
    unsigned int _fps;

    /**
     * @brief Add an entity to the game
     *
     * @param entity Entity to add
     * @return Id of the entity
     * @warning This method is moving ownership of the entity
     */
    void _registerEntity(shared::games::entity::EntityPtr entity);
};
