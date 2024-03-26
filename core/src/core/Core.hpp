/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#pragma once

#include "types/Providers.hpp"

class Core {
    public:
        Core(GameProviders gameProviders, GraphicsProviders graphicsProviders);
        ~Core();

        /**
         * @brief Run the core
         * 
         */
        void run();


    protected:
    private:
        std::shared_ptr<shared::games::IGame> _game;
        std::shared_ptr<shared::graphics::IWindow> _window;
        std::shared_ptr<shared::games::IGameProvider> _gameProvider;
        std::shared_ptr<shared::graphics::IGraphicsProvider> _graphicsProvider;
        GameProviders _gameProviders;
        GraphicsProviders _graphicsProviders;

        /**
         * @brief Initialize the core
         * 
         */
        void _setup();

        /**
         * @brief Render all entities
         * 
         */
        void _renderEntities();
};
