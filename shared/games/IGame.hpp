/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** IGame
*/

#pragma once

#include <memory>
#include <chrono>
#include "IEntity.hpp"
#include "../types/Vector.hpp"
#include "types/GameManifest.hpp"

using namespace shared::types;

namespace shared::games {
    class IGame;

    /// @brief Delta time in milliseconds
    typedef std::chrono::duration<double, std::milli> DeltaTime;
}

/**
 * @brief Interface of a game
 * 
 */
class shared::games::IGame {
public:
    virtual ~IGame() = default;

    /**
     * @brief Compute the game each tick of the program
     *
     * @param dt Time since last tick (Time in `milliseconds`)
     */
    virtual void compute(DeltaTime dt) = 0;

    /**
     * @brief Manifest with informations of the game
     *
     * @return Manifest of the game
     */
    virtual const GameManifest &getManifest() const noexcept = 0;

    /**
     * @brief Number of tiles that represent the game
     * Tile size is managed by the renderer
     *
     * @return The number of tiles of the game
     */
    virtual const Vector2u getSize() const noexcept = 0;

    /**
     * @brief Get fps of the game
     *
     * @return The number of frame per seconds of the game
     */
    virtual const unsigned int getFps() const noexcept = 0;

    /**
     * @brief Get map of entities
     *
     * @return Entities map of the game
     */
    virtual const entity::EntitiesMap &getEntities(void) const = 0;

    /**
     * @brief Get the score of the game
     *
     * @return The score of the game
     */
    virtual const int getScore() const noexcept = 0;
};
