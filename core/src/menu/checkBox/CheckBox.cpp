/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

CheckBox::CheckBox(std::shared_ptr<Texture> texture, std::shared_ptr<Text> text) :
    _texture(texture), _text(text)
{
    this->_checked = false;
    this->_hovered = false;
    this->_texture->setOrigin({1, 0});
}

CheckBox::~CheckBox() {}

void CheckBox::check()
{
    this->_checked = true;
    this->_texture->setOrigin({0, 0});
}

void CheckBox::uncheck()
{
    this->_checked = false;
    this->_texture->setOrigin({1, 0});
}

bool CheckBox::isChecked() const
{
    return this->_checked;
}

void CheckBox::hover()
{
    this->_hovered = true;
    this->_text->setColor(Color{53, 186, 243, 255});
}

void CheckBox::unhover()
{
    this->_hovered = false;
    this->_text->setColor(Color{255, 255, 255, 255});
}

bool CheckBox::isHovered() const
{
    return this->_hovered;
}

bool CheckBox::isHovered(const Vector2f &mousePos) const
{
    auto pos = this->_text->getPosition();
    auto size = this->_text->getSize();

    if (mousePos.x >= pos.x && mousePos.x <= pos.x + size.x &&
        mousePos.y >= pos.y && mousePos.y <= pos.y + size.y)
        return true;
    return false;
}