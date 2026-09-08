#pragma once

#include "Math/Types.h"
#include "Framework/PlatformDefines.h"

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

        TT_FORCEINLINE Vec3 cross(const Vec3& other) const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE T dot(const Vec3& other) const;
        TT_FORCEINLINE Vec3<T> sqrt() const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE bool nearly_equal(const Vec3& other) const;

        TT_FORCEINLINE Vec3 operator +(const Vec3& other) const;
        TT_FORCEINLINE Vec3 operator -(const Vec3& other) const;
        TT_FORCEINLINE Vec3 operator *(const Vec3& other) const;
        TT_FORCEINLINE Vec3 operator *(T value) const;
        TT_FORCEINLINE Vec3& operator *=(T value);
        TT_FORCEINLINE Vec3 operator /(const Vec3& other) const;
        TT_FORCEINLINE Vec3 operator /(T value) const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE Vec3& operator +=(const Vec3<T>& other);
        TT_FORCEINLINE bool operator !=(const Vec3& other) const;
        TT_FORCEINLINE bool operator ==(const Vec3& other) const;
        TT_FORCEINLINE T operator[](size_t index) const;

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

}

namespace tt
{
    using Vector3f = math::Vec3<float>;
    using Vector3i = math::Vec3<int32>;
    using Vector3d = math::Vec3<double>;
    using Vector3  = Vector3f;
}

#include "Math/Vector3.inl"
