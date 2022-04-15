#pragma once

#include "Math.h"

namespace Engine
{
	class Transform
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Transform() { }

		Transform(const Vector3& translation,
			const Quat& rotation,
			const Vector3& scale)
		{
			m_translation = translation;
			m_rotation = rotation;
			m_scale = scale;
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		inline Vector3 getTranslation() const
		{
			return m_translation;
		}

		inline Quat getRotation() const
		{
			return m_rotation;
		}

		inline Vector3 getScale() const
		{
			return m_scale;
		}

		inline void setTranslation(const Vector3& t)
		{
			m_translation = t;
		}

		inline void setRotation(const Quat& q)
		{
			m_rotation = q;
		}

		inline void setScale(const Vector3& s)
		{
			m_scale = s;
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		inline void translate(float x, float y, float z)
		{
			m_translation += Vector3(x, y, z);
		}

		inline void translate(const Vector3& v)
		{
			m_translation += v;
		}

		inline void rotate(float pitch, float yaw, float roll)
		{
			m_rotation *= Quat(Rotator(pitch, yaw, roll));
		}

		inline void rotate(const Rotator& r)
		{
			m_rotation *= Quat(r);
		}

		inline void rotate(const Quat& q)
		{
			m_rotation *= q;
		}

		inline Matrix toMatrix() const
		{
			Matrix translationMatrix = XMMatrixTranslationFromVector(m_translation.xmLoad());
			Matrix rotationMatrix = XMMatrixRotationQuaternion(m_rotation.xmLoad());
			Matrix scaleMatrix = XMMatrixScalingFromVector(m_scale.xmLoad());

			return scaleMatrix * rotationMatrix * translationMatrix;
		}

		inline Transform getRelativeTransform(const Transform& other) const
		{
			Transform result;

			Vector3 safeReciprocalScale = other.getSafeScaleReciprocal();
			Quat inversedRotation = other.getRotation().inverse();

			result.setScale(getScale() * safeReciprocalScale);
			result.setRotation(inversedRotation * getRotation());
			result.setTranslation((inversedRotation * (getTranslation() - other.getTranslation()) * safeReciprocalScale));

			return result;
		}

		inline Vector3 getSafeScaleReciprocal(float tolerance = TRANSFORM_TOLERANCE) const
		{
			Vector3 scale = getScale();

			Vector3 safeReciprocalScale;
			if (fabsf(scale.getX()) <= tolerance)
			{
				safeReciprocalScale.setX(0.f);
			}
			else
			{
				safeReciprocalScale.setX(1 / scale.getX());;
			}

			if (fabsf(scale.getY()) <= tolerance)
			{
				safeReciprocalScale.setY(0.f);
			}
			else
			{
				safeReciprocalScale.setY(1 / scale.getY());;
			}

			if (fabsf(scale.getZ()) <= tolerance)
			{
				safeReciprocalScale.setZ(0.f);
			}
			else
			{
				safeReciprocalScale.setZ(1 / scale.getZ());;
			}

			return safeReciprocalScale;
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Vector3 m_translation;
		Quat m_rotation;
		Vector3 m_scale;
	};
}
