/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SoundComponent
*/

#pragma once

#include "AComponent.hpp"
#include "shared/games/components/ISoundComponent.hpp"

namespace arcade::games::common::components
{
    class SoundComponent;
}

class arcade::games::common::components::SoundComponent
    : public virtual shared::games::components::ISoundComponent, public AComponent
{
public:
    typedef void (*onChangeFunction)(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    ~SoundComponent() override = default;

    explicit SoundComponent(shared::games::entity::IEntity &entity, const std::string &path,
        shared::games::components::SoundState state, shared::games::components::SoundVolume volume, bool loop, onChangeFunction onChange = nullptr);

    /**
     * @brief Get path of the sound
     *
     * @return Sound path
     */
    const std::string &getPath() const noexcept override;

    /**
     * @brief Get state of the sound
     *
     * @return Sound state
     */
    shared::games::components::SoundState &getState() noexcept override;

    /**
     * @brief Get volume of the sound
     *
     * @return Sound volume
     */
    shared::games::components::SoundVolume &getVolume() noexcept override;

    /**
     * @brief Get loop of the sound
     *
     * @return Sound loop
     */
    bool &getLoop() noexcept override;

    /**
     * @brief On state change event handler for the component
     *
     * @param ctx Context of the game
     * @param state New state of the sound
     */
    void onStateChange(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state) override;

    /**
     * @brief Set the state of the sound
     *
     * @param state New state of the sound
     */
    void setState(shared::games::components::SoundState state);

protected:
    std::string _path;
    shared::games::components::SoundState _state;
    shared::games::components::SoundVolume _volume;
    onChangeFunction _onChange;
    bool _loop;
};
