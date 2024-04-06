/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IGameProvider
*/

#pragma once

#include <memory>
#include "IGame.hpp"
#include "types/GameManifest.hpp"

namespace shared::games {
    class IGameProvider;
}

/**
 * @brief Interface of a game provider
 * 
 */
class shared::games::IGameProvider {
public:
    virtual ~IGameProvider() = default;

    /**
     * @brief Provides the game manifest
     *
     * @return Manifest of current game
     */
    virtual const GameManifest &getManifest() const noexcept = 0;

    /**
     * @brief Provides a new instance of the game
     *
     * @return Created game instance
     */
    virtual std::shared_ptr<shared::games::IGame> createInstance(void) = 0;
};
