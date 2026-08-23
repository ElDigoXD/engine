
#include "Math/Utils.h"

namespace math
{
	template<typename T>
	Vec2<T>::Vec2()
		: x(T{})
		, y(T{})
	{
		
	}

	template<typename T>
	Vec2<T>::Vec2(T p_x, T p_y)
		: x(p_x)
		, y(p_y)
	{

	}

	template<typename T>
	Vec2<T>::Vec2(const Vec2<T>& other)
		: x(other.x)
		, y(other.y)
	{

	}

	template<typename T>
	Vec2<T>::Vec2(Vec2<T>&& other)
		: x(other.x)
		, y(other.y)
	{

	}

	template<typename T>
	T Vec2<T>::dot(const Vec2<T>& other) const
	{
		Vec2 tmp(*this * other);
		return tmp.x + tmp.y;
	}

	template<typename T>
	bool Vec2<T>::nearly_equal(const Vec2<T>& other) const
	{
		return math::nearly_equal(x, other.x) && math::nearly_equal(y, other.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::sqrt() const requires (!std::is_integral_v<T>)
	{
		return { std::sqrt(x), std::sqrt(y) };
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator+(const Vec2<T>& other) const
	{
		return {
			x + other.x,
			y + other.y
		};
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator-(const Vec2<T>& other) const
	{
		return {
			x - other.x,
			y - other.y
		};
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator*(const Vec2<T>& other) const
	{
		return {
			x * other.x,
			y * other.y
		};
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator*(T value) const
	{
		return {
			x * value,
			y * value
		};
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator/(const Vec2<T>& other) const
	{
		return {
			x * other.x,
			y * other.y
		};
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator/(T value) const requires (!std::is_integral_v<T>)
	{
		return {
			x / value,
			y / value
		};
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	template<typename T>
	bool Vec2<T>::operator==(const Vec2<T>& other) const
	{
		return x == other.x && y == other.y;
	}

	template<typename T>
	bool Vec2<T>::operator!=(const Vec2<T>& other) const
	{
		return x != other.x || y != other.y;
	}

	template<typename T>
	T Vec2<T>::operator[](size_t index) const
	{
		return data[index];
	}
}