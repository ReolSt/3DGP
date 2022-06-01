#include "DX12BasicMeshComponent.h"

namespace Engine
{
	DX12BasicMeshComponent::DX12BasicMeshComponent(__ComponentDefaultParamsDef, DX12BasicMesh* mesh) : MeshComponent(ComponentDefaultParams)
	{
		m_mesh = mesh;
	}

	DX12BasicMeshComponent::~DX12BasicMeshComponent()
	{

	}

	DX12BasicMesh* DX12BasicMeshComponent::getMesh()
	{
		return m_mesh;
	}

	DX12Shader* DX12BasicMeshComponent::getShader()
	{
		return m_shader;
	}

	void DX12BasicMeshComponent::setMesh(DX12BasicMesh* mesh)
	{
		m_mesh = mesh;
	}

	void DX12BasicMeshComponent::setShader(DX12Shader* shader)
	{
		m_shader = shader;
	}
}
