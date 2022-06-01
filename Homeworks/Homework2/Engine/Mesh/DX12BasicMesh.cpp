#include "Mesh/DX12BasicMesh.h"

#include "DirectX/DX12Helpers.h"
#include "Render/DX12BasicRenderer.h"

namespace Engine
{
	using namespace Math;

	DX12BasicMesh::DX12BasicMesh()
	{

	}

	DX12BasicMesh::~DX12BasicMesh()
	{

	}

	Array<Vector4>& DX12BasicMesh::getVertexColorData()
	{
		return m_vertexColorData;
	}

	UInt64 DX12BasicMesh::getVertexColorCount() const
	{
		return m_vertexColorData.size();
	}

	void DX12BasicMesh::setVertexColorData(Array<Math::Vector4>& vertexColorData)
	{
		m_vertexColorData = vertexColorData;
	}

	ID3D12Resource* DX12BasicMesh::getVertexBuffer()
	{
		return m_vertexBuffer.Get();
	}

	ID3D12Resource* DX12BasicMesh::getVertexColorBuffer()
	{
		return m_vertexColorBuffer.Get();
	}

	ID3D12Resource* DX12BasicMesh::getIndexBuffer()
	{
		return m_indexBuffer.Get();
	}

	D3D12_VERTEX_BUFFER_VIEW& DX12BasicMesh::getVertexBufferView()
	{
		return m_vertexBufferView;
	}

	D3D12_VERTEX_BUFFER_VIEW& DX12BasicMesh::getVertexColorBufferView()
	{
		return m_vertexColorBufferView;
	}

	D3D12_INDEX_BUFFER_VIEW& DX12BasicMesh::getIndexBufferView()
	{
		return m_indexBufferView;
	}

	Vector4 DX12BasicMesh::getVertexColor(UInt64 arrayIndex)
	{
		return m_vertexColorData[arrayIndex];
	}

	void DX12BasicMesh::setVertexColor(UInt64 arrayIndex, const Vector4& vertexColor)
	{
		m_vertexColorData[arrayIndex] = vertexColor;
	}

	void DX12BasicMesh::insertVertexColor(UInt64 arrayIndex, const Vector4& vertexColor)
	{
		m_vertexColorData.insert(m_vertexColorData.begin() + arrayIndex, vertexColor);
	}

	void DX12BasicMesh::removeVertexColor(UInt64 arrayIndex)
	{
		m_vertexColorData.erase(m_vertexColorData.begin() + arrayIndex);
	}

	void DX12BasicMesh::pushVertexColor(const Vector4& vertexColor)
	{
		m_vertexColorData.push_back(vertexColor);
	}
	
	Vector4 DX12BasicMesh::popVertexColor()
	{
		auto vertexColor = m_vertexColorData.back();
		m_vertexColorData.pop_back();

		return vertexColor;
	}

	void DX12BasicMesh::initialize()
	{
		if (m_initialized)
		{
			return;
		}

		auto vertexData = getVertexData();
		auto vertexColorData = getVertexColorData();
		auto indices = getIndices();

		Array<XMFLOAT3> dxVertexData;
		Array<XMFLOAT4> dxVertexColorData;
		Array<UINT> dxIndices;

		for (const auto& vertex : vertexData)
		{
			dxVertexData.push_back(*vertex.getDXVector());
		}

		for (const auto& vertexColor : vertexColorData)
		{
			dxVertexColorData.push_back(*vertexColor.getDXVector());
		}

		for (const auto& index : indices)
		{
			dxIndices.push_back(index);
		}

		auto dxVertexElementSize = sizeof(XMFLOAT3);
		auto dxVertexBufferSize = dxVertexElementSize * vertexData.size();
		m_vertexBuffer = DirectX::CreateBufferResource(
			dxVertexData.data(),
			dxVertexBufferSize,
			D3D12_HEAP_TYPE_DEFAULT,
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
			&m_vertexUploadBuffer);

		m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
		m_vertexBufferView.StrideInBytes = dxVertexElementSize;
		m_vertexBufferView.SizeInBytes = dxVertexBufferSize;

		auto dxVertexColorElementSize = sizeof(XMFLOAT4);
		auto dxVertexColorBufferSize = dxVertexColorElementSize * vertexColorData.size();
		m_vertexColorBuffer = DirectX::CreateBufferResource(
			dxVertexColorData.data(),
			dxVertexColorBufferSize,
			D3D12_HEAP_TYPE_DEFAULT,
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
			&m_vertexColorUploadBuffer);

		m_vertexColorBufferView.BufferLocation = m_vertexColorBuffer->GetGPUVirtualAddress();
		m_vertexColorBufferView.StrideInBytes = dxVertexColorElementSize;
		m_vertexColorBufferView.SizeInBytes = dxVertexColorBufferSize;

		auto dxIndexElementSize = sizeof(UINT);
		auto dxIndexBufferSize = dxIndexElementSize * indices.size();
		m_indexBuffer = DirectX::CreateBufferResource(
			dxIndices.data(),
			dxIndexBufferSize,
			D3D12_HEAP_TYPE_DEFAULT, 
			D3D12_RESOURCE_STATE_INDEX_BUFFER,
			&m_indexUploadBuffer);

		m_indexBufferView.BufferLocation = m_indexBuffer->GetGPUVirtualAddress();
		m_indexBufferView.Format = DXGI_FORMAT_R32_UINT;
		m_indexBufferView.SizeInBytes = dxIndexBufferSize;

		m_initialized = true;
	}
}