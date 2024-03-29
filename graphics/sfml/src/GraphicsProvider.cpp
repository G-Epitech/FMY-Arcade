/*
** EPITECH PROJECT, 2024
** GraphicsProvider.cpp
** File description:
** GraphicsProvider class
*/

#include <iostream>
#include "GraphicsProvider.hpp"
#include "window/Window.hpp"

using namespace shared::graphics;
using namespace arcade::graphics::sfml;

const shared::graphics::GraphicsManifest GraphicsProvider::_manifest = {
    .name = "sfml",
    .description = "SFML Library",
    .version = "1.0",
    .authors = {
        {
            .name = "tekmath",
            .email = "matheo.coquet@epitech.eu",
            .website = "thismath.com"
        },
        {
            .name = "Flavien Chenu",
            .email = "flavien.chenu@epitech.eu",
            .website = "https://github.com/flavien-chenu"
        }
    }
};

GraphicsProvider::GraphicsProvider() = default;

const GraphicsManifest &GraphicsProvider::getManifest() const noexcept {
    return GraphicsProvider::_manifest;
}

std::unique_ptr<IWindow> GraphicsProvider::createWindow(const IWindow::WindowInitProps &props) {
    return std::make_unique<Window>(props);
}

std::shared_ptr<ISound> GraphicsProvider::createSound(const std::string &path) {
    return nullptr;
}

std::shared_ptr<ITexture> GraphicsProvider::createTexture(const std::string &bin, const std::string &ascii) {
    return nullptr;
}

std::shared_ptr<IFont> GraphicsProvider::createFont(const std::string &path) {
    return nullptr;
}
