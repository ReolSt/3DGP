#include "SplineCurveMesh.h"

#include "Engine/Math.h"

using namespace Engine::Math;

SplineCurveMesh::SplineCurveMesh(const Engine::Array<Engine::Math::Vector3>& points, int iteration)
{
	assert(points.size() >= 3);
	assert(iteration % 2 == 0);

	Vector3 color(0.0f);

	if (points.size() == 3)
	{
		auto v1 = points[0], v2 = points[1], v3 = points[2];

		auto forward = (v2 - v1).normalize();
		auto right = forward.crossProduct(Vector3::right()).normalize() * 0.1f;

		for (int j = 0; j < iteration; ++j)
		{
			float t = j / (float)iteration;
			auto v = v1 * (2 * t * t - 3 * t + 1) + v2 * (-4 * t * t + 4 * t) + v3 * (2 * t * t - t);

			pushVertex(v);
			pushVertex(v + right * 0.1f);

			pushVertexColor(color);
			pushVertexColor(color);

			if (j == iteration / 2)
			{
				forward = (v3 - v2).normalize();
				right = forward.crossProduct(Vector3::right()).normalize() * 0.1f;
			}
		}

		for (int i = 0; i < 2 * iteration - 2; i += 2)
		{
			pushIndex(i);
			pushIndex(i + 1);
			pushIndex(i + 2);

			pushIndex(i + 1);
			pushIndex(i + 2);
			pushIndex(i + 3);
		}
	}
	else
	{
		auto forward = (points[1] - points[0]).normalize();
		auto right = forward.crossProduct(Vector3::right()).normalize() * 0.1f;

		for (int i = 0; i < iteration / 2; ++i)
		{
			auto v1 = points[0], v2 = points[1], v3 = points[2];

			float t = i / (float)iteration;
			auto v = v1 * (2 * t * t - 3 * t + 1) + v2 * (-4 * t * t + 4 * t) + v3 * (2 * t * t - t);

			pushVertex(v);
			pushVertex(v + right);

			pushVertexColor(color);
			pushVertexColor(color);
		}

		for (int i = 0; i < points.size() - 3; ++i)
		{
			auto v1 = points[i], v2 = points[i + 1], v3 = points[i + 2], v4 = points[i + 3];

			for (int j = 0; j < iteration; ++j)
			{
				float t = j / (float)iteration;
				auto v = v1 * (-pow(t, 3) + 2 * pow(t, 2) - t) + v2 * (3 * pow(t, 3) - 5 * pow(t, 2) + 2) + v3 * (-3 * pow(t, 3) + 4 * pow(t, 2) + t) + v4 * (pow(t, 3) - pow(t, 2));
				v /= 2;

				pushVertex(v);
				pushVertex(v + right);

				pushVertexColor(color);
				pushVertexColor(color);
			}
		}

		for (int i = iteration / 2; i < iteration; ++i)
		{
			auto v1 = points[points.size() - 3], v2 = points[points.size() - 2], v3 = points[points.size() - 1];

			float t = i / (float)iteration;
			auto v = v1 * (2 * t * t - 3 * t + 1) + v2 * (-4 * t * t + 4 * t) + v3 * (2 * t * t - t);

			pushVertex(v);
			pushVertex(v + right);

			pushVertexColor(color);
			pushVertexColor(color);
		}

		for (int i = 0; i < getVertexCount() - 4; i += 2)
		{
			pushIndex(i);
			pushIndex(i + 1);
			pushIndex(i + 2);

			pushIndex(i + 1);
			pushIndex(i + 2);
			pushIndex(i + 3);
		}
	}	
}
