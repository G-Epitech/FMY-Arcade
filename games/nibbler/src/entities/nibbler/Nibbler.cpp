/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** nibbler.cpp
*/

#include "Nibbler.hpp"
#include "TailEntity.hpp"
#include "HeadEntity.hpp"

using namespace shared::games::entity;
using namespace arcade::games::nibbler;

Nibbler::Nibbler(unsigned int tails) {
    this->lastMove = std::chrono::milliseconds(900);
    this->head = std::make_shared<HeadEntity>();
    this->_baseTails = tails;

    this->reset();
}

Nibbler::~Nibbler() = default;

std::vector<std::shared_ptr<TailEntity>> &Nibbler::getTails() {
    return this->_tails;
}

std::shared_ptr<TailEntity> Nibbler::addTail() {
    std::shared_ptr<TailEntity> newTail = std::make_shared<TailEntity>();

    this->_tails.push_back(newTail);
    return newTail;
}

void Nibbler::forward() {
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

void Nibbler::reset() {
    this->head->reset();
    this->_tails.clear();

    for (size_t i = 0; i < this->_baseTails; i++) {
        this->addTail();
        this->forward();
    }
}
