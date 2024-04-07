/*
** EPITECH PROJECT, 2024
** PacmanGame.cpp
** File description:
** PacmanGame class
*/

#include <random>
#include "PacmanGame.hpp"
#include "entities/map/MapEntity.hpp"
#include "entities/ghost/GhostEntity.hpp"

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

    for (unsigned int i = 0; i < 4; i++) {
        this->_ghosts.push_back(std::make_unique<GhostEntity>(i));
        this->_registerEntity(this->_ghosts[i]);
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
                    this->_player->getPosition().x + this->_player->direction.x] != '#') {
            this->_player->forward();
        }
    }

    for (auto ghost : this->_ghosts) {
        if (this->_clock > std::chrono::milliseconds(100) + ghost->lastMove) {
            if (ghost->direction.x == 0 && ghost->direction.y == 0) {
                ghost->direction = Vector2i(0, -1);
                ghost->position = Vector2i(13, 12);
            }
            if (this->_map->mapData[ghost->position.y + ghost->direction.y][
                        ghost->position.x + ghost->direction.x] != '#') {
                ghost->lastMove = this->_clock;
                ghost->forward();
            } else {
                this->_redirectGhost(ghost);
            }
        }
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

void pacman::PacmanGame::_redirectGhost(std::shared_ptr<GhostEntity> ghost) {
    std::vector<Vector2i> pos;

    if (this->_map->mapData[ghost->position.y - 1][
                ghost->position.x] == ' ')
        pos.push_back(Vector2i(0, -1));
    if (this->_map->mapData[ghost->position.y + 1][
                ghost->position.x] == ' ')
        pos.push_back(Vector2i(0, 1));
    if (this->_map->mapData[ghost->position.y][
                ghost->position.x - 1] == ' ')
        pos.push_back(Vector2i(-1, 0));
    if (this->_map->mapData[ghost->position.y][
                ghost->position.x + 1] == ' ')
        pos.push_back(Vector2i(1, 0));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, pos.size() - 1);

    ghost->direction = pos[dis(gen)];
}
