/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NibblerGame.cpp
*/

#include <fstream>
#include <iostream>
#include "NibblerGame.hpp"
#include "entities/wall/WallEntity.hpp"
#include "entities/background/BackgroundEntity.hpp"
#include "entities/apple/AppleEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "entities/nibbler/components/HeadKeyboardComponent.hpp"

using namespace arcade::games;

const shared::games::GameManifest nibbler::NibblerGame::manifest = {
        .name = "nibbler",
        .description = "The nibbler original game",
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
                },
                {
                        .name = "Yann Masson",
                        .email = "yannmasson@epitech.eu",
                        .website = "yannmasson.fr"
                }
        }
};

nibbler::NibblerGame::NibblerGame() : common::AGame(Vector2u(19, 19), 60) {

    this->_nibbler = std::make_unique<Nibbler>(4);
    this->_registerEntity(this->_nibbler->head);
    this->changeToLevel(1);

    this->_clock = std::chrono::milliseconds(0);
    this->_looseGame = false;
    this->speedTime = 100;
    this->speedBoost = 0;
    this->moved = false;
    this->canMakeChoice = true;
}

const shared::games::GameManifest &nibbler::NibblerGame::getManifest() const noexcept {
    return NibblerGame::manifest;
}

void nibbler::NibblerGame::compute(shared::games::DeltaTime dt) {
    unsigned int speed = this->speedTime;
    this->_clock += dt;

    if (this->_looseGame) {
        return this->_loose();
    }
    if (this->speedBoost > 0) {
        speed = 0;
        this->speedBoost -= 1;
    }
    if (this->_clock > std::chrono::milliseconds(speed) + this->_nibbler->lastMove) {
        this->_preventWallCollision();
        this->moved = false;
        if (!this->canMakeChoice)
            return;
        this->_nibbler->lastMove = this->_clock;
        this->_nibbler->forward();
    }
}

void nibbler::NibblerGame::_loose() {
    this->_clock = std::chrono::milliseconds(0);
    this->_nibbler->lastMove = std::chrono::milliseconds(900);

    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](const shared::games::entity::EntityPtr& entity) {
        auto tail = std::dynamic_pointer_cast<TailEntity>(entity);
        return !(tail == nullptr);
    }), this->_entities.end());

    this->_nibbler->reset();
    for (auto &tail: this->_nibbler->getTails()) {
        this->_registerEntity(tail);
    }

    this->_looseGame = false;
    if (this->_score < this->_currentScore)
        this->_score = this->_currentScore;
    this->speedTime = 100;
    this->changeToLevel(1);
}

void nibbler::NibblerGame::setLooseGame(bool state) {
    this->_looseGame = state;
}

void nibbler::NibblerGame::addNewPoint() {
    std::shared_ptr<TailEntity> newTail = this->_nibbler->addTail();

    this->changeStateSound("eat", shared::games::components::SoundState::PLAY);
    this->_registerEntity(newTail);

    auto headPostion = this->_nibbler->head->position;

    int count = 0;
    for (auto &entity: this->_entities) {
        auto apple = std::dynamic_pointer_cast<AppleEntity>(entity);
        if (apple == nullptr)
            continue;
        count += 1;
        auto applePostion = apple->postion;
        if (headPostion.x == applePostion.x && headPostion.y == applePostion.y) {
            this->_entities.erase(std::remove(this->_entities.begin(), this->_entities.end(), entity), this->_entities.end());
            count -= 1;
        }
    }
    this->_currentScore += 10;
    if (count == 0) {
        this->changeToLevel(2);
        this->speedTime -= 20;
    }
}

void nibbler::NibblerGame::changeStateSound(const std::string &soundName, shared::games::components::SoundState state) {
    for (auto &entity: this->_entities) {
        auto head = std::dynamic_pointer_cast<nibbler::HeadEntity>(entity);
        if (head == nullptr)
            continue;
        auto components = head->getComponents();
        for (auto &component: components) {
            auto sound = std::dynamic_pointer_cast<arcade::games::nibbler::components::HeadKeyboardComponent>(component);
            if (sound == nullptr)
                continue;
            sound->sounds[soundName]->setState(state);
        }
    }
}

bool nibbler::NibblerGame::isValidDirection(Vector2i direction) {
    auto headPosition = this->_nibbler->head->position;

    if (direction.x == 0 && direction.y == -1) {
        if (this->_map[headPosition.x][headPosition.y - 1] == WALL)
            return false;
    } else if (direction.x == 0 && direction.y == 1) {
        if (this->_map[headPosition.x][headPosition.y + 1] == WALL)
            return false;
    } else if (direction.x == -1 && direction.y == 0) {
        if (this->_map[headPosition.x - 1][headPosition.y] == WALL)
            return false;
    } else if (direction.x == 1 && direction.y == 0) {
        if (this->_map[headPosition.x + 1][headPosition.y] == WALL)
            return false;
    }
    return true;
}

