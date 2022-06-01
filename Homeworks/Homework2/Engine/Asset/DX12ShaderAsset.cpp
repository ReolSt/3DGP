#include "DX12ShaderAsset.h"

#include "Asset/AssetStorage.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	DX12ShaderAsset::DX12ShaderAsset()
	{

	}

	DX12ShaderAsset::~DX12ShaderAsset()
	{
		
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void DX12ShaderAsset::load(const WString& assetFilePath)
	{
		Asset::load(assetFilePath);
	}

	void DX12ShaderAsset::unload()
	{
		Asset::unload();
	}
}


