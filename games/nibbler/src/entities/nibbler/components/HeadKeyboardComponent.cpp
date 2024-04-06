/*
** EPITECH PROJECT, 2024
** KeyboardComponent.cpp
** File description:
** HeadKeyboardComponent class
*/

#include "HeadKeyboardComponent.hpp"
#include "../../../NibblerGame.hpp"

using namespace arcade::games::common::components;
using namespace arcade::games::nibbler::components;
using namespace shared::games::components;

HeadKeyboardComponent::HeadKeyboardComponent(HeadEntity &entity) : AComponent(KEYBOARD, entity), _parent(entity), _previousDirection(1, 0) {}

void HeadKeyboardComponent::onKeyPress(std::shared_ptr<shared::games::IGame> ctx,
                                   shared::games::components::IKeyboardComponent::KeyData keyData)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (!game->moved && keyData.type == ARROW) {
        if (keyData.code.arrow == UP && this->_parent.direction.y != 1) {
            auto dir = Vector2i(0, -1);
            if (game->isValidDirection(dir)) {
                this->_parent.setDirection(dir);
            }
        }
        if (keyData.code.arrow == DOWN && this->_parent.direction.y != -1) {
            auto dir = Vector2i(0, 1);
            if (game->isValidDirection(dir)) {
                this->_parent.setDirection(dir);
            }
        }
        if (keyData.code.arrow == LEFT && this->_parent.direction.x != 1) {
            auto dir = Vector2i(-1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.setDirection(dir);
            }
        }
        if (keyData.code.arrow == RIGHT && this->_parent.direction.x != -1) {
            auto dir = Vector2i(1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.setDirection(dir);
            }
        }
        game->moved = true;
        game->canMakeChoice = true;
    }
    if (!game->moved && keyData.type == CHAR) {
        if (keyData.code.character == 'z' && this->_parent.direction.y != 1) {
            auto dir = Vector2i(0, -1);
            if (game->isValidDirection(dir))
                this->_parent.setDirection(dir);
        }
        if (keyData.code.character == 's' && this->_parent.direction.y != -1) {
            auto dir = Vector2i(0, 1);
            if (game->isValidDirection(dir))
                this->_parent.setDirection(dir);
        }
        if (keyData.code.character == 'q' && this->_parent.direction.x != 1) {
            auto dir = Vector2i(-1, 0);
            if (game->isValidDirection(dir))
                this->_parent.setDirection(dir);
        }
        if (keyData.code.character == 'd' && this->_parent.direction.x != -1) {
            auto dir = Vector2i(1, 0);
            if (game->isValidDirection(dir))
                this->_parent.setDirection(dir);
        }
        game->moved = true;
        game->canMakeChoice = true;
    }
    if (keyData.type == CHAR && keyData.code.character == ' ') {
        game->speedBoost = 3;
    }
}

void HeadKeyboardComponent::onKeyRelease(std::shared_ptr<shared::games::IGame> ctx,
                                     shared::games::components::IKeyboardComponent::KeyData keyData) {}

