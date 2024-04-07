/*
** EPITECH PROJECT, 2024
** PlayerEntity.cpp
** File description:
** PlayerEntity class
*/

#include "PlayerEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "common/components/CollidableComponent.hpp"
#include "components/HeadKeyboardComponent.hpp"
#include "../../PacmanGame.hpp"
#include "../map/PointEntity.hpp"

using namespace arcade::games::pacman;
using namespace arcade::games::common::components;
using namespace shared::types;

PlayerEntity::PlayerEntity(shared::types::Vector2i defaultPosition): _position(defaultPosition), direction(1, 0),
                                                                     _origin(0, 0) {
    this->lastMove = std::chrono::milliseconds(900);
    this->_spawnPlayer();

    std::shared_ptr<components::HeadKeyboardComponent> keyboard = std::make_shared<components::HeadKeyboardComponent>(
            *this);
    this->_components.push_back(keyboard);
}

void PlayerEntity::_spawnPlayer() {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/pacman.ascii",
                    .bin = "assets/pacman/pacman.png",
                    .binTileSize = Vector2f(100, 100)
            },
            .origin = this->_origin
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, this->_onCollide);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 5,
                                                                                   textureProps);

    collision->getPosition().x = this->_position.x;
    collision->getPosition().y = this->_position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = this->_position.x;
    texture->getPosition().y = this->_position.y;
    this->_components.push_back(texture);
}

void PlayerEntity::forward() {
    this->_position.x += this->direction.x;
    this->_position.y += this->direction.y;

    if (this->_position.y == 14) {
        if (this->_position.x < -1) {
            this->_position.x = 27;
        }
        if (this->_position.x > 28) {
            this->_position.x = 1;
        }
    }

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = this->_position.x;
        posCmp->getPosition().y = this->_position.y;

        auto textureCmp = std::dynamic_pointer_cast<TextureComponent>(component);
        if (textureCmp == nullptr) continue;

        textureCmp->getTextureProps().origin = Vector2u(this->_origin.x, 0);
        if (this->direction.y == -1)
            textureCmp->getTextureProps().origin.y = 3;
        if (this->direction.y == 1)
            textureCmp->getTextureProps().origin.y = 2;
        if (this->direction.x == -1)
            textureCmp->getTextureProps().origin.y = 1;
    }
}

void PlayerEntity::_onCollide(std::shared_ptr<shared::games::IGame> ctx,
                             std::shared_ptr<shared::games::components::ICollidableComponent> target) {
    auto game = std::dynamic_pointer_cast<PacmanGame>(ctx);
    auto entity = dynamic_cast<const PointEntity *>(&target->getEntity());

    if (!game)
        return;
    if (entity) {
        game->addNewPoint(entity->position);
        if (entity->ghostBonus) {
            game->canEatGhosts();
        }
    }
}

shared::types::Vector2i PlayerEntity::getPosition() const {
    return this->_position;
}

void PlayerEntity::reset(shared::types::Vector2i defaultPosition) {
    this->_position = defaultPosition;
    this->forward();
    this->lastMove = std::chrono::milliseconds(900);
}
