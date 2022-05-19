#include "LineMeshComponent.h"
#include "LineMesh.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	LineMeshComponent::LineMeshComponent(__ComponentDefaultParamsDef, LineMesh* mesh)
		: MeshComponent(ComponentDefaultParams)
	{
		setMesh(mesh);
	}

	LineMeshComponent::~LineMeshComponent()
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
