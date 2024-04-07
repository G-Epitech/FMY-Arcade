/*
** EPITECH PROJECT, 2024
** PositionableComponent.cpp
** File description:
** PositionableComponent class
*/

#include "PositionableComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

PositionableComponent::PositionableComponent(shared::games::entity::IEntity &entity) : AComponent(POSITIONABLE, entity),
                                                                                       _position(0, 0), _size(1, 1) {
}

shared::types::Vector2f &PositionableComponent::getPosition() noexcept {
    return this->_position;
}

shared::types::Vector2u &PositionableComponent::getSize() noexcept {
    return this->_size;
}
