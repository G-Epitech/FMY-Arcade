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
    this->lastMove = std::chrono::milliseconds(900);
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
    int at = -1;

    this->head->forward();
    for (auto &tail: this->_tails) {
        at += 1;
        tempOldPosition = tail->getPosition();
        tail->setPosition(oldPosition);
        oldPosition = tempOldPosition;

        Vector2i old = at > 0 ? this->_tails.at(at - 1)->getPosition() : this->head->position;
        if (tail == this->_tails.back()) {
            if (tail->getPosition().y < old.y)
                tail->setTextureOrigin(Vector2u(0, 1));
            if (tail->getPosition().y > old.y)
                tail->setTextureOrigin(Vector2u(1, 1));
            if (tail->getPosition().x < old.x)
                tail->setTextureOrigin(Vector2u(2, 1));
            if (tail->getPosition().x > old.x)
                tail->setTextureOrigin(Vector2u(3, 1));
            continue;
        }
        if (tail->getPosition().y == old.y)
            tail->setTextureOrigin(Vector2u(1, 0));
        else
            tail->setTextureOrigin(Vector2u(0, 0));
    }
}

void Snake::reset() {
    this->head->reset();
    this->_tails.clear();

    for (size_t i = 0; i < this->_baseTails; i++) {
        this->addTail();
        this->forward();
    }
}
