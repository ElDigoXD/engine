#pragma once

#include "Core/Types.h"

namespace ecs
{
    class Stage;
}

namespace ecs
{
    class World
    {
    public:
        template<typename T, typename... Args>
        T& AddComponent(Args&&... args);

    private:
        ecs::Stage* stages = nullptr;
        size_t stage_count = 0;
    };


}

#include "ECS/World.inl"
