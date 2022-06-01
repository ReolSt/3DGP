#include "Mesh/DX12Mesh.h"

#include "DirectX/DX12Helpers.h"

namespace Engine
{
	using namespace Math;

	Array<Vector3>& DX12Mesh::getNormalData()
	{
		return m_normalData;
	}

	Array<Math::Vector2>& DX12Mesh::getUVData()
	{
		return m_uvData;
	}

	UInt64 DX12Mesh::getNormalCount() const
	{
		return m_normalData.size();
	}

	UInt64 DX12Mesh::getUVCount() const
	{
		return m_uvData.size();
	}

	void DX12Mesh::setNormalData(Array<Math::Vector3>& normalData)
	{
		m_normalData = normalData;
	}

	void DX12Mesh::setUVData(Array<Math::Vector2>& uvData)
	{
		m_uvData = uvData;
	}

	ID3D12Resource* DX12Mesh::getVertexBuffer()
	{
		return m_vertexBuffer.Get();
	}

	ID3D12Resource* DX12Mesh::getNormalBuffer()
	{
		return m_normalBuffer.Get();
	}

	ID3D12Resource* DX12Mesh::getUVBuffer()
	{
		return m_uvBuffer.Get();
	}

	ID3D12Resource* DX12Mesh::getIndexBuffer()
	{
		return m_indexBuffer.Get();
	}

	D3D12_VERTEX_BUFFER_VIEW& DX12Mesh::getVertexBufferView()
	{
		return m_vertexBufferView;
	}

	D3D12_VERTEX_BUFFER_VIEW& DX12Mesh::getNormalBufferView()
	{
		return m_normalBufferView;
	}

	D3D12_VERTEX_BUFFER_VIEW& DX12Mesh::getUVBufferView()
	{
		return m_uvBufferView;
	}

	D3D12_INDEX_BUFFER_VIEW& DX12Mesh::getIndexBufferView()
	{
		return m_indexBufferView;
	}

	Vector3 DX12Mesh::getNormal(UInt64 arrayIndex)
	{
		return m_normalData[arrayIndex];
	}

	void DX12Mesh::setNormal(UInt64 arrayIndex, const Vector3& normal)
	{
		m_normalData[arrayIndex] = normal;
	}

	void DX12Mesh::insertNormal(UInt64 arrayIndex, const Vector3& normal)
	{
		m_normalData.insert(m_normalData.begin() + arrayIndex, normal);
	}

	void DX12Mesh::removeNormal(UInt64 arrayIndex)
	{
		m_normalData.erase(m_normalData.begin() + arrayIndex);
	}

	void DX12Mesh::pushUV(const Math::Vector2& uv)
	{
		m_uvData.push_back(uv);
	}

	Math::Vector2 DX12Mesh::popUV()
	{
		auto uv = m_uvData.back();
		m_uvData.pop_back();

		return uv;
	}

	Math::Vector2 DX12Mesh::getUV(UInt64 arrayIndex)
	{
		return m_uvData[arrayIndex];
	}

	void DX12Mesh::setUV(UInt64 arrayIndex, const Math::Vector2& uv)
	{
		m_uvData[arrayIndex] = uv;
	}

	void DX12Mesh::insertUV(UInt64 arrayIndex, const Math::Vector2& uv)
	{
		m_uvData.insert(m_uvData.begin() + arrayIndex, uv);
	}

	void DX12Mesh::removeUV(UInt64 arrayIndex)
	{
		m_uvData.erase(m_uvData.begin() + arrayIndex);
	}

	void DX12Mesh::pushNormal(const Vector3& normal)
	{
		m_normalData.push_back(normal);
	}

	Vector3 DX12Mesh::popNormal()
	{
		auto normal = m_normalData.back();
		m_normalData.pop_back();

		return normal;
	}

	void DX12Mesh::initialize()
	{
		if (m_initialized)
		{
			return;
		}

		const auto& vertexData = getVertexData();
		const auto& normalData = getNormalData();
		const auto& uvData = getUVData();
		const auto& indices = getIndices();

		Array<XMFLOAT3> dxVertexData;
		Array<XMFLOAT3> dxNormalData;
		Array<XMFLOAT2> dxUVData;
		Array<UINT> dxIndices;

		for (const auto& vertex : vertexData)
		{
			dxVertexData.push_back(*vertex.getDXVector());
		}

		for (const auto& normal : normalData)
		{
			dxNormalData.push_back(*normal.getDXVector());
		}

		for (const auto& uv : uvData)
		{
			dxUVData.push_back(*uv.getDXVector());
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
			&m_vertexUploadBuffer
		);

		m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
		m_vertexBufferView.StrideInBytes = dxVertexElementSize;
		m_vertexBufferView.SizeInBytes = dxVertexBufferSize;

		auto dxNormalElementSize = sizeof(XMFLOAT3);
		auto dxNormalBufferSize = dxNormalElementSize * normalData.size();
		m_normalBuffer = DirectX::CreateBufferResource(
			dxNormalData.data(),
			dxNormalBufferSize,
			D3D12_HEAP_TYPE_DEFAULT,
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
			&m_normalUploadBuffer
		);

		m_normalBufferView.BufferLocation = m_normalBuffer->GetGPUVirtualAddress();
		m_normalBufferView.StrideInBytes = dxNormalElementSize;
		m_normalBufferView.SizeInBytes = dxNormalBufferSize;

		auto dxUVElementSize = sizeof(XMFLOAT2);
		auto dxUVBufferSize = dxUVElementSize * uvData.size();
		m_uvBuffer = DirectX::CreateBufferResource(
			dxUVData.data(),
			dxUVBufferSize,
			D3D12_HEAP_TYPE_DEFAULT,
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
			&m_uvUploadBuffer
		);

		m_uvBufferView.BufferLocation = m_uvBuffer->GetGPUVirtualAddress();
		m_uvBufferView.StrideInBytes = dxUVElementSize;
		m_uvBufferView.SizeInBytes = dxUVBufferSize;

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