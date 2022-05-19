#pragma once

#include "Math.h"

namespace Engine
{
	namespace Math
	{
		class Transform
		{
		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Transform();

			Transform(const Vector3& translation, const Quat& rotation, const Vector3& scale);

			// ----------------------------------------------------------------------
			// Getter, Setter
			// ----------------------------------------------------------------------

			Vector3 getTranslation() const;
			Quat getRotation() const;
			Vector3 getScale() const;

			void setTranslation(const Vector3& t);
			void setRotation(const Quat& q);
			void setScale(const Vector3& s);

			// ----------------------------------------------------------------------
			// Public Member Method
			// ----------------------------------------------------------------------

			void translate(float x, float y, float z);
			void translate(const Vector3& v);
			void rotate(float pitch, float yaw, float roll);
			void rotate(const Rotator& r);
			void rotate(const Quat& q);
			void rotate(const Vector3& axis, float angle);

			Matrix toMatrix() const;
			Transform getRelativeTransform(const Transform& other) const;
			Vector3 getSafeScaleReciprocal(float tolerance = TRANSFORM_TOLERANCE) const;

		private:
			// ----------------------------------------------------------------------
			// Private Member Variable
			// ----------------------------------------------------------------------

			Vector3 m_translation;
			Quat m_rotation;
			Vector3 m_scale;
		};
	}
}
