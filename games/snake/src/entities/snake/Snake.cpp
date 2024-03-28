/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** snake.cpp
*/

#include "Snake.hpp"
#include "TailEntity.hpp"

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
    EntityPtr newTail = std::make_shared<TailEntity>();

    this->_tails.push_back(newTail);
    return newTail;
}
