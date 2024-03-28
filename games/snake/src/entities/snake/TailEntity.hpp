/*
** EPITECH PROJECT, 2024
** TailEntity.hpp
** File description:
** TailEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"

namespace arcade::games::snake {
    class TailEntity;
}

class arcade::games::snake::TailEntity : public common::AEntity {
public:
    ~TailEntity() override = default;

    explicit TailEntity();
};
