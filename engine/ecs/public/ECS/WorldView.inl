#pragma once
#include "Query.h"

template<ecs::query::QueryFilter Filter, ecs::AccessFilter... FilterAccess>
consteval bool ecs::WorldView::CheckFilter()
{
    if constexpr (std::is_same<Filter, ecs::query::Include>::value)
    {
        return ecs::query::Include::template Check<FilterAccess...>();
    }
    else if constexpr (std::is_same<Filter, ecs::query::Exclude>::value)
    {
        return ecs::query::Exclude::template Check<FilterAccess...>();
    }
    else if constexpr (std::is_same<Filter, ecs::query::Has>::value)
    {
        return ecs::query::Has::template Check<FilterAccess...>();
    }
}

template <ecs::AccessFilter ... FilterAccess>
template<ecs::query::QueryFilter... Filters>
requires (CheckFilter<Filters, FilterAccess...> && ...)
void ecs::WorldView<FilterAccess...>::Query()
{

}


