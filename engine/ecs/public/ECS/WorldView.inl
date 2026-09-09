#pragma once

template <ecs::AccessFilter ... FilterAccess>
template<ecs::query::QueryFilter... Filters>
// ReSharper disable once CppMemberFunctionMayBeConst
void ecs::WorldView<FilterAccess...>::Query()
{
    using Includes =
        typename ecs::query::Find<
            ecs::query::Include,
            Filters...
        >::Type;

    using Excludes =
        typename ecs::query::Find<
            ecs::query::Exclude,
            Filters...
        >::Type;

    using Has =
        typename ecs::query::Find<
            ecs::query::Has,
            Filters...
        >::Type;

    static_assert(Includes::template Check<FilterAccess...>());
}
