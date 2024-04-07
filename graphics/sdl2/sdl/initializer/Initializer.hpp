/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Initializer.hpp
*/

#pragma once

namespace sdl {
    class Initializer;
}

class sdl::Initializer {
public:
    Initializer() = delete;
    ~Initializer() = delete;

    /**
     * @brief Initialize all SDL2 modules
     */
    static void init();

    /**
     * @brief Quit all SDL2 modules
     */
    static void quit();

private:
    /**
     * @brief Initialize SDL2 module
     */
    static void _initSDL();

    /**
     * @brief Quit SDL2 module
     */
    static void _quitSDL();

    /**
     * @brief Initialize SDL2_image module
     */
    static void _initIMG();

    /**
     * @brief Quit SDL2_image module
     */
    static void _quitIMG();

    /**
     * @brief Initialize SDL2_ttf module
     */
    static void _initTTF();

    /**
     * @brief Quit SDL2_ttf module
     */
    static void _quitTTF();
};
