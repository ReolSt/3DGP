#pragma once

#include "Core/Types.h"
#include "Core/ObjectBase.h"

#include "Asset/AssetStorage.h"

#define AssetDefaultMacro(AssetClassName) \
public: \
inline static AssetClassName* Load(const WString& assetFilePath) \
{ \
    if(Asset::IsLoaded(assetFilePath)) \
	{ \
		return dynamic_cast<AssetClassName*>(AssetStorage::GetRegisteredAsset(assetFilePath)); \
    } \
    AssetClassName* asset = new AssetClassName(); \
	asset->load(assetFilePath); \
	return asset; \
} \


namespace Engine
{
	class Asset : public ObjectBase
	{
		AssetDefaultMacro(Asset)

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Asset() { }
		virtual ~Asset() { }

	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

		static bool IsLoaded(const WString& assetFilePath);

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		virtual void load(const WString& assetFilePath);
		virtual void unload();

		bool isLoaded();

	private:
		WString m_assetFilePath;
	};
}

