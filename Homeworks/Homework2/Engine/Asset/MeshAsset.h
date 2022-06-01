#pragma once

#include "Asset/Asset.h"
#include "Math/Math.h"

namespace Engine
{
	class MeshAsset : public Asset
	{
		AssetDefaultMacro(MeshAsset)

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		MeshAsset();
		virtual ~MeshAsset();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Array<Math::Vector3>& getVertices();
		Array<Math::Vector3>& getNormals();
		Array<Math::Vector2>& getUVs();
		Array<UInt64>& getIndices();

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

		Array<Math::Vector3> m_vertices;
		Array<Math::Vector3> m_normals;
		Array<Math::Vector2> m_uvs;
		Array<UInt64> m_indices;
	};
}
