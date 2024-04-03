/*
** EPITECH PROJECT, 2024
** KeyboardComponent.cpp
** File description:
** HeadKeyboardComponent class
*/

#include "HeadKeyboardComponent.hpp"

using namespace arcade::games::snake::components;
using namespace shared::games::components;

HeadKeyboardComponent::HeadKeyboardComponent(HeadEntity &entity) : AComponent(KEYBOARD, entity), _parent(entity) {}

void HeadKeyboardComponent::onKeyPress(std::shared_ptr<shared::games::IGame> ctx,
                                   shared::games::components::IKeyboardComponent::KeyData keyData) {
    if (keyData.type == ARROW) {
        if (keyData.code.arrow == UP && this->_parent.direction.y != 1) {
            this->_parent.direction = Vector2i(0, -1);
        }
        if (keyData.code.arrow == DOWN && this->_parent.direction.y != -1) {
            this->_parent.direction = Vector2i(0, 1);
        }
        if (keyData.code.arrow == LEFT && this->_parent.direction.x != 1) {
            this->_parent.direction = Vector2i(-1, 0);
        }
        if (keyData.code.arrow == RIGHT && this->_parent.direction.x != -1) {
            this->_parent.direction = Vector2i(1, 0);
        }
    }
    if (keyData.type == CHAR) {
        if (keyData.code.character == 'z') {
            this->_parent.direction = Vector2i(0, -1);
        }
        if (keyData.code.character == 's') {
            this->_parent.direction = Vector2i(0, 1);
        }
        if (keyData.code.character == 'q') {
            this->_parent.direction = Vector2i(-1, 0);
        }
        if (keyData.code.character == 'd') {
            this->_parent.direction = Vector2i(1, 0);
        }
    }
}

void HeadKeyboardComponent::onKeyRelease(std::shared_ptr<shared::games::IGame> ctx,
                                     shared::games::components::IKeyboardComponent::KeyData keyData) {}
