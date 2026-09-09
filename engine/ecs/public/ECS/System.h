#pragma once

#include <concepts>

#include "ECS/WorldView.h"

namespace ecs::system
{

    template<typename T>
    concept SystemType = requires
    {
        { T::is_editor } -> std::convertible_to<bool>; //Is executed while game paused in editor.
        { T::name }      -> std::convertible_to<const char*>;
    };

    template<typename T, typename... Components>
    concept HasUpdate = requires(T& t, ecs::WorldView<Components...>& world)
    {
        t.update(world);
    };
}

