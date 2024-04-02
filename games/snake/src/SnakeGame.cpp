/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGame.cpp
*/

#include <iostream>
#include "SnakeGame.hpp"
#include "entities/wall/WallEntity.hpp"
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
    this->_snake = std::make_unique<Snake>(2);
    this->_registerEntity(this->_snake->head);

    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }

    this->_registerEntity(std::make_unique<WallEntity>(Vector2u(20, 20)));

    this->_clock = std::chrono::milliseconds(0);
}

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    this->_clock += dt;

    if (this->_clock > std::chrono::milliseconds(300) + this->_snake->lastMove) {
        this->_snake->lastMove = this->_clock;
        this->_snake->head->forward();

        // DEBUG //
        auto position = std::dynamic_pointer_cast<shared::games::components::IPositionableComponent>(this->_snake->head->getComponents().at(1));
        std::cout << "Snake Position [" << position->getPosition().x << ", " << position->getPosition().y << "]" << std::endl;

        this->loose();
        // END DEBUG //
    }
}

void snake::SnakeGame::loose() {
    this->_clock = std::chrono::milliseconds(0);
    this->_snake->lastMove = std::chrono::milliseconds(0);

    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](const shared::games::entity::EntityPtr& entity) {
        auto tail = std::dynamic_pointer_cast<TailEntity>(entity);
        return !(tail == nullptr);
    }), this->_entities.end());

    this->_snake->reset();

    for (size_t i = 0; i < 2; i++) {
        this->_snake->addTail();
    }
    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }
}
