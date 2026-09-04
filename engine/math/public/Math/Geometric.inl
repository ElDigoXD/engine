#include <cmath>

template <typename T>
T math::normalize(const T& vector)
{
    static_assert(!std::is_integral_v<typename T::ValueType>, "Vector type is not floating-point");

    return vector * (1 / sqrt(vector.dot(vector)));
}

template <typename T>
T::ValueType math::length(const T& vector)
{
    return std::sqrt(vector.dot(vector));;
}

template <typename T>
T::ValueType math::distance(const T& vector_a, const T& vector_b)
{
    T tmp = vector_b - vector_a;
    return math::length(tmp);
}
