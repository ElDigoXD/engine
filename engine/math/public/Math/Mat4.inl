#pragma once

#include "Math/Common.h"

namespace math
{
    template <typename T>
    Matrix4x4<T>::Matrix4x4()
        : row1(T{static_cast<T>(1)}, T{}, T{}, T{})
        , row2(T{}, T{static_cast<T>(1)}, T{}, T{})
        , row3(T{}, T{}, T{static_cast<T>(1)}, T{})
        , row4(T{}, T{}, T{}, T{static_cast<T>(1)})
    {
    }

    template <typename T>
    Matrix4x4<T>::Matrix4x4(std::initializer_list<float> p_raw_data)
    {
        std::memcpy(raw_data, p_raw_data.begin(), sizeof(raw_data));
    }

    template <typename T>
    Matrix4x4<T>::Matrix4x4(
        const Vec4<T>& p_row1,
        const Vec4<T>& p_row2,
        const Vec4<T>& p_row3,
        const Vec4<T>& p_row4)
        : row1(p_row1)
        , row2(p_row2)
        , row3(p_row3)
        , row4(p_row4)
    {
    }

    template <typename T>
    Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& other)
        : row1(other.row1)
        , row2(other.row2)
        , row3(other.row3)
        , row4(other.row4)
    {
    }

    template <typename T>
    Matrix4x4<T>::Matrix4x4(Matrix4x4<T>&& other) noexcept
        : row1(std::move(other.row1))
        , row2(std::move(other.row2))
        , row3(std::move(other.row3))
        , row4(std::move(other.row4))
    {
    }

    template <typename T>
    Matrix4x4<T> Matrix4x4<T>::transpose() const
    {
        Matrix4x4<T> result;

        result.raw_data[0] = raw_data[0];
        result.raw_data[1] = raw_data[4];
        result.raw_data[2] = raw_data[8];
        result.raw_data[3] = raw_data[12];

        result.raw_data[4] = raw_data[1];
        result.raw_data[5] = raw_data[5];
        result.raw_data[6] = raw_data[9];
        result.raw_data[7] = raw_data[13];

        result.raw_data[8]  = raw_data[2];
        result.raw_data[9]  = raw_data[6];
        result.raw_data[10] = raw_data[10];
        result.raw_data[11] = raw_data[14];

        result.raw_data[12] = raw_data[3];
        result.raw_data[13] = raw_data[7];
        result.raw_data[14] = raw_data[11];
        result.raw_data[15] = raw_data[15];

        return result;
    }

    template<typename T>
    T Matrix4x4<T>::determinant() const
    {

        T SubFactor00 = raw_data[10] * raw_data[15] - raw_data[14] * raw_data[11];
        T SubFactor01 = raw_data[9]  * raw_data[15] - raw_data[13] * raw_data[11];
        T SubFactor02 = raw_data[9]  * raw_data[14] - raw_data[13] * raw_data[10];
        T SubFactor03 = raw_data[8]  * raw_data[15] - raw_data[12] * raw_data[11];
        T SubFactor04 = raw_data[8]  * raw_data[15] - raw_data[12] * raw_data[10];
        T SubFactor05 = raw_data[8]  * raw_data[13] - raw_data[12] * raw_data[9];

        Vec4<T> det_cof(
            + (raw_data[5] * SubFactor00 - raw_data[6] * SubFactor01 + raw_data[8] * SubFactor02),
            - (raw_data[4] * SubFactor00 - raw_data[6] * SubFactor03 + raw_data[7] * SubFactor04),
            + (raw_data[4] * SubFactor01 - raw_data[5] * SubFactor03 + raw_data[7] * SubFactor05),
            - (raw_data[4] * SubFactor02 - raw_data[5] * SubFactor04 + raw_data[6] * SubFactor05)
        );

        return raw_data[0] * det_cof[0]
            + raw_data[1] * det_cof[1]
            + raw_data[2] * det_cof[2]
            + raw_data[3] * det_cof[3];
    }

    template <typename T>
    Matrix4x4<T> Matrix4x4<T>::inverse() const
    {
        T Coef00 = raw_data[10] * raw_data[15] - raw_data[14] * raw_data[11];
		T Coef02 = raw_data[6]  * raw_data[15] - raw_data[14] * raw_data[7];
		T Coef03 = raw_data[6]  * raw_data[11] - raw_data[10] * raw_data[7];

		T Coef04 = raw_data[9] * raw_data[15] - raw_data[13] * raw_data[11];
		T Coef06 = raw_data[5] * raw_data[15] - raw_data[13] * raw_data[7];
		T Coef07 = raw_data[5] * raw_data[11] - raw_data[9]  * raw_data[7];

		T Coef08 = raw_data[9] * raw_data[14] - raw_data[13] * raw_data[10];
		T Coef10 = raw_data[5] * raw_data[14] - raw_data[13] * raw_data[6];
		T Coef11 = raw_data[5] * raw_data[10] - raw_data[9]  * raw_data[6];

		T Coef12 = raw_data[8] * raw_data[15] - raw_data[12] * raw_data[11];
		T Coef14 = raw_data[4] * raw_data[15] - raw_data[12] * raw_data[7];
		T Coef15 = raw_data[4] * raw_data[11] - raw_data[8]  * raw_data[7];

		T Coef16 = raw_data[8] * raw_data[14] - raw_data[12] * raw_data[10];
		T Coef18 = raw_data[4] * raw_data[14] - raw_data[12] * raw_data[6];
		T Coef19 = raw_data[4] * raw_data[8]  - raw_data[8]  * raw_data[6];

		T Coef20 = raw_data[2][0] * raw_data[3][1] - raw_data[3][0] * raw_data[2][1];
		T Coef22 = raw_data[1][0] * raw_data[3][1] - raw_data[3][0] * raw_data[1][1];
		T Coef23 = raw_data[1][0] * raw_data[2][1] - raw_data[2][0] * raw_data[1][1];

		Vec4<T> Fac0(Coef00, Coef00, Coef02, Coef03);
		Vec4<T> Fac1(Coef04, Coef04, Coef06, Coef07);
		Vec4<T> Fac2(Coef08, Coef08, Coef10, Coef11);
		Vec4<T> Fac3(Coef12, Coef12, Coef14, Coef15);
		Vec4<T> Fac4(Coef16, Coef16, Coef18, Coef19);
		Vec4<T> Fac5(Coef20, Coef20, Coef22, Coef23);

		Vec4<T> Vec0(raw_data[4], raw_data[0], raw_data[0], raw_data[0]);
		Vec4<T> Vec1(raw_data[5], raw_data[1], raw_data[1], raw_data[1]);
		Vec4<T> Vec2(raw_data[6], raw_data[2], raw_data[2], raw_data[2]);
		Vec4<T> Vec3(raw_data[7], raw_data[3], raw_data[3], raw_data[3]);

		Vec4<T> Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
		Vec4<T> Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
		Vec4<T> Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
		Vec4<T> Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

		Vec4<T> SignA(+1, -1, +1, -1);
		Vec4<T> SignB(-1, +1, -1, +1);
		Matrix4x4<T> Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

		Vec4<T> Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

		Vec4<T> Dot0(raw_data[0] * Row0);
		T Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

		T OneOverDeterminant = static_cast<T>(1) / Dot1;

		return Inverse * OneOverDeterminant;
    }

    template<typename T>
    Matrix4x4<T> & Matrix4x4<T>::operator=(const Matrix4x4 &other)
    {
        std::memcpy(raw_data, other.raw_data, sizeof(T) * 16);
        return *this;
    }

    template<typename T>
    bool Matrix4x4<T>::operator==(const Matrix4x4 &other) const
    {
        return data[0] == other.data[0]
            && data[1] == other.data[1]
            && data[2] == other.data[2]
            && data[3] == other.data[3];
    }

    template<typename T>
    bool Matrix4x4<T>::operator!=(const Matrix4x4 &other) const
    {
        return !operator==(other);
    }

    template<typename T>
    T Matrix4x4<T>::operator[](size_t index) const
    {
        return raw_data[index];
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator*(T scalar) const
    {
        return Matrix4x4<T>(
            data[0] * scalar,
            data[1] * scalar,
            data[2] * scalar,
            data[3] * scalar
        );
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator*=(T scalar)
    {
        data[0] *= scalar;
        data[1] *= scalar;
        data[2] *= scalar;
        data[3] *= scalar;

        return *this;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator/(T scalar) const
    {
        return Matrix4x4<T>(
            data[0] / scalar,
            data[1] / scalar,
            data[2] / scalar,
            data[3] / scalar
        );
    }
}
