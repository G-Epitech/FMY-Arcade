/*
** EPITECH PROJECT, 2024
** GraphicsProvider.hpp
** File description:
** GraphicsProvider class
*/

#pragma once

#include "shared/graphics/ITexture.hpp"
#include "shared/graphics/IGraphicsProvider.hpp"

namespace arcade::graphics::sdl2
{
    using namespace shared::graphics;

    class GraphicsProvider;
}

class arcade::graphics::sdl2::GraphicsProvider : public IGraphicsProvider
{
public:
    GraphicsProvider();
    ~GraphicsProvider() override = default;

    /**
     * @brief Get the manifest of the graphics library
     *
     * @return Manifest of the graphics library
     */
    const GraphicsManifest &getManifest() const noexcept override;

    /**
     * @brief Create a renderer object
     *
     * @param windowProps Properties to use to init the window
     * @return Created renderer object
     */
    std::unique_ptr<IWindow> createWindow(const IWindow::WindowInitProps &windowProps) override;

    /**
     * @brief Create a sound object
     *
     * @param path Path of the sound file
     * @return Created sound object
     */
    std::shared_ptr<ISound> createSound(const std::string &path) override;

    /**
     * @brief Create a texture object
     *
     * @param bin Path of the binary texture file
     * @param ascii Path of the ascii texture file
     * @return Created texture object
     */
    std::shared_ptr<ITexture> createTexture(const std::string &bin, const std::string &ascii) override;

    /**
     * @brief Create a font object
     *
     * @param path Path of the font file
     * @return Created font object
     */
    std::shared_ptr<IFont> createFont(const std::string &path) override;

protected:
    static const GraphicsManifest _manifest;
};
