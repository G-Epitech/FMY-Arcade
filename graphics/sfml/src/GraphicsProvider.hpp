/*
** EPITECH PROJECT, 2024
** GraphicsProvider.hpp
** File description:
** GraphicsProvider class
*/

#pragma once

#include "shared/graphics/IGraphicsProvider.hpp"

namespace sfml
{
    class GraphicsProvider;
}

class sfml::GraphicsProvider : public shared::graphics::IGraphicsProvider
{
public:
    GraphicsProvider() = default;
    ~GraphicsProvider() override = default;

    /**
     * @brief Get the manifest of the graphics library
     *
     * @return Manifest of the graphics library
     */
    const shared::graphics::GraphicsManifest &getManifest();

    /**
     * @brief Create a renderer object
     *
     * @param windowProps Properties to use to init the window
     * @return Created renderer object
     */
    std::unique_ptr<shared::graphics::IWindow> createWindow(const shared::graphics::WindowInitProps &windowProps) override;

    /**
     * @brief Create a sound object
     *
     * @param path Path of the sound file
     * @return Created sound object
     */
    std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;

    /**
     * @brief Create a texture object
     *
     * @param bin Path of the binary texture file
     * @param ascii Path of the ascii texture file
     * @return Created texture object
     */
    std::shared_ptr<shared::graphics::ITexture> createTexture(const std::string &bin, const std::string &ascii) override;

protected:
    static const shared::graphics::GraphicsManifest _manifest;
};
