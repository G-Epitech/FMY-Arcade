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
#include "shared/graphics/events/IMouseButtonEvent.hpp"

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

        /**
         * @brief Update the score
         * 
         * @param game Game
         */
        void updateScore(const std::shared_ptr<IGame>& game);

    private:

        typedef struct {
            std::string game;
            std::string player;
            int score;
        } Score;

        typedef enum {
            GAME,
            AUTHOR,
        } TextType;

        typedef enum {
            GAME_CHECKBOX,
            GRAPHICS_CHECKBOX
        } CheckBoxType;

        TextType _textType;
        CheckBoxType _checkBoxType;
        Score _score;
        std::vector<Score> _scores;
        SceneStage &_sceneStage;
        std::unique_ptr<IWindow> _window;
        GameProviders &_gameProviders;
        GraphicsProviders &_graphicsProviders;
        std::shared_ptr<IGameProvider> &_gameProvider;
        std::shared_ptr<IGraphicsProvider> &_graphicsProvider;
        std::vector<std::shared_ptr<CheckBox>> _gamesCheckBoxes;
        std::vector<std::shared_ptr<CheckBox>> _graphicsCheckBoxes;
        std::vector<std::shared_ptr<Text>> _texts;
        std::vector<std::shared_ptr<Texture>> _textures;
        std::map<std::shared_ptr<CheckBox>, std::vector<std::shared_ptr<Text>>> _hiddenTexts;
        std::map<std::shared_ptr<CheckBox>, std::vector<std::shared_ptr<Text>>> _hiddenAuthors;
        std::shared_ptr<IFont> _font;
        std::shared_ptr<Text> _nameField;
        std::shared_ptr<ISound> _music;

        /**
         * @brief Initialize the window
         * 
         */
        void _initWindow();

        /**
         * @brief Clear all lists
         * 
         */
        void _clearLists();

        /**
         * @brief Prevent the graphics provider
         * 
         */
        void _preventGraphicsProvider();

        /**
         * @brief Render the menu
         * 
         */
        void _render();

        /**
         * @brief Render the field name
         * 
         */
        void _renderField();

        /**
         * @brief Handle events
         * 
         */
        void _handleEvents();

        /**
         * @brief Handle mouse move events
         * 
         * @param mouse Mouse event
         */
        void _handleMouseMoveEvents(const std::shared_ptr<events::IMouseEvent>& mouse);

        /**
         * @brief Handle mouse button events
         * 
         * @param mouse Mouse event
         */
        void _handleMouseButtonEvents(const std::shared_ptr<events::IMouseButtonEvent>& mouse);

        /**
         * @brief Handle checkbox events
         * 
         * @param key Key event
         */
        void _handleKeyboardEvents(const std::shared_ptr<events::IKeyEvent>& key);

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
         * @brief Change the text type
         * 
         */
        void _changeGraphics(const std::shared_ptr<CheckBox>& checkBox);

        /**
         * @brief Initialize checkboxes for games
         * 
         */
        void _initCheckBoxesGames();

        /**
         * @brief Initialize checkboxes for graphics
         * 
         */
        void _initCheckBoxesGraphics();

        /**
         * @brief Initialize textures
         * 
         */
        void _initTextures();

        /**
         * @brief Initialize Background Music
         * 
         */
        void _initMusic();

        /**
         * @brief Initialize hidden textures
         * 
         * @param gameManifest GameManifest
         * @param checkBox CheckBox
         */
        void _initHiddenAuthors(const GameManifest &gameManifest, const std::shared_ptr<CheckBox>& checkBox, std::shared_ptr<IFont> font);

        /**
         * @brief Initialize hidden texts
         * 
         * @param gameManifest GameManifest
         * @param checkBox CheckBox
         * @param font IFont
         */
        void _initHiddenScore(const GameManifest &gameManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

        /**
         * @brief Initialize hidden score header
         * 
         * @param gameManifest GameManifest
         * @param checkBox CheckBox
         * @param font IFont
         */
        void _initHiddenScoreHeader(const GameManifest &gameManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

        /**
         * @brief Initialize hidden score board
         * 
         * @param gameManifest GameManifest
         * @param checkBox CheckBox
         * @param font IFont
         */
        void _initHiddenScoreBoard(const GameManifest &gameManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

        /**
         * @brief Initialize When No game found
         * 
         */
        void _initNoGameFound();

        /**
         * @brief Initialize hidden graphics
         * 
         * @param graphicsManifest GraphicsManifest
         * @param checkBox CheckBox
         */
        void _initHiddenGraphics(const GraphicsManifest &graphicsManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

        /**
         * @brief Initialize hidden graphics header
         * 
         * @param graphicsManifest GraphicsManifest
         * @param checkBox CheckBox
         */
        void _initHiddenGraphicsHeader(const GraphicsManifest &graphicsManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

        /**
         * @brief Initialize hidden graphics board
         * 
         * @param graphicsManifest GraphicsManifest
         * @param checkBox CheckBox
         */
        void _initHiddenGraphicsBoard(const GraphicsManifest &graphicsManifest, const std::shared_ptr<CheckBox>& checkBox, const std::shared_ptr<IFont>& font);

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

        /**
         * @brief Define the previous selected graphics
         * 
         */
        void _previousSelectedGraphics();

        /**
         * @brief Truncate a string
         * 
         * @param str 
         * @param size 
         * @return std::string 
         */
        static std::string _truncString(const std::string &str, int size);

        /**
         * @brief Sort the scores
         * 
         */
        void _sortScores();

        /**
         * @brief Get the game provider object
         * 
         * @param index 
         * @return std::shared_ptr<IGameProvider> 
         */
        std::shared_ptr<IGameProvider>& _getGameProvider(const unsigned char &index);

        /**
         * @brief Get the graphics provider object
         * 
         * @param index 
         * @return std::shared_ptr<IGraphicsProvider> 
         */
        std::shared_ptr<IGraphicsProvider>& _getGraphicsProvider(const unsigned char &index);

        /**
         * @brief Read the scores
         * 
         */
        void _readScores();

        /**
         * @brief Write the scores
         * 
         */
        void _writeScore();
};
