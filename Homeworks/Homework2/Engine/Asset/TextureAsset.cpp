#include "TextureAsset.h"

#include "Asset/AssetStorage.h"
#include "Math/Math.h"

#include <string>

namespace Engine
{
	using namespace Math;

	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	TextureAsset::TextureAsset()
	{

	}

	TextureAsset::~TextureAsset()
	{
		
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void TextureAsset::load(const WString& assetFilePath)
	{
		Asset::load(assetFilePath);

		std::string filePath;
		filePath.assign(assetFilePath.begin(), assetFilePath.end());

		FILE* file = fopen(filePath.c_str(), "r");
		if (file == NULL)
		{
			return;
		}
	}

	void TextureAsset::unload()
	{
		Asset::unload();
	}
}


