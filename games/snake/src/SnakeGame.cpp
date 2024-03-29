/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGame.cpp
*/

#include <iostream>
#include "SnakeGame.hpp"
#include "common/components/TextureComponent.hpp"

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

snake::SnakeGame::SnakeGame() : common::AGame(Vector2u(19, 19), 60) {
    this->_snake = std::make_unique<Snake>(2);
    this->_registerEntity(this->_snake->head);

    for (auto &tail: this->_snake->getTails()) {
        this->_registerEntity(tail);
    }
    this->_clock = std::chrono::milliseconds(0);
}

snake::SnakeGame::~SnakeGame() = default;

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    this->_clock += dt;

    if (this->_clock > std::chrono::milliseconds(300) + this->_snake->lastMove) {
        this->_snake->lastMove = this->_clock;
        this->_snake->head->forward();

        // DEBUG //
        auto position = std::dynamic_pointer_cast<shared::games::components::IPositionComponent>(this->_snake->head->getComponents().at(1));
        std::cout << "Snake Position [" << position->getPosition().x << ", " << position->getPosition().y << "]" << std::endl;
        // END DEBUG //
    }
}
