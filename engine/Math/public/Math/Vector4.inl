#include "Math/Utils.h"

namespace math
{
    template <typename T>
    Vec4<T>::Vec4()
        : x(T{})
        , y(T{})
        , z(T{})
        , w(T{})
    {
    }

    template <typename T>
    Vec4<T>::Vec4(T p_x, T p_y, T p_z, T p_w)
        : x(p_x)
        , y(p_y)
        , z(p_z)
        , w(p_w)
    {
    }

    template <typename T>
    Vec4<T>::Vec4(const Vec4<T>& other)
        : x(other.x)
        , y(other.y)
        , z(other.z)
        , w(other.w)
    {
    }

    template <typename T>
    Vec4<T>::Vec4(Vec4<T>&& other) noexcept
        : x(other.x)
        , y(other.y)
        , z(other.z)
        , w(other.w)
    {
    }

    template <typename T>
    Vec4<T> Vec4<T>::cross(const Vec4<T>& other) const requires (!std::is_integral_v<T>)
    {
        return {
            (y * other.z) - other.y * z,
            (z * other.x) - other.z * x,
            (x * other.y) - other.x * y,
            0.0f
        };
    }

    template <typename T>
    T Vec4<T>::dot(const Vec4<T>& other) const
    {
        Vec4 tmp(*this * other);

        return (tmp.x + tmp.y) + (tmp.z + tmp.w);
    }

    template <typename T>
    bool Vec4<T>::nearly_equal(const Vec4<T>& other) const
    {
        return math::nearly_equal(x, other.x)
            && math::nearly_equal(y, other.y)
            && math::nearly_equal(z, other.z)
            && math::nearly_equal(w, other.w);
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator+(const Vec4<T>& other) const
    {
        return {
            x + other.x,
            y + other.y,
            z + other.z,
            w + other.w
        };
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator-(const Vec4<T>& other) const
    {
        return {
            x - other.x,
            y - other.y,
            z - other.z,
            w - other.w
        };
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator*(const Vec4<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.z,
            w * other.w
        };
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator*(T value) const
    {
        return {
            x * value,
            y * value,
            z * value,
            w * value
        };
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator/(const Vec4<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.y,
            w * other.w
        };
    }

    template <typename T>
    Vec4<T> Vec4<T>::operator/(T value) const requires (!std::is_integral_v<T>)
    {
        return {
            x / value,
            y / value,
            z / value,
            w / value
        };
    }

    template <typename T>
    bool Vec4<T>::operator==(const Vec4<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    template <typename T>
    bool Vec4<T>::operator!=(const Vec4<T>& other) const
    {
        return x != other.x || y != other.y || z != other.z || w != other.w;
    }

    template <typename T>
    T Vec4<T>::operator[](size_t index) const
    {
        return data[index];
    }

    template <typename T>
    Vec4<T>& Vec4<T>::operator+=(const Vec4<T>& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;

        return *this;
    }
}
