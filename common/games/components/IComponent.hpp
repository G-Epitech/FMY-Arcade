/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IComponent
*/

#pragma once

#include "../IEntity.hpp"
#include "../../types/UUId.hpp"

namespace shared::games::components {
  typedef enum {
    DISPLAYABLE,
    SOUND,
    COLLIDABLE,
    POSITION,
    KEYBOARD
  } ComponentType;

  class IComponent;
}

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
   * @brief Get the uuid of component
   *
   * @return Component id
   */
  virtual const types::UUId &getId() const noexcept = 0;

  /**
   * @brief Get the parent entity of the component
   *
   * @return Entity of the component
   */
  virtual std::shared_ptr<entity::IEntity> getEntity() noexcept = 0;
};
