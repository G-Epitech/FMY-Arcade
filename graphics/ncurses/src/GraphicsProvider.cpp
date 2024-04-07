/*
** EPITECH PROJECT, 2024
** GraphicsProvider.cpp
** File description:
** GraphicsProvider class
*/

#include <iostream>
#include "GraphicsProvider.hpp"
#include "utils/compiler.hpp"
#include "window/Window.hpp"
#include "font/Font.hpp"
#include "sound/Sound.hpp"
#include "texture/Texture.hpp"

using namespace shared::graphics;
using namespace arcade::graphics::ncurses;

const shared::graphics::GraphicsManifest GraphicsProvider::_manifest = {
    .name = "ncurses",
    .description = "NCURSES Library",
    .version = "1.0",
    .authors = {
        {
            .name = "Yann Masson",
            .email = "yann.masson@epitech.eu",
            .website = "yannmasson.fr"
        }
    }
};

GraphicsProvider::GraphicsProvider() = default;

const GraphicsManifest &GraphicsProvider::getManifest() const noexcept {
    return GraphicsProvider::_manifest;
}

std::unique_ptr<IWindow> GraphicsProvider::createWindow(const IWindow::WindowInitProps &props) {
    return std::make_unique<window::Window>(props);
}

std::shared_ptr<ISound> GraphicsProvider::createSound(const std::string &path) {
    return std::make_shared<sound::Sound>(path);
}

std::shared_ptr<ITexture> GraphicsProvider::createTexture(unused const std::string &bin, const std::string &ascii) {
    return std::make_shared<texture::Texture>(ascii);
}

std::shared_ptr<IFont> GraphicsProvider::createFont(const std::string &path) {
    return std::make_shared<font::Font>(path);
}
