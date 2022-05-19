#include "CubeMesh.h"

#include "Engine/Math.h"

using namespace Engine;

CubeMesh::CubeMesh() : LineMesh()
{
	Math::Vector3 vertices[8] = {
		Math::Vector3(-0.5f, -0.5f, -0.5f),
		Math::Vector3(0.5f, -0.5f, -0.5f),
		Math::Vector3(-0.5f, 0.5f, -0.5f),
		Math::Vector3(0.5f, 0.5f, -0.5f),
		Math::Vector3(-0.5f, -0.5f, 0.5f),
		Math::Vector3(0.5f, -0.5f, 0.5f),
		Math::Vector3(-0.5f, 0.5f, 0.5f),
		Math::Vector3(0.5f, 0.5f, 0.5f)
	};

	for (UInt64 i = 0; i < 8; ++i)
	{
		pushVertex(vertices[i]);
		pushVertexColor(Math::Vector3((float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX)));
	}

	UInt64 indices[36] = {
		2, 1, 0,
		1, 2, 3,
		4, 5, 6,
		7, 6, 5,
		4, 2, 0,
		2, 4, 6,
		1, 3, 5,
		7, 5, 3,
		0, 1, 4,
		5, 4, 1,
		6, 3, 2,
		3, 6, 7
	};

	for (int i = 0; i < 36; ++i)
	{
		pushIndex(indices[i]);
	}
}
