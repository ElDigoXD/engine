#pragma once

#include "Core/Types.h"

namespace ecs
{
	struct EntityId
	{
		uint32 generation;
		uint32 index;
	};

	using EntityHandle = EntityId;
}