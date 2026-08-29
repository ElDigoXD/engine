#pragma once

#include <initializer_list>

#include "Math/Vector3.h"
#include "Math/Vector4.h"
#include "Math/Types.h"

namespace math
{
    template <typename T>
    class Matrix4x4
    {
    public:
        Matrix4x4();
        Matrix4x4(std::initializer_list<float> raw_data);
        Matrix4x4(const Vec4<T>& row1,
                  const Vec4<T>& row2,
                  const Vec4<T>& row3,
                  const Vec4<T>& row4);
        Matrix4x4(const Matrix4x4<T>& other);
        Matrix4x4(Matrix4x4<T>&& other) noexcept;

        Matrix4x4 transpose() const;
        T determinant() const;
        Matrix4x4 inverse() const;

        Matrix4x4& operator =(const Matrix4x4& other);
        Matrix4x4 operator *(const Matrix4x4& other) const;
        Vec3<T> operator *(const Vec3<T>& other) const;
        bool operator ==(const Matrix4x4& other) const;
        bool operator !=(const Matrix4x4& other) const;
        T operator[](size_t index) const;
        Matrix4x4 operator *(T scalar) const;
        Matrix4x4& operator *=(T scalar);
        Matrix4x4 operator /(T scalar) const;

        union
        {
            struct
            {
                Vec4<T> row1;
                Vec4<T> row2;
                Vec4<T> row3;
                Vec4<T> row4;
            };

            T raw_data[16];

            Vec4<T> data[4];
        };
    };

    using Mat4i = Matrix4x4<int32>;
    using Mat4f = Matrix4x4<float>;
    using Mat4d = Matrix4x4<double>;
    using Mat4  = Mat4f;
}

#include "Math/Mat4.inl"
