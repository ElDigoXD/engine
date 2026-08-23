#pragma once

namespace math
{
	template<typename T>
	class alignas(16) Vec2
	{
	public:
		using ValueType = T;

		Vec2();
		Vec2(T x, T y);
		Vec2(const Vec2<T>& other);
		Vec2(Vec2<T>&& other);

		T dot(const Vec2& other) const;
		Vec2<T> sqrt() const requires (!std::is_integral_v<T>);
		bool nearly_equal(const Vec2& other) const;

		Vec2 operator +(const Vec2& other) const;
		Vec2 operator -(const Vec2& other) const;
		Vec2 operator *(const Vec2& other) const;
		Vec2 operator *(T value) const;
		Vec2 operator /(const Vec2& other) const;
		Vec2 operator /(T value) const requires (!std::is_integral_v<T>);
		Vec2& operator +=(const Vec2<T>& rhs);
		bool operator !=(const Vec2& other) const;
		bool operator ==(const Vec2& other) const;
		T operator[](size_t index) const;

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


	using Vector2f = Vec2<float>;
	using Vector2i = Vec2<int>;
	using Vector2d = Vec2<double>;
	using Vector2  = Vector2f;
}

#include "Math/Vector2.inl"