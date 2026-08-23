#include "Math/Utils.h"

namespace math
{
    template <typename T>
    Vec3<T>::Vec3(T value)
        : x(value)
      , y(value)
      , z(value)
    {
    }

    template <typename T>
    Vec3<T>::Vec3()
        : x(T{})
      , y(T{})
      , z(T{})
    {
    }

    template <typename T>
    Vec3<T>::Vec3(T p_x,
                  T p_y,
                  T p_z)
        : x(p_x)
      , y(p_y)
      , z(p_z)
    {
    }

    template <typename T>
    Vec3<T>::Vec3(const Vec3<T>& other)
        : x(other.x)
      , y(other.y)
      , z(other.z)
    {
    }

    template <typename T>
    Vec3<T>::Vec3(Vec3<T>&& other) noexcept
        : x(other.x)
      , y(other.y)
      , z(other.z)
    {
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const
    {
        return {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    template <typename T>
    Vec3<T> Vec3<T>::cross(const Vec3<T>& other) const requires (!std::is_integral_v<T>)
    {
        return {
            (y * other.z) - (other.y * z),
            (z * other.x) - (other.z * x),
            (x * other.y) - (other.x * y)
        };
    }

    template <typename T>
    T Vec3<T>::dot(const Vec3<T>& other) const
    {
        Vec3 tmp(*this * other);

        return tmp.x + tmp.y + tmp.z;
    }

    template <typename T>
    Vec3<T> Vec3<T>::sqrt() const requires (!std::is_integral_v<T>)
    {
        return {std::sqrt(x), std::sqrt(y), std::sqrt(z)};
    }

    template <typename T>
    bool Vec3<T>::nearly_equal(const Vec3<T>& other) const
    {
        return math::nearly_equal(x, other.x)
                && math::nearly_equal(y, other.y)
                && math::nearly_equal(z, other.z);
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const
    {
        return {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator*(const Vec3<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.z
        };
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator*(T value) const
    {
        return {
            x * value,
            y * value,
            z * value
        };
    }

    template <typename T>
    Vec3<T>& Vec3<T>::operator*=(T value)
    {
        x *= value;
        y *= value;
        z *= value;

        return *this;
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator/(const Vec3<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.y
        };
    }

    template <typename T>
    Vec3<T> Vec3<T>::operator/(T value) const requires (!std::is_integral_v<T>)
    {
        return {
            x / value,
            y / value,
            z / value
        };
    }

    template <typename T>
    bool Vec3<T>::operator==(const Vec3<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    template <typename T>
    Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    template <typename T>
    bool Vec3<T>::operator!=(const Vec3<T>& other) const
    {
        return x != other.x || y != other.y || z != other.z;
    }

    template <typename T>
    T Vec3<T>::operator[](size_t index) const
    {
        return data[index];
    }
}
