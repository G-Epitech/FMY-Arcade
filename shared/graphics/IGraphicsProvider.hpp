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
#include "IWindow.hpp"
#include "types/GraphicsManifest.hpp"

namespace shared::graphics {
    class IGraphicsProvider;
}

/**
 * @brief Interface for the graphics provider
 * 
 */
class shared::graphics::IGraphicsProvider {
public:
    virtual ~IGraphicsProvider() = default;

    /**
     * @brief Get the manifest of the graphics library
     *
     * @return Manifest of the graphics library
     */
    virtual const GraphicsManifest &getManifest(void) const noexcept = 0;

    /**
     * @brief Create a new window object
     *
     * @param windowProps Properties to use to init the window
     * @return Created window object
     */
    virtual std::unique_ptr<IWindow> createWindow(const IWindow::WindowInitProps &windowProps) = 0;

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
     * @param bin Path of the binary texture file
     * @param ascii Path of the ascii texture file
     * @return Created texture object
     */
    virtual std::shared_ptr<ITexture> createTexture(const std::string &bin, const std::string &ascii) = 0;

    /**
     * @brief Create a font object
     *
     * @param path Path of the font file
     * @return Created font object
     */
    virtual std::shared_ptr<IFont> createFont(const std::string &path) = 0;
};
