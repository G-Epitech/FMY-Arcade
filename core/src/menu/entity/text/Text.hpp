/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Text
*/

#pragma once

#include <memory>
#include <iostream>
#include "shared/types/Libraries.hpp"
#include "shared/graphics/events/IKeyEvent.hpp"

using namespace shared::graphics;

class Text {
public:
    Text(std::shared_ptr<IFont> font,
        unsigned int fontSize,
        std::string content,
        TextAlign align,
        TextVerticalAlign verticalAlign,
        Color color,
        Vector2u size,
        Vector2i position);

    /**
     * @brief Destructor for Text object
     */
    ~Text();

    /**
     * @brief Draw the checkbox
     * 
     * @param window Window to draw on
     */
    void draw(std::shared_ptr<IWindow> window);

    /**
     * @brief Set the Color object
     * 
     * @param color 
     */
    void setColor(Color color);

private:
    std::shared_ptr<IFont> _font;
    unsigned int _fontSize;
    std::string _content;
    TextAlign _align;
    TextVerticalAlign _verticalAlign;
    Color _color;
    Vector2u _size;
    Vector2i _position;
};
