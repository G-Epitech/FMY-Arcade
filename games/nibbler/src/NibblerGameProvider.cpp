/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NibblerGameProvider.cpp
*/

#include "NibblerGame.hpp"
#include "NibblerGameProvider.hpp"

using namespace arcade::games;

const shared::games::GameManifest &nibbler::NibblerGameProvider::getManifest() const noexcept {
    return NibblerGame::manifest;
}

std::shared_ptr<shared::games::IGame> nibbler::NibblerGameProvider::createInstance() {
    return std::make_shared<NibblerGame>();
}
