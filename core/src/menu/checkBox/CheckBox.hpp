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

using namespace shared::graphics;

class CheckBox {
public:

    CheckBox(const std::string &name, std::shared_ptr<IGraphicsProvider> graphicsProvider,
        Vector2i position, unsigned int fontSize = 10, Vector2u size = {20, 1});

    /**
     * @brief Destructor for CheckBox object
     */
    ~CheckBox();

    /**
     * @brief Draw the checkbox
     * 
     * @param window Window to draw on
     */
    void draw(std::shared_ptr<IWindow> &window);

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

private:
    std::shared_ptr<Text> _name;
    std::shared_ptr<Texture> _checkbox;
    bool _checked;
    bool _hovered;
};
