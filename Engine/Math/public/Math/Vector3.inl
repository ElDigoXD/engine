
namespace math
{
	template<typename T>
	Vec3<T>::Vec3()
		: x(T{})
		, y(T{})
		, z(T{})
	{

	}

	template<typename T>
	Vec3<T>::Vec3(T p_x, T p_y, T p_z)
		: x(p_x)
		, y(p_y)
		, z(p_z)
	{

	}

	template<typename T>
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
	T Vec3<T>::operator[](int index) const
	{
		return data[index];
	}
}