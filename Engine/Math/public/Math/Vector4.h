#pragma once

namespace math
{
	template<typename T>
	class alignas(16) Vec4
	{
	public:
		Vec4();
		Vec4(T x, T y, T z, T w);
		Vec4(const Vec4<T>& other);
		Vec4(Vec4<T>&& other);

		Vec4 cross(const Vec4& other) const requires (!std::is_integral_v<T>);
		T dot(const Vec4& other) const;
		Vec4 operator +(const Vec4& other) const;
		Vec4 operator -(const Vec4& other) const;
		Vec4 operator *(const Vec4& other) const;
		Vec4 operator *(T value) const;
		Vec4 operator /(const Vec4& other) const;
		Vec4 operator /(T value) const requires (!std::is_integral_v<T>);
		Vec4& operator +=(const Vec4<T>& rhs);
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
	using Vector4i = Vec4<int>;
	using Vector4d = Vec4<double>;
	using Vector4  = Vector4f;
}

#include "Math/Vector4.inl"