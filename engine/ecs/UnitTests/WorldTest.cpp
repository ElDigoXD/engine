#include <catch2/catch_test_macros.hpp>

#include "ECS/EntityIndex.h"
#include "ECS/Entity.h"
#include "ECS/World.h"

namespace
{
    struct ComponentA : ECS_COMPONENT {};
    struct ComponentB : ECS_COMPONENT {};
}

namespace ecs
{
    TEST_CASE("Register component.", "[World]")
    {
        ecs::World world;

        world.register_component<ComponentA>();
        world.register_component<ComponentB>();

        const EntityId a_id = ecs::GetId<ComponentA>();
        const EntityId b_id = ecs::GetId<ComponentB>();

        CHECK(a_id == 1);
        CHECK(b_id == 2);
    }

    TEST_CASE("Register components.", "[World]")
    {
        ecs::World world;

        using ComponentList = ecs::TypeList<
            ComponentA,
            ComponentB
        >;
        world.register_components<ComponentList>();

        const EntityId a_id = ecs::GetId<ComponentA>();
        const EntityId b_id = ecs::GetId<ComponentB>();

        CHECK(a_id == 1);
        CHECK(b_id == 2);
    }
}