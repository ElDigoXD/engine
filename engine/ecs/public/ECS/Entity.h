#pragma once

#include "Core/Types.h"
#include "ECSLibType.h"

namespace ecs
{
	struct ECS_API EntityId
	{
		uint32 generation;
		uint32 index;
	};

	using EntityHandle = EntityId;
}