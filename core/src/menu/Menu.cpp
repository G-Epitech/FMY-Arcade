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

void Menu::_initCheckBoxes()
{
    int index = 8;

    this->_gamesCheckBoxes.clear();
    for (auto gameProvider : this->_gameProviders) {
        std::cout << "Game: " << gameProvider->getManifest().name << std::endl;
        auto checkBox = std::make_shared<CheckBox>(gameProvider->getManifest().name, this->_graphicsProvider, Vector2i{15, index});
        this->_gamesCheckBoxes.push_back(checkBox);
        index += 2;
    }
}

void Menu::_initTextures()
{
    auto texture = this->_graphicsProvider->createTexture("assets/menu/img/yellow.png", "assets/menu/img/yellow.ascii");
    this->_textures.push_back(std::make_shared<Texture>(texture, Vector2f{1, 1}, Vector2u{5, 5}, Vector2u{50, 20}, Vector2i{0, 0}));
}

void Menu::_initWindow()
{
    IWindow::WindowInitProps windowInitProps {
        .size = {50, 20},
        .mode = IWindow::WindowMode::WINDOWED,
        .fps = 60,
        .title = "Menu",
        .icon = "assets/menu/img/icon.png"
    };

    if (!this->_graphicsProvider) {
        if (this->_graphicsProviders.empty())
            throw std::runtime_error("No graphics provider found");
        this->_graphicsProvider = this->_graphicsProviders.at(0);
        std::cout << "No graphics provider found, using default provider" << std::endl;
    }
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
        if (checkBox->isHovered()) {
            checkBox->check();
        } else {
            checkBox->uncheck();
        }
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
            this->_gameProvider = this->_gameProviders.at(std::distance(this->_gamesCheckBoxes.begin(), std::find(this->_gamesCheckBoxes.begin(), this->_gamesCheckBoxes.end(), checkBox)));
            break;
        }
    }
    this->_sceneStage = NEWGAME;
    this->_window->close();
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
    }
}

void Menu::_render()
{
    this->_window->clear();
    for (auto texture : this->_textures) {
        texture->draw(this->_window);
    }
    for (auto checkBox : this->_gamesCheckBoxes) {
        checkBox->draw(this->_window);
    }
    this->_window->display();
}

void Menu::run()
{
    this->_sceneStage = MENU;
    this->_initWindow();
    this->_gamesCheckBoxes.at(0)->check();
    this->_gamesCheckBoxes.at(0)->hover();
    while (this->_window->isOpen()) {
        this->_handleEvents();
        this->_render();
    }
}
