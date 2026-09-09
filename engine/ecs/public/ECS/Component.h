#pragma once

namespace ecs
{
    struct Component
    {};

    struct SingletonComponent
    {};

    template<typename T>
    concept ComponentType = std::derived_from<T, Component>;

    template<typename... Ts>
    concept ComponentTypes = (ComponentType<Ts> && ...);
}

#define ECS_COMPONENT public ecs::Component