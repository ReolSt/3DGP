#pragma once

#include "MeshComponent.h"
#include "LineMesh.h"

namespace Engine
{
	class LineMeshComponent : public MeshComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		LineMeshComponent(__ComponentDefaultParamsDef);

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

		LineMesh* m_mesh;
	};
}
