/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sound.cpp
*/

#include "Sound.hpp"
#include "common/exceptions/SoundException.hpp"

using namespace arcade::graphics::sdl2::sound;
using namespace arcade::graphics::common::exceptions;

Sound::Sound(const std::string &path, SoundState state) {
    if(!_buffer.loadFromFile(path)) {
        throw SoundException(
            "Failed to load sound at: " + path,
            "Sound constructor in SDL2 library"
        );
    }
    _sound.setBuffer(_buffer);
    _sound.stop();
}

Sound::SoundVolume Sound::getVolume() const {
    return static_cast<SoundVolume>(_sound.getVolume());
}

void Sound::setVolume(SoundVolume volume) {
    _sound.setVolume(volume);
}

void Sound::setState(SoundState state) {
    switch (state) {
        case PLAY:
            return _sound.play();
        case PAUSE:
            return _sound.pause();
        case STOP:
            return _sound.stop();
    }
}

Sound::SoundState Sound::getState() const {
    auto state = _sound.getStatus();

    switch (state) {
        case sf::Sound::Playing:
            return PLAY;
        case sf::Sound::Paused:
            return PAUSE;
        default:
            return STOP;
    }
}

void Sound::setLoopState(bool loop) {
    _sound.setLoop(loop);
}

bool Sound::getLoopState() const {
    return _sound.getLoop();
}
