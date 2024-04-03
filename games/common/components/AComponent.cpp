/*
** EPITECH PROJECT, 2024
** AComponent.cpp
** File description:
** AComponent class
*/

#include <iostream>
#include "AComponent.hpp"

using namespace arcade::games::common::components;

AComponent::AComponent(shared::games::components::ComponentType type, shared::games::entity::IEntity &entity) : _parent(
        entity) {
    this->_type = type;
}

const shared::games::components::ComponentType AComponent::getType() const noexcept {
    return this->_type;
}

const shared::games::entity::IEntity &AComponent::getEntity() noexcept {
    return this->_parent;
}
