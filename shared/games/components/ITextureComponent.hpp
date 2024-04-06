/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ITextureComponent
*/

#pragma once

#include "IDisplayableComponent.hpp"
#include "../IGame.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
    class ITextureComponent;

    /// @brief Texture sources
    typedef struct {
        /// @brief ASCII image representation path
        const std::string ascii;
        /// @brief Binary image path
        const std::string bin;
        /// @brief Size of the binary tile
        Vector2f binTileSize;
    } TextureSources;

    /// @brief Texture properties
    typedef struct {
        /// @brief Sources of textures
        TextureSources sources;
        /// @brief Size of the texture
        Vector2u origin;
    } TextureProps;
}

/**
 * @brief Interface of a texture component
 * 
 */
class shared::games::components::ITextureComponent : public virtual IDisplayableComponent {
public:
    virtual ~ITextureComponent() = default;

    /**
     * @brief Get texture properties
     *
     * @return TextureProps &Texture properties
     */
    virtual TextureProps &getTextureProps() noexcept = 0;
};
