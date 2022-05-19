#include "CircleMesh.h"

#include "Engine/Math.h"

using namespace Engine::Math;

CircleMesh::CircleMesh(unsigned int vertices) : Engine::LineMesh()
{
	assert(vertices >= 3);

	float pi = PI;
	float radius = 0.5f;

	Vector3 color(0.0f);

	for (unsigned int i = 0; i < vertices; ++i)
	{
		float rads = pi * 2 * i / (float)(vertices);

		pushVertex(Vector3(cos(rads) * radius, 0.0f, sin(rads) * radius));
		pushVertexColor(color);

		if (i > 1)
		{
			pushIndex(0);
			pushIndex(i - 1);
			pushIndex(i);
		}
	}
}