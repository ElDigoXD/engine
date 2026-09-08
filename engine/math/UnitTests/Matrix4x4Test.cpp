#include <catch2/catch_test_macros.hpp>

#include "Math/Mat4.h"


namespace math::ut
{
    TEST_CASE("Mat4 default construction", "[Matrix3x3]")
    {
        const tt::Mat4 m;

        CHECK(m.row1 == tt::Vector4(1.0f, 0.0f, 0.0f, 0.0f));
        CHECK(m.row2 == tt::Vector4(0.0f, 1.0f, 0.0f, 0.0f));
        CHECK(m.row3 == tt::Vector4(0.0f, 0.0f, 1.0f, 0.0f));
        CHECK(m.row4 == tt::Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    }
}

