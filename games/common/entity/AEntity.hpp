/*
** EPITECH PROJECT, 2024
** AEntity.hpp
** File description:
** AEntity class
*/

#pragma once

#include "shared/games/IEntity.hpp"

namespace arcade::games::common {
    class AEntity;
}

class arcade::games::common::AEntity : public shared::games::entity::IEntity {
public:
    ~AEntity() override = default;

    /**
     * @brief Get the components of the entity
     *
     * @return Components of the entity
     */
    const shared::games::components::ComponentsMap &getComponents() const noexcept override;

protected:
    /**
     * @brief Create a entity
     */
    explicit AEntity() = default;

    shared::games::components::ComponentsMap _components;
};
