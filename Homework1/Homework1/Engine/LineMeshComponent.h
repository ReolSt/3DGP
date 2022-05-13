#pragma once

#include "MeshComponent.h"

namespace Engine
{
	class LineMesh;

	class LineMeshComponent : public MeshComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		LineMeshComponent(__ComponentDefaultParamsDef, LineMesh* mesh = nullptr);

		~LineMeshComponent();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		LineMesh* getMesh();

		void setMesh(LineMesh* mesh);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		LineMesh* m_mesh = nullptr;
	};
}
