/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** Texture
*/

#pragma once

#include <memory>

#include "../ITexture.hpp"
#include "../../types/types.hpp"

using namespace shared::types;

namespace shared::graphics
{
  typedef struct
  {
    const std::shared_ptr<ITexture> texture;  // Texture of the entity
    const Vector2f binTileSize;               // Size of a binary tile
    const Vector2u origin;                    // Origin of the texture
  } EntityTextureProps;

  typedef struct
  {
    EntityTextureProps textureProps; // Properties to use with the texture for the entity
    Vector2u size;                   // Size of the entity
    Vector2i position;               // Position of the entity
  } EntityProps;
}
