/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IWindow
*/

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "events/IEvent.hpp"
#include "types/TextureProps.hpp"
#include "types/TextProps.hpp"

using namespace shared::types;

namespace shared::graphics {
    class IWindow;
}

/**
 * @brief Interface for the window object
 * 
 */
class shared::graphics::IWindow {
  public:
    virtual ~IWindow() = default;

    /**
     * @brief Window mode
     * 
     */
    typedef enum {
      /// @brief Windowed mode
      WINDOWED,
      /// @brief Fullscreen mode
      FULLSCREEN
    } WindowMode;

    /**
     * @brief Window initial properties
     * 
     */
    typedef struct {
      /// @brief Initial size of the window
      Vector2u size;
      /// @brief Initial mode of the window
      WindowMode mode;
      /// @brief Initial framerate of the window
      unsigned int fps;
      /// @brief Initial title of the window
      const std::string title;
      /// @brief Initial icon of the window
      const std::string icon;
    } WindowInitProps;

    /**
     * @brief Set the title of current window
     *
     * @param title Title of the window
     */
    virtual void setTitle(const std::string &title) = 0;

    /**
     * @brief Set the size of the window
     *
     * @param size Size of the window
     */
    virtual void setSize(Vector2u size) = 0;

    /**
     * @brief Get the size of the window
     *
     * @return Size of the window
     */
    virtual Vector2u getSize() const = 0;

    /**
     * @brief Set the framerate Limit of the window
     *
     * @param fps Frame per seconds
     */
    virtual void setFramerateLimit(unsigned int fps) = 0;

    /**
     * @brief Get the framerate Limit of the window
     *
     * @return Frame per seconds
     */
    virtual unsigned int getFramerateLimit() const = 0;

    /**
     * @brief Set the mode of the window
     *
     * @param mode Mode to apply to the window
     */
    virtual void setMode(WindowMode mode) = 0;

    /**
     * @brief Get the mode of the window
     *
     * @return Mode of the window
     */
    virtual WindowMode getMode(void) const = 0;

    /**
     * @brief Set the icon of the window
     *
     * @param icon Icon to use
     */
    virtual void setIcon(const std::string &icon) = 0;

    /**
     * @brief Render the texture of entity with given properties
     *
     * @param props Properties of the entity & texture to render
     */
    virtual void render(const TextureProps &props) = 0;

    /**
     * @brief Render the text of entity with given properties
     *
     * @param props Properties of the entity & text to render
     */
    virtual void render(const TextProps &props) = 0;

    /**
     * @brief Clear the content of the window
     *
     */
    virtual void clear(void) = 0;

    /**
     * @brief Display the content of the window
     *
     */
    virtual void display(void) = 0;

    /**
     * @brief Close the window
     *
     */
    virtual void close(void) = 0;

    /**
     * @brief Check if the window is open
     *
     * @return Open status of the window
     */
    virtual bool isOpen(void) const = 0;

    /**
     * @brief Get the events object
     *
     * @return Last events occured
     * @warning Call successively this method will result in losing events
     * @note Call `A` return `eventsA` containing 2 events,
     * but make another call `B` (directly after call `A`) `eventsB`
     * will result to an empty vector
     */
    virtual std::vector<events::EventPtr> getEvents(void) = 0;
};
