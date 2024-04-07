/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ISound
*/

#pragma once

namespace shared::graphics {
    class ISound;
}

/**
 * @brief Interface for the sound object
 * 
 */
class shared::graphics::ISound {
public:
    virtual ~ISound() = default;

    /// @brief Sound volume
    typedef unsigned char SoundVolume;

    /// @brief Sound state
    typedef enum {
        /// @brief Sound is playing
        PLAY,
        /// @brief Sound is paused
        PAUSE,
        /// @brief Sound is stopped
        STOP
    } SoundState;

    /**
     * @brief Get the state of the sound
     *
     * @param state State of sound playing
     */
    virtual void setState(SoundState state) = 0;

    /**
     * @brief Get the state of the sound
     *
     * @return Current state of the sound
     */
    virtual SoundState getState() const = 0;

    /**
     * @brief Set the volume of the sound
     *
     * @param volume Volume of the sound
     */
    virtual void setVolume(SoundVolume volume) = 0;

    /**
     * @brief Get the volume of the sound
     *
     * @return Volume of the sound
     */
    virtual SoundVolume getVolume() const = 0;

    /**
     * @brief Set the loop state of sound
     *
     * @param loop Loop state of sound
     */
    virtual void setLoopState(bool loop) = 0;

    /**
     * @brief Get the loop state of sound
     *
     * @return Loop state of sound
     */
    virtual bool getLoopState(void) const = 0;
};
