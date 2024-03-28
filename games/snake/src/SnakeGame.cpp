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
}

snake::SnakeGame::~SnakeGame() = default;

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    std::cout << "SnakeGame::compute" << std::endl;
    std::cout << "DeltaTime: " << dt << std::endl;
    std::cout << "Number of entity: " << this->_entities.size() << std::endl;

    auto txcmp = std::dynamic_pointer_cast<shared::games::components::ITextureComponent>(this->_entities[1]->getComponents().at(1));
    std::cout << "Origin texture first tail: " << txcmp->getTextureProps().origin.x << std::endl;
    txcmp->getTextureProps().origin.x += 2;
}
