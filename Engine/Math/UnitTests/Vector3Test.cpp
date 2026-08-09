
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector3.h"

TEST_CASE("Vector3f default construction", "[Vector3]")
{
    math::Vector3 v;

    REQUIRE(v.x == 0.0f);
    REQUIRE(v.y == 0.0f);
    REQUIRE(v.z == 0.0f);
}

TEST_CASE("Vector3f construction", "[Vector3]")
{
    math::Vector3 v{ 3.0f, 4.0f, 2.0f };

    REQUIRE(v.x == 3.0f);
    REQUIRE(v.y == 4.0f);
    REQUIRE(v.z == 2.0f);
}

TEST_CASE("Vector3f addition", "[Vector3]")
{
    const math::Vector3 a{ 1.0f, 2.0f, 2.0f};
    const math::Vector3 b{ 3.0f, 4.0f, 2.0f };

    const math::Vector3 result = a + b;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
    REQUIRE(result.z == 4.0f);
}

TEST_CASE("Vector3f subtraction", "[Vector3]")
{
    const math::Vector3 a{ 5.0f, 7.0f, 2.0f };
    const math::Vector3 b{ 2.0f, 3.0f, 2.0f };

    const math::Vector3 result = a - b;

    REQUIRE(result.x == 3.0f);
    REQUIRE(result.y == 4.0f);
    REQUIRE(result.z == 0.0f);
}

TEST_CASE("Vector3f scalar multiplication", "[Vector3]")
{
    const math::Vector3 v{ 2.0f, 3.0f, 4.0f };

    const math::Vector3 result = v * 2.0f;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
    REQUIRE(result.z == 8.0f);
}

TEST_CASE("Vector3f equality", "[Vector3]")
{
    const math::Vector3 a{ 1.0f, 2.0f, 1.0f };
    const math::Vector3 b{ 1.0f, 2.0f, 1.0f };

    REQUIRE(a == b);
}

TEST_CASE("Vector3f inequality X", "[Vector3]")
{
    const math::Vector3 a{ 0.0f, 2.0f, 4.0f };
    const math::Vector3 b{ 1.0f, 2.0f, 4.0f };

    REQUIRE(a != b);
}

TEST_CASE("Vector3f inequality Y", "[Vector3]")
{
    const math::Vector3 a{ 1.0f, 1.0f, 4.0f };
    const math::Vector3 b{ 1.0f, 2.0f, 4.0f };

    REQUIRE(a != b);
}

TEST_CASE("Vector3f inequality Z", "[Vector3]")
{
    const math::Vector3 a{ 1.0f, 1.0f, 4.0f };
    const math::Vector3 b{ 1.0f, 1.0f, 2.0f };

    REQUIRE(a != b);
}
