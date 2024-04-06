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
    
    /// @brief Texture properties
    typedef struct {
        /// @brief Texture of the entity
        std::shared_ptr <ITexture> texture;
        /// @brief Size of a binary tile
        Vector2f binTileSize;
        /// @brief Origin of the texture
        Vector2u origin;
        /// @brief Size of the entity
        Vector2u size;
        /// @brief Position of the entity
        Vector2f position;
    } TextureProps;
}
