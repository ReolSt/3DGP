#include "LineMeshComponent.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	LineMeshComponent::LineMeshComponent(__ComponentDefaultParamsDef)
		: MeshComponent(ComponentDefaultParams)
	{

	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	LineMesh* LineMeshComponent::getMesh()
	{
		return m_mesh;
	}

	void LineMeshComponent::setMesh(LineMesh* mesh)
	{
		m_mesh = mesh;
	}
}
