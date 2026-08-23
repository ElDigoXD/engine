
#include <catch2/catch_test_macros.hpp>

#include "Math/Vector3.h"

namespace math
{
    TEST_CASE("Vector3f default construction", "[Vector3]")
    {
        math::Vector3 v;

        CHECK(v.x == 0.0f);
        CHECK(v.y == 0.0f);
        CHECK(v.z == 0.0f);
    }

    TEST_CASE("Vector3f construction", "[Vector3]")
    {
        math::Vector3 v{ 3.0f, 4.0f, 2.0f };

        CHECK(v.x == 3.0f);
        CHECK(v.y == 4.0f);
        CHECK(v.z == 2.0f);
    }

    TEST_CASE("Vector3f cross product", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 2.0f, 3.0f };
        const math::Vector3 b{ 4.0f, 5.0f, 6.0f };

        const math::Vector3 result = a.cross(b);

        CHECK(result.x == -3.0f);
        CHECK(result.y == 6.0f);
        CHECK(result.z == -3.0f);
    }

    TEST_CASE("Vector3f dot product", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 2.0f, 3.0f };
        const math::Vector3 b{ 4.0f, 5.0f, 6.0f };

        const float result = a.dot(b);

        CHECK(result == 32.0f);
    }

    TEST_CASE("Vector3f sqrt", "[Vector3]")
    {
        const math::Vector3 a{ 4.0f, 4.0f, 4.0f };

        const math::Vector3 result = a.sqrt();

        CHECK(result == math::Vector3{ 2.0f, 2.0f, 2.0f });
    }

    TEST_CASE("Vector3f addition", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 2.0f, 2.0f };
        const math::Vector3 b{ 3.0f, 4.0f, 2.0f };

        const math::Vector3 result = a + b;

        CHECK(result.x == 4.0f);
        CHECK(result.y == 6.0f);
        CHECK(result.z == 4.0f);
    }

    TEST_CASE("Vector3f subtraction", "[Vector3]")
    {
        const math::Vector3 a{ 5.0f, 7.0f, 2.0f };
        const math::Vector3 b{ 2.0f, 3.0f, 2.0f };

        const math::Vector3 result = a - b;

        CHECK(result.x == 3.0f);
        CHECK(result.y == 4.0f);
        CHECK(result.z == 0.0f);
    }

    TEST_CASE("Vector3f scalar multiplication", "[Vector3]")
    {
        const math::Vector3 v{ 2.0f, 3.0f, 4.0f };

        const math::Vector3 result = v * 2.0f;

        CHECK(result.x == 4.0f);
        CHECK(result.y == 6.0f);
        CHECK(result.z == 8.0f);
    }

    TEST_CASE("Vector3f equality", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 2.0f, 1.0f };
        const math::Vector3 b{ 1.0f, 2.0f, 1.0f };

        CHECK(a == b);
    }

    TEST_CASE("Vector3f inequality X", "[Vector3]")
    {
        const math::Vector3 a{ 0.0f, 2.0f, 4.0f };
        const math::Vector3 b{ 1.0f, 2.0f, 4.0f };

        CHECK(a != b);
    }

    TEST_CASE("Vector3f inequality Y", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 1.0f, 4.0f };
        const math::Vector3 b{ 1.0f, 2.0f, 4.0f };

        CHECK(a != b);
    }

    TEST_CASE("Vector3f inequality Z", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 1.0f, 4.0f };
        const math::Vector3 b{ 1.0f, 1.0f, 2.0f };

        CHECK(a != b);
    }

    TEST_CASE("Vector3 neary_equal", "[Vector3]")
    {
        const math::Vector3 a{ 1.0f, 2.0f, 0.0f };
        const math::Vector3 b{ 1.0000012315f, 2.00000123123f, 0.0000012344f };

        REQUIRE(math::nearly_equal(a, b));
    }
}
