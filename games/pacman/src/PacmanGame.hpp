/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** PacmanGame.hpp
*/

#pragma once

#include "common/game/AGame.hpp"
#include "games/pacman/src/entities/pacman/Pacman.hpp"
#include "entities/apple/AppleEntity.hpp"

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

    /**
     * @brief Set loose game state
     *
     * @param state If the game is loose or not
     */
    void setLooseGame(bool state);

    /**
     * @brief Add new point to player and re-generate an apple
     */
    void addNewPoint();

    unsigned int speedTime;

    unsigned int speedBoost;

protected:
    /**
     * @brief Execute the process of the end of the game when the player _loose
     */
    void _loose();

    std::unique_ptr<Pacman> _pacman;
    std::shared_ptr<AppleEntity> _apple;
    shared::games::DeltaTime _clock;
    bool _looseGame;
};
