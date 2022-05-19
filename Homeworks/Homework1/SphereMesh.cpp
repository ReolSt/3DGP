#include "SphereMesh.h"

#include "Engine/Math.h"

using namespace Engine;

SphereMesh::SphereMesh(int rings, int segments) : LineMesh()
{
	float pi = Math::PI;
	float radius = 0.5f;

	for (UInt64 r = 1; r < rings; ++r)
	{
		float ringRads = pi * r / (float)rings;

		float ringRadius = Math::sin(ringRads) * radius;
		float ringY = Math::cos(ringRads) * radius;

		UInt64 indexOffset = (r - 1) * segments;
		UInt64 nextIndexOffset = r * segments;

		for (UInt64 s = 0; s < segments; ++s)
		{
			float rads = XM_2PI * s / (float)segments;

			pushVertex(Math::Vector3(Math::cos(rads) * ringRadius, ringY, Math::sin(rads) * ringRadius));

			UInt64 nextSegment = (s + 1) % segments;
			if (r < rings - 1)
			{
				pushIndex(indexOffset + s);
				pushIndex(indexOffset + nextSegment);
				pushIndex(nextIndexOffset + s);

				pushIndex(nextIndexOffset + s);
				pushIndex(indexOffset + nextSegment);
				pushIndex(nextIndexOffset + nextSegment);
			}
		}
	}

	Math::Vector3 top(0.0f, radius, 0.0f);
	Math::Vector3 bottom(0.0f, -radius, 0.0f);

	UInt64 indexOffset = getVertexCount();

	pushVertex(bottom);
	pushVertex(top);

	for (UInt64 s = 0; s < segments; ++s)
	{
		pushIndex(indexOffset - s - 1);
		pushIndex(indexOffset);
		pushIndex(indexOffset - (s + 1) % segments - 1);

		pushIndex(s);
		pushIndex(indexOffset + 1);
		pushIndex((s + 1) % segments);
	}

	for (UInt64 i = 0; i < getVertexCount(); ++i)
	{
		pushVertexColor(Math::Vector3((float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX), (float)rand() / (float)(RAND_MAX)));
	}
}
