/*
** EPITECH PROJECT, 2024
** PacmanGame.hpp
** File description:
** PacmanGame class
*/

#pragma once

#include "common/game/AGame.hpp"
#include "entities/player/PlayerEntity.hpp"
#include "entities/map/MapEntity.hpp"
#include "entities/ghost/GhostEntity.hpp"

#define MAP_PATH "assets/pacman/map.ascii"

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
     * @brief Add new point to player
     */
    void addNewPoint(Vector2i position);

    /**
     * @brief When a ghost eat a player
     */
    void eatPlayer(Vector2i position);

    /**
     * @brief Enable the ghost mode
     */
    void canEatGhosts();

protected:
    shared::games::DeltaTime _clock;
    std::shared_ptr<PlayerEntity> _player;
    std::shared_ptr<MapEntity> _map;
    std::vector<std::shared_ptr<GhostEntity>> _ghosts;

    bool _canEatGhost;
    shared::games::DeltaTime _stopEatGhostTime;

    /**
     * @brief Redirect the ghost when he is blocked
     * @param ghost
     */
    void _redirectGhost(std::shared_ptr<GhostEntity> ghost);
};
