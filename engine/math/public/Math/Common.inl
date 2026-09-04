template <typename T>
math::Vec4<T> math::xyz0(const math::Vec3<T>& vec)
{
    return math::Vec4<T>(vec.x, vec.y, vec.z, T{});
}

template <typename T>
math::Vec3<T> math::xy0(const math::Vec2<T>& vec)
{
    return math::Vec3<T>(vec.x, vec.y, T{});
}

template <typename T>
math::Vec4<T> math::xyz1(const math::Vec3<T>& vec)
{
    return math::Vec4<T>(vec.x, vec.y, vec.z, T{1});
}

template <typename T>
math::Vec3<T> math::xy1(const math::Vec2<T>& vec)
{
    return math::Vec3<T>(vec.x, vec.y, T{1});
}

template <typename T>
math::Vec3<T> math::xyz(const math::Vec4<T>& vec)
{
    return math::Vec3<T>(vec.x, vec.y, vec.z);
}

template <typename T>
math::Vec2<T> math::xy(const math::Vec4<T>& vec)
{
    return math::Vec2<T>(vec.x, vec.y);
}

template <typename T>
math::Vec2<T> math::xy(const math::Vec3<T>& vec)
{
    return math::Vec2<T>(vec.x, vec.y);
}
