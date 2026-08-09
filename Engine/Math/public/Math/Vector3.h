#pragma once

namespace math
{
	template<typename T>
	class alignas(16) Vec3
	{
	public:
		Vec3();
		Vec3(T x, T y, T z);
		Vec3(const Vec3<T>& other);
		Vec3(Vec3<T>&& other);

		Vec3 operator +(const Vec3& other) const;
		Vec3 operator -(const Vec3& other) const;
		Vec3 operator *(const Vec3& other) const;
		Vec3 operator *(T value) const;
		Vec3 operator /(const Vec3& other) const;
		Vec3 operator /(T value) const requires (!std::is_integral_v<T>);
		bool operator !=(const Vec3& other) const;
		bool operator ==(const Vec3& other) const;
		T operator[](int index) const;

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
	using Vector3i = Vec3<int>;
	using Vector3d = Vec3<double>;
	using Vector3  = Vector3f;
}

#include "Math/Vector3.inl"