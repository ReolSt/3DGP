#pragma once

#include "Component.h"

namespace Engine
{
	class Actor;

	class StaticMeshComponent : public Component
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		StaticMeshComponent(Actor* owner, const std::string& name);
	};
}