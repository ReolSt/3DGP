#include "Plane.h"

namespace Engine
{
	namespace Math
	{
		Plane::Plane(float x, float y, float z, float w)
		{
			setX(x);
			setY(y);
			setZ(z);
			setW(w);
		}

		Plane::Plane(const Vector4& other)
		{
			xmStore(other);
		}

		Plane::Plane(const Plane& other)
		{
			xmStore(other);
		}

		bool Plane::intersectTriangle(const Vector3& v1, const Vector3& v2, const Vector3& v3) const
		{
			return TriangleTests::Intersects(v1.xmLoad(), v2.xmLoad(), v3.xmLoad(), xmLoad()) == PlaneIntersectionType::INTERSECTING;
		}

		bool Plane::intersectPlane(const Plane& p) const
		{
			XMVECTOR linePoint1, linePoint2;

			XMPlaneIntersectPlane(&linePoint1, &linePoint2, xmLoad(), p.xmLoad());

			// Not implemented yet

			return false;
		}
	}
}

