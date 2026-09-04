#include <cmath>

template <typename T>
bool math::nearly_equal(const T& a, const T& b)
{
    if constexpr (std::is_integral_v<T>)
    {
        return a == b;
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        constexpr T epsilon = static_cast<T>(1e-5);
        return std::abs(a - b) <= epsilon;
    }
    else
    {
        return a.nearly_equal(b);
    }
}
