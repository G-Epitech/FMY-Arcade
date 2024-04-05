/*
** EPITECH PROJECT, 2024
** AppleEntity.cpp
** File description:
** AppleEntity class
*/

#include <random>
#include "AppleEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"
#include "../pacman/HeadEntity.hpp"
#include "../pacman/TailEntity.hpp"
#include "../../PacmanGame.hpp"

using namespace arcade::games::pacman;
using namespace arcade::games::common::components;

arcade::games::pacman::AppleEntity::AppleEntity(shared::types::Vector2u size): _mapSize(size) {
    this->_create();
    this->generateApple();
}

void AppleEntity::generateApple() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, this->_mapSize.x - 2);
    Vector2i randomPosition = Vector2i(dis(gen), dis(gen));

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = randomPosition.x;
        posCmp->getPosition().y = randomPosition.y;
    }
}

void AppleEntity::_create() {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/apple.ascii",
                    .bin = "assets/pacman/apple.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, this->_onCollide);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 9,
                                                                                   textureProps);

    this->_components.push_back(collision);
    this->_components.push_back(texture);
}

void arcade::games::pacman::AppleEntity::_onCollide(std::shared_ptr<shared::games::IGame> ctx,
                                                  std::shared_ptr<shared::games::components::ICollidableComponent> target) {
    auto game = std::dynamic_pointer_cast<PacmanGame>(ctx);

    if (!game)
        return;
    if (dynamic_cast<const HeadEntity *>(&target->getEntity()) || dynamic_cast<const TailEntity *>(&target->getEntity())) {
        game->addNewPoint();
    }
}
