/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sound.hpp
*/

#pragma once

#include <string>
#include <SFML/Audio.hpp>

#include "shared/graphics/ISound.hpp"

using namespace shared::graphics;

namespace arcade::graphics::sfml::sound {
    class Sound;
}

class arcade::graphics::sfml::sound::Sound : public ISound {
public:
    explicit Sound(const std::string &path, SoundState state = STOP);
    ~Sound() override = default;

    SoundVolume getVolume() const override;
    SoundState getState() const override;
    void setVolume(SoundVolume volume) override;
    void setState(SoundState state) override;
    void setLoopState(bool loop) override;
    bool getLoopState() const override;

private:
    sf::SoundBuffer _buffer;
    sf::Sound       _sound;
};
