
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
	T Vec2<T>::operator[](int index) const
	{
		return data[index];
	}
}