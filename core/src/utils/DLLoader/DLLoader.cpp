/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

void DLLoader::_throwError() {
    std::string error = dlerror();

    throw ArcadeError(error.length() ? error : "Unknown error while loading library");
}

DLLoader::DLLoader() {
    this->_handle = nullptr;
}

DLLoader::~DLLoader() {
    if (this->_handle)
        dlclose(this->_handle);
}

void DLLoader::openLibrary(const std::string &filepath) {
    if (this->_handle)
        dlclose(this->_handle);
    this->_handle = dlopen(filepath.c_str(), RTLD_LAZY);
    if (!this->_handle)
        this->_throwError();
    dlerror();
}
