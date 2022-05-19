#pragma once

#include "Core/Types.h"
#include "Core/ObjectBase.h"

namespace Engine
{
	class Asset : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Asset() { }
		virtual ~Asset() { }

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void load(const WString& assetFilePath) = 0;
		virtual void unload() = 0;
	};
}

