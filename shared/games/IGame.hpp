/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** IGame
*/

#pragma once

#include <memory>
#include "IEntity.hpp"
#include "../types/types.hpp"
#include "types/GameManifest.hpp"

using namespace shared::types;

namespace shared::games
{
  class IGame;

  typedef unsigned long DeltaTime;
}

class shared::games::IGame
{
public:
  virtual ~IGame() = default;

  /**
   * @brief Compute the game each tick of the program
   *
   * @param dt Time since last tick (Time in `milliseconds`)
   */
  virtual void compute(DeltaTime dt) = 0;

  /**
   * @brief Manifest with informations of the game
   *
   */
  virtual const GameManifest &getManifest() const noexcept = 0;

  /**
   * @brief Number of tiles that represent the game
   * Tile size is managed by the renderer
   *
   */
  virtual const Vector2u getSize() const noexcept = 0;

  /**
   * @brief Get fps of the game
   *
   * @return The number of frame per seconds of the game
   */
  virtual const unsigned int getFps() const noexcept = 0;

  /**
   * @brief Get map of entities
   *
   */
  virtual const entity::EntitiesMap &getEntities(void) const = 0;

  /**
   * @brief Get entity by id
   *
   * @param id Id of the entity
   * @return The specific entity
   */
  virtual std::shared_ptr<entity::IEntity> getEntityById(const UUId &id) const = 0;
};
