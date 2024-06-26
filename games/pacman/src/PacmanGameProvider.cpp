/*
** EPITECH PROJECT, 2024
** PacmanGameProvider.cpp
** File description:
** PacmanGameProvider class
*/

#include "PacmanGame.hpp"
#include "PacmanGameProvider.hpp"

using namespace arcade::games;

const shared::games::GameManifest &pacman::PacmanGameProvider::getManifest() const noexcept {
    return PacmanGame::manifest;
}

std::shared_ptr<shared::games::IGame> pacman::PacmanGameProvider::createInstance() {
    return std::make_shared<PacmanGame>();
}
