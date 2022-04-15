#pragma once

#include "MathCommon.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	class Plane : public Vector4
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		inline Plane(float x, float y, float z, float w)
		{
			setX(x);
			setY(y);
			setZ(z);
			setW(w);
		}

		inline Plane(const Vector4& other)
		{
			xmStore(other);
		}

		inline Plane(const Plane& other)
		{
			xmStore(other);
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		inline bool intersectTriangle(const Vector3& v1, const Vector3& v2, const Vector3& v3) const
		{
			return TriangleTests::Intersects(v1.xmLoad(), v2.xmLoad(), v3.xmLoad(), xmLoad()) == PlaneIntersectionType::INTERSECTING;
		}

		inline bool intersectPlane(const Plane& p) const
		{
			XMVECTOR linePoint1, linePoint2;

			XMPlaneIntersectPlane(&linePoint1, &linePoint2, xmLoad(), p.xmLoad());
		}
	};
}