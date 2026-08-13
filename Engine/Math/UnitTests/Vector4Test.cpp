
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector4.h"

TEST_CASE("Vector4f default construction", "[Vector4]")
{
    math::Vector4 v;

    CHECK(v.x == 0.0f);
    CHECK(v.y == 0.0f);
    CHECK(v.z == 0.0f);
    CHECK(v.w == 0.0f);
}

TEST_CASE("Vector4f construction", "[Vector4]")
{
    math::Vector4 v{ 3.0f, 4.0f, 2.0f, 1.0f };

    CHECK(v.x == 3.0f);
    CHECK(v.y == 4.0f);
    CHECK(v.z == 2.0f);
    CHECK(v.w == 1.0f);
}

TEST_CASE("Vector4f cross", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 3.0f, 0.0f };
    const math::Vector4 b{ 4.0f, 5.0f, 6.0f, 0.0f };

    const math::Vector4 result = a.cross(b);

    CHECK(result.x == -3.0f);
    CHECK(result.y == 6.0f);
    CHECK(result.z == -3.0f);
}

TEST_CASE("Vector4f DOT", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
    const math::Vector4 b{ 5.0f, 6.0f, 7.0f, 8.0f };

    const float result = a.dot(b);

    CHECK(result == 70.0f);
}

TEST_CASE("Vector4f addition", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 2.0f, 1.0f };
    const math::Vector4 b{ 3.0f, 4.0f, 2.0f, 1.0f};

    const math::Vector4 result = a + b;

    CHECK(result.x == 4.0f);
    CHECK(result.y == 6.0f);
    CHECK(result.z == 4.0f);
    CHECK(result.w == 2.0f);
}

TEST_CASE("Vector4f subtraction", "[Vector4]")
{
    const math::Vector4 a{ 5.0f, 7.0f, 2.0f, 1.0f };
    const math::Vector4 b{ 2.0f, 3.0f, 2.0f, 1.0f};

    const math::Vector4 result = a - b;

    CHECK(result.x == 3.0f);
    CHECK(result.y == 4.0f);
    CHECK(result.z == 0.0f);
    CHECK(result.w == 0.0f);
}

TEST_CASE("Vector4f scalar multiplication", "[Vector4]")
{
    const math::Vector4 v{ 2.0f, 3.0f, 4.0f, 1.0f };

    const math::Vector4 result = v * 2.0f;

    CHECK(result.x == 4.0f);
    CHECK(result.y == 6.0f);
    CHECK(result.z == 8.0f);
    CHECK(result.w == 2.0f);
}

TEST_CASE("Vector4f equality", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 2.0f, 1.0f, 2.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 1.0f, 2.0f };

    CHECK(a == b);
}

TEST_CASE("Vector4f inequality X", "[Vector4]")
{
    const math::Vector4 a{ 0.0f, 2.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 4.0f, 1.0f };

    CHECK(a != b);
}

TEST_CASE("Vector4f inequality Y", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 2.0f, 4.0f, 1.0f };

    CHECK(a != b);
}

TEST_CASE("Vector4f inequality Z", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 1.0f, 2.0f, 1.0f };

    CHECK(a != b);
}

TEST_CASE("Vector4f inequality W", "[Vector4]")
{
    const math::Vector4 a{ 1.0f, 1.0f, 4.0f, 1.0f };
    const math::Vector4 b{ 1.0f, 1.0f, 2.0f, 1.0f };

    CHECK(a != b);
}
