#pragma once

#include "Core/Module.h"
#include "ECS/Component.h"
#include "ECS/Entity.h"
#include "ECS/System.h"

namespace ecs
{
    class Stage;

    template<typename... Ts>
    requires ComponentTypes<Ts...>
    struct ComponentTypeList
    {

    };
}

namespace ecs
{
    class World
    {
    public:
        template<ComponentType T, typename... Args>
        T& add_component(Args&&... args);

        template<tt::ModuleType T>
        void add_module();
        //
        // using Modules = ModuleList<RenderModule, PhysicsModules>;
        // add_modulde(Modules {});
        //void add_modules(ecs::ModuleList modules);

        /* WARNING.
         * Permitir hacer esto tiene muchas implicaciones, habria que
         * guardar las dependencias y quitar o avisar si un modulo
         * dependia del otro.
         */
        template<tt::ModuleType T>
        void remove_module();

        template<SystemType T>
        void register_system();

        template<ComponentType T>
        void register_component();

        template <typename... T>
        void register_components();
    private:

        ecs::Stage* stages = nullptr;
        size_t stage_count = 0;
    };


}


#include "ECS/World.inl"
