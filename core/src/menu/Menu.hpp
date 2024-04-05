/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#pragma once

#include <map>
#include "types/Stages.hpp"
#include "types/Providers.hpp"
#include "checkBox/CheckBox.hpp"
#include "exception/ArcadeError.hpp"

using namespace arcade::core;
using namespace shared::games;
using namespace shared::graphics;

class Menu {
    public:

        /**
         * @brief Construct a new Menu object
         * 
         * @param gameProviders GameProviders
         * @param graphicsProviders GraphicsProviders
         * @param gameProvider gameProvider
         * @param graphicsProvider graphicsProvider
         */
        Menu(GameProviders &gameProviders, GraphicsProviders &graphicsProviders, std::shared_ptr<IGameProvider> &gameProvider, std::shared_ptr<IGraphicsProvider> &graphicsProvider, SceneStage &sceneStage);
        ~Menu();

        /**
         * @brief Run the menu
         * 
         */
        void run();

    private:
        std::shared_ptr<IWindow> _window;
        SceneStage &_sceneStage;
        GameProviders &_gameProviders;
        GraphicsProviders &_graphicsProviders;
        std::shared_ptr<IGameProvider> &_gameProvider;
        std::shared_ptr<IGraphicsProvider> &_graphicsProvider;
        std::vector<std::shared_ptr<CheckBox>> _gamesCheckBoxes;
        std::vector<std::shared_ptr<Text>> _texts;
        std::vector<std::shared_ptr<Texture>> _textures;
        std::map<std::shared_ptr<CheckBox>, std::vector<std::shared_ptr<Text>>> _hiddenTexts;

        /**
         * @brief Initialize the window
         * 
         */
        void _initWindow();

        /**
         * @brief Render the menu
         * 
         */
        void _render();

        /**
         * @brief Handle events
         * 
         */
        void _handleEvents();

        /**
         * @brief Handle checkbox events
         * 
         * @param key Key event
         */
        void _handleKeyboardEvents(std::shared_ptr<events::IKeyEvent> key);

        /**
         * @brief Handle select upper checkbox
         * 
         */
        void _handleSelectUpperCheckBox();

        /**
         * @brief Handle select lower checkbox
         * 
         */
        void _handleSelectLowerCheckBox();

        /**
         * @brief Select the hovered game
         * 
         */
        void _selectGame();

        /**
         * @brief Exit the menu
         * 
         */
        void _exitWithNewGame();

        /**
         * @brief Exit and play old game
         * 
         */
        void _exitAndPlayOldGame();

        /**
         * @brief Initialize checkboxes
         * 
         */
        void _initCheckBoxes();

        /**
         * @brief Initialize textures
         * 
         */
        void _initTextures();

        /**
         * @brief Initialize hidden textures
         * 
         * @param gameManifest GameManifest
         * @param checkBox CheckBox
         */
        void _initHiddenTextures(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font);

        /**
         * @brief Initialize texts
         * 
         */
        void _initTexts();

        /**
         * @brief Define the previous selected game
         * 
         */
        void _previousSelectedGame();

        std::string _truncString(const std::string &str, int size);
};
