#pragma once

#include "Singleton.h"
#include "World.h"

namespace Engine
{
	class GameEngine : public Singleton<GameEngine>
	{

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		World* m_world;
	};


}