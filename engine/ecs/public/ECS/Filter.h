#pragma once

#include <type_traits>

#include "ECS/Component.h"
#include "ECS/TypeList.h"

namespace ecs
{
     // ============================================================
    // Access
    // ============================================================
    struct AccessType {};

    struct Access
    {
        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct All : AccessType
        {
        };

        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct Add : AccessType
        {
        };

        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct Remove : AccessType
        {
        };

        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct Has : AccessType
        {
        };

        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct Read : AccessType
        {
        };

        template<typename... Ts>
        requires ComponentTypes<Ts...>
        struct Write : AccessType
        {
        };
    };

    template<typename T>
    concept AccessFilter = std::derived_from<T, AccessType>;

    // ============================================================
    // Helper para comprobar si un tipo está en una lista
    // ============================================================
    template<typename T, typename... Ts>
    concept OneOf = (std::is_same_v<T, Ts> || ...);

    // ============================================================
    // Error intencionado.
    //
    // NO definir esta estructura.
    //
    // Cuando falte un componente, el compilador mostrará:
    //
    //     MissingAccess<Suyo>
    //
    // Esto permite saber exactamente qué componente falta.
    // ============================================================
    template<typename T>
    struct MissingAccess;

    // ============================================================
    // SatisfiesAccess
    //
    // Reglas:
    //    Required  | Available
    //     Has<T>   <- Add<T>    OK
    //     Has<T>   <- All<T>    OK
    //     Has<T>   <- Has<T>    OK
    //     Has<T>   <- Read<T>   OK
    //     Has<T>   <- Write<T>  OK
    //     ------------------
    //     Read<T>  <- All<T>    OK
    //     Read<T>  <- Read<T>   OK
    //     Read<T>  <- Write<T>  OK
    //     ------------------
    //     Write<T> <- All<T>    OK
    //     Write<T> <- Write<T>  OK
    //     Write<T> <- Read<T>   NO
    //
    // Para varios componentes:
    //
    //     Read<A, B> <- Write<A, B, C>   OK
    //     Write<A, B> <- Write<A, B, C>  OK
    //
    // El orden NO importa.
    // ============================================================

    template<typename Required, typename Available>
    struct satisfies_access : std::false_type
    {
    };

    // ------------------------------------------------------------
    // Read<Required...> <- All<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Read<Required...>, Access::All<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Read<Required...> <- Read<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Read<Required...>, Access::Read<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Read<Required...> <- Write<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Read<Required...>, Access::Write<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Has<Required...> <- All<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Has<Required...>, Access::All<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Has<Required...> <- Add<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Has<Required...>, Access::Add<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Has<Required...> <- Write<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Has<Required...>, Access::Write<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Has<Required...> <- Read<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Has<Required...>, Access::Read<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Has<Required...> <- Has<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Has<Required...>, Access::Has<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ------------------------------------------------------------
    // Write<Required...> <- Write<Available...>
    // ------------------------------------------------------------

    template<typename... Required, typename... Available>
    struct satisfies_access<Access::Write<Required...>, Access::Write<Available...>>
        : std::bool_constant<(OneOf<Required, Available...> && ...)>
    {
    };

    // ============================================================
    // Concept para un acceso
    // ============================================================
    template<typename Required, typename Available>
    concept SatisfiesAccess = satisfies_access<Required, Available>::value;


    // ============================================================
    // ¿Existe algún Available que satisfaga Required?
    // ============================================================
    template<typename Required, typename... Available>
    concept HasSatisfyingAccess = (SatisfiesAccess<Required, Available> || ...);

    // ============================================================
    // CheckAccess
    //
    // Comprueba un acceso completo.
    //
    // Ejemplo:
    //
    //     CheckAccess<
    //         Write<Mio, Suyo>,
    //         Write<Mio>,
    //         Read<Otro>
    //     >
    //
    // Primero comprueba Mio.
    // Después comprueba Suyo.
    //
    // Y si Suyo no existe, aparecerá:
    //
    //     MissingAccess<Suyo>
    // ============================================================
    template<typename Required, typename... Available>
    consteval bool CheckAccess()
    {
        if constexpr (HasSatisfyingAccess<Required, Available...>)
        {
            return true;
        }
        else
        {
            // Este caso sirve para cuando no existe ningún
            // acceso compatible con Required.
            MissingAccess<Required> error;

            return false;
        }
    }

    // ============================================================
    // Comprobar TODOS los accesos de una WorldView
    // ============================================================
    template<typename RequiredList, typename AvailableList>
    struct AllAccessesSatisfied;

    // ------------------------------------------------------------
    // Descomponemos las dos TypeList
    // ------------------------------------------------------------
    template<typename... Required, typename... Available>
    struct AllAccessesSatisfied<TypeList<Required...>, TypeList<Available...>>
    {
        static constexpr bool value = (CheckAccess<Required, Available...>() && ...);
    };

    // ============================================================
    // Concept final
    // ============================================================
    template<typename Required, typename Available>
    concept CompatibleWorldViews =  AllAccessesSatisfied<typename Required::accesses, typename Available::accesses>::value;
}
