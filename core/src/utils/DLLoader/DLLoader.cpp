/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

void DLLoader::_throwError() {
    std::string error = dlerror();

    throw DLLoaderExeption(error.empty() ? "Unknown error while loading library" : error);
}

DLLoader::DLLoader(const std::string &filepath) : _filepath(filepath) {
    this->_handle = nullptr;
}

DLLoader::~DLLoader() {
    if (this->_handle)
        dlclose(this->_handle);
}

void DLLoader::open(DLLoader::LoadingMode mode) {
    if (this->_handle)
        dlclose(this->_handle);
    this->_handle = dlopen(this->_filepath.c_str(), mode);
    if (!this->_handle)
        this->_throwError();
    dlerror();
}

DLLoader::DLLoaderExeption::DLLoaderExeption(const std::string &message) : _message(message) {}

const char *DLLoader::DLLoaderExeption::what() const noexcept {
    return this->_message.c_str();
}
