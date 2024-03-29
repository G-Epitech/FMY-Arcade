/*
** EPITECH PROJECT, 2024
** TextureComponent.hpp
** File description:
** TextureComponent class
*/

#pragma once

#include "shared/games/components/ITextureComponent.hpp"
#include "ADisplayableComponent.hpp"

namespace arcade::games::common::components {
    class TextureComponent;
}

class arcade::games::common::components::TextureComponent
        : public virtual shared::games::components::ITextureComponent, public ADisplayableComponent {
public:
    ~TextureComponent() override = default;

    explicit TextureComponent(shared::games::entity::IEntity &entity, Vector2u size, unsigned int zindex,
                              shared::games::components::TextureProps &props);

    /**
     * @brief Get texture properties
     *
     */
    shared::games::components::TextureProps &getTextureProps() noexcept override;

protected:
    shared::games::components::TextureProps _textureProps;
};
