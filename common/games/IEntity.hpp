/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IEntity
*/

#pragma once

#include <map>
#include <memory>

#include "../types/UUId.hpp"

namespace shared::games
{
  class IGame;

  namespace entity
  {
    class IEntity;

    typedef std::map<types::UUId, std::shared_ptr<IEntity>> EntitiesMap;
  }

  namespace components
  {
    class IComponent;

    typedef std::map<types::UUId, std::shared_ptr<IComponent>> ComponentsMap;
  }
}

class shared::games::entity::IEntity
{
public:
  virtual ~IEntity() = default;

  /**
   * @brief Get the id of the entity
   *
   * @return Entity unique id
   */
  virtual const types::UUId &getId(void) const noexcept = 0;

  /**
   * @brief Get the components of the entity
   *
   * @return Components of the entity
   */
  virtual const components::ComponentsMap &getComponents(void) const noexcept = 0;
};
