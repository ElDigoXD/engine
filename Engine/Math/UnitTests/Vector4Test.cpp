
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector4.h"

TEST_CASE("Vector4f default construction", "[Vector4]")
{
    math::Vector4 v;

    REQUIRE(v.x == 0.0f);
    REQUIRE(v.y == 0.0f);
    REQUIRE(v.z == 0.0f);
    REQUIRE(v.w == 0.0f);
}

TEST_CASE("Vector4f construction", "[Vector4]")
{
    math::Vector4 v{ 3.0f, 4.0f, 2.0f, 1.0f };

    REQUIRE(v.x == 3.0f);
    REQUIRE(v.y == 4.0f);
    REQUIRE(v.z == 2.0f);
    REQUIRE(v.w == 1.0f);
}

TEST_CASE("Vector4f addition", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 2.0f, 1.0f };
    const math::Vector4 b{ 3.0f, 4.0f, 2.0f, 1.0f};

    const math::Vector4 result = a + b;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
    REQUIRE(result.z == 4.0f);
    REQUIRE(result.w == 2.0f);
}

TEST_CASE("Vector4f subtraction", "[Vector4]")
{
    const math::Vector4 a{ 5.0f, 7.0f, 2.0f, 1.0f };
    const math::Vector4 b{ 2.0f, 3.0f, 2.0f, 1.0f};

    const math::Vector4 result = a - b;

    REQUIRE(result.x == 3.0f);
    REQUIRE(result.y == 4.0f);
    REQUIRE(result.z == 0.0f);
    REQUIRE(result.w == 0.0f);
}

TEST_CASE("Vector4f scalar multiplication", "[Vector4]")
{
    const math::Vector4 v{ 2.0f, 3.0f, 4.0f, 1.0f };

    const math::Vector4 result = v * 2.0f;

    REQUIRE(result.x == 4.0f);
    REQUIRE(result.y == 6.0f);
    REQUIRE(result.z == 8.0f);
    REQUIRE(result.w == 2.0f);
}

TEST_CASE("Vector4f equality", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 1.0f, 2.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 1.0f, 2.0f };

    REQUIRE(a == b);
}

TEST_CASE("Vector4f inequality X", "[Vector4]")
{
    const math::Vector4 a{ 0.0f, 2.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 4.0f, 1.0f };

    REQUIRE(a != b);
}

TEST_CASE("Vector4f inequality Y", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 4.0f, 1.0f };

    REQUIRE(a != b);
}

TEST_CASE("Vector4f inequality Z", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 1.0f, 2.0f, 1.0f };

    REQUIRE(a != b);
}

TEST_CASE("Vector4f inequality W", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 1.0f, 2.0f, 1.0f };

    REQUIRE(a != b);
}
