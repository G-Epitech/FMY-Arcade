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
}

/**
 * @brief Interface of a text component
 * 
 */
class shared::games::components::ITextComponent : public virtual IDisplayableComponent {
public:

    /// @brief Horizontal text alignment
    typedef enum {
        /// @brief Align text to the left
        LEFT,
        /// @brief Align text to the center
        CENTER,
        /// @brief Align text to the right
        RIGHT
    } TextAlign;

    /// @brief Vertical text alignment
    typedef enum {
        /// @brief Align text to the bottom
        BOTTOM,
        /// @brief Align text to the middle
        MIDDLE,
        /// @brief Align text to the top
        TOP
    } TextVerticalAlign;

    /// @brief Font properties
    typedef struct {
        /// @brief Path of the font
        std::string path;
        /// @brief Size of the font
        unsigned int size;
    } TextFontProps;

    /// @brief Text properties
    typedef struct {
        /// @brief Content of the text
        std::string content;
        /// @brief Horizontal alignment of the text
        TextAlign align;
        /// @brief Vertical alignment of the text
        TextVerticalAlign verticalAlign;
        /// @brief Font of the text
        TextFontProps font;
        /// @brief Color of the text
        types::Color color;
    } TextProps;

    virtual ~ITextComponent() = default;

    /**
     * @brief Get text props of the entity
     *
     * @return text props
     */
    virtual TextProps getTextProps() noexcept = 0;
};
