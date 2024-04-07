/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ISoundComponent
*/

#pragma once

#include "IComponent.hpp"
#include "../IGame.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
    class ISoundComponent;

    /// @brief State of the sound
    typedef enum {
        /// @brief Sound is playing
        PLAY,
        /// @brief Sound is paused
        PAUSE,
        /// @brief Sound is stopped
        STOP
    } SoundState;

    /// @brief Volume of the sound
    typedef unsigned char SoundVolume;
}

/**
 * @brief Interface of a sound component
 * 
 */
class shared::games::components::ISoundComponent: public virtual IComponent {
public:
    virtual ~ISoundComponent() = default;

    /**
     * @brief Get path of the sound
     *
     * @return Sound path
     */
    virtual const std::string &getPath() const noexcept = 0;

    /**
     * @brief Get state of the sound
     *
     * @return Sound state
     */
    virtual SoundState &getState() noexcept = 0;

    /**
     * @brief Get volume of the sound
     *
     * @return Sound volume
     */
    virtual SoundVolume &getVolume() noexcept = 0;

    /**
     * @brief Get loop of the sound
     *
     * @return Sound loop
     */
    virtual bool &getLoop() noexcept = 0;

    /**
     * @brief On state change event handler for the component
     *
     * @param ctx Context of the game
     * @param state New state of the sound
     */
    virtual void onStateChange(std::shared_ptr<IGame> ctx, SoundState state) = 0;
};
