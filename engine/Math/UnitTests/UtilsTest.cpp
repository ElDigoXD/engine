#include <catch2/catch_test_macros.hpp>

#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"
#include "Math/Utils.h"
#include "Math/Geometric.h"

namespace math
{
    TEST_CASE("Vector4f length", "[Vector4]")
    {
        const math::Vector4 a{2.0f, 3.0f, 6.0f, 0.0f};

        const float result = math::length(a);

        CHECK(result == 7.0f);
    }

    TEST_CASE("Vector4f distance", "[Vector4]")
    {
        const math::Vector4 a{0.0f, 0.0f, 0.0f, 0.0f};
        const math::Vector4 b{1.0f, 0.0f, 0.0f, 0.0f};

        const float result = math::distance(a, b);

        CHECK(result == 1.0f);
    }

    TEST_CASE("Vector3f length", "[Vector3]")
    {
        const math::Vector3 a{2.0f, 3.0f, 6.0f};

        const float result = math::length(a);

        CHECK(result == 7.0f);
    }

    TEST_CASE("Vector3f distance", "[Vector3]")
    {
        const math::Vector3 a{0.0f, 0.0f, 0.0f};
        const math::Vector3 b{1.0f, 0.0f, 0.0f};

        const float result = math::distance(a, b);

        CHECK(result == 1.0f);
    }

    TEST_CASE("Vector2f length", "[Vector2]")
    {
        const math::Vector2 a{3.0f, 4.0f};

        const float result = math::length(a);

        CHECK(result == 5.0f);
    }

    TEST_CASE("Vector2f distance", "[Vector3]")
    {
        const math::Vector2 a{0.0f, 0.0f};
        const math::Vector2 b{1.0f, 0.0f};

        const float result = math::distance(a, b);

        CHECK(result == 1.0f);
    }

    TEST_CASE("Vector3f normalize", "[Vector3]")
    {
        const math::Vector3 a{1.0f, 1.0f, 1.0f};

        const math::Vector3 result = math::normalize(a);

        CHECK(math::nearly_equal(result, math::Vector3(0.57735, 0.57735, 0.57735)));
    }
}
