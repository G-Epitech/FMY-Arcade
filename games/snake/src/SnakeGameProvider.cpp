/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGameProvider.cpp
*/

#include "SnakeGame.hpp"
#include "SnakeGameProvider.hpp"

using namespace arcade::games;

const shared::games::GameManifest &snake::SnakeGameProvider::getManifest() const noexcept {
    return SnakeGame::manifest;
}

std::shared_ptr<shared::games::IGame> snake::SnakeGameProvider::createInstance() {
    return std::make_shared<SnakeGame>();
}
