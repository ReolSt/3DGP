#pragma once

#include "Core/Singleton.h"

namespace Engine
{
	class AssetLoader : public Singleton<AssetLoader>
	{
	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------
		void LoadAll();
	};
}