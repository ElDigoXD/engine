#include <catch2/catch_test_macros.hpp>

#include "Math/Common.h"

namespace math
{
    TEST_CASE("Vector3 xyz0", "[Common]")
    {
        const tt::Vector3 vec(1.0f, 1.0f, 1.0f);
        tt::Vector4 result = xyz0(vec);

        CHECK(result == tt::Vector4(1.0f, 1.0f, 1.0f, 0.0f));
    }

    TEST_CASE("Vector2 xy0", "[Common]")
    {
        const tt::Vector2 vec(1.0f, 1.0f);
        tt::Vector3 result = xy0(vec);

        CHECK(result == tt::Vector3(1.0f, 1.0f, 0.0f));
    }

    TEST_CASE("Vector3 xyz1", "[Common]")
    {
        const tt::Vector3 vec(1.0f, 1.0f, 1.0f);
        tt::Vector4 result = xyz1(vec);

        CHECK(result == tt::Vector4(1.0f, 1.0f, 1.0f, 1.0f));
    }

    TEST_CASE("Vector2 xy1", "[Common]")
    {
        const tt::Vector2 vec(1.0f, 1.0f);
        tt::Vector3 result = xy1(vec);

        CHECK(result == tt::Vector3(1.0f, 1.0f, 1.0f));
    }

    TEST_CASE("Vector4 xyz", "[Common]")
    {
        const tt::Vector4 vec(1.0f, 1.0f, 1.0f, 1.0f);
        tt::Vector3 result = xyz(vec);

        CHECK(result == tt::Vector3(1.0f, 1.0f, 1.0f));
    }

    TEST_CASE("Vector4 xy", "[Common]")
    {
        const tt::Vector4 vec(1.0f, 1.0f, 1.0f, 1.0f);
        tt::Vector2 result = xy(vec);

        CHECK(result == tt::Vector2(1.0f, 1.0f));
    }

    TEST_CASE("Vector3 xy", "[Common]")
    {
        const tt::Vector3 vec(1.0f, 1.0f, 1.0f);
        tt::Vector2 result = xy(vec);

        CHECK(result == tt::Vector2(1.0f, 1.0f));
    }
}
