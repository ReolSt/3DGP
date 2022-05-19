#pragma once

#include "MathCommon.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	namespace Math
	{
		class Plane : public Vector4
		{
		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Plane(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
			Plane(const Vector4& other);
			Plane(const Plane& other);

			// ----------------------------------------------------------------------
			// Public Member Method
			// ----------------------------------------------------------------------

			bool intersectTriangle(const Vector3& v1, const Vector3& v2, const Vector3& v3) const;
			bool intersectPlane(const Plane& p) const;
		};
	}
}