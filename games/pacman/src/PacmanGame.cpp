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

pacman::PacmanGame::PacmanGame() : common::AGame(Vector2u(27, 30), 60),
                                   _player(std::make_unique<PlayerEntity>(Vector2i(13, 23))),
                                   _map(std::make_unique<MapEntity>()) {

    for (const auto &entity: this->_map->generateWalls(MAP_PATH)) {
        this->_registerEntity(entity);
    }

    this->_registerEntity(this->_map);
    this->_registerEntity(this->_player);
}

const shared::games::GameManifest &pacman::PacmanGame::getManifest() const noexcept {
    return this->manifest;
}

void pacman::PacmanGame::compute(shared::games::DeltaTime dt) {
    this->_clock += dt;

    if (this->_clock > std::chrono::milliseconds(100) + this->_player->lastMove) {
        this->_player->lastMove = this->_clock;
        if (this->_map->mapData[this->_player->getPosition().y + this->_player->direction.y][
                    this->_player->getPosition().x + this->_player->direction.x] == '#') {
            return;
        }
        this->_player->forward();
    }
}

void pacman::PacmanGame::addNewPoint(Vector2i position) {
    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(),
                                         [&position](const shared::games::entity::EntityPtr &entity) {
                                             auto tail = std::dynamic_pointer_cast<PointEntity>(entity);
                                             if (tail) {
                                                 return tail->position.x == position.x &&
                                                        tail->position.y == position.y;
                                             }
                                             return false;
                                         }), this->_entities.end());
}
