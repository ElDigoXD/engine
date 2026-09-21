#pragma once
#include "ECS/Component.h"
#include "ECS/Entity.h"


namespace ecs
{
    static uint64 g_entity_index = 0;

    template<ComponentType T>
    EntityId GetId()
    {
        static EntityId id = ++g_entity_index;

        return id;
    }
}
