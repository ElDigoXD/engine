#pragma once

namespace ecs
{
    template<typename... Ts>
    class TypeList
    {
    public:
        // --------------------------------------------------------
        // Contains
        // --------------------------------------------------------

        template<typename T>
        static constexpr bool Contains = (std::is_same_v<T, Ts> || ...);

        // --------------------------------------------------------
        // AddUnique
        // --------------------------------------------------------

        template<typename T>
        using AddUnique =
            std::conditional_t<
                Contains<T>,
                TypeList<Ts...>,
                TypeList<Ts..., T>
            >;

        template<template<typename...> class T>
        using As = T<Ts...>;
    };
}