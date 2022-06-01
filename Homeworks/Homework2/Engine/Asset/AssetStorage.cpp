#include "AssetStorage.h"

#include "Asset/Asset.h"

namespace Engine
{
    bool AssetStorage::IsRegistered(const WString& assetFilePath)
    {
        auto assetStorage = AssetStorage::GetInstance();
        return assetStorage->isRegistered(assetFilePath);
    }

    Asset* AssetStorage::GetRegisteredAsset(const WString& assetFilePath)
    {
        auto assetStorage = AssetStorage::GetInstance();
        return assetStorage->getRegisteredAsset(assetFilePath);
    }

    void AssetStorage::RegisterAsset(const WString& assetFilePath, Asset* asset)
    {
        auto assetStorage = AssetStorage::GetInstance();
        assetStorage->registerAsset(assetFilePath, asset);
    }

    void AssetStorage::UnregisterAsset(const WString& assetFilePath)
    {
        auto assetStorage = AssetStorage::GetInstance();
        assetStorage->unregisterAsset(assetFilePath);
    }

    bool AssetStorage::isRegistered(const WString& assetFilePath)
    {
        return m_assets.find(assetFilePath) != m_assets.end();
    }

    Asset* AssetStorage::getRegisteredAsset(const WString& assetFilePath)
    {
        if (m_assets.find(assetFilePath) == m_assets.end())
        {
            return nullptr;
        }

        return m_assets[assetFilePath];
    }

    void AssetStorage::registerAsset(const WString& assetFilePath, Asset* asset)
    {
        m_assets[assetFilePath] = asset;
    }

    void AssetStorage::unregisterAsset(const WString& assetFilePath)
    {
        m_assets.erase(assetFilePath);
    }
}
