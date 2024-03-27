/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** Texture
*/

#pragma once

#include <memory>

#include "../ITexture.hpp"
#include "../../types/Vector.hpp"

using namespace shared::types;

namespace shared::graphics {
    typedef struct {
        std::shared_ptr <ITexture> texture;   // Texture of the entity
        Vector2f binTileSize;                 // Size of a binary tile
        Vector2u origin;                      // Origin of the texture
        Vector2u size;                              // Size of the entity
        Vector2i position;                          // Position of the entity
    } TextureProps;
}
