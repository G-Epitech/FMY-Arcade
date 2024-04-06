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

HeadKeyboardComponent::HeadKeyboardComponent(HeadEntity &entity) : AComponent(KEYBOARD, entity), _parent(entity), _previousDirection(1, 0)
{
    auto up = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/up.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeUp);
    this->sounds["up"] = up;
    auto down = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/down.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeDown);
    this->sounds["down"] = down;
    auto left = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/left.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeLeft);
    this->sounds["left"] = left;
    auto right = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/right.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeRight);
    this->sounds["right"] = right;
    auto eat = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/eat.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeEat);
    this->sounds["eat"] = eat;
    auto death = std::make_shared<SoundComponent>(this->_parent, "assets/nibbler/death.wav", SoundState::STOP, 100, false, HeadKeyboardComponent::_onSoundStateChangeDeath);
    this->sounds["death"] = death;
}

#include <iostream>
void HeadKeyboardComponent::onKeyPress(std::shared_ptr<shared::games::IGame> ctx,
                                   shared::games::components::IKeyboardComponent::KeyData keyData)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    std::cout << "Key pressed" << std::endl;
    if (!game)
        return;
    if (!game->moved && keyData.type == ARROW) {
        if (keyData.code.arrow == UP && this->_parent.direction.y != 1) {
            auto dir = Vector2i(0, -1);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(0, -1);
                this->_playSound("up");
            }
        }
        if (keyData.code.arrow == DOWN && this->_parent.direction.y != -1) {
            auto dir = Vector2i(0, 1);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(0, 1);
                this->_playSound("down");
            }
        }
        if (keyData.code.arrow == LEFT && this->_parent.direction.x != 1) {
            auto dir = Vector2i(-1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(-1, 0);
                this->_playSound("left");
            }
        }
        if (keyData.code.arrow == RIGHT && this->_parent.direction.x != -1) {
            auto dir = Vector2i(1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(1, 0);
                this->_playSound("right");
            }
        }
        game->moved = true;
        game->canMakeChoice = true;
    }
    if (!game->moved && keyData.type == CHAR) {
        if (keyData.code.character == 'z' && this->_parent.direction.y != 1) {
            auto dir = Vector2i(0, -1);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(0, -1);
                this->_playSound("up");
            }
        }
        if (keyData.code.character == 's' && this->_parent.direction.y != -1) {
            auto dir = Vector2i(0, 1);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(0, 1);
                this->_playSound("down");
            }
        }
        if (keyData.code.character == 'q' && this->_parent.direction.x != 1) {
            auto dir = Vector2i(-1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(-1, 0);
                this->_playSound("left");
            }
        }
        if (keyData.code.character == 'd' && this->_parent.direction.x != -1) {
            auto dir = Vector2i(1, 0);
            if (game->isValidDirection(dir)) {
                this->_parent.direction = Vector2i(1, 0);
                this->_playSound("right");
            }
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

void HeadKeyboardComponent::_playSound(const std::string &soundName)
{
    if (this->_previousDirection.x != this->_parent.direction.x &&
        this->_previousDirection.y != this->_parent.direction.y) {
            this->sounds[soundName]->setState(shared::games::components::SoundState::PLAY);
        }
    this->_previousDirection = this->_parent.direction;
}

void HeadKeyboardComponent::_onSoundStateChangeUp(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("up", shared::games::components::SoundState::STOP);
}

void HeadKeyboardComponent::_onSoundStateChangeDown(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("down", shared::games::components::SoundState::STOP);
}

void HeadKeyboardComponent::_onSoundStateChangeLeft(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("left", shared::games::components::SoundState::STOP);
}

void HeadKeyboardComponent::_onSoundStateChangeRight(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("right", shared::games::components::SoundState::STOP);
}

void HeadKeyboardComponent::_onSoundStateChangeEat(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("eat", shared::games::components::SoundState::STOP);
}

void HeadKeyboardComponent::_onSoundStateChangeDeath(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state)
{
    auto game = std::dynamic_pointer_cast<NibblerGame>(ctx);

    if (!game)
        return;
    if (state == shared::games::components::SoundState::STOP)
        game->changeStateSound("death", shared::games::components::SoundState::STOP);
}
