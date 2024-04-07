/*
** EPITECH PROJECT, 2024
** GhostEntity.cpp
** File description:
** GhostEntity class
*/

#include "../../PacmanGame.hpp"
#include "GhostEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "common/components/CollidableComponent.hpp"

using namespace arcade::games::pacman;
using namespace arcade::games::common::components;
using namespace shared::types;

GhostEntity::GhostEntity(unsigned int asset): position(11 + asset , 14), direction(0, 0) {
    this->lastMove = std::chrono::seconds(10 + asset * 2);
    this->_spawnGhost(asset);
}

void GhostEntity::_spawnGhost(unsigned int asset) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/ghost.ascii",
                    .bin = "assets/pacman/ghost.png",
                    .binTileSize = Vector2f(35, 35)
            },
            .origin = Vector2u(0, asset)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, this->_onCollide);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 15,
                                                                                   textureProps);

    collision->getPosition().x = this->position.x;
    collision->getPosition().y = this->position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = this->position.x;
    texture->getPosition().y = this->position.y;
    this->_components.push_back(texture);
}

void GhostEntity::forward() {
    this->position.x += this->direction.x;
    this->position.y += this->direction.y;

    if (this->position.y == 14) {
        if (this->position.x < -1) {
            this->position.x = 27;
        }
        if (this->position.x > 28) {
            this->position.x = 1;
        }
    }

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = this->position.x;
        posCmp->getPosition().y = this->position.y;
    }
}

void GhostEntity::_onCollide(std::shared_ptr<shared::games::IGame> ctx,
                             std::shared_ptr<shared::games::components::ICollidableComponent> target) {
    auto game = std::dynamic_pointer_cast<PacmanGame>(ctx);
    auto entity = dynamic_cast<const PlayerEntity *>(&target->getEntity());

    if (!game)
        return;
    if (entity) {
        game->eatPlayer();
    }
}

void GhostEntity::reset(unsigned int index) {
    this->lastMove = std::chrono::seconds(10 + index * 2);
    this->position = Vector2i(11 + index , 14);
    this->direction = Vector2i(0, 0);
    this->forward();
}
