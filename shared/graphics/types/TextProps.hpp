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

    /// @brief Horizontal alignment of the text
    typedef enum {
        /// @brief Left alignment
        LEFT,
        /// @brief Center alignment
        CENTER,
        /// @brief Right alignment
        RIGHT
    } TextAlign;

    /// @brief Vertical alignment of the text
    typedef enum {
        /// @brief Bottom alignment
        BOTTOM,
        /// @brief Middle alignment
        MIDDLE,
        /// @brief Top alignment
        TOP
    } TextVerticalAlign;

    /// @brief Text properties
    typedef struct {
        /// @brief Font of the text
        std::shared_ptr<IFont> font;
        /// @brief Font size
        unsigned int fontSize;
        /// @brief Content of the text
        std::string content;
        /// @brief Horizontal alignment of the text
        TextAlign align;
        /// @brief Vertical alignment of the text
        TextVerticalAlign verticalAlign;
        /// @brief Color of the text
        types::Color color;
        /// @brief Size of the entity
        Vector2u size;
        /// @brief Position of the entity
        Vector2f position;
    } TextProps;
}
