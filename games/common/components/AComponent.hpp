/*
** EPITECH PROJECT, 2024
** AComponent.hpp
** File description:
** AComponent class
*/

#pragma once

#include "shared/games/components/IComponent.hpp"

namespace arcade::games::common::components {
    class AComponent;
}

class arcade::games::common::components::AComponent : public virtual shared::games::components::IComponent {
public:
    ~AComponent() override = default;

    /**
     * @brief Get the type of the component
     *
     * @return Type of the component
     */
    const shared::games::components::ComponentType getType() const noexcept override;

    /**
     * @brief Get the parent entity of the component
     *
     * @return Entity of the component
     */
    const shared::games::entity::IEntity &getEntity() noexcept override;

protected:
    /**
     * @brief Create a component
     *
     * @param entity Entity parent of the component
     */
    explicit AComponent(shared::games::components::ComponentType type, shared::games::entity::IEntity &entity);

    shared::games::entity::IEntity &_parent;
    shared::games::components::ComponentType _type;
};
