#pragma once

#include "Math/Vector2.h"
#include "Math/Vector3.h"

namespace math
{
    template <typename T, T Value>
    class Matrix3x3
    {
    public:
        Matrix3x3();
        Matrix3x3(std::initializer_list<float> raw_data);
        Matrix3x3(const Vec3<T>& row1,
                  const Vec3<T>& row2,
                  const Vec3<T>& row3);
        Matrix3x3(const Matrix3x3<T, Value>& other);
        Matrix3x3(Matrix3x3<T, Value>&& other) noexcept;

        Matrix3x3 transpose() const;
        T determinant() const;
        Matrix3x3 inverse() const;

        Matrix3x3& operator =(const Matrix3x3& other);
        Matrix3x3 operator *(const Matrix3x3& other) const;
        Vec2<T> operator *(const Vec2<T>& other) const;
        bool operator ==(const Matrix3x3& other) const;
        bool operator !=(const Matrix3x3& other) const;
        T operator[](size_t index) const;
        Matrix3x3 operator *(T scalar) const;
        Matrix3x3& operator *=(T scalar);
        Matrix3x3 operator /(T scalar) const;

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

    using Mat3f = Matrix3x3<float, 1.0f>;
    using Mat3i = Matrix3x3<int, 1>;
    using Mat3d = Matrix3x3<double, 1.0>;
    using Mat3  = Mat3f;
}

#include "Math/Mat3.inl"
