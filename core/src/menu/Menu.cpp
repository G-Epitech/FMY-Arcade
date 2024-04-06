/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "Menu.hpp"

Menu::Menu(GameProviders &gameProviders, GraphicsProviders &graphicsProviders,
    std::shared_ptr<IGameProvider> &gameProvider, std::shared_ptr<IGraphicsProvider> &graphicsProvider, arcade::core::SceneStage &sceneStage) :
    _gameProviders(gameProviders), _graphicsProviders(graphicsProviders),
    _gameProvider(gameProvider), _graphicsProvider(graphicsProvider), _sceneStage(sceneStage)
{
    this->_score.player = "";
    this->_score.score = 0;
    this->_readScores();
    this->_textType = GAME;
    this->_music = nullptr;
}

Menu::~Menu()
{
    this->_writeScore();
}

std::shared_ptr<IGameProvider> &Menu::_getGameProvider(const unsigned char &index)
{
    if (index > this->_gameProviders.size() - 1)
        throw ArcadeError("Invalid game provider index");
    auto it = this->_gameProviders.begin();
    std::advance(it, index);
    return it->second;
}

std::shared_ptr<IGraphicsProvider> &Menu::_getGraphicsProvider(const unsigned char &index)
{
    if (index > this->_graphicsProviders.size() - 1)
        throw ArcadeError("Invalid graphics provider index");
    auto it = this->_graphicsProviders.begin();
    std::advance(it, index);
    return it->second;
}

void Menu::_sortScores()
{
    std::sort(this->_scores.begin(), this->_scores.end(), [](const Score& a, const Score& b) {
        return a.score > b.score;
    });
}

std::string Menu::_truncString(const std::string &str, int size)
{
    auto strPadding = size - static_cast<int>(str.size());
    std::string newString = str.substr(0, size - 3);

    if (strPadding < 0)
        newString += "...";
    else
        newString = str;
    return newString;
}

void Menu::_initHiddenAuthors(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto authorNames = std::make_shared<Text>(font, 35, "Authors:", TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{8, 1}, Vector2f{26, 8});
    this->_hiddenAuthors[checkBox].push_back(authorNames);

    auto authors = gameManifest.authors;
    float index = 10.0;
    for (auto author : authors) {
        auto authorNameText = std::make_shared<Text>(font, 30, this->_truncString(author.name, 22) , TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index});
        auto authorMailText = std::make_shared<Text>(font, 30, this->_truncString(author.email, 22), TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index + 1});
        auto authorSiteText = std::make_shared<Text>(font, 30, this->_truncString(author.website, 22), TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index + 2});
        this->_hiddenAuthors[checkBox].push_back(authorNameText);
        this->_hiddenAuthors[checkBox].push_back(authorMailText);
        this->_hiddenAuthors[checkBox].push_back(authorSiteText);
        index += 4;
    }
}

void Menu::_initHiddenScoreHeader(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto truncatName = this->_truncString(gameManifest.name, 23);
    auto nameText = std::make_shared<Text>(font, 35, truncatName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 8});
    this->_hiddenTexts[checkBox].push_back(nameText);

    auto truncatDesc = this->_truncString(gameManifest.description, 23);
    auto descriptionText = std::make_shared<Text>(font, 30, truncatDesc, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 10});
    this->_hiddenTexts[checkBox].push_back(descriptionText);
}

void Menu::_initHiddenScoreBoard(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto scoreHI = std::make_shared<Text>(font, 30, "HI-SCORE", TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{8, 1}, Vector2f{26, 12});
    this->_hiddenTexts[checkBox].push_back(scoreHI);

    this->_sortScores();
    auto score = 0;
    for (auto &scoreElem : this->_scores) {
        if (scoreElem.game == gameManifest.name && scoreElem.score > score)
            score = scoreElem.score;
    }
    auto scoreString = std::to_string(score).substr(0, 5);
    while (scoreString.length() < 5)
        scoreString = "0" + scoreString;
    auto scoreText = std::make_shared<Text>(font, 30, scoreString, TextAlign::RIGHT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{14, 1}, Vector2f{34, 12});
    this->_hiddenTexts[checkBox].push_back(scoreText);

    float index = 14;
    int count = 0;
    for (auto &scoreElem : this->_scores) {
        if (scoreElem.game == gameManifest.name) {
            if (count > 7)
                break;
            auto playerName = scoreElem.player.empty() ? "Guest" : scoreElem.player;
            auto truncatPlayer = this->_truncString(playerName, 17);
            auto playerText = std::make_shared<Text>(font, 25, truncatPlayer, TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{17, 1}, Vector2f{26, index});
            auto scoreString = std::to_string(scoreElem.score).substr(0, 5);
            while (scoreString.length() < 5)
                scoreString = "0" + scoreString;
            auto scoreText = std::make_shared<Text>(font, 25, scoreString, TextAlign::RIGHT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{5, 1}, Vector2f{43, index});
            this->_hiddenTexts[checkBox].push_back(playerText);
            this->_hiddenTexts[checkBox].push_back(scoreText);
            index += 1;
            count += 1;
        }
    }
}

void Menu::_initHiddenScore(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    this->_initHiddenScoreHeader(gameManifest, checkBox, font);
    this->_initHiddenScoreBoard(gameManifest, checkBox, font);
}

void Menu::_initNoGameFound()
{
    auto font = this->_font;

    if (this->_gamesCheckBoxes.empty()) {
        auto noGames = std::make_shared<Text>(font, 35, "No games found", TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{2, 11});
        this->_texts.push_back(noGames);
    }
}

void Menu::_initCheckBoxesGames()
{
    std::shared_ptr<shared::graphics::ITexture> texture = nullptr;
    auto font = this->_font;
    float index = 9.0;
    int count = 0;

    try {
        texture = this->_graphicsProvider->createTexture("assets/menu/img/space-invader.png", "assets/menu/img/space-invader.ascii");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    for (auto gameProvider : this->_gameProviders) {
        if (count > 5)
            break;
        std::string truncatedName = gameProvider.second->getManifest().name.substr(0, 20);
        auto pos = 11 - (static_cast<float>(truncatedName.size()) / 2);
        auto textCheckBox = std::make_shared<Text>(font, 35, truncatedName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{static_cast<unsigned int>(truncatedName.size()), 1}, Vector2f{pos + 2, index});
        auto textureCheckBox = std::make_shared<Texture>(texture, Vector2f{360, 360}, Vector2u{0, 0}, Vector2u{1, 1}, Vector2f{pos, index});
        auto checkBox = std::make_shared<CheckBox>(textureCheckBox, textCheckBox);
        this->_texts.push_back(textCheckBox);
        this->_textures.push_back(textureCheckBox);
        this->_gamesCheckBoxes.push_back(checkBox);
        this->_initHiddenScore(gameProvider.second->getManifest(), checkBox, font);
        this->_initHiddenAuthors(gameProvider.second->getManifest(), checkBox, font);
        index += 1;
        count += 1;
    }
    this->_initNoGameFound();
}

void Menu::_initHiddenGraphicsHeader(const GraphicsManifest &graphicsManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto truncatName = this->_truncString(graphicsManifest.name, 23);
    auto nameText = std::make_shared<Text>(font, 35, truncatName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 8});
    this->_hiddenTexts[checkBox].push_back(nameText);

    auto truncatDesc = this->_truncString(graphicsManifest.description, 23);
    auto descriptionText = std::make_shared<Text>(font, 30, truncatDesc, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 10});
    this->_hiddenTexts[checkBox].push_back(descriptionText);
}

void Menu::_initHiddenGraphicsBoard(const GraphicsManifest &graphicsManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto authors = graphicsManifest.authors;
    float index = 12.0;
    for (auto author : authors) {
        auto authorNameText = std::make_shared<Text>(font, 25, this->_truncString(author.name, 23), TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, index});
        auto authorMailText = std::make_shared<Text>(font, 25, this->_truncString(author.email, 23), TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, index + 1});
        auto authorSiteText = std::make_shared<Text>(font, 25, this->_truncString(author.website, 23), TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, index + 2});
        this->_hiddenTexts[checkBox].push_back(authorNameText);
        this->_hiddenTexts[checkBox].push_back(authorMailText);
        this->_hiddenTexts[checkBox].push_back(authorSiteText);
        index += 4;
    }
}

void Menu::_initHiddenGraphics(const GraphicsManifest &graphicsManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    this->_initHiddenGraphicsHeader(graphicsManifest, checkBox, font);
    this->_initHiddenGraphicsBoard(graphicsManifest, checkBox, font);
}

void Menu::_initCheckBoxesGraphics()
{
    std::shared_ptr<shared::graphics::ITexture> texture = nullptr;
    auto font = this->_font;
    float index = 17.0;
    int count = 0;

    try {
        texture = this->_graphicsProvider->createTexture("assets/menu/img/space-invader.png", "assets/menu/img/space-invader.ascii");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    for (auto graphicsProvider : this->_graphicsProviders) {
        if (count > 5)
            break;
        std::string truncatedName = graphicsProvider.second->getManifest().name.substr(0, 20);
        auto pos = 11 - (static_cast<float>(truncatedName.size()) / 2);
        auto textCheckBox = std::make_shared<Text>(font, 35, truncatedName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{static_cast<unsigned int>(truncatedName.size()), 1}, Vector2f{pos + 2, index});
        auto textureCheckBox = std::make_shared<Texture>(texture, Vector2f{360, 360}, Vector2u{0, 0}, Vector2u{1, 1}, Vector2f{pos, index});
        auto checkBox = std::make_shared<CheckBox>(textureCheckBox, textCheckBox);
        this->_texts.push_back(textCheckBox);
        this->_textures.push_back(textureCheckBox);
        this->_graphicsCheckBoxes.push_back(checkBox);
        this->_initHiddenGraphics(graphicsProvider.second->getManifest(), checkBox, font);
        index += 1;
        count += 1;
    }
}

void Menu::_initTextures()
{
    try {
        auto backgroundTexture = this->_graphicsProvider->createTexture("assets/menu/img/background.png", "assets/menu/img/background.ascii");
        this->_textures.push_back(std::make_shared<Texture>(backgroundTexture, Vector2f{12, 12}, Vector2u{0, 0}, Vector2u{50, 25}, Vector2f{0, 0}));
        auto titleTexture = this->_graphicsProvider->createTexture("assets/menu/img/title.png", "assets/menu/img/title.ascii");
        this->_textures.push_back(std::make_shared<Texture>(titleTexture, Vector2f{17, 17}, Vector2u{0, 0}, Vector2u{31, 5}, Vector2f{10, 1}));
        auto middleTexture = this->_graphicsProvider->createTexture("assets/menu/img/middle.png", "assets/menu/img/middle.ascii");
        this->_textures.push_back(std::make_shared<Texture>(middleTexture, Vector2f{12, 12}, Vector2u{0, 0}, Vector2u{1, 15}, Vector2f{24, 7}));
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Menu::_initTexts()
{
    auto font = this->_graphicsProvider->createFont("assets/menu/fonts/arcade.ttf");

    this->_font = font;
    auto games = std::make_shared<Text>(font, 40, "Games", TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{24, 1}, Vector2f{1, 7});
    this->_texts.push_back(games);
    auto graphics = std::make_shared<Text>(font, 40, "Graphics", TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{24, 1}, Vector2f{1, 15});
    this->_texts.push_back(graphics);
}

void Menu::_clearLists()
{
    this->_hiddenAuthors.clear();
    this->_hiddenTexts.clear();
    this->_texts.clear();
    this->_textures.clear();
    this->_gamesCheckBoxes.clear();
    this->_graphicsCheckBoxes.clear();
}

void Menu::_preventGraphicsProvider()
{
    if (this->_graphicsProvider)
        return;
    if (this->_graphicsProviders.empty())
        throw ArcadeError("No graphics provider found");
    this->_graphicsProvider = this->_getGraphicsProvider(0);
    std::cout << "No graphics provider found, using default provider" << std::endl;
}

void Menu::_initMusic()
{
    this->_music = this->_graphicsProvider->createSound("assets/menu/sounds/music.wav");
    this->_music->setVolume(50);
    this->_music->setLoopState(true);
    this->_music->setState(ISound::SoundState::PLAY);
}

void Menu::_initWindow()
{
    IWindow::WindowInitProps windowInitProps {
        .size = {50, 25},
        .mode = IWindow::WindowMode::WINDOWED,
        .fps = 60,
        .title = "Menu",
        .icon = "assets/menu/img/icon.png"
    };

    try {
        this->_window = this->_graphicsProvider->createWindow(windowInitProps);
        this->_clearLists();
        this->_preventGraphicsProvider();
        this->_initTexts();
        this->_initTextures();
        this->_initCheckBoxesGames();
        this->_initCheckBoxesGraphics();
        this->_initMusic();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Menu::_handleSelectUpperCheckBox()
{
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox));
            if (index != 0)
                this->_gamesCheckBoxes.at(index - 1)->hover();
            else
                checkBox->hover();
            break;
        }
    }
    for (auto checkBox : this->_graphicsCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_graphicsCheckBoxes.begin(), std::find(this->_graphicsCheckBoxes.begin(), this->_graphicsCheckBoxes.end(), checkBox));
            if (index == 0) {
                if (!this->_gamesCheckBoxes.empty()) {
                    this->_gamesCheckBoxes.at(this->_gamesCheckBoxes.size() - 1)->hover();
                    this->_checkBoxType = GAME_CHECKBOX;
                } else {
                    checkBox->hover();
                }
            } else {
                this->_graphicsCheckBoxes.at(index - 1)->hover();
            }
            break;
        }
    }
}

void Menu::_handleSelectLowerCheckBox()
{
    for (auto checkBox : this->_graphicsCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_graphicsCheckBoxes.begin(), std::find(this->_graphicsCheckBoxes.begin(), this->_graphicsCheckBoxes.end(), checkBox));
            if (index != this->_graphicsCheckBoxes.size() - 1)
                this->_graphicsCheckBoxes.at(index + 1)->hover();
            else
                checkBox->hover();
            break;
        }
    }
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox));
            if (index == this->_gamesCheckBoxes.size() - 1) {
                this->_graphicsCheckBoxes.at(0)->hover();
                this->_checkBoxType = GRAPHICS_CHECKBOX;
            } else {
                this->_gamesCheckBoxes.at(index + 1)->hover();
            }
            break;
        }
    }
}

void Menu::_handleKeyboardEvents(std::shared_ptr<events::IKeyEvent> key)
{
    if (!key)
        return;
    auto type = key->getKeyType();
    auto code = key->getKeyCode();

    if (type == events::IKeyEvent::KeyType::ARROW) {
        if (code.arrow == events::IKeyEvent::ArrowCode::DOWN)
            this->_handleSelectLowerCheckBox();
        if (code.arrow == events::IKeyEvent::ArrowCode::UP)
            this->_handleSelectUpperCheckBox();
        if (code.arrow == events::IKeyEvent::ArrowCode::RIGHT)
            this->_textType = AUTHOR;
        if (code.arrow == events::IKeyEvent::ArrowCode::LEFT)
            this->_textType = GAME;
    }
    if (type == events::IKeyEvent::KeyType::CHAR) {
        if (code.character == '\n')
            this->_selectGame();
        else if (code.character == 27)
            this->_exitAndPlayOldGame();
        else if (code.character == 8)
            this->_score.player = this->_score.player.substr(0, this->_score.player.size() - 1);
        else if (this->_score.player.size() < 15 && code.character >= 33 && code.character <= 126)
            this->_score.player += code.character;
    }
}

void Menu::_selectGame()
{
    if (this->_checkBoxType == GAME_CHECKBOX) {
        for (auto checkBox : this->_gamesCheckBoxes) {
            if (checkBox->isHovered() && checkBox->isChecked())
                this->_exitWithNewGame();
            if (checkBox->isHovered())
                checkBox->check();
            else
                checkBox->uncheck();
        }
    } else {
        for (auto checkBox : this->_graphicsCheckBoxes) {
            if (checkBox->isHovered() && checkBox->isChecked())
                this->_changeGraphics(checkBox);
            if (checkBox->isHovered())
                checkBox->check();
            else
                checkBox->uncheck();
        }
    }
}

void Menu::_changeGraphics(std::shared_ptr<CheckBox> checkBox)
{
    auto index = std::distance(this->_graphicsCheckBoxes.begin(), std::find(this->_graphicsCheckBoxes.begin(), this->_graphicsCheckBoxes.end(), checkBox));
    auto graphicsProvider = this->_getGraphicsProvider(index);
    if (graphicsProvider != this->_graphicsProvider) {
        this->_graphicsProvider = graphicsProvider;
        this->_window->close();
        this->_initWindow();
    }
}

void Menu::_exitAndPlayOldGame()
{
    this->_sceneStage = RESUME;
    this->_window->close();
}

void Menu::_exitWithNewGame()
{
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isChecked()) {
            this->_gameProvider = this->_getGameProvider(std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox)));
            break;
        }
    }
    this->_sceneStage = NEWGAME;
    this->_window->close();
}

void Menu::_handleMouseMouveEvents(std::shared_ptr<events::IMouseEvent> mouse)
{
    if (!mouse)
        return;
    auto position = mouse->getPosition();
    std::shared_ptr<CheckBox> lastHoveredCheckBox = nullptr;
    bool hoveredAtLeastOne = false;

    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered())
            lastHoveredCheckBox = checkBox;
    }
    for (auto checkBox : this->_graphicsCheckBoxes) {
        if (checkBox->isHovered())
            lastHoveredCheckBox = checkBox;
    }
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered())
            checkBox->unhover();
        if (checkBox->isHovered(position)) {
            checkBox->hover();
            this->_checkBoxType = GAME_CHECKBOX;
            hoveredAtLeastOne = true;
        }
    }
    for (auto checkBox : this->_graphicsCheckBoxes) {
        if (checkBox->isHovered())
            checkBox->unhover();
        if (checkBox->isHovered(position)) {
            checkBox->hover();
            this->_checkBoxType = GRAPHICS_CHECKBOX;
            hoveredAtLeastOne = true;
        }
    }
    if (!hoveredAtLeastOne && lastHoveredCheckBox)
        lastHoveredCheckBox->hover();
}

void Menu::_handleMouseButtonEvents(std::shared_ptr<events::IMouseButtonEvent> mouse)
{
    if (!mouse)
        return;
    auto position = mouse->getPosition();
    auto button = mouse->getButton();
    auto move = std::dynamic_pointer_cast<events::IMouseEvent>(mouse);

    if (button != events::IMouseButtonEvent::MouseButton::LEFT)
        return;
    this->_handleMouseMouveEvents(move);
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered(position)) {
            this->_selectGame();
        }
    }
}

void Menu::_handleEvents()
{
    auto events = this->_window->getEvents();

    for (auto event : events) {
        auto type = event->getType();
        if (type == events::WINDOW_CLOSE) {
            this->_window->close();
            this->_sceneStage = EXIT;
        }
        if (type == events::KEY_PRESS) {
            auto key = std::dynamic_pointer_cast<events::IKeyEvent>(event);
            this->_handleKeyboardEvents(key);
        }
        if (type == events::MOUSE_MOVE) {
            auto mouse = std::dynamic_pointer_cast<events::IMouseEvent>(event);
            this->_handleMouseMouveEvents(mouse);
        }
        if (type == events::MOUSE_BTN_PRESS) {
            auto mouse = std::dynamic_pointer_cast<events::IMouseButtonEvent>(event);
            this->_handleMouseButtonEvents(mouse);
        }
    }
}

void Menu::_renderField()
{
    if (!this->_font)
        return;
    if (this->_score.player.empty()) {
        auto placeholder = std::make_shared<Text>(this->_font, 30, "Guest", TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{16, 1}, Vector2f{17, 23});
        this->_nameField = placeholder;
    } else {
        auto truncatName = this->_truncString(this->_score.player, 17);
        auto name = std::make_shared<Text>(this->_font, 35, truncatName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{16, 1}, Vector2f{17, 23});
        this->_nameField = name;
    }
    if (this->_nameField)
        this->_nameField->draw(this->_window);
}

void Menu::_render()
{
    this->_window->clear();
    for (auto texture : this->_textures) {
        texture->draw(this->_window);
    }
    for (auto text : this->_texts) {
        text->draw(this->_window);
    }
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered()) {
            if (this->_textType == GAME) {
                for (auto text : this->_hiddenTexts[checkBox]) {
                    text->draw(this->_window);
                }
            } else {
                for (auto text : this->_hiddenAuthors[checkBox]) {
                    text->draw(this->_window);
                }
            }
        }
    }
    for (auto checkBox : this->_graphicsCheckBoxes) {
        if (checkBox->isHovered()) {
            for (auto text : this->_hiddenTexts[checkBox]) {
                text->draw(this->_window);
            }
        }
    }
    this->_renderField();
    this->_window->display();
}

void Menu::_previousSelectedGame()
{
    this->_checkBoxType = GAME_CHECKBOX;
    if (this->_gamesCheckBoxes.empty())
        return;
    for (auto gameProvider : this->_gameProviders) {
        if (this->_gameProvider == gameProvider.second) {
            auto index = std::distance(this->_gameProviders.begin(), std::find(this->_gameProviders.begin(), this->_gameProviders.end(), gameProvider));
            auto checkBox = this->_gamesCheckBoxes.at(index);
            checkBox->check();
            checkBox->hover();
            return;
        }
    }
    if (!this->_gamesCheckBoxes.empty()) {
        this->_gamesCheckBoxes.at(0)->check();
        this->_gamesCheckBoxes.at(0)->hover();
    } else {
        std::cout << "Can't select a previous game, no games found" << std::endl;
    }
}

void Menu::_previousSelectedGraphics()
{
    if (this->_graphicsCheckBoxes.empty())
        return;
    for (auto graphicsProvider : this->_graphicsProviders) {
        if (this->_graphicsProvider == graphicsProvider.second) {
            auto index = std::distance(this->_graphicsProviders.begin(), std::find(this->_graphicsProviders.begin(), this->_graphicsProviders.end(), graphicsProvider));
            auto checkBox = this->_graphicsCheckBoxes.at(index);
            checkBox->check();
            if (this->_gamesCheckBoxes.empty()) {
                checkBox->hover();
                this->_checkBoxType = GRAPHICS_CHECKBOX;
            }
            return;
        }
    }
    if (!this->_graphicsCheckBoxes.empty()) {
        this->_graphicsCheckBoxes.at(0)->check();
        if (this->_gamesCheckBoxes.empty()) {
            _graphicsCheckBoxes.at(0)->hover();
            this->_checkBoxType = GRAPHICS_CHECKBOX;
        }
    } else {
        std::cout << "Can't select a previous graphics, no graphics found" << std::endl;
    }
}

void Menu::run()
{
    this->_sceneStage = MENU;
    this->_initWindow();
    this->_previousSelectedGame();
    this->_previousSelectedGraphics();
    if (!this->_window)
        throw ArcadeError("Can't create window");
    while (this->_window->isOpen()) {
        this->_handleEvents();
        this->_render();
    }
    if (this->_music)
        this->_music->setState(ISound::SoundState::STOP);
}

void Menu::_readScores()
{
    std::ifstream scoreFile("./scores.txt");

    if (!scoreFile.is_open()) {
        std::cout << "Can't open scores file" << std::endl;
        return;
    }

    std::string line;
    std::getline(scoreFile, line);

    while (std::getline(scoreFile, line)) {
        std::stringstream ss(line);
        Score score;
        ss >> score.game >> score.player >> score.score;
        this->_scores.push_back(score);
    }
    scoreFile.close();
}

void Menu::_writeScore()
{
    std::ofstream scoreFile("./scores.txt");

    if (!scoreFile.is_open()) {
        std::cout << "Can't open scores file" << std::endl;
        return;
    }

    scoreFile << "Game\tPlayer\tScore" << std::endl;
    auto player = this->_score.player.empty() ? "Guest" : this->_score.player;
    for (auto score : this->_scores) {
        scoreFile << score.game << "\t" << player << "\t" << score.score << std::endl;
    }
    scoreFile.close();
}

void Menu::updateScore(std::shared_ptr<IGame> game)
{
    this->_score.game = game->getManifest().name;
    this->_score.score = game->getScore();

    std::cout << "Player Score: " << this->_score.score << std::endl;
    for (auto &score : this->_scores) {
        auto playerName = this->_score.player.empty() ? "Guest" : this->_score.player;
        auto scoreName = score.player.empty() ? "Guest" : score.player;
        if (score.game == this->_score.game && scoreName == playerName) {
            if (score.score < this->_score.score)
                score.score = this->_score.score;
            return;
        }
    }
    this->_scores.push_back(this->_score);
}
