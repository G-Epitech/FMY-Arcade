/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CheckBox
*/

#pragma once

#include <memory>
#include <iostream>
#include "menu/entity/text/Text.hpp"
#include "menu/entity/texture/Texture.hpp"
#include "shared/types/Libraries.hpp"
#include "shared/graphics/events/IKeyEvent.hpp"

class CheckBox {
public:

    /**
     * @brief Construct a new CheckBox object
     * 
     * @param texture 
     * @param text 
     */
    CheckBox(std::shared_ptr<Texture> texture, std::shared_ptr<Text> text);

    /**
     * @brief Destructor for CheckBox object
     */
    ~CheckBox();

    /**
     * @brief Check the checkbox
     * 
     */
    void check();

    /**
     * @brief Uncheck the checkbox
     * 
     */
    void uncheck();

    /**
     * @brief Check if the checkbox is checked
     * 
     * @return true if checked
     * @return false if not checked
     */
    bool isChecked() const;

    /**
     * @brief Hover the checkbox
     * 
     */
    void hover();

    /**
     * @brief Unhover the checkbox
     * 
     */
    void unhover();

    /**
     * @brief Check if the checkbox is hovered
     * 
     * @return true if hovered
     * @return false if not hovered
     */
    bool isHovered() const;

    /**
     * @brief Check if the checkbox is hovered by the mouse
     * 
     * @param mousePos Mouse event
     * @return true if hovered
     * @return false if not hovered
     */
    bool isHovered(const shared::types::Vector2i &mousePos) const;

private:
    bool _checked;
    bool _hovered;
    std::shared_ptr<Text> _text;
    std::shared_ptr<Texture> _texture;
};
