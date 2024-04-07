/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Text
*/

#include "Text.hpp"

#include <utility>

Text::Text(std::shared_ptr<IFont> font, unsigned int fontSize, std::string content,
        TextAlign align, TextVerticalAlign verticalAlign, Color color, Vector2u size,
        Vector2f position) :
    _font(std::move(font)), _fontSize(fontSize), _content(std::move(content)), _align(align), _verticalAlign(verticalAlign),
    _color(color), _size(size), _position(position) {}

Text::~Text() = default;

void Text::draw(std::unique_ptr<IWindow> &window)
{
    TextProps textProps = {
        .font = this->_font,
        .fontSize = this->_fontSize,
        .content = this->_content,
        .align = this->_align,
        .verticalAlign = this->_verticalAlign,
        .color = this->_color,
        .size = this->_size,
        .position = this->_position
    };

    try {
        window->render(textProps);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Text::setColor(Color color)
{
    this->_color = color;
}

Vector2u Text::getSize() const
{
    return this->_size;
}

Vector2f Text::getPosition() const
{
    return this->_position;
}
