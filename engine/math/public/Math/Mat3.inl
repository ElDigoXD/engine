#pragma once

#include "Math/Common.h"

namespace math
{
    template <typename T>
    Matrix3x3<T>::Matrix3x3()
        : row1(T{static_cast<T>(1)}, T{}, T{})
        , row2(T{}, T{static_cast<T>(1)}, T{})
        , row3(T{}, T{}, T{static_cast<T>(1)})
    {
    }

    template <typename T>
    Matrix3x3<T>::Matrix3x3(std::initializer_list<float> p_raw_data)
    {
        std::memcpy(raw_data, p_raw_data.begin(), sizeof(raw_data));
    }

    template <typename T>
    Matrix3x3<T>::Matrix3x3(
        const Vec3<T>& p_row1,
        const Vec3<T>& p_row2,
        const Vec3<T>& p_row3)
        : row1(p_row1)
        , row2(p_row2)
        , row3(p_row3)
    {
    }

    template <typename T>
    Matrix3x3<T>::Matrix3x3(const Matrix3x3<T>& other)
        : row1(other.row1)
        , row2(other.row2)
        , row3(other.row3)
    {
    }

    template <typename T>
    Matrix3x3<T>::Matrix3x3(
        Matrix3x3<T>&& other) noexcept
        : row1(std::move(other.row1))
        , row2(std::move(other.row2))
        , row3(std::move(other.row3))
    {
    }

    template <typename T>
    Matrix3x3<T> Matrix3x3<T>::transpose() const
    {
        Matrix3x3<T> result;

        result.raw_data[0] = raw_data[0];
        result.raw_data[1] = raw_data[3];
        result.raw_data[2] = raw_data[6];

        result.raw_data[3] = raw_data[1];
        result.raw_data[4] = raw_data[4];
        result.raw_data[5] = raw_data[7];

        result.raw_data[6] = raw_data[2];
        result.raw_data[7] = raw_data[5];
        result.raw_data[8] = raw_data[8];

        return result;
    }

    template <typename T>
    T Matrix3x3<T>::determinant() const
    {
        return +raw_data[0] * (raw_data[4] * raw_data[8] - raw_data[7] * raw_data[5])
            - raw_data[3] * (raw_data[1] * raw_data[8] - raw_data[7] * raw_data[2])
            + raw_data[6] * (raw_data[1] * raw_data[5] - raw_data[4] * raw_data[2]);
    }

    template <typename T>
    Matrix3x3<T> Matrix3x3<T>::inverse() const
    {
        Vec4<T> a = xyz0(row1);
        Vec4<T> b = xyz0(row2);
        Vec4<T> c = xyz0(row3);

        Vec4<T> i0 = b.cross(c);
        Vec4<T> i1 = c.cross(a);
        Vec4<T> i2 = a.cross(b);

        Matrix3x3<T> inverse(xyz(i0), xyz(i1), xyz(i2));
        inverse = inverse.transpose();

        T determinant = a.dot(b.cross(c));

        inverse *= (static_cast<T>(1) / determinant);

        return inverse;
    }

    template <typename T>
    Matrix3x3<T>& Matrix3x3<T>::operator=(const Matrix3x3& other)
    {
        std::memcpy(raw_data, other.raw_data, sizeof(T) * 9);
        return *this;
    }


    template <typename T>
    Matrix3x3<T> Matrix3x3<T>::operator *(const Matrix3x3<T>& other) const
    {
        Vec3 tmp0 = data[0] * other.row1.x;
        tmp0      += data[1] * other.row1.y;
        tmp0      += data[2] * other.row1.z;

        Vec3 tmp1 = data[0] * other.row2.x;
        tmp1      += data[1] * other.row2.y;
        tmp1      += data[2] * other.row2.z;

        Vec3 tmp2 = data[0] * other.row3.x;
        tmp2      += data[1] * other.row3.y;
        tmp2      += data[2] * other.row3.z;

        return {
            tmp0,
            tmp1,
            tmp2
        };
    }

    template <typename T>
    Vec2<T> Matrix3x3<T>::operator *(const Vec2<T>& other) const
    {
        return {
            row1.x * other.x + row1.y * other.y + row1.z,
            row2.x * other.x + row2.y * other.y + row2.z
        };
    }

    template <typename T>
    bool Matrix3x3<T>::operator ==(const Matrix3x3<T>& other) const
    {
        return row1 == other.row1 && row2 == other.row2 && row3 == other.row3;
    }

    template <typename T>
    bool Matrix3x3<T>::operator !=(const Matrix3x3<T>& other) const
    {
        return row1 != other.row1 || row2 != other.row2 || row3 != other.row3;
    }

    template <typename T>
    T Matrix3x3<T>::operator [](size_t index) const
    {
        return raw_data[index];
    }

    template <typename T>
    Matrix3x3<T> Matrix3x3<T>::operator *(T scalar) const
    {
        return {
            row1 * scalar,
            row2 * scalar,
            row3 * scalar
        };
    }

    template <typename T>
    Matrix3x3<T>& Matrix3x3<T>::operator *=(T scalar)
    {
        row1 *= scalar;
        row2 *= scalar;
        row3 *= scalar;

        return *this;
    }

    template <typename T>
    Matrix3x3<T> Matrix3x3<T>::operator /(
        T scalar) const
    {
        return {
            row1 / scalar,
            row2 / scalar,
            row3 / scalar
        };
    }

    /*template<typename T>
    Vec3<T>::Vec3(const Vec3<T>& other)
        : x(other.x)
        , y(other.y)
        , z(other.z)
    {

    }

    template<typename T>
    Vec3<T>::Vec3(Vec3<T>&& other)
        : x(other.x)
        , y(other.y)
        , z(other.z)
    {

    }

    template<typename T>
    Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const
    {
        return {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    template<typename T>
    Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const
    {
        return {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }

    template<typename T>
    Vec3<T> Vec3<T>::operator*(const Vec3<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.z
        };
    }

    template<typename T>
    Vec3<T> Vec3<T>::operator*(T value) const
    {
        return {
            x * value,
            y * value,
            z * value
        };
    }

    template<typename T>
    Vec3<T> Vec3<T>::operator/(const Vec3<T>& other) const
    {
        return {
            x * other.x,
            y * other.y,
            z * other.y
        };
    }

    template<typename T>
    Vec3<T> Vec3<T>::operator/(T value) const requires (!std::is_integral_v<T>)
    {
        return {
            x / value,
            y / value,
            z / value
        };
    }

    template<typename T>
    bool Vec3<T>::operator==(const Vec3<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    template<typename T>
    bool Vec3<T>::operator!=(const Vec3<T>& other) const
    {
        return x != other.x || y != other.y || z != other.z;
    }

    template<typename T>
    T Vec3<T>::operator[](size_t index) const
    {
        return data[index];
    }*/
}
