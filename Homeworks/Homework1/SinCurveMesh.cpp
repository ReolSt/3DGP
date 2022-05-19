#include "SinCurveMesh.h"

#include "Engine/Math.h"

using namespace Engine::Math;

SinCurveMesh::SinCurveMesh(float left, float right, float dx) : Engine::LineMesh()
{
	assert(left <= right);

	Vector3 color(0.0f);

	for (int i = 0; left + dx * i <= right; ++i)
	{
		float x = left + dx * i;
		pushVertex(Vector3(x, sin(x), 0.5f));
		pushVertex(Vector3(x, sin(x), -0.5f));

		pushVertexColor(color);
		pushVertexColor(color);

		if (x != left)
		{
			pushIndex((i - 1) * 2);
			pushIndex((i - 1) * 2 + 1);
			pushIndex(i * 2);

			pushIndex(i * 2);
			pushIndex(i * 2 + 1);
			pushIndex((i - 1) * 2 + 1);
		}
	}
}
