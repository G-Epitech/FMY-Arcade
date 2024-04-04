/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

CheckBox::CheckBox(const std::string &name, std::shared_ptr<IGraphicsProvider> graphicsProvider,
    Vector2i position, unsigned int fontSize, Vector2u size)
{
    auto font = graphicsProvider->createFont("assets/menu/fonts/kenvector_future_thin.ttf");
    auto texture = graphicsProvider->createTexture("assets/menu/img/checkBox.png", "assets/menu/img/checkBox.ascii");

    this->_checked = false;
    this->_hovered = false;
    this->_name = std::make_shared<Text>(font, fontSize, name, TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{0, 0, 0, 255}, Vector2u{size.x - 1, size.y}, Vector2i{position.x + 2, position.y});
    this->_checkbox = std::make_shared<Texture>(texture, Vector2f{38, 36}, Vector2u{0, 0}, Vector2u{1, 1}, position);
}

CheckBox::~CheckBox() {}

void CheckBox::draw(std::shared_ptr<IWindow> &window)
{
    if (this->_checked)
        this->_checkbox->setOrigin({1, 0});
    else
        this->_checkbox->setOrigin({0, 0});
    if (this->_hovered)
        this->_name->setColor(Color{53, 186, 243, 255});
    else
        this->_name->setColor(Color{0, 0, 0, 255});
    this->_checkbox->draw(window);
    this->_name->draw(window);
}

void CheckBox::check()
{
    this->_checked = true;
}

void CheckBox::uncheck()
{
    this->_checked = false;
}

bool CheckBox::isChecked() const
{
    return this->_checked;
}

void CheckBox::hover()
{
    this->_hovered = true;
}

void CheckBox::unhover()
{
    this->_hovered = false;
}

bool CheckBox::isHovered() const
{
    return this->_hovered;
}