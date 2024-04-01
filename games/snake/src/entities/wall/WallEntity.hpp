/*
** EPITECH PROJECT, 2024
** WallEntity.hpp
** File description:
** WallEntity class
*/

#pragma once

#include <string>
#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::snake {
    class WallEntity;
}


class arcade::games::snake::WallEntity : public common::AEntity {
public:
    ~WallEntity() override = default;

    explicit WallEntity(shared::types::Vector2u size);

    class WallExeption : public std::exception {
    public:
        WallExeption(const std::string &message);

        const char *what() const noexcept override;

    private:
        const std::string &_message;
    };

protected:
    /**
     * @brief Create a wall (part of) (Component creation)
     * @param position Position of the wall
     */
    void _createWall(shared::types::Vector2i position);
};
