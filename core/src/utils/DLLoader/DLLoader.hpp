/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#pragma once

#include <memory>
#include <dlfcn.h>
#include <iostream>

class DLLoader {
    public:

        typedef enum {
            LAZY = RTLD_LAZY,
            NOW = RTLD_NOW,
            LOCAL = RTLD_LOCAL,
            GLOBAL = RTLD_GLOBAL,
            NODELETE = RTLD_NODELETE,
            NOLOAD = RTLD_NOLOAD
        } LoadingMode;

        /**
         * @brief Construct a new DLLoader object
         * 
         * @param filepath Path to the library
         */
        DLLoader(const std::string &filepath, LoadingMode mode = LAZY);

        ~DLLoader();

        /**
         * @brief Open the library
         * 
         * @param filepath Path to the library
         * @param mode Loading mode
         */
        static std::shared_ptr<DLLoader> open(const std::string &filepath, LoadingMode mode = LAZY);

        /**
         * @brief Get a function from the library
         * 
         * @tparam T Function prototype
         * @param name Symbol name
         * @return T Function founded
         */
        template <typename T>
        T loadSymbol(std::string name) {
            if (!this->_handle)
                throw DLLoaderExeption("Library not loaded");
            T symbol = reinterpret_cast<T>(dlsym(this->_handle, name.c_str()));
            if (!symbol)
                this->_throwError();
            return symbol;
        }

        class DLLoaderExeption : public std::exception {
            public:
                DLLoaderExeption(const std::string &message);

                const char *what() const noexcept override;

            private:
                const std::string _message;
        };

    protected:
    private:
        void *_handle;
        std::string _filepath;

        /**
         * @brief Throw an error
         * 
         */
        void _throwError();
};