void nibbler::NibblerGame::_preventWallCollision() {
    auto headDirection = this->_nibbler->head->direction;
    auto headPosition = this->_nibbler->head->position;

    if (headDirection.x == 0 && headDirection.y == -1) {
        if (this->_map[headPosition.x][headPosition.y - 1] == WALL) {
            if (this->_map[headPosition.x - 1][headPosition.y] == SPACE && this->_map[headPosition.x + 1][headPosition.y] == SPACE) {
                this->canMakeChoice = false;
            } else if (this->_map[headPosition.x - 1][headPosition.y] == WALL && this->_map[headPosition.x + 1][headPosition.y] == SPACE) {
                this->_nibbler->head->direction = Vector2i(1, 0);
                this->canMakeChoice = true;
                this->moved = true;
            } else if (this->_map[headPosition.x + 1][headPosition.y] == WALL && this->_map[headPosition.x - 1][headPosition.y] == SPACE) {
                this->_nibbler->head->direction = Vector2i(-1, 0);
                this->canMakeChoice = true;
                this->moved = true;
            }
        }
    } else if (headDirection.x == 0 && headDirection.y == 1) {
        if (this->_map[headPosition.x][headPosition.y + 1] == WALL) {
            if (this->_map[headPosition.x - 1][headPosition.y] == SPACE && this->_map[headPosition.x + 1][headPosition.y] == SPACE) {
                this->canMakeChoice = false;
            } else if (this->_map[headPosition.x - 1][headPosition.y] == WALL && this->_map[headPosition.x + 1][headPosition.y] == SPACE) {
                this->_nibbler->head->direction = Vector2i(1, 0);
                this->canMakeChoice = true;
                this->moved = true;
            } else if (this->_map[headPosition.x + 1][headPosition.y] == WALL && this->_map[headPosition.x - 1][headPosition.y] == SPACE) {
                this->_nibbler->head->direction = Vector2i(-1, 0);
                this->canMakeChoice = true;
                this->moved = true;
            }
        }
    } else if (headDirection.x == -1 && headDirection.y == 0) {
        if (this->_map[headPosition.x - 1][headPosition.y] == WALL) {
            if (this->_map[headPosition.x][headPosition.y - 1] == SPACE && this->_map[headPosition.x][headPosition.y + 1] == SPACE) {
                this->canMakeChoice = false;
            } else if (this->_map[headPosition.x][headPosition.y - 1] == WALL && this->_map[headPosition.x][headPosition.y + 1] == SPACE) {
                this->_nibbler->head->direction = Vector2i(0, 1);
                this->canMakeChoice = true;
                this->moved = true;
            } else if (this->_map[headPosition.x][headPosition.y + 1] == WALL && this->_map[headPosition.x][headPosition.y - 1] == SPACE) {
                this->_nibbler->head->direction = Vector2i(0, -1);
                this->canMakeChoice = true;
                this->moved = true;
            }
        }
    } else if (headDirection.x == 1 && headDirection.y == 0) {
        if (this->_map[headPosition.x + 1][headPosition.y] == WALL) {
            if (this->_map[headPosition.x][headPosition.y - 1] == SPACE && this->_map[headPosition.x][headPosition.y + 1] == SPACE) {
                this->canMakeChoice = false;
            } else if (this->_map[headPosition.x][headPosition.y - 1] == WALL && this->_map[headPosition.x][headPosition.y + 1] == SPACE) {
                this->_nibbler->head->direction = Vector2i(0, 1);
                this->canMakeChoice = true;
                this->moved = true;
            } else if (this->_map[headPosition.x][headPosition.y + 1] == WALL && this->_map[headPosition.x][headPosition.y - 1] == SPACE) {
                this->_nibbler->head->direction = Vector2i(0, -1);
                this->canMakeChoice = true;
                this->moved = true;
            }
        }
    }
}

void nibbler::NibblerGame::changeToLevel(int level) {
    std::string line;
    std::ifstream file("assets/nibbler/levels/" + std::to_string(level) + ".ascii");

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }
    std::size_t x = 0;
    std::size_t y = 0;

    this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](const shared::games::entity::EntityPtr& entity) {
        auto tail = std::dynamic_pointer_cast<TailEntity>(entity);
        return !(tail == nullptr);
    }), this->_entities.end());

    this->_nibbler->reset();
    for (auto &tail: this->_nibbler->getTails()) {
        this->_registerEntity(tail);
    }

    while (std::getline(file, line)) {
        for (auto &c: line) {
            if (c == '#')
                this->_registerEntity(std::make_unique<WallEntity>(Vector2u(x, y)));
            if (c == '*')
                this->_registerEntity(std::make_unique<AppleEntity>(Vector2u(x, y)));
            if (c == ' '  || c == '*')
                this->_registerEntity(std::make_unique<BackgroundEntity>(Vector2u(x, y)));
            this->_map[x][y] = c == '#' ? WALL : SPACE;
            x += 1;
        }
        x = 0;
        y += 1;
    }
    file.close();
}
