/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture
*/

#pragma once

#include <memory>
#include <iostream>
#include "shared/types/Libraries.hpp"
#include "shared/graphics/events/IKeyEvent.hpp"

using namespace shared::games;
using namespace shared::graphics;

class Texture {
public:

    /**
     * @brief Construct a new Texture object
     * 
     * @param texture Texture
     * @param binTileSize BinTileSize
     * @param origin Origin
     * @param size Size
     */
    Texture(std::shared_ptr<ITexture> texture, Vector2f binTileSize, Vector2u origin,
        Vector2u size, Vector2f position);

    /**
     * @brief Destructor for Texture object
     */
    ~Texture();

    /**
     * @brief Draw the checkbox
     * 
     * @param window Window to draw on
     */
    void draw(std::shared_ptr<IWindow> window);

    /**
     * @brief Set the Position object
     * 
     * @param position Position
     */
    void setOrigin(Vector2u origin);

private:
    std::shared_ptr<ITexture> _texture;
    Vector2f _binTileSize;
    Vector2u _origin;
    Vector2u _size;
    Vector2f _position;
};
