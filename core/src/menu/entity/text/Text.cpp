/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(std::shared_ptr<IFont> font, unsigned int fontSize, std::string content,
        TextAlign align, TextVerticalAlign verticalAlign, Color color, Vector2u size,
        Vector2i position) :
    font(font), fontSize(fontSize), content(content), align(align), verticalAlign(verticalAlign),
    color(color), size(size), position(position) {}

Text::~Text() {}

void Text::draw(std::shared_ptr<IWindow> &window)
{
    TextProps textProps = {
        .font = this->font,
        .fontSize = this->fontSize,
        .content = this->content,
        .align = this->align,
        .verticalAlign = this->verticalAlign,
        .color = this->color,
        .size = this->size,
        .position = this->position
    };

    window->render(textProps);
}
