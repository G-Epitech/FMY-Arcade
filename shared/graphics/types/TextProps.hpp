/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** Text
*/

#pragma once

#include <string>
#include <memory>

#include "../IFont.hpp"
#include "../../types/Vector.hpp"
#include "../../types/Color.hpp"

using namespace shared::types;

namespace shared::graphics {
    typedef enum {
        LEFT,
        CENTER,
        RIGHT
    } TextAlign;

    typedef enum {
        BOTTOM,
        MIDDLE,
        TOP
    } TextVerticalAlign;

    typedef struct {
        std::shared_ptr<IFont> font;        // Font of the text
        unsigned int fontSize;              // Font size
        std::string content;                // Content of the text
        TextAlign align;                    // Alignment of the text
        TextVerticalAlign verticalAlign;    // Vertical alignment of the text
        types::Color color;                 // Color of the text
        Vector2u size;                      // Size of the entity
        Vector2f position;                  // Position of the entity
    } TextProps;
}
