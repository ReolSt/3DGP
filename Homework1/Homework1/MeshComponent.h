#pragma once

#include "SceneComponent.h"

namespace Engine
{
	class MeshComponent : public SceneComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		MeshComponent(Actor* owner, const String& name);
	};
}