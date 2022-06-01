#pragma once

#include "Component/MeshComponent.h"
#include "Mesh/DX12BasicMesh.h"
#include "Shader/DX12Shader.h"

namespace Engine
{
	class DX12BasicMeshComponent : public MeshComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12BasicMeshComponent(__ComponentDefaultParamsDef, DX12BasicMesh* mesh = nullptr);
		~DX12BasicMeshComponent();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		DX12BasicMesh* getMesh();
		DX12Shader* getShader();

		void setMesh(DX12BasicMesh* mesh);
		void setShader(DX12Shader* shader);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		DX12BasicMesh* m_mesh = nullptr;
		DX12Shader* m_shader = nullptr;
	};
}