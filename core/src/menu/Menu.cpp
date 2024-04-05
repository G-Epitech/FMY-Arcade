/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include <iostream>
#include "Menu.hpp"

Menu::Menu(GameProviders &gameProviders, GraphicsProviders &graphicsProviders,
    std::shared_ptr<IGameProvider> &gameProvider, std::shared_ptr<IGraphicsProvider> &graphicsProvider, arcade::core::SceneStage &sceneStage) :
    _gameProviders(gameProviders), _graphicsProviders(graphicsProviders),
    _gameProvider(gameProvider), _graphicsProvider(graphicsProvider), _sceneStage(sceneStage) {}

Menu::~Menu() {}

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

void Menu::_initHiddenTextures(const GameManifest &gameManifest, std::shared_ptr<CheckBox> checkBox, std::shared_ptr<IFont> font)
{
    auto truncatName = this->_truncString(gameManifest.name, 23);
    auto nameText = std::make_shared<Text>(font, 11, truncatName, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 8});
    this->_hiddenTexts[checkBox].push_back(nameText);

    std::string truncatDesc = this->_truncString(gameManifest.description, 23);
    auto descriptionText = std::make_shared<Text>(font, 9, truncatDesc, TextAlign::CENTER, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{23, 1}, Vector2f{25, 10});
    this->_hiddenTexts[checkBox].push_back(descriptionText);

    int score = 154;
    auto scoreString = std::to_string(score);
    while (scoreString.length() < 5)
        scoreString = "0" + scoreString;
    auto scoreText = std::make_shared<Text>(font, 10, scoreString, TextAlign::RIGHT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{14, 1}, Vector2f{34, 12});
    this->_hiddenTexts[checkBox].push_back(scoreText);

    auto authors = gameManifest.authors;
    float index = 15.0;
    for (auto author : authors) {
        auto authorNameText = std::make_shared<Text>(font, 7, this->_truncString(author.name, 22) , TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index});
        auto authorMailText = std::make_shared<Text>(font, 7, this->_truncString(author.email, 22), TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index + 1});
        auto authorSiteText = std::make_shared<Text>(font, 7, this->_truncString(author.website, 22), TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{22, 1}, Vector2f{27, index + 2});
        this->_hiddenTexts[checkBox].push_back(authorNameText);
        this->_hiddenTexts[checkBox].push_back(authorMailText);
        this->_hiddenTexts[checkBox].push_back(authorSiteText);
        index += 4;
    }
}

void Menu::_initCheckBoxes()
{
    auto texture = this->_graphicsProvider->createTexture("assets/menu/img/space-invader.png", "assets/menu/img/space-invader.ascii");
    auto font = this->_graphicsProvider->createFont("assets/menu/fonts/arcade.ttf");
    float index = 8.0;

    for (auto gameProvider : this->_gameProviders) {
        auto marginRight = 23 - static_cast<float>(gameProvider.second->getManifest().name.size());
        std::string truncatedName = gameProvider.second->getManifest().name.substr(0, 20);
        if (marginRight < 0) {
            truncatedName += "...";
            marginRight = 0;
        } else {
            truncatedName = gameProvider.second->getManifest().name;
            marginRight -= 3;
        }
        auto textCheckBox = std::make_shared<Text>(font, 10, truncatedName, TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{20, 1}, Vector2f{3 + marginRight, index});
        auto textureCheckBox = std::make_shared<Texture>(texture, Vector2f{360, 360}, Vector2u{0, 0}, Vector2u{1, 1}, Vector2f{1 + marginRight, index});
        auto checkBox = std::make_shared<CheckBox>(textureCheckBox, textCheckBox);
        this->_texts.push_back(textCheckBox);
        this->_textures.push_back(textureCheckBox);
        this->_gamesCheckBoxes.push_back(checkBox);
        this->_initHiddenTextures(gameProvider.second->getManifest(), checkBox, font);
        index += 2;
    }
}

