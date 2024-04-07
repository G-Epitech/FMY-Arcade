/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sound.cpp
*/

#include "Sound.hpp"
#include "common/exceptions/SoundException.hpp"

using namespace arcade::graphics::ncurses::sound;
using namespace arcade::graphics::common::exceptions;

Sound::Sound(const std::string &path, SoundState state) {}

Sound::SoundVolume Sound::getVolume() const {
    return 100;
}

void Sound::setVolume(SoundVolume volume) {}

void Sound::setState(SoundState state) {}

Sound::SoundState Sound::getState() const {
    return SoundState::STOP;
}

void Sound::setLoopState(bool loop) {}

bool Sound::getLoopState() const {
    return false;
}
