#pragma once

#include "Asset/Asset.h"

namespace Engine
{
	class DXShaderAsset : public Asset
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DXShaderAsset();
		virtual ~DXShaderAsset();

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void load(const WString& assetFilePath) override;
		virtual void unload() override;

	};
}

