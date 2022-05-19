#pragma once

#include "Asset/DXShaderAsset.h"

namespace Engine
{
	class DXVertexShaderAsset : public DXShaderAsset
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DXVertexShaderAsset();
		virtual ~DXVertexShaderAsset();

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void load(const WString& assetFilePath) override;
		void unload() override;
	};
}

class DXVertexShaderAsset
{
};

