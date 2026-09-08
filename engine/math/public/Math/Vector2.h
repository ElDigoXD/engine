#pragma once

#include "Math/Types.h"
#include "Framework/PlatformDefines.h"

namespace math
{
    template <typename T>
    class alignas(16) Vec2
    {
    public:
        using ValueType = T;

        Vec2();
        Vec2(T x,
             T y);
        Vec2(const Vec2<T>& other);
        Vec2(Vec2<T>&& other) noexcept;

        TT_FORCEINLINE T dot(const Vec2& other) const;
        TT_FORCEINLINE Vec2<T> sqrt() const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE bool nearly_equal(const Vec2& other) const;

        TT_FORCEINLINE Vec2 operator +(const Vec2& other) const;
        TT_FORCEINLINE Vec2 operator -(const Vec2& other) const;
        TT_FORCEINLINE Vec2 operator *(const Vec2& other) const;
        TT_FORCEINLINE Vec2 operator *(T value) const;
        TT_FORCEINLINE Vec2 operator /(const Vec2& other) const;
        TT_FORCEINLINE Vec2 operator /(T value) const requires (!std::is_integral_v<T>);
        TT_FORCEINLINE Vec2& operator +=(const Vec2<T>& rhs);
        TT_FORCEINLINE bool operator !=(const Vec2& other) const;
        TT_FORCEINLINE bool operator ==(const Vec2& other) const;
        TT_FORCEINLINE T operator[](size_t index) const;

        union
        {
            struct
            {
                T x;
                T y;
            };

            T data[2];
        };
    };



}

namespace tt
{
    using Vector2f = math::Vec2<float>;
    using Vector2i = math::Vec2<int32>;
    using Vector2d = math::Vec2<double>;
    using Vector2  = Vector2f;
}

#include "Math/Vector2.inl"
