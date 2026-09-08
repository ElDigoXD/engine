#include <catch2/catch_test_macros.hpp>

#include "Math/Mat4.h"


namespace math::ut
{
    TEST_CASE("Mat4 default construction", "[Matrix4x4]")
    {
        const tt::Mat4 m;

        CHECK(m.row1 == tt::Vector4(1.0f, 0.0f, 0.0f, 0.0f));
        CHECK(m.row2 == tt::Vector4(0.0f, 1.0f, 0.0f, 0.0f));
        CHECK(m.row3 == tt::Vector4(0.0f, 0.0f, 1.0f, 0.0f));
        CHECK(m.row4 == tt::Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    }

    TEST_CASE("Mat4 transpose")
    {
        const tt::Mat4 m = {
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f
        };

        const tt::Mat4 result = m.transpose();

        CHECK(result == tt::Mat4{
            1.0f, 1.0f, 1.0f, 1.0f,
            2.0f, 2.0f, 2.0f, 2.0f,
            3.0f, 3.0f, 3.0f, 3.0f,
            4.0f, 4.0f, 4.0f, 4.0f
        });
    }
}

