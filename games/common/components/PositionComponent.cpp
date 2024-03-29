/*
** EPITECH PROJECT, 2024
** PositionComponent.cpp
** File description:
** PositionComponent class
*/

#include "PositionComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

PositionComponent::PositionComponent(shared::games::entity::IEntity &entity) : AComponent(POSITION, entity),
                                                                               _position(0, 0) {
}

shared::types::Vector2i &PositionComponent::getPosition() noexcept {
    return this->_position;
}
