#pragma once

#include <utility>

//TODO needs alloctor and use stage
template<typename T, typename ... Args>
T & ecs::World::AddComponent(Args &&...args)
{
    return *new T(std::forward<Args>(args)...);
}
