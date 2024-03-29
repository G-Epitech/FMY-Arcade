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
        std::cout << "Games libraries:" << loader.getGamesLibraries().size() << std::endl;
        std::cout << "Graphics libraries:" << loader.getGraphicsLibraries().size() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    auto lib = loader.getGamesLibraries().at(0);
    auto manifest = lib->getManifest();
    std::cout << "Game name: " << manifest.name << std::endl;
    std::cout << "Game description: " << manifest.description << std::endl;
    std::cout << "Game version: " << manifest.version << std::endl;
    std::cout << "Game authors: " << manifest.authors[0].name << std::endl;

    auto game = lib->createInstance();

    auto last = std::chrono::high_resolution_clock::now();
    while (true) {
        auto current_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = duration_cast<std::chrono::duration<double, std::milli>>(current_time - last);
        game->compute(elapsed_time);
        last = current_time;
    }
    return 0;
}
