/*
** EPITECH PROJECT, 2024
** TextureComponent.cpp
** File description:
** TextureComponent class
*/

#include "TextureComponent.hpp"

using namespace arcade::games::common::components;

TextureComponent::TextureComponent(shared::games::entity::IEntity &entity,
                                   Vector2u size, unsigned int zindex,
                                   shared::games::components::TextureProps &props)
        : ADisplayableComponent(entity, size, zindex),
          _textureProps(props) {
    this->_type = shared::games::components::TEXTURE;
}

shared::games::components::TextureProps &TextureComponent::getTextureProps() noexcept {
    return this->_textureProps;
}
