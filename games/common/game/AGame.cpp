/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

#include <utility>

using namespace arcade::games;

common::AGame::AGame(shared::types::Vector2u size, unsigned int fps) : _size(size), _fps(fps) {
    this->_entities = {};
    this->_score = 0;
}

const shared::games::entity::EntitiesMap &common::AGame::getEntities() const {
    return this->_entities;
}

const shared::types::Vector2u common::AGame::getSize() const noexcept {
    return this->_size;
}

const unsigned int common::AGame::getFps() const noexcept {
    return this->_fps;
}

void common::AGame::_registerEntity(shared::games::entity::EntityPtr entity) {
    this->_entities.push_back(std::move(entity));
}

const int common::AGame::getScore() const noexcept {
    return this->_score;
}
