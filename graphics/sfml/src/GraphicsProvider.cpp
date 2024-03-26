/*
** EPITECH PROJECT, 2024
** GraphicsProvider.cpp
** File description:
** GraphicsProvider class
*/

#include "GraphicsProvider.hpp"
#include "window/Window.hpp"

const shared::graphics::GraphicsManifest sfml::GraphicsProvider::_manifest = {
        .name = "sfml",
        .description = "SFML Library",
        .version = "1.0",
        .authors = {{
                            .name = "tekmath",
                            .email = "matheo.coquet@epitech.eu",
                            .website = "thismath.com"
                    }}
};

const shared::graphics::GraphicsManifest &sfml::GraphicsProvider::getManifest() {
    return sfml::GraphicsProvider::_manifest;
}

std::unique_ptr<shared::graphics::IWindow>
sfml::GraphicsProvider::createWindow(const shared::graphics::WindowInitProps &windowProps) {
    std::unique_ptr<shared::graphics::IWindow> WindowObject = std::make_unique<Window>(windowProps.title,
                                                                                       windowProps.size);

    return WindowObject;
}
