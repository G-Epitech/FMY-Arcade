/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

#include <utility>

using namespace arcade::games;

common::AGame::AGame(shared::types::Vector2u size) : _size(size) {
    this->_entities = {};
}

const shared::games::entity::EntitiesMap &common::AGame::getEntities() const {
    return this->_entities;
}

common::EntityPtr common::AGame::getEntityById(const shared::types::UUId &id) const {
    try {
        return this->_entities.at(id);
    } catch (std::out_of_range &e) {
        return nullptr;
    }
}

const shared::types::Vector2u common::AGame::getSize() const noexcept {
    return this->_size;
}

shared::types::UUId common::AGame::_registerEntity(EntityPtr entity) {
    const shared::types::UUId id;

    this->_entities[id] = std::move(entity);
    return id;
}
