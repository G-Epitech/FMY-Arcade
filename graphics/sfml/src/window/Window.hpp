/*
** EPITECH PROJECT, 2024
** Window.hpp
** File description:
** Window class
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "shared/graphics/IWindow.hpp"
#include "EventsHandler.hpp"

namespace arcade::graphics::sfml::window {
    class Window;
}

class arcade::graphics::sfml::window::Window: public shared::graphics::IWindow {
public:
    explicit Window(const WindowInitProps &props);
    ~Window() override;

    /**
     * @brief Set the title of current window
     *
     * @param title Title of the window
     */
    void setTitle(const std::string &title) override;

    /**
     * @brief Set the size of the window
     *
     * @param size Size of the window
     */
    void setSize(Vector2u size) override;

    /**
     * @brief Get the size of the window
     *
     * @return Size of the window
     */
    Vector2u getSize() const override;

    /**
     * @brief Set the framerate Limit of the window
     *
     * @param fps Frame per seconds
     */
    void setFramerateLimit(unsigned int fps) override;

    /**
     * @brief Get the framerate Limit of the window
     *
     * @return Frame per seconds
     */
    unsigned int getFramerateLimit() const override;

    /**
     * @brief Set the mode of the window
     *
     * @param mode Mode to apply to the window
     */
    void setMode(IWindow::WindowMode mode) override;

    /**
     * @brief Get the mode of the window
     *
     * @return Mode of the window
     */
    WindowMode getMode() const override;

    /**
     * @brief Set the icon of the window
     *
     * @param icon Icon to use
     */
    void setIcon(const std::string &icon) override;

    /**
     * @brief Render the text with given properties
     *
     * @param props Properties of the entity to render
     */
    void render(const shared::graphics::TextProps &props) override;

    /**
     * @brief Render the entity with given properties
     *
     * @param props Properties of the entity to render
     */
    void render(const shared::graphics::TextureProps &props) override;

    /**
     * @brief Clear the content of the window
     *
     */
    void clear() override;

    /**
     * @brief Display the content of the window
     *
     */
    void display() override;

    /**
     * @brief Close the window
     *
     */
    void close() override;

    /**
     * @brief Check if the window is open
     *
     * @return Open status of the window
     */
    bool isOpen() const override;

    /**
     * @brief Get the events object
     *
     * @return Last events occurred
     * @warning Call successively this method will result in losing events
     * @note Call `A` return `eventsA` containing 2 events,
     * but make another call `B` (directly after call `A`) `eventsB`
     * will result to an empty vector
     */
    std::vector<shared::graphics::events::EventPtr> getEvents() override;

    /**
     * @brief Get the window object
     * @return Window object
     */
    sf::RenderWindow &getInnerWindow() noexcept;

    /**
     * @brief On resize event
     */
    void onResize();

private:
    Vector2u _getPixelSizeFromTiles(const Vector2u &size) const;

    EventsHandler       _eventsHandler;
    Renderer            _renderer;
    sf::RenderWindow    _window;
    std::string         _title;
    unsigned int        _fps;
    WindowMode          _mode;
    sf::Image           _icon;
    Vector2u            _size;
};
