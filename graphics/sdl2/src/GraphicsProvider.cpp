/*
** EPITECH PROJECT, 2024
** GraphicsProvider.cpp
** File description:
** GraphicsProvider class
*/

#include <iostream>
#include "GraphicsProvider.hpp"
#include "window/Window.hpp"
#include "font/Font.hpp"
#include "sound/Sound.hpp"
#include "texture/Texture.hpp"

using namespace arcade::graphics::sdl2;

const GraphicsManifest GraphicsProvider::_manifest = {
    .name = "sdl2",
    .description = "SDL2 Library",
    .version = "1.0",
    .authors = {
        {
            .name = "Flavien Chenu",
            .email = "flavien.chenu@epitech.eu",
            .website = "https://github.com/flavien-chenu"
        }
    }
};

GraphicsProvider::GraphicsProvider() = default;

GraphicsProvider::~GraphicsProvider() {
    sdl::Initializer::quit();
}

const shared::graphics::GraphicsManifest &GraphicsProvider::getManifest() const noexcept {
    return GraphicsProvider::_manifest;
}

std::unique_ptr<IWindow> GraphicsProvider::createWindow(const IWindow::WindowInitProps &props) {
    return std::make_unique<window::Window>(props);
}

std::shared_ptr<ISound> GraphicsProvider::createSound(const std::string &path) {
    return std::make_shared<sound::Sound>(path);
}

std::shared_ptr<ITexture>GraphicsProvider::createTexture(const std::string &bin, const std::string &ascii) {
    return std::make_shared<texture::Texture>(bin);
}

std::shared_ptr<IFont> GraphicsProvider::createFont(const std::string &path) {
    return std::make_shared<font::Font>(path);
}
