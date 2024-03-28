/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include "common/entity/AEntity.hpp"

using namespace shared::games::entity;
using namespace arcade::games::snake;

Snake::Snake(unsigned int tails) {
    for (size_t i = 0; i < tails; i++) {
        this->addTail();
    }
}

Snake::~Snake() = default;

std::vector<EntityPtr> &Snake::getTails() {
    return this->_tails;
}

EntityPtr Snake::addTail() {
}
