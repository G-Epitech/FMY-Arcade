/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#pragma once

#include <dlfcn.h>
#include "exception/ArcadeError.hpp"

class DLLoader {
    public:
        DLLoader();
        ~DLLoader();

        /**
         * @brief Open a library
         * 
         * @param filepath 
         */
        void openLibrary(const std::string &filepath);

        /**
         * @brief Get a function from the library
         * 
         * @tparam T Function prototype
         * @param functionName Function name
         * @return T Function founded
         */
        template <typename T>
        T getFunction(std::string functionName) {
            T function = reinterpret_cast<T>(dlsym(this->_handle, functionName.c_str()));

            if (!function)
                this->_throwError();
            return function;
        }

    protected:
    private:
        void *_handle;

        /**
         * @brief Throw an error
         * 
         */
        void _throwError();
};
