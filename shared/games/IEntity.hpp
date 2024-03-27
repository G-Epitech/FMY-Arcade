/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IEntity
*/

#pragma once

#include <vector>
#include <memory>

namespace shared::games
{
  class IGame;

  namespace entity
  {
    class IEntity;

    typedef std::shared_ptr<IEntity> EntityPtr;
    typedef std::vector<EntityPtr> EntitiesMap;
  }

  namespace components
  {
    class IComponent;

    typedef std::vector<std::shared_ptr<IComponent>> ComponentsMap;
  }
}

class shared::games::entity::IEntity
{
public:
  virtual ~IEntity() = default;

  /**
   * @brief Get the components of the entity
   *
   * @return Components of the entity
   */
  virtual const components::ComponentsMap &getComponents(void) const noexcept = 0;
};
