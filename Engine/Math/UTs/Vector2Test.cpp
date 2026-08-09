
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector2.h"

TEST_CASE("Vector2f default construction", "[Vector2]")
{
    Math::Vector2 v;

    REQUIRE(v.x == 0.0f);
    REQUIRE(v.y == 0.0f);
}

TEST_CASE("Vector2f construction", "[Vector2]")
{
    Math::Vector2 v{ 3.0f, 4.0f };

    REQUIRE(v.x == 3.0f);
    REQUIRE(v.y == 4.0f);
}

TEST_CASE("Vector2f addition", "[Vector2]")
{
    const Math::Vector2 a{ 1.0f, 2.0f };
    const Math::Vector2 b{ 3.0f, 4.0f };

    const Math::Vector2 result = a + b;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
}

TEST_CASE("Vector2f subtraction", "[Vector2]")
{
    const Math::Vector2 a{ 5.0f, 7.0f };
    const Math::Vector2 b{ 2.0f, 3.0f };

    const Math::Vector2 result = a - b;

    REQUIRE(result.x == 3.0f);
    REQUIRE(result.y == 4.0f);
}

TEST_CASE("Vector2f scalar multiplication", "[Vector2]")
{
    const Math::Vector2 v{ 2.0f, 3.0f };

    const Math::Vector2 result = v * 2.0f;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
}

TEST_CASE("Vector2f equality", "[Vector2]")
{
    const Math::Vector2 a{ 1.0f, 2.0f };
    const Math::Vector2 b{ 1.0f, 2.0f };

    REQUIRE(a == b);
}

TEST_CASE("Vector2f inequality", "[Vector2]")
{
    const Math::Vector2 a{ 1.0f, 2.0f };
    const Math::Vector2 b{ 1.0f, 3.0f };

    REQUIRE(a != b);
}
