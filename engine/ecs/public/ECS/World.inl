#pragma once

#include <utility>
#include "ECS/EntityIndex.h"

//TODO needs alloctor and use stage
template<ecs::ComponentType T, typename ... Args>
T & ecs::World::add_component(Args &&...args)
{
    return *new T(std::forward<Args>(args)...);
}

template <ecs::SystemType T>
void ecs::World::register_system()
{
    using Update = decltype(&T::update);

    using WorldView = ecs::get_worldview<Update>::type;
}

template <ecs::ComponentType T>
void ecs::World::register_component()
{
    ecs::GetId<T>();
}

template <typename... T>
void ecs::World::register_components()
{
    auto register_list = [&]<typename... Ts>(ecs::TypeList<Ts...>)
    {
        (register_component<Ts>(), ...);
    };

    (register_list(T{}), ...);
}
