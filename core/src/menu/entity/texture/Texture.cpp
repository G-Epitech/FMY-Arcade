/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture
*/

#include "Texture.hpp"

#include <utility>

Texture::Texture(std::shared_ptr<ITexture> texture, Vector2f binTileSize, Vector2u origin,
        Vector2u size, Vector2f position) : _texture(std::move(texture)), _binTileSize(binTileSize), _origin(origin),
        _size(size), _position(position) {}

Texture::~Texture() = default;

void Texture::draw(std::unique_ptr<IWindow> &window)
{
    TextureProps textureProps = {
        .texture = this->_texture,
        .binTileSize = this->_binTileSize,
        .origin = this->_origin,
        .size = this->_size,
        .position = this->_position
    };

    try {
        window->render(textureProps);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Texture::setOrigin(Vector2u origin)
{
    this->_origin = origin;
}
