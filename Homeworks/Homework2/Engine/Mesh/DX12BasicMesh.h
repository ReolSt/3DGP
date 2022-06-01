#pragma once

#include "Mesh/Mesh.h"
#include "Math/Math.h"

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <wrl.h>

#include "DirectX/d3dx12.h"

namespace Engine
{
	using Microsoft::WRL::ComPtr;

	class DX12BasicMesh : public Mesh
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12BasicMesh();
		~DX12BasicMesh();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Array<Math::Vector4>& getVertexColorData();
		UInt64 getVertexColorCount() const;

		void setVertexColorData(Array<Math::Vector4>& vertexColorData);

		ID3D12Resource* getVertexBuffer();
		ID3D12Resource* getVertexColorBuffer();
		ID3D12Resource* getIndexBuffer();

		D3D12_VERTEX_BUFFER_VIEW& getVertexBufferView();
		D3D12_VERTEX_BUFFER_VIEW& getVertexColorBufferView();
		D3D12_INDEX_BUFFER_VIEW& getIndexBufferView();

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		Math::Vector4 getVertexColor(UInt64 arrayIndex);
		void setVertexColor(UInt64 arrayIndex, const Math::Vector4& vertexColor);

		void insertVertexColor(UInt64 arrayIndex, const Math::Vector4& vertexColor);
		void removeVertexColor(UInt64 arrayIndex);

		void pushVertexColor(const Math::Vector4& vertexColor);
		Math::Vector4 popVertexColor();

		void initialize();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Array<Math::Vector4> m_vertexColorData;

		ComPtr<ID3D12Resource> m_vertexBuffer;
		ComPtr<ID3D12Resource> m_vertexColorBuffer;
		ComPtr<ID3D12Resource> m_indexBuffer;

		ComPtr<ID3D12Resource> m_vertexUploadBuffer;
		ComPtr<ID3D12Resource> m_vertexColorUploadBuffer;
		ComPtr<ID3D12Resource> m_indexUploadBuffer;

		D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
		D3D12_VERTEX_BUFFER_VIEW m_vertexColorBufferView;
		D3D12_INDEX_BUFFER_VIEW m_indexBufferView;

		bool m_initialized = false;
	};
}

