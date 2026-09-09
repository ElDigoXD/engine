#pragma once

#include "ECS/Component.h"
#include "ECS/Filter.h"
#include "ECS/TypeList.h"

namespace ecs
{
    template<typename T, typename List>
    struct Contains;

    template<typename T, typename... Types>
    struct Contains<T, TypeList<Types...>>
        : std::bool_constant<(std::is_same_v<T, Types> || ...)>
    {};

    template<template<typename...> typename Pattern, typename... Types>
    struct Get;

    template<template<typename...> typename Pattern>
    struct Get<Pattern>
    {
        using Type = TypeList<>;
    };

    template<template<typename...> typename Pattern, typename... Types, typename... Rest>
    struct Get<Pattern, Pattern<Types...>, Rest...>
    {
        using Type = TypeList<Types...>;
    };

    template<template<typename...> typename Pattern, typename First, typename... Rest>
    struct Get<Pattern, First, Rest...>
    : Get<Pattern, Rest...>
    {
    };

}

namespace ecs::query
{
    struct FilterTag {};

    struct IncludeTag : FilterTag {};
    struct ExcludeTag : FilterTag{};
    struct AddedTag : FilterTag{};
    struct RemovedTag : FilterTag{};
    struct HasTag : FilterTag{};

    template<typename... Types>
    requires ComponentTypes<Types...>
    struct Include : IncludeTag
    {
        using TypesList = ecs::TypeList<Types...>;

        template<typename T, typename Accesses>
        static constexpr bool CheckAccess()
        {
            using Component = std::remove_const_t<T>;

            using Reads  = typename ecs::Get<Access::Read, Accesses>::Type;
            using Writes = typename ecs::Get<Access::Write, Accesses>::Type;
            using All    = typename ecs::Get<Access::All, Accesses>::Type;

            if constexpr (std::is_const_v<T>)
            {
                return Contains<Component, Reads>::value ||
                       Contains<Component, All>::value;
            }
            else
            {
                return Contains<Component, Writes>::value ||
                       Contains<Component, All>::value;
            }
        }
        template<typename Accesses>
        static constexpr bool Check()
        {
            return (CheckAccess<Types, Accesses>() && ...);
        }
    };

    template<typename... Types>
    requires ComponentTypes<Types...>
    struct Exclude : ExcludeTag
    {
        using TypesList = ecs::TypeList<Types...>;

        template<typename T, typename Accesses>
        static constexpr bool CheckAccess()
        {
            using Component = std::remove_const_t<T>;

            using Reads  = typename Get<Access::Read, Accesses>::Type;
            using Writes = typename Get<Access::Write, Accesses>::Type;
            using All    = typename Get<Access::All, Accesses>::Type;

            if constexpr (std::is_const_v<T>)
            {
                return Contains<Component, Reads>::value ||
                       Contains<Component, All>::value;
            }
            else
            {
                return Contains<Component, Writes>::value ||
                       Contains<Component, All>::value;
            }
        }
        template<typename Accesses>
        static constexpr bool Check()
        {
            return (CheckAccess<Types, Accesses>() && ...);
        }
    };

    template<typename... Types>
    requires ComponentTypes<Types...>
    struct Added : AddedTag
    {
        using TypesList = ecs::TypeList<Types...>;

        template<typename T, typename Accesses>
        static constexpr bool CheckAccess()
        {
            using Component = std::remove_const_t<T>;

            using Reads  = typename Get<Access::Read, Accesses>::Type;
            using Writes = typename Get<Access::Write, Accesses>::Type;
            using All    = typename Get<Access::All, Accesses>::Type;

            if constexpr (std::is_const_v<T>)
            {
                return Contains<Component, Reads>::value ||
                       Contains<Component, All>::value;
            }
            else
            {
                return Contains<Component, Writes>::value ||
                       Contains<Component, All>::value;
            }
        }
        template<typename Accesses>
        static constexpr bool Check()
        {
            return (CheckAccess<Types, Accesses>() && ...);
        }
    };

    template<typename... Types>
    requires ComponentTypes<Types...>
    struct Removed : RemovedTag
    {
        using TypesList = ecs::TypeList<Types...>;

        template<typename T, typename Accesses>
        static constexpr bool CheckAccess()
        {
            using Component = std::remove_const_t<T>;

            using Reads  = typename Get<Access::Read, Accesses>::Type;
            using Writes = typename Get<Access::Write, Accesses>::Type;
            using All    = typename Get<Access::All, Accesses>::Type;

            if constexpr (std::is_const_v<T>)
            {
                return Contains<Component, Reads>::value ||
                       Contains<Component, All>::value;
            }
            else
            {
                return Contains<Component, Writes>::value ||
                       Contains<Component, All>::value;
            }
        }
        template<typename Accesses>
        static constexpr bool Check()
        {
            return (CheckAccess<Types, Accesses>() && ...);
        }
    };

    template<typename... Types>
    requires ComponentTypes<Types...>
    struct Has : HasTag
    {
        using TypesList = ecs::TypeList<Types...>;

        template<typename T, typename Accesses>
        static constexpr bool CheckAccess()
        {
            using Component = std::remove_const_t<T>;

            using Reads  = typename Get<Access::Read, Accesses>::Type;
            using Writes = typename Get<Access::Write, Accesses>::Type;
            using All    = typename Get<Access::All, Accesses>::Type;
            using Has    = typename Get<Access::Has, Accesses>::Type;

            if constexpr (std::is_const_v<T>)
            {
                return Contains<Component, Reads>::value ||
                       Contains<Component, Has>::value ||
                       Contains<Component, All>::value;
            }
            else
            {
                return Contains<Component, Writes>::value ||
                       Contains<Component, Has>::value ||
                       Contains<Component, All>::value;
            }
        }
        template<typename Accesses>
        static constexpr bool Check()
        {
            return (CheckAccess<Types, Accesses>() && ...);
        }
    };

    template<typename T>
    concept QueryFilter = std::derived_from<T, ecs::query::FilterTag>;

    template<template<typename...> class Filter, typename... Filters>
    struct Find
    {
        using Type = void;
    };

    template<template<typename...> typename Pattern,
             typename... Types,
             typename... Rest>
    struct Find<Pattern, Pattern<Types...>, Rest...>
    {
        using Type = Pattern<Types...>;
    };

    template<template<typename...> typename Pattern,
             typename First,
             typename... Rest>
    struct Find<Pattern, First, Rest...>
        : Find<Pattern, Rest...>
    {
    };
}

