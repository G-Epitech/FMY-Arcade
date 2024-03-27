/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "loader/DLLoader.hpp"

int main(void) {
    DLLoader loader;

    try {
        loader.loadLibraries("./lib");
        std::cout << "Games libraries: " << loader.getGamesLibraries().size() << std::endl;
        std::cout << "Graphics libraries: " << loader.getGraphicsLibraries().size() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    auto graphics = loader.getGraphicsLibraries();
    auto provider = graphics[0];
    auto window = provider->createWindow({
        {1920, 1080},
         shared::graphics::IWindow::FULLSCREEN,
         60,
         "Notre putain de snake"
    });
    while (window->isOpen()) {
        window->getEvents();
    }
    return 0;
}
