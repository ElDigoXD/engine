#include <catch2/catch_test_macros.hpp>

#include "ECS/WorldView.h"

namespace
{
    struct ComponentA : ECS_COMPONENT {};
    struct ComponentB : ECS_COMPONENT {};
}

namespace ecs
{
    TEST_CASE("Check world view Read-Write.", "[WorldView]")
    {
        using WorldView_1 = ecs::WorldView<
            Access::Read<
                ComponentB
            >,
            Access::Write<
                ComponentA,
                ComponentB
            >
        >;

        using WorldView_2 = ecs::WorldView<
            Access::Write<
                ComponentA,
                ComponentB
            >
        >;

        static_assert(CompatibleWorldViews<WorldView_1, WorldView_2>, "Missing access");
    }

    TEST_CASE("Check world view Read-Read.", "[WorldView]")
    {
        using WorldView_1 = ecs::WorldView<
            Access::Read<
                ComponentA,
                ComponentB
            >
        >;

        using WorldView_2 = ecs::WorldView<
            Access::Read<
                ComponentA,
                ComponentB
            >
        >;

        static_assert(CompatibleWorldViews<WorldView_1, WorldView_2>, "Missing access");
    }


    TEST_CASE("Check world view Has-All.", "[WorldView]")
    {
        using WorldView_1 = ecs::WorldView<
            Access::Has<
                ComponentA,
                ComponentB
            >
        >;

        using WorldView_2 = ecs::WorldView<
            Access::All<
                ComponentA,
                ComponentB
            >
        >;

        static_assert(CompatibleWorldViews<WorldView_1, WorldView_2>, "Missing access");
    }

    TEST_CASE("Check world view Has-Read.", "[WorldView]")
    {
        using WorldView_1 = ecs::WorldView<
            Access::Has<
                ComponentA,
                ComponentB
            >
        >;

        using WorldView_2 = ecs::WorldView<
            Access::Read<
                ComponentA,
                ComponentB
            >
        >;

        static_assert(CompatibleWorldViews<WorldView_1, WorldView_2>, "Missing access");
    }

    TEST_CASE("Check world view Has-Write.", "[WorldView]")
    {
        using WorldView_1 = ecs::WorldView<
            Access::Has<
                ComponentA,
                ComponentB
            >
        >;

        using WorldView_2 = ecs::WorldView<
            Access::Write<
                ComponentA,
                ComponentB
            >
        >;

        WorldView_2 world;
        world.Query<ecs::query::Include<ComponentA>>();
        static_assert(CompatibleWorldViews<WorldView_1, WorldView_2>, "Missing access");
    }
}
