#pragma once

#include "Core/Singleton.h"
#include "Core/Types.h"

namespace Engine
{
	class Asset;

	class AssetStorage : public Singleton<AssetStorage>
	{
	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

		static bool IsRegistered(const WString& assetFilePath);
		static Asset* GetRegisteredAsset(const WString& assetFilePath);
		static void RegisterAsset(const WString& assetFilePath, Asset* asset);
		static void UnregisterAsset(const WString& assetFilePath);
		
	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

		bool isRegistered(const WString& assetFilePath);
		Asset* getRegisteredAsset(const WString& assetFilePath);
		void registerAsset(const WString& assetFilePath, Asset* asset);
		void unregisterAsset(const WString& assetFilePath);

	private:
		Map<WString, Asset*> m_assets;
	};
}