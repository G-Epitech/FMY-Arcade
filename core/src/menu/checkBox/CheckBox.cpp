/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

CheckBox::CheckBox(const GameManifest manifest, std::shared_ptr<IGraphicsProvider> graphicsProvider,
    Vector2i position, unsigned int fontSize, Vector2u size) :
    _manifest(manifest)
{
    auto font = graphicsProvider->createFont("assets/menu/fonts/kenvector_future_thin.ttf");
    auto texture = graphicsProvider->createTexture("assets/menu/img/checkBox.png", "assets/menu/img/checkBox.ascii");

    this->_checked = false;
    this->_name = std::make_shared<Text>(font, fontSize, _manifest.name, TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{size.x - 1, size.y}, Vector2i{position.x + 2, position.y});
    this->_checkbox = std::make_shared<Texture>(texture, Vector2f{36, 38}, Vector2u{0, 0}, Vector2u{1, 1}, position);
}

CheckBox::~CheckBox() {}

void CheckBox::draw(std::shared_ptr<IWindow> &window)
{
    if (this->_checked)
        this->_checkbox->setOrigin({1, 0});
    else
        this->_checkbox->setOrigin({0, 0});
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