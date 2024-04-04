/*
** EPITECH PROJECT, 2024
** Window.hpp
** File description:
** Window class
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer.hpp"
#include "EventsHandler.hpp"
#include "shared/graphics/IWindow.hpp"
#include "graphics/sdl2/sdl/window/Window.hpp"

namespace arcade::graphics::sdl2::window {
    using namespace arcade::graphics::sdl2::types;

    class Window;
}

class arcade::graphics::sdl2::window::Window: public shared::graphics::IWindow {
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
    sdl::Window &getInnerWindow() noexcept;

    /**
     * @brief Convert a position in pixels to a position in tiles
     * @return Converted position
     */
    Vector2i pixelsToTiles(const Vector2i &position) const;

    /**
     * @brief Convert a position in tiles to a position in pixels
     * @return Converted position
     */
    Vector2i tilesToPixels(const Vector2i &position) const;

    /**
     * @brief Convert a position in tiles to a position in pixels
     * @return Converted position
     */
    Vector2i tilesToPixels(const Vector2u &position) const;

    /**
     * @brief Get the size of a tile
     * @return Size of a tile
     */
    static const Vector2u  tileSize;

private:
    static Vector2u _getPixelSizeFromTiles(const Vector2u &size);

    /**
     * @brief Initialize the inner window
     * @param props Properties of the window
     */
    void _initInnerWindow(const WindowInitProps &props);

    EventsHandler       _eventsHandler;
    Renderer            _renderer;
    sdl::Window         _window;
    unsigned int        _fps;
    WindowMode          _mode;
    Vector2u            _size;
    bool                _isOpen;
};
