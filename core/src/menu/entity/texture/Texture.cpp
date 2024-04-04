/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture
*/

#include "Texture.hpp"

Texture::Texture(std::shared_ptr<ITexture> texture, Vector2f binTileSize, Vector2u origin,
        Vector2u size, Vector2i position) : _texture(texture), _binTileSize(binTileSize), _origin(origin),
        _size(size), _position(position) {}

Texture::~Texture() {}

void Texture::draw(std::shared_ptr<IWindow> &window)
{
    TextureProps textureProps = {
        .texture = this->_texture,
        .binTileSize = this->_binTileSize,
        .origin = this->_origin,
        .size = this->_size,
        .position = this->_position
    };

    window->render(textureProps);
}

void Texture::setOrigin(Vector2u origin)
{
    this->_origin = origin;
}
