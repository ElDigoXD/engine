#pragma once

namespace math
{
    template <typename T>
    T::ValueType distance(const T& vector_a, const T& vector_b);

    template <typename T>
    T::ValueType length(const T& vector);

    template <typename T>
    T normalize(const T& vector);
}

#include "Math/Geometric.inl"
