#include "DX12MeshComponent.h"

namespace Engine
{
	DX12MeshComponent::DX12MeshComponent(__ComponentDefaultParamsDef, DX12Mesh* mesh) : MeshComponent(ComponentDefaultParams)
	{
		m_mesh = mesh;
	}

	DX12MeshComponent::~DX12MeshComponent()
	{

	}

	DX12Mesh* DX12MeshComponent::getMesh()
	{
		return m_mesh;
	}

	DX12Shader* DX12MeshComponent::getShader()
	{
		return m_shader;
	}

	void DX12MeshComponent::setMesh(DX12Mesh* mesh)
	{
		m_mesh = mesh;
	}

	void DX12MeshComponent::setShader(DX12Shader* shader)
	{
		m_shader = shader;
	}
}
