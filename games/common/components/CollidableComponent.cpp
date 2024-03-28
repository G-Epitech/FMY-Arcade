/*
** EPITECH PROJECT, 2024
** CollidableComponent.cpp
** File description:
** CollidableComponent class
*/

#include "CollidableComponent.hpp"
#include <iostream>

using namespace arcade::games::common::components;

CollidableComponent::CollidableComponent(shared::games::entity::IEntity &entity) : PositionComponent(entity) {
    this->_type = shared::games::components::COLLIDABLE;
}

void CollidableComponent::onCollide(std::shared_ptr<shared::games::IGame> &ctx,
                                    std::shared_ptr<ICollidableComponent> target) {
}
