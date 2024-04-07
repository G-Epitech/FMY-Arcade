/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sound.hpp
*/

#pragma once

#include <string>

#include "shared/graphics/ISound.hpp"

namespace arcade::graphics::ncurses::sound {
    class Sound;
}

class arcade::graphics::ncurses::sound::Sound : public shared::graphics::ISound {
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
};
