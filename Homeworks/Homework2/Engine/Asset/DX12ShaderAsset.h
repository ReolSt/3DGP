#pragma once

#include "Asset/Asset.h"

namespace Engine
{
	class DX12ShaderAsset : public Asset
	{
		AssetDefaultMacro(DX12ShaderAsset)

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12ShaderAsset();
		virtual ~DX12ShaderAsset();

	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void load(const WString& assetFilePath) override;
		virtual void unload() override;

	};
}

