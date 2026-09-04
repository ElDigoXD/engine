#pragma once

#include "Math/Types.h"

namespace math
{
    template <typename T>
    class alignas(16) Vec4
    {
    public:
        using ValueType = T;

        Vec4();
        Vec4(T x,
             T y,
             T z,
             T w);
        Vec4(const Vec4<T>& other);
        Vec4(Vec4<T>&& other) noexcept;

        Vec4 cross(const Vec4& other) const requires (!std::is_integral_v<T>);
        T dot(const Vec4& other) const;
        bool nearly_equal(const Vec4& other) const;

        Vec4 operator +(const Vec4& other) const;
        Vec4 operator -(const Vec4& other) const;
        Vec4 operator *(const Vec4& other) const;
        Vec4 operator *(T value) const;
        Vec4 operator /(const Vec4& other) const;
        Vec4 operator /(T value) const requires (!std::is_integral_v<T>);
        Vec4& operator +=(const Vec4<T>& other);
        bool operator !=(const Vec4& other) const;
        bool operator ==(const Vec4& other) const;
        T operator[](size_t index) const;

        union
        {
            struct
            {
                T x;
                T y;
                T z;
                T w;
            };

            T data[4];
        };
    };

    using Vector4f = Vec4<float>;
    using Vector4i = Vec4<int32>;
    using Vector4d = Vec4<double>;
    using Vector4  = Vector4f;
}

#include "Math/Vector4.inl"
