/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGame.cpp
*/

#include <iostream>
#include "SnakeGame.hpp"
#include "entities/wall/WallEntity.hpp"
#include "entities/background/BackgroundEntity.hpp"
#include "entities/apple/AppleEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "entities/snake/components/HeadKeyboardComponent.hpp"

using namespace arcade::games;

const shared::games::GameManifest snake::SnakeGame::manifest = {
        .name = "snake",
        .description = "The snake original game",
        .version = "1.0.0",
        .authors = {
                {
                        .name = "TekMath",
                        .email = "matheo.coquet@epitech.eu",
                        .website = "https://github.com/tekmath"
                },
                {
                        .name = "Flavien Chenu",
                        .email = "flavienchenu@epitech.eu",
                        .website = "https://github.com/flavien-chenu"
                }
        }
};

snake::SnakeGame::SnakeGame() : common::AGame(Vector2u(20, 20), 60) {
    this->_snake = std::make_unique<Snake>(4);
    this->_registerEntity(this->_snake->head);

    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }

    this->_registerEntity(std::make_unique<WallEntity>(this->getSize()));
    this->_registerEntity(std::make_unique<BackgroundEntity>(this->getSize()));

    this->_apple = std::make_unique<AppleEntity>(this->getSize());
    this->_registerEntity(this->_apple);

    this->_clock = std::chrono::milliseconds(0);
    this->_looseGame = false;
    this->speedTime = 100;
    this->speedBoost = 0;
}

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    unsigned int speed = this->speedTime;
    this->_clock += dt;

    if (this->_looseGame) {
        return this->_loose();
    }
    if (this->speedBoost > 0) {
        speed = 0;
        this->speedBoost -= 1;
    }
    if (this->_clock > std::chrono::milliseconds(speed) + this->_snake->lastMove) {
        this->_snake->lastMove = this->_clock;
        this->_snake->forward();
    }
}

void snake::SnakeGame::_loose() {
    this->_clock = std::chrono::milliseconds(0);
    this->_snake->lastMove = std::chrono::milliseconds(900);

    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](const shared::games::entity::EntityPtr& entity) {
        auto tail = std::dynamic_pointer_cast<TailEntity>(entity);
        return !(tail == nullptr);
    }), this->_entities.end());

    this->_snake->reset();
    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }

    this->_looseGame = false;
    this->_score = 0;
}

void snake::SnakeGame::setLooseGame(bool state) {
    this->_looseGame = state;
}

void snake::SnakeGame::addNewPoint() {
    std::shared_ptr<TailEntity> newTail = this->_snake->addTail();

    this->_registerEntity(newTail);
    this->_apple->generateApple();
    this->speedTime -= 2;
    this->_score += 10;
}
