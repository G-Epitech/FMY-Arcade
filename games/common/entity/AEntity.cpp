/*
** EPITECH PROJECT, 2024
** AEntity.cpp
** File description:
** AEntity class
*/

#include "AEntity.hpp"

using namespace arcade::games;
using namespace shared::games;

const components::ComponentsMap &arcade::games::common::AEntity::getComponents() const noexcept {
    return this->_components;
}
