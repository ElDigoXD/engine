#pragma once

#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

namespace math
{
    template <typename T>
    Vec4<T> xyz0(const Vec3<T>& vec);

    template <typename T>
    Vec3<T> xy0(const Vec2<T>& vec);

    template <typename T>
    Vec4<T> xyz1(const Vec3<T>& vec);

    template <typename T>
    Vec3<T> xy1(const Vec2<T>& vec);

    template <typename T>
    Vec3<T> xyz(const Vec4<T>& vec);

    template <typename T>
    Vec2<T> xy(const Vec4<T>& vec);

    template <typename T>
    Vec2<T> xy(const Vec3<T>& vec);
}

#include "Math/Common.inl"
