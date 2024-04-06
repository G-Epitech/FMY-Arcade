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
#include "../nibbler/HeadEntity.hpp"
#include "../nibbler/TailEntity.hpp"
#include "../../NibblerGame.hpp"

using namespace arcade::games::nibbler;
using namespace arcade::games::common::components;

arcade::games::nibbler::AppleEntity::AppleEntity(shared::types::Vector2u size): postion(size) {
    this->_create(Vector2i(size.x, size.y));
}

void AppleEntity::generateApple() {}

void AppleEntity::_create(Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/nibbler/apple.ascii",
                    .bin = "assets/nibbler/apple.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, this->_onCollide);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 9,
                                                                                   textureProps);

    collision->getPosition().x = position.x;
    collision->getPosition().y = position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = position.x;
    texture->getPosition().y = position.y;
    this->_components.push_back(texture);
}

void arcade::games::nibbler::AppleEntity::_onCollide(std::shared_ptr<shared::games::IGame> ctx,
                                                  std::shared_ptr<shared::games::components::ICollidableComponent> target) {
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (dynamic_cast<const HeadEntity *>(&target->getEntity()) || dynamic_cast<const TailEntity *>(&target->getEntity())) {
        game->addNewPoint();
    }
}
