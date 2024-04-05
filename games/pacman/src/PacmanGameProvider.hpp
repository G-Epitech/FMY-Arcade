/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** PacmanGameProvider.hpp
*/

#pragma once

#include "shared/games/IGameProvider.hpp"

namespace arcade::games::pacman {
    class PacmanGameProvider;
}

class arcade::games::pacman::PacmanGameProvider : public shared::games::IGameProvider {
public:
    PacmanGameProvider() = default;

    ~PacmanGameProvider() override = default;

    /**
    * @brief Provides the game manifest
    *
    * @return Manifest of current game
    */
    const shared::games::GameManifest &getManifest() const noexcept override;

    /**
     * @brief Provides a new instance of the game
     *
     * @return Created game instance
     */
    std::shared_ptr<shared::games::IGame> createInstance() override;
};
