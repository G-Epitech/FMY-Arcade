/*
** EPITECH PROJECT, 2024
** PacmanGame.cpp
** File description:
** PacmanGame class
*/

#include "PacmanGame.hpp"
#include "entities/map/MapEntity.hpp"

using namespace arcade::games;

const shared::games::GameManifest pacman::PacmanGame::manifest = {
        .name = "pacman",
        .description = "The pacman arcade game",
        .version = "1.0.0",
        .authors = {
                {
                        .name = "TekMath",
                        .email = "matheo.coquet@epitech.eu",
                        .website = "https://github.com/tekmath"
                }
        }
};

pacman::PacmanGame::PacmanGame(): common::AGame(Vector2u(27, 30), 60) {
    this->_registerEntity(std::make_unique<MapEntity>(MAP_PATH));
}

const shared::games::GameManifest &pacman::PacmanGame::getManifest() const noexcept {
    return this->manifest;
}

void pacman::PacmanGame::compute(shared::games::DeltaTime dt) {
    this->_clock += dt;
}
