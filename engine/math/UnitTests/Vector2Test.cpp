
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector2.h"

namespace math
{
    TEST_CASE("Vector2f default construction", "[Vector2]")
    {
        math::Vector2 v;

        REQUIRE(v.x == 0.0f);
        REQUIRE(v.y == 0.0f);
    }

    TEST_CASE("Vector2f construction", "[Vector2]")
    {
        math::Vector2 v{ 3.0f, 4.0f };

        REQUIRE(v.x == 3.0f);
        REQUIRE(v.y == 4.0f);
    }

    TEST_CASE("Vector2f dot", "[Vector2]")
    {
        const math::Vector2 a{ 2.0f, 3.0f };
        const math::Vector2 b{ 4.0f, 5.0f };

        const float result = a.dot(b);

        REQUIRE(result == 23.0f);
    }

    TEST_CASE("Vector2f sqrt", "[Vector3]")
    {
        const math::Vector2 a{ 4.0f, 4.0f };

        const math::Vector2 result = a.sqrt();

        CHECK(result == math::Vector2{ 2.0f, 2.0f });
    }

    TEST_CASE("Vector2f addition", "[Vector2]")
    {
        const math::Vector2 a{ 1.0f, 2.0f };
        const math::Vector2 b{ 3.0f, 4.0f };

        const math::Vector2 result = a + b;

        REQUIRE(result.x == 4.0f);
        REQUIRE(result.y == 6.0f);
    }

    TEST_CASE("Vector2f subtraction", "[Vector2]")
    {
        const math::Vector2 a{ 5.0f, 7.0f };
        const math::Vector2 b{ 2.0f, 3.0f };

        const math::Vector2 result = a - b;

        REQUIRE(result.x == 3.0f);
        REQUIRE(result.y == 4.0f);
    }

    TEST_CASE("Vector2f scalar multiplication", "[Vector2]")
    {
        const math::Vector2 v{ 2.0f, 3.0f };

        const math::Vector2 result = v * 2.0f;

        REQUIRE(result.x == 4.0f);
        REQUIRE(result.y == 6.0f);
    }

    TEST_CASE("Vector2f equality", "[Vector2]")
    {
        const math::Vector2 a{ 1.0f, 2.0f };
        const math::Vector2 b{ 1.0f, 2.0f };

        REQUIRE(a == b);
    }

    TEST_CASE("Vector2f inequality", "[Vector2]")
    {
        const math::Vector2 a{ 1.0f, 2.0f };
        const math::Vector2 b{ 1.0f, 3.0f };

        REQUIRE(a != b);
    }

    TEST_CASE("Vector2f neary_equal", "[Vector2]")
    {
        const math::Vector2 a{ 1.0f, 2.0f };
        const math::Vector2 b{ 1.0000012315f, 2.00000123123f };

        REQUIRE(math::nearly_equal(a, b));
    }
}
