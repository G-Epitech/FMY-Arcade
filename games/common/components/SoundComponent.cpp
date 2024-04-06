/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SoundComponent
*/

#include "SoundComponent.hpp"

using namespace shared::games::components;
using namespace arcade::games::common::components;

SoundComponent::SoundComponent(shared::games::entity::IEntity &entity, const std::string &path,
    shared::games::components::SoundState state, shared::games::components::SoundVolume volume, bool loop, onChangeFunction onChange)
    : AComponent(SOUND, entity), _path(path), _state(state), _volume(volume), _loop(loop), _onChange(onChange)
{
    this->_type = SOUND;
}

const std::string &SoundComponent::getPath() const noexcept
{
    return this->_path;
}

SoundState &SoundComponent::getState() noexcept
{
    return this->_state;
}

SoundVolume &SoundComponent::getVolume() noexcept
{
    return this->_volume;
}

bool &SoundComponent::getLoop() noexcept
{
    return this->_loop;
}

void SoundComponent::onStateChange(std::shared_ptr<shared::games::IGame> ctx,
    shared::games::components::SoundState state)
{
    if (this->_onChange)
        this->_onChange(ctx, state);
}

void SoundComponent::setState(SoundState state)
{
    this->_state = state;
}
