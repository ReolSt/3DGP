#include "Asset.h"

#include "Asset/AssetStorage.h"

namespace Engine
{
	bool Asset::IsLoaded(const WString& assetFilePath)
	{
		return AssetStorage::IsRegistered(assetFilePath);
	}

	void Asset::load(const WString& assetFilePath)
	{
		m_assetFilePath = assetFilePath;

		AssetStorage::RegisterAsset(assetFilePath, this);
	}

	void Asset::unload()
	{
		AssetStorage::UnregisterAsset(m_assetFilePath);
	}

	bool Asset::isLoaded()
	{
		return AssetStorage::IsRegistered(m_assetFilePath);
	}
}