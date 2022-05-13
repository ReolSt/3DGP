#include "PlaneMesh.h"

#include "Engine/Math.h"

using namespace Engine::Math;

PlaneMesh::PlaneMesh() : LineMesh()
{
	Vector3 vertices[4] = {
		Vector3(-0.5f, 0.0f, -0.5f),
		Vector3(0.5f, 0.0f, -0.5f),
		Vector3(-0.5f, 0.0f, 0.5f),
		Vector3(0.5f, 0.0f, 0.5f)
	};

	Engine::UInt64 indices[6] = {
		0, 1, 2,
		1, 3, 2
	};

	for (Engine::UInt64 i = 0; i < 4; ++i)
	{
		pushVertex(vertices[i]);
		pushVertexColor(Vector3((float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX)));
	}

	for (Engine::UInt64 i = 0; i < 6; ++i)
	{
		pushIndex(indices[i]);
	}
}
