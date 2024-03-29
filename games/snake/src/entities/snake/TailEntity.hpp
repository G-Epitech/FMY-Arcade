/*
** EPITECH PROJECT, 2024
** TailEntity.hpp
** File description:
** TailEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

namespace arcade::games::snake {
    class TailEntity;
}

class arcade::games::snake::TailEntity : public common::AEntity {
public:
    ~TailEntity() override = default;

    explicit TailEntity();

protected:
    /**
     * @brief Get default texture props
     * @return Texture props
     */
    static shared::games::components::TextureProps _defaultTextureProps();

    shared::games::components::TextureProps _textureProps;
};
