/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** PacmanGame.cpp
*/

#include <iostream>
#include "PacmanGame.hpp"
#include "entities/wall/WallEntity.hpp"
#include "entities/background/BackgroundEntity.hpp"
#include "entities/apple/AppleEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "entities/pacman/components/HeadKeyboardComponent.hpp"

using namespace arcade::games;

const shared::games::GameManifest pacman::PacmanGame::manifest = {
        .name = "pacman",
        .description = "Pacman original game",
        .version = "1.0.0",
        .authors = {
                {
                        .name = "TekMath",
                        .email = "matheo.coquet@epitech.eu",
                        .website = "https://github.com/tekmath"
                },
                {
                        .name = "Yann Masson",
                        .email = "flavienchenu@epitech.eu",
                        .website = "https://github.com/flavien-chenu"
                }
        }
};

pacman::PacmanGame::PacmanGame() : common::AGame(Vector2u(20, 20), 60) {
    this->_pacman = std::make_unique<Pacman>(4);
    this->_registerEntity(this->_pacman->head);

    for (auto &tail: this->_pacman->getTails()) {
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

const shared::games::GameManifest &pacman::PacmanGame::getManifest() const noexcept {
    return PacmanGame::manifest;
}

void pacman::PacmanGame::compute(shared::games::DeltaTime dt) {
    unsigned int speed = this->speedTime;
    this->_clock += dt;

    if (this->_looseGame) {
        return this->_loose();
    }
    if (this->speedBoost > 0) {
        speed = 0;
        this->speedBoost -= 1;
    }
    if (this->_clock > std::chrono::milliseconds(speed) + this->_pacman->lastMove) {
        this->_pacman->lastMove = this->_clock;
        this->_pacman->forward();
    }
}

void pacman::PacmanGame::_loose() {
    this->_clock = std::chrono::milliseconds(0);
    this->_pacman->lastMove = std::chrono::milliseconds(900);

    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](const shared::games::entity::EntityPtr& entity) {
        auto tail = std::dynamic_pointer_cast<TailEntity>(entity);
        return !(tail == nullptr);
    }), this->_entities.end());

    this->_pacman->reset();
    for (auto &tail: this->_pacman->getTails()) {
        this->_registerEntity(tail);
    }

    this->_looseGame = false;
}

void pacman::PacmanGame::setLooseGame(bool state) {
    this->_looseGame = state;
}

void pacman::PacmanGame::addNewPoint() {
    std::shared_ptr<TailEntity> newTail = this->_pacman->addTail();

    this->_registerEntity(newTail);
    this->_apple->generateApple();
    this->speedTime -= 2;
    this->_score += 10;
}
