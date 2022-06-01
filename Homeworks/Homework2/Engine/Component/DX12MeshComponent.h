#pragma once
#include "Component/MeshComponent.h"
#include "Mesh/DX12Mesh.h"
#include "Shader/DX12Shader.h"

namespace Engine
{
	class DX12MeshComponent : public MeshComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12MeshComponent(__ComponentDefaultParamsDef, DX12Mesh* mesh = nullptr);
		~DX12MeshComponent();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		DX12Mesh* getMesh();
		DX12Shader* getShader();

		void setMesh(DX12Mesh* mesh);
		void setShader(DX12Shader* shader);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		DX12Mesh* m_mesh = nullptr;
		DX12Shader* m_shader = nullptr;
	};
}

