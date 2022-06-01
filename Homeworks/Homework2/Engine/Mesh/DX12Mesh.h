#pragma once

#include "Mesh/Mesh.h"
#include "DirectX/d3dx12.h"

namespace Engine
{
	using Microsoft::WRL::ComPtr;

	class DX12Mesh : public Mesh
	{
	public:
        // ----------------------------------------------------------------------
        // Constructor, Destructor
        // ----------------------------------------------------------------------

        DX12Mesh() { }

    public:
        // ----------------------------------------------------------------------
        // Getter, Setter
        // ----------------------------------------------------------------------

		Array<Math::Vector3>& getNormalData();
		Array<Math::Vector2>& getUVData();
		UInt64 getNormalCount() const;
		UInt64 getUVCount() const;

		void setNormalData(Array<Math::Vector3>& normalData);
		void setUVData(Array<Math::Vector2>& uvData);

		ID3D12Resource* getVertexBuffer();
		ID3D12Resource* getNormalBuffer();
		ID3D12Resource* getUVBuffer();
		ID3D12Resource* getIndexBuffer();

		D3D12_VERTEX_BUFFER_VIEW& getVertexBufferView();
		D3D12_VERTEX_BUFFER_VIEW& getNormalBufferView();
		D3D12_VERTEX_BUFFER_VIEW& getUVBufferView();
		D3D12_INDEX_BUFFER_VIEW& getIndexBufferView();

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		Math::Vector3 getNormal(UInt64 arrayIndex);
		void setNormal(UInt64 arrayIndex, const Math::Vector3& normal);

		void insertNormal(UInt64 arrayIndex, const Math::Vector3& normal);
		void removeNormal(UInt64 arrayIndex);

		void pushNormal(const Math::Vector3& uv);
		Math::Vector3 popNormal();

		Math::Vector2 getUV(UInt64 arrayIndex);
		void setUV(UInt64 arrayIndex, const Math::Vector2& uv);

		void insertUV(UInt64 arrayIndex, const Math::Vector2& uv);
		void removeUV(UInt64 arrayIndex);

		void pushUV(const Math::Vector2& UV);
		Math::Vector2 popUV();

		void initialize();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Array<Math::Vector3> m_normalData;
		Array<Math::Vector2> m_uvData;

		ComPtr<ID3D12Resource> m_vertexBuffer;
		ComPtr<ID3D12Resource> m_normalBuffer;
		ComPtr<ID3D12Resource> m_uvBuffer;
		ComPtr<ID3D12Resource> m_indexBuffer;

		ComPtr<ID3D12Resource> m_vertexUploadBuffer;
		ComPtr<ID3D12Resource> m_normalUploadBuffer;
		ComPtr<ID3D12Resource> m_uvUploadBuffer;
		ComPtr<ID3D12Resource> m_indexUploadBuffer;

		D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
		D3D12_VERTEX_BUFFER_VIEW m_normalBufferView;
		D3D12_VERTEX_BUFFER_VIEW m_uvBufferView;
		D3D12_INDEX_BUFFER_VIEW m_indexBufferView;

		bool m_initialized = false;

	};
}
