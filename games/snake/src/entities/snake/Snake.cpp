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
    this->_baseTails = tails;

    this->reset();
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

void Snake::forward() {
    Vector2i oldPosition = this->head->position;
    Vector2i tempOldPosition = oldPosition;

    this->head->forward();
    for (auto &tail: this->_tails) {
        tempOldPosition = tail->getPosition();
        tail->setPosition(oldPosition);
        oldPosition = tempOldPosition;
    }
}

void Snake::reset() {
    this->head->reset();
    this->_tails.clear();

    for (size_t i = 0; i < this->_baseTails; i++) {
        this->addTail();
    }
}
