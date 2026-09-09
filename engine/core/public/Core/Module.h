#pragma once

#include <concepts>


namespace tt
{
    template<typename T>
    concept HasRegisterEditorComponents = requires(T& t)
    {
        t.register_editor_components();
    };

    template<typename T>
    concept HasRegisterEditorSystems = requires(T& t)
    {
        t.register_editor_systems();
    };

    //TODO Cuando tengamos el world seria concept HasRegisterSystems = requires(T& t, World& world)
    //t.register_systems(world);
    template<typename T>
    concept HasRegisterSystems = requires(T& t)
    {
        t.register_systems();
    };

    template<typename T>
    concept HasRegisterComponents = requires(T& t)
    {
        t.register_components();
    };

    template<typename T>
    concept HasEditorSystems = requires
    {
        typename T::EditorSystems;
    };

    template<typename T>
    concept HasEditorComponents = requires
    {
        typename T::EditorComponents;
    };

    template<typename T>
    concept ModuleType = requires
    {
        { T::is_editor } -> std::convertible_to<bool>;
        { T::name }      -> std::convertible_to<const char*>;
        typename T::Systems;
    };

    template<typename... Ts>
    concept ModuleTypes = (ModuleType<Ts> && ...);

    template<typename... Ts>
    requires ModuleTypes<Ts...>
    struct ModuleList
    {
    };
}


