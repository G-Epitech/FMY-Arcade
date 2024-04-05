/*
** EPITECH PROJECT, 2024
** PacmanGame.hpp
** File description:
** PacmanGame class
*/

#pragma once

#include "common/game/AGame.hpp"

namespace arcade::games::pacman {
    class PacmanGame;
}

class arcade::games::pacman::PacmanGame : public arcade::games::common::AGame {
public:
    PacmanGame();

    ~PacmanGame() override = default;

    /**
     * @brief Game manifest
     *
     */
    static const shared::games::GameManifest manifest;

    /**
     * @brief Get the manifest object
     *
     * @return const shared::games::GameManifest&
     */
    const shared::games::GameManifest &getManifest() const noexcept override;

    /**
     * @brief Allow game possible actions
     *
     * @param dt Delta time from last frame
     */
    void compute(shared::games::DeltaTime dt) override;

protected:
    shared::games::DeltaTime _clock;
};
