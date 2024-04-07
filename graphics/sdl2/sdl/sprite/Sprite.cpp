/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

using namespace sdl;

Sprite::Sprite(): _position(0, 0), _textureRect(0, 0, 0, 0), _scale(1, 1){
}

Sprite::~Sprite() = default;

void Sprite::setPosition(const Vector2f &position)
{
    _position = position;
}

const Vector2f &Sprite::getPosition() const
{
    return _position;
}

void Sprite::setTextureRect(const Rect &textureRect)
{
    _textureRect = textureRect;
}

const Rect &Sprite::getTextureRect() const
{
    return _textureRect;
}

const Vector2f &Sprite::getScale() const
{
    return _scale;
}

void Sprite::setScale(const Vector2f &scale)
{
    _scale = scale;
}

FRect Sprite::getGlobalBounds() const
{
    return {
        _position.x,
        _position.y,
        static_cast<float>(_textureRect.w) * _scale.x,
        static_cast<float>(_textureRect.h) * _scale.y
    };
}
