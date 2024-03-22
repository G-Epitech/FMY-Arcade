/*
** EPITECH PROJECT, 2024
** arcade-shared [WSL: Ubuntu-22.04]
** File description:
** ADisplaybleComponent
*/

#pragma once

#include "IPositionComponent.hpp"
#include "../IGame.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
  class IDisplayableComponent;

  typedef struct
  {
    const std::string ascii; // ASCII image representation path
    const std::string bin;   // Binary image path
    Vector2f binTileSize;    // Size of the binary tile
  } TextureSources;

  typedef struct
  {
    TextureSources sources; // Sources of textures
    Vector2u origin;        // Origin of the texture
  } TextureProps;
}

class shared::games::components::IDisplayableComponent: public virtual IPositionComponent
{
public:
  virtual ~IDisplayableComponent() = default;

    /**
   * @brief Get size of the entity (tiles)
   *
   */
  virtual Vector2u &getSize(void) noexcept = 0;

  /**
   * @brief Get Z index that is usefull for display prioroty
   *
   */
  virtual unsigned int &getZIndex(void) noexcept = 0;

  /**
   * @brief Get texture properties
   *
   */
  virtual TextureProps &getTextureProps(void) noexcept = 0;

  /**
   * @brief On click event handler for the entity
   * @param ctx Context of the game
   */
  virtual void onMousePress(game::UniqueGame &ctx) = 0;

  /**
   * @brief On release event handler for the entity
   * @param ctx Context of the game
   */
  virtual void onMouseRelease(game::UniqueGame &ctx) = 0;

  /**
   * @brief On hover event handler for the entity
   * @param ctx Context of the game
   */
  virtual void onMouseHover(game::UniqueGame &ctx) = 0;
};
