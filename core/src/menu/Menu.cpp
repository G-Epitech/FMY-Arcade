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
    if (!this->_graphicsProvider) {
        if (this->_graphicsProviders.empty()) {
            throw std::runtime_error("No graphics provider found");
        }
        this->_graphicsProvider = this->_graphicsProviders.at(0);
        std::cout << "No graphics provider found, using default provider" << std::endl;
    }
    int index = 8;

    this->_checkBoxes.clear();
    for (auto gameProvider : this->_gameProviders) {
        std::cout << "Game: " << gameProvider->getManifest().name << std::endl;
        auto checkBox = std::make_shared<CheckBox>(gameProvider->getManifest(), this->_graphicsProvider, Vector2i{15, index});
        this->_checkBoxes.push_back(checkBox);
        index += 2;
    }
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

    this->_initCheckBoxes();
    this->_window = this->_graphicsProvider->createWindow(windowInitProps);
}

void Menu::_handleSelectUpperCheckBox()
{
    for (auto checkBox : this->_checkBoxes) {
        if (checkBox->isChecked()) {
            checkBox->uncheck();
            auto index = std::distance(this->_checkBoxes.begin(), std::find(this->_checkBoxes.begin(), this->_checkBoxes.end(), checkBox));
            if (index == 0) {
                this->_checkBoxes.at(this->_checkBoxes.size() - 1)->check();
                break;
            }
            this->_checkBoxes.at(index - 1)->check();
            break;
        }
    }
}

void Menu::_handleSelectLowerCheckBox()
{
    for (auto checkBox : this->_checkBoxes) {
        if (checkBox->isChecked()) {
            checkBox->uncheck();
            auto index = std::distance(this->_checkBoxes.begin(), std::find(this->_checkBoxes.begin(), this->_checkBoxes.end(), checkBox));
            if (index == this->_checkBoxes.size() - 1) {
                this->_checkBoxes.at(0)->check();
                break;
            }
            this->_checkBoxes.at(index + 1)->check();
            break;
        }
    }
}

void Menu::_handleKeyboardEvents(std::shared_ptr<events::IKeyEvent> key)
{
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
            this->_exitWithNewGame();
        if (code.character == 27)
            this->_exitAndPlayOldGame();
    }
}

void Menu::_exitAndPlayOldGame()
{
    this->_sceneStage = RESUME;
    this->_window->close();
}

void Menu::_exitWithNewGame()
{
    for (auto checkBox : this->_checkBoxes) {
        if (checkBox->isChecked()) {
            this->_gameProvider = this->_gameProviders.at(std::distance(this->_checkBoxes.begin(), std::find(this->_checkBoxes.begin(), this->_checkBoxes.end(), checkBox)));
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

void Menu::run()
{
    this->_sceneStage = MENU;
    this->_initWindow();
    this->_checkBoxes.at(0)->check();
    while (this->_window->isOpen()) {
        this->_handleEvents();
        this->_window->clear();
        for (auto checkBox : this->_checkBoxes) {
            checkBox->draw(this->_window);
        }
        this->_window->display();
    }
}
