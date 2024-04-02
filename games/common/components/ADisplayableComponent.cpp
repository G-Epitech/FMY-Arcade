/*
** EPITECH PROJECT, 2024
** ADisplayableComponent.cpp
** File description:
** ADisplayableComponent class
*/

#include "ADisplayableComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games;

ADisplayableComponent::ADisplayableComponent(entity::IEntity &entity, Vector2u size, unsigned int zindex)
        : PositionableComponent(entity),
          _size(size), _zindex(zindex) {
}

Vector2u &ADisplayableComponent::getSize() noexcept {
    return this->_size;
}

unsigned int &ADisplayableComponent::getZIndex() noexcept {
    return this->_zindex;
}

void ADisplayableComponent::onMousePress(std::shared_ptr<IGame> ctx) {}

void ADisplayableComponent::onMouseHover(std::shared_ptr<IGame> ctx) {}

void ADisplayableComponent::onMouseRelease(std::shared_ptr<IGame> ctx) {}
