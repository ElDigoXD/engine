#pragma once

#include "RenderLibType.h"

namespace tt
{
    struct RENDER_API RenderModule
    {
        static constexpr bool is_editor = false;
        static constexpr const char* name = "render_module";
    };
}