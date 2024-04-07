/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IEntity
*/

#pragma once

#include <vector>
#include <memory>

namespace shared::games {
    class IGame;

    namespace entity {
        class IEntity;

        /// @brief Entity pointer
        typedef std::shared_ptr<IEntity> EntityPtr;
        /// @brief Entities map pointers
        typedef std::vector<EntityPtr> EntitiesMap;
    }

    namespace components {
        class IComponent;

        /// @brief Components map pointers
        typedef std::vector<std::shared_ptr<IComponent>> ComponentsMap;
    }
}

/**
 * @brief Interface of an entity
 * 
 */
class shared::games::entity::IEntity {
public:
    virtual ~IEntity() = default;

    /**
     * @brief Get the components of the entity
     *
     * @return Components of the entity
     */
    virtual const components::ComponentsMap &getComponents(void) const noexcept = 0;
};
