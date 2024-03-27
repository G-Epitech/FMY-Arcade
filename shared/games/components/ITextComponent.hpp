/*
** EPITECH PROJECT, 2024
** ITextComponent.hpp
** File description:
** ITextComponent class
*/

#pragma once

#include "IDisplayableComponent.hpp"
#include "../../types/Vector.hpp"
#include "../../types/Color.hpp"

namespace shared::games::components {
    class ITextComponent;

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
        std::string path;       // Path of the font
        types::Vector2u size;   // Font size
    } TextFontProps;

    typedef struct {
        std::string content;                // Content of the text
        TextAlign align;                    // Alignment of the text
        TextVerticalAlign verticalAlign;    // Vertical alignment of the text
        TextFontProps font;                 // Font of the text
        types::Color color;                 // Color of the text
    } TextProps;
}

class shared::games::components::ITextComponent : public virtual IDisplayableComponent {
public:
    virtual ~ITextComponent() = default;

    /**
     * @brief Get text props of the entity
     *
     * @return text props
     */
    virtual TextProps getTextProps() noexcept = 0;
};
