/*
** EPITECH PROJECT, 2024
** Window.hpp
** File description:
** Window class
*/

#pragma once

#include "shared/graphics/window/IWindow.hpp"

using namespace shared::graphics;
namespace sfml {
    class Window;
}

class sfml::Window : public IWindow {
public:
    Window(std::string title, Vector2u size);
    ~Window() override = default;

    /**
     * @brief Set the title of current window
     *
     * @param title Title of the window
     */
    void setTitle(const std::string &title);

    /**
     * @brief Get the title of current window
     *
     * @return Title of the window
     */
    std::string getTitle() const;

    /**
     * @brief Set the size of the window
     *
     * @param size Size of the window
     */
    void setSize(Vector2u size);

    /**
     * @brief Get the size of the window
     *
     * @return Size of the window
     */
    Vector2u getSize() const;

    /**
     * @brief Set the framerate Limit of the window
     *
     * @param fps Frame per seconds
     */
    void setFramerateLimit(unsigned int fps);

    /**
     * @brief Get the framerate Limit of the window
     *
     * @return Frame per seconds
     */
    unsigned int getFramerateLimit() const;

    /**
     * @brief Set the mode of the window
     *
     * @param mode Mode to apply to the window
     */
    void setMode(shared::graphics::WindowMode mode);

    /**
     * @brief Get the mode of the window
     *
     * @return Mode of the window
     */
    WindowMode getMode() const;

    /**
     * @brief Set the icon of the window
     *
     * @param icon Icon to use
     */
    void setIcon(const std::string &icon);

    /**
     * @brief Get the icon of the window
     *
     * @return Icon object of the window
     */
    const std::string &getIcon() const;

    /**
     * @brief Render the entity with given properties
     *
     * @param props Properties of the entity to render
     */
    void render(const EntityProps &props);

    /**
     * @brief Clear the content of the window
     *
     */
    void clear();

    /**
     * @brief Display the content of the window
     *
     */
    void display();

    /**
     * @brief Close the window
     *
     */
    void close();

    /**
     * @brief Check if the window is open
     *
     * @return Open status of the window
     */
    bool isOpen() const;

    /**
     * @brief Get the events object
     *
     * @return Last events occured
     * @warning Call successively this method will result in losing events
     * @note Call `A` return `eventsA` containing 2 events,
     * but make another call `B` (directly after call `A`) `eventsB`
     * will result to an empty vector
     */
    std::vector<events::IEvent> getEvents() = 0;
};
