/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IRendererFactory
*/

#pragma once

#include <memory>

#include "ISound.hpp"
#include "ITexture.hpp"
#include "window/IWindow.hpp"

namespace shared::graphics {
  class IGraphicsFactory;
}

class shared::graphics::IGraphicsFactory {
  public:
    virtual ~IGraphicsFactory() = default;

    /**
     * @brief Create a renderer object
     *
     * @param windowProps Properties to use to init the window
     * @return Created renderer object
     */
    virtual std::unique_ptr<IWindow> createWindow(const WindowInitProps &windowProps) = 0;

    /**
     * @brief Create a sound object
     *
     * @param path Path of the sound file
     * @return Created sound object
     */
    virtual std::shared_ptr<ISound> createSound(const std::string &path) = 0;

    /**
     * @brief Create a texture object
     *
     * @param path Path of the texture file
     * @return Created texture object
     */
    virtual std::shared_ptr<ITexture> createTexture(const std::string &path) = 0;

    /**
     * @brief Create a window icon object
     *
     * @param path Path of the window icon file
     * @return Created window icon object
     */
    virtual std::unique_ptr<IWindowIcon> createWindowIcon(const std::string &path) = 0;
};
