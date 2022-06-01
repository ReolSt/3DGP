#pragma once

#include "Asset/Asset.h"
#include "Math/Math.h"

namespace Engine
{
	class TextureAsset : public Asset
	{
		AssetDefaultMacro(TextureAsset)

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		TextureAsset();
		virtual ~TextureAsset();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void load(const WString& assetFilePath) override;
		virtual void unload() override;

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

	};
}
