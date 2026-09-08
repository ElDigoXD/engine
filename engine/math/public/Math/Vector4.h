#pragma once

#include "Math/Types.h"
#include "Framework/PlatformDefines.h"

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

        TT_FORCEINLINE Vec4 cross(const Vec4& other) const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE T dot(const Vec4& other) const;
        TT_FORCEINLINE bool nearly_equal(const Vec4& other) const;

        TT_FORCEINLINE Vec4 operator +(const Vec4& other) const;
        TT_FORCEINLINE Vec4 operator -(const Vec4& other) const;
        TT_FORCEINLINE Vec4 operator *(const Vec4& other) const;
        TT_FORCEINLINE Vec4 operator *(T value) const;
        TT_FORCEINLINE Vec4 operator /(const Vec4& other) const;
        TT_FORCEINLINE Vec4 operator /(T value) const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE Vec4& operator +=(const Vec4<T>& other);
        TT_FORCEINLINE bool operator !=(const Vec4& other) const;
        TT_FORCEINLINE bool operator ==(const Vec4& other) const;
        TT_FORCEINLINE T operator[](size_t index) const;

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
}

namespace tt
{
    using Vector4f = math::Vec4<float>;
    using Vector4i = math::Vec4<int32>;
    using Vector4d = math::Vec4<double>;
    using Vector4  = Vector4f;
}

#include "Math/Vector4.inl"
