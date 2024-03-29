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

    typedef struct {
        const std::string ascii; // ASCII image representation path
        const std::string bin;   // Binary image path
        Vector2f binTileSize;    // Size of the binary tile
    } TextureSources;

    typedef struct {
        TextureSources sources; // Sources of textures
        Vector2u origin;        // Origin of the texture
    } TextureProps;
}

class shared::games::components::ITextureComponent : public virtual IDisplayableComponent {
public:
    virtual ~ITextureComponent() = default;

    /**
     * @brief Get texture properties
     *
     */
    virtual TextureProps &getTextureProps() noexcept = 0;
};
