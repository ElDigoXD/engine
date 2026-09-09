#pragma once

#include "ECS/Filter.h"
#include "ECS/Query.h"

namespace ecs
{
    // ============================================================
    // WorldView
    // ============================================================
    template<AccessFilter... FilterAccess>
    struct WorldView
    {
        using accesses = TypeList<FilterAccess...>;
    public:
        template<ecs::query::QueryFilter... Filters>
        void Query();
    };
}

#include "ECS/WorldView.inl"