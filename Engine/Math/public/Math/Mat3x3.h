#pragma once

#include "Math/Vector2.h"
#include "Math/Vector3.h"

namespace math
{
    template <typename T, T Value>
    class Mat3x3
    {
    public:
        Mat3x3();
        Mat3x3(std::initializer_list<float> raw_data);
        Mat3x3(const Vec3<T>& row1,
               const Vec3<T>& row2,
               const Vec3<T>& row3);
        Mat3x3(const Mat3x3<T, Value>& other);
        Mat3x3(Mat3x3<T, Value>&& other) noexcept;

        Mat3x3 transpose() const;
        T determinant() const;
        Mat3x3 inverse() const;

        Mat3x3& operator =(const Mat3x3& other);
        Mat3x3 operator *(const Mat3x3& other) const;
        Vec2<T> operator *(const Vec2<T>& other) const;
        bool operator ==(const Mat3x3& other) const;
        bool operator !=(const Mat3x3& other) const;
        T operator[](size_t index) const;
        Mat3x3 operator *(T scalar) const;
        Mat3x3& operator *=(T scalar);
        Mat3x3 operator /(T scalar) const;

        union
        {
            struct
            {
                Vec3<T> row1;
                Vec3<T> row2;
                Vec3<T> row3;
            };

            T raw_data[9];

            Vec3<T> data[3];
        };
    };


    using Matrix3x3f = Mat3x3<float, 1.0f>;
    using Matrix3x3i = Mat3x3<int, 1>;
    using Matrix3x3d = Mat3x3<double, 1.0>;
    using Matrix3x3  = Matrix3x3f;
}

#include "Math/Mat3x3.inl"
