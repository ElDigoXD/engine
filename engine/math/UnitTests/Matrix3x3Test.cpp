#include <catch2/catch_test_macros.hpp>

#include "Math/Mat3.h"

namespace math
{
    TEST_CASE("Mat3 default construction", "[Matrix3x3]")
    {
        const math::Mat3 m;

        CHECK(m.row1 == math::Vector3(1.0f, 0.0f, 0.0f));
        CHECK(m.row2 == math::Vector3(0.0f, 1.0f, 0.0f));
        CHECK(m.row3 == math::Vector3(0.0f, 0.0f, 1.0f));
    }

    TEST_CASE("Mat3 move construction", "[Matrix3x3]")
    {
        const math::Vector3 row(0.0f, 1.0f, 4.0f);

        math::Mat3 m1 = {row, row, row};
        const math::Mat3 m2(std::move(m1));

        CHECK(m2.row1 == row);
        CHECK(m2.row2 == row);
        CHECK(m2.row3 == row);
    }

    TEST_CASE("Mat3 mult Mat3", "[Matrix3x3]")
    {
        const math::Vector3 row(0.0f, 1.0f, 4.0f);
        const math::Vector3 rowResult(0.0f, 5.0f, 20.0f);

        const math::Mat3 m1 = {row, row, row};
        const math::Mat3 m2 = {row, row, row};

        const math::Mat3 result = m1 * m2;

        CHECK(result.row1 == rowResult);
        CHECK(result.row2 == rowResult);
        CHECK(result.row3 == rowResult);
    }

    TEST_CASE("Mat3 equal Mat3", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Mat3 m2 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        CHECK(m1 == m2);
    }

    TEST_CASE("Mat3 not equal Mat3 row 1", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 1.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Mat3 m2 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        CHECK(m1 != m2);
    }

    TEST_CASE("Mat3 not equal Mat3 row 2", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 0.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Mat3 m2 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        CHECK(m1 != m2);
    }

    TEST_CASE("Mat3 not equal Mat3 row 3", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 1.0f, 1.0f
        };

        const math::Mat3 m2 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        CHECK(m1 != m2);
    }

    TEST_CASE("Mat3 mult Vector2", "[Matrix3x3]")
    {
        const math::Vector2 v(2.0f, 3.0f);

        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Vector2 result = m1 * v;

        CHECK(result.x == 7.0f);
        CHECK(result.y == 5.0f);
    }

    TEST_CASE("Mat3 index value", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        CHECK(m1[0] == 1.0f);
        CHECK(m1[8] == 1.0f);
    }

    TEST_CASE("Mat3 mult scalar", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Mat3 result = m1 * 2.0f;

        CHECK(result == math::Mat3{
              2.0f, 0.0f, 10.0f,
              0.0f, 2.0f, 4.0f,
              0.0f, 0.0f, 2.0f
              });
    }

    TEST_CASE("Mat3 div scalar", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 2.0f,
            0.0f, 0.0f, 1.0f
        };

        const math::Mat3 result = m1 / 2.0f;

        CHECK(result == math::Mat3{
              0.5f, 0.0f, 2.5f,
              0.0f, 0.5f, 1.0f,
              0.0f, 0.0f, 0.5f
              });
    }

    TEST_CASE("Mat3 transpose", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 1.0f, 1.0f,
            2.0f, 2.0f, 2.0f,
            3.0f, 3.0f, 3.0f
        };

        const math::Mat3 result = m1.transpose();

        CHECK(result == math::Mat3{
              1.0f, 2.0f, 3.0f,
              1.0f, 2.0f, 3.0f,
              1.0f, 2.0f, 3.0f
              });
    }

    TEST_CASE("Mat3 determinant", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 2.0f, 3.0f,
            0.0f, 4.0f, 5.0f,
            1.0f, 0.0f, 6.0f
        };

        const float result = m1.determinant();

        CHECK(result == 22.0f);
    }

    TEST_CASE("Mat3 inverse", "[Matrix3x3]")
    {
        const math::Mat3 m1 = {
            1.0f, 2.0f, 0.0f,
            0.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f
        };

        const math::Mat3 result   = m1.inverse();
        const math::Mat3 identity = m1 * result;

        CHECK(identity == Mat3());
    }
}
