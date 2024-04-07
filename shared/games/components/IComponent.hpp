/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IComponent
*/

#pragma once

#include "../IEntity.hpp"

namespace shared::games::components {

    /// @brief Enum of component types
    typedef enum {
        /// @brief Component type for a texture
        TEXTURE,
        /// @brief Component type for a text
        TEXT,
        /// @brief Component type for a displayable
        DISPLAYABLE,
        /// @brief Component type for a sound
        SOUND,
        /// @brief Component type for a collidable
        COLLIDABLE,
        /// @brief Component type for a positionable
        POSITIONABLE,
        /// @brief Component type for a keyboard
        KEYBOARD
    } ComponentType;

    class IComponent;
}

/**
 * @brief Interface of a component
 * 
 */
class shared::games::components::IComponent {
public:
    virtual ~IComponent() = default;

    /**
     * @brief Get the type of the component
     *
     * @return Type of the component
     */
    virtual const ComponentType getType() const noexcept = 0;

    /**
     * @brief Get the parent entity of the component
     *
     * @return Entity of the component
     */
    virtual const entity::IEntity &getEntity() noexcept = 0;
};
