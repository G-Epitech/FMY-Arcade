/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** snake.cpp
*/

#include "Snake.hpp"
#include "TailEntity.hpp"
#include "HeadEntity.hpp"

using namespace shared::games::entity;
using namespace arcade::games::snake;

Snake::Snake(unsigned int tails) {
    this->lastMove = std::chrono::milliseconds(0);
    this->head = std::make_shared<HeadEntity>();

    for (size_t i = 0; i < tails; i++) {
        this->addTail();
    }
}

Snake::~Snake() = default;

std::vector<std::shared_ptr<TailEntity>> &Snake::getTails() {
    return this->_tails;
}

std::shared_ptr<TailEntity> Snake::addTail() {
    std::shared_ptr<TailEntity> newTail = std::make_shared<TailEntity>();

    this->_tails.push_back(newTail);
    return newTail;
}

void Snake::reset() {
    this->head->reset();
    this->_tails.clear();
}
