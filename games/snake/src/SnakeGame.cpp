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
    this->_snake = std::make_unique<Snake>(5);
    this->_registerEntity(this->_snake->head);

    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }

    this->_registerEntity(std::make_unique<WallEntity>(this->getSize()));
    this->_registerEntity(std::make_unique<BackgroundEntity>(this->getSize()));

    this->_clock = std::chrono::milliseconds(0);
    this->_looseGame = false;
}

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    this->_clock += dt;

    if (this->_looseGame) {
        return this->_loose();
    }
    if (this->_clock > std::chrono::milliseconds(100) + this->_snake->lastMove) {
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
}

void snake::SnakeGame::setLooseGame(bool state) {
    this->_looseGame = state;
}