void Menu::_initTextures()
{
    auto backgroundTexture = this->_graphicsProvider->createTexture("assets/menu/img/background.png", "assets/menu/img/background.ascii");
    this->_textures.push_back(std::make_shared<Texture>(backgroundTexture, Vector2f{12, 12}, Vector2u{0, 0}, Vector2u{50, 25}, Vector2f{0, 0}));
    auto titleTexture = this->_graphicsProvider->createTexture("assets/menu/img/title.png", "assets/menu/img/title.ascii");
    this->_textures.push_back(std::make_shared<Texture>(titleTexture, Vector2f{17, 17}, Vector2u{0, 0}, Vector2u{31, 5}, Vector2f{10, 1}));
    auto middleTexture = this->_graphicsProvider->createTexture("assets/menu/img/middle.png", "assets/menu/img/middle.ascii");
    this->_textures.push_back(std::make_shared<Texture>(middleTexture, Vector2f{12, 12}, Vector2u{0, 0}, Vector2u{1, 17}, Vector2f{24, 7}));
}

void Menu::_initTexts()
{
    auto font = this->_graphicsProvider->createFont("assets/menu/fonts/arcade.ttf");

    auto score = std::make_shared<Text>(font, 10, "HI-SCORE", TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{8, 1}, Vector2f{26, 12});
    this->_texts.push_back(score);

    auto authors = std::make_shared<Text>(font, 8, "Authors:", TextAlign::LEFT, TextVerticalAlign::MIDDLE, Color{255, 255, 255, 255}, Vector2u{8, 1}, Vector2f{26, 14});
    this->_texts.push_back(authors);
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

    this->_texts.clear();
    this->_textures.clear();
    this->_gamesCheckBoxes.clear();
    if (!this->_graphicsProvider) {
        if (this->_graphicsProviders.empty())
            throw ArcadeError("No graphics provider found");
        this->_graphicsProvider = this->_getGraphicsProvider(0);
        std::cout << "No graphics provider found, using default provider" << std::endl;
    }
    this->_initTexts();
    this->_initTextures();
    this->_initCheckBoxes();
    this->_window = this->_graphicsProvider->createWindow(windowInitProps);
}

void Menu::_handleSelectUpperCheckBox()
{
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox));
            if (index == 0)
                this->_gamesCheckBoxes.at(this->_gamesCheckBoxes.size() - 1)->hover();
            else
                this->_gamesCheckBoxes.at(index - 1)->hover();
            break;
        }
    }
}

void Menu::_handleSelectLowerCheckBox()
{
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered()) {
            checkBox->unhover();
            auto index = std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox));
            if (index == this->_gamesCheckBoxes.size() - 1)
                this->_gamesCheckBoxes.at(0)->hover();
            else 
                this->_gamesCheckBoxes.at(index + 1)->hover();
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
    }
    if (type == events::IKeyEvent::KeyType::CHAR) {
        if (code.character == '\n')
            this->_selectGame();
        if (code.character == 27)
            this->_exitAndPlayOldGame();
    }
}

void Menu::_selectGame()
{
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered() && checkBox->isChecked())
            this->_exitWithNewGame();
        if (checkBox->isHovered())
            checkBox->check();
        else
            checkBox->uncheck();
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
        if (checkBox->isHovered()) {
            lastHoveredCheckBox = checkBox;
            break;
        }
    }
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered())
            checkBox->unhover();
        if (checkBox->isHovered(position)) {
            checkBox->hover();
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

    if (button != events::IMouseButtonEvent::MouseButton::LEFT)
        return;
    for (auto checkBox : this->_gamesCheckBoxes) {
        if (checkBox->isHovered(position))
            this->_selectGame();
    }
}

void Menu::_handleEvents()
{
    auto events = this->_window->getEvents();

    for (auto event : events) {
        auto type = event->getType();
        if (type == events::WINDOW_CLOSE)
            this->_window->close();
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
            for (auto text : this->_hiddenTexts[checkBox]) {
                text->draw(this->_window);
            }
        }
    }
    this->_window->display();
}

void Menu::_previousSelectedGame()
{
    for (auto gameProvider : this->_gameProviders) {
        if (this->_gameProvider == gameProvider.second) {
            auto index = std::distance(this->_gameProviders.begin(), std::find(this->_gameProviders.begin(), this->_gameProviders.end(), gameProvider));
            auto checkBox = this->_gamesCheckBoxes.at(index);
            checkBox->check();
            checkBox->hover();
            return;
        }
    }
    if (this->_gamesCheckBoxes.empty())
        throw ArcadeError("No games found");
    this->_gamesCheckBoxes.at(0)->check();
    this->_gamesCheckBoxes.at(0)->hover();
}

void Menu::run()
{
    this->_sceneStage = MENU;
    this->_initWindow();
    this->_previousSelectedGame();
    while (this->_window->isOpen()) {
        this->_handleEvents();
        this->_render();
    }
}
