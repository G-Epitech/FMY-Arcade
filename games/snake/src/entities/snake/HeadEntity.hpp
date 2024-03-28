/*
** EPITECH PROJECT, 2024
** HeadEntity.hpp
** File description:
** HeadEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

namespace arcade::games::snake {
    class HeadEntity;
}

class arcade::games::snake::HeadEntity : public common::AEntity {
public:
    ~HeadEntity() override = default;

    explicit HeadEntity();

protected:
    /**
     * @brief Get default texture props
     * @return Texture props
     */
    static shared::games::components::TextureProps _defaultTextureProps();

    shared::games::components::TextureProps _textureProps;
};
