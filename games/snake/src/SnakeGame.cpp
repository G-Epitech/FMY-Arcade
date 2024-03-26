/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGame.cpp
*/

#include <iostream>
#include "SnakeGame.hpp"

using namespace arcade::games;

const shared::games::GameManifest snake::SnakeGame::manifest = {
    .name = "Snake",
    .description = "The snake original game",
    .version = "0.0.1",
    .authors = {
        {
            .name = "Flavien Chenu",
            .email = "flavienchenu@epitech.eu",
            .website = "https://github.com/flavien-chenu"
        }
    }
};

snake::SnakeGame::SnakeGame(): common::AGame(Vector2u(12, 12)) {
    std::cout << "SnakeGame created" << std::endl;
}

snake::SnakeGame::~SnakeGame() = default;

const shared::games::GameManifest &snake::SnakeGame::getManifest() const noexcept {
    return SnakeGame::manifest;
}

void snake::SnakeGame::compute(shared::games::DeltaTime dt) {
    std::cout << "SnakeGame::compute" << std::endl;
    std::cout << "DeltaTime: " << dt << std::endl;
}
