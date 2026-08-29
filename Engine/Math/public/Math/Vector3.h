#pragma once

#include "Math/Types.h"

namespace math
{
    template <typename T>
    class Vec3
    {
    public:
        using ValueType = T;

        Vec3();
        explicit Vec3(T value);
        Vec3(T x,
             T y,
             T z);
        Vec3(const Vec3<T>& other);
        Vec3(Vec3<T>&& other) noexcept;

        Vec3 cross(const Vec3& other) const requires (!std::is_integral_v<T>);
        T dot(const Vec3& other) const;
        Vec3<T> sqrt() const requires (!std::is_integral_v<T>);
        bool nearly_equal(const Vec3& other) const;

        Vec3 operator +(const Vec3& other) const;
        Vec3 operator -(const Vec3& other) const;
        Vec3 operator *(const Vec3& other) const;
        Vec3 operator *(T value) const;
        Vec3& operator *=(T value);
        Vec3 operator /(const Vec3& other) const;
        Vec3 operator /(T value) const requires (!std::is_integral_v<T>);
        Vec3& operator +=(const Vec3<T>& other);
        bool operator !=(const Vec3& other) const;
        bool operator ==(const Vec3& other) const;
        T operator[](size_t index) const;

        union
        {
            struct
            {
                T x;
                T y;
                T z;
            };

            T data[3];
        };
    };

    using Vector3f = Vec3<float>;
    using Vector3i = Vec3<int32>;
    using Vector3d = Vec3<double>;
    using Vector3  = Vector3f;
}

#include "Math/Vector3.inl"
