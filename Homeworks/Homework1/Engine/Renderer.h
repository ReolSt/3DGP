#pragma once

#include "ObjectBase.h"

namespace Engine
{
	class GameEngine;

	class Renderer : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Renderer();
		virtual ~Renderer();

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void render(GameEngine* engine) = 0;

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------
	};
}