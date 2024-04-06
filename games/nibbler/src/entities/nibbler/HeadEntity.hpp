/*
** EPITECH PROJECT, 2024
** HeadEntity.hpp
** File description:
** HeadEntity class
*/

#pragma once

#include <map>
#include "common/entity/AEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"
#include "common/components/SoundComponent.hpp"

namespace arcade::games::nibbler {
    class NibblerGame;

    class HeadEntity;
}

class arcade::games::nibbler::HeadEntity : public common::AEntity {
public:
    ~HeadEntity() override = default;

    /**
     * @brief Create the head of a nibbler
     */
    explicit HeadEntity();

    /**
     * @brief Update the position of the head of the nibbler
     */
    void forward();

    /**
     * @brief Direction of the nibbler head
     */
    Vector2i direction;

    /**
     * @brief Set the direction of the nibbler head
     * @param dir Direction
     */
    void setDirection(Vector2i dir);

    /**
     * @brief Position of the nibbler head
     */
    Vector2i position;

    /**
     * @brief Set the head at default position
     */
    void reset();

    /// @brief Map of sounds
    std::map<std::string, std::shared_ptr<arcade::games::common::components::SoundComponent>> sounds;

protected:
    /**
     * @brief Get default texture props
     * @return Texture props
     */
    static shared::games::components::TextureProps _defaultTextureProps();

    /**
     * @brief Represent the function that will be executed
     * when the nibbler will collide with an other collidable component
     * @param ctx Context of the game
     * @param target Target component
     */
    static void _onCollide(std::shared_ptr<shared::games::IGame> ctx,
                           std::shared_ptr<shared::games::components::ICollidableComponent> target);

    Vector2i _previousDirection;
    shared::games::components::TextureProps _textureProps;

    /**
     * @brief On sound state change event UP
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeUp(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event DOWN
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeDown(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event LEFT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeLeft(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event RIGHT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeRight(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event EAT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeEat(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event DEATH
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeDeath(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);
};
