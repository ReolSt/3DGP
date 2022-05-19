#include "Transform.h"

namespace Engine
{
	namespace Math
	{
		Transform::Transform()
		{
			setTranslation(Vector3());
			setRotation(Quat());
			setScale(Vector3(1.0f));
		}

		Transform::Transform(const Vector3& translation, const Quat& rotation, const Vector3& scale)
		{
			setTranslation(translation);
			setRotation(rotation);
			setScale(scale);
		}

		Vector3 Transform::getTranslation() const
		{
			return m_translation;
		}

		Quat Transform::getRotation() const
		{
			return m_rotation;
		}

		Vector3 Transform::getScale() const
		{
			return m_scale;
		}

		void Transform::setTranslation(const Vector3& t)
		{
			m_translation = t;
		}

		void Transform::setRotation(const Quat& q)
		{
			m_rotation = q;
		}

		void Transform::setScale(const Vector3& s)
		{
			m_scale = s;
		}

		void Transform::translate(float x, float y, float z)
		{
			m_translation += Vector3(x, y, z);
		}

		void Transform::translate(const Vector3& v)
		{
			m_translation += v;
		}

		void Transform::rotate(float yaw, float pitch, float roll)
		{
			m_rotation *= Quat(Rotator(yaw, pitch, roll));
		}

		void Transform::rotate(const Rotator& r)
		{
			m_rotation *= Quat(r);
		}

		void Transform::rotate(const Quat& q)
		{
			m_rotation *= q;
		}

		void Transform::rotate(const Vector3& axis, float angle)
		{
			m_rotation *= Quat(axis, angle);
		}

		Matrix Transform::toMatrix() const
		{
			/*
			Matrix translationMatrix = XMMatrixTranslationFromVector(m_translation.xmLoad());
			Matrix rotationMatrix = XMMatrixRotationQuaternion(m_rotation.xmLoad());
			Matrix scaleMatrix = XMMatrixScalingFromVector(m_scale.xmLoad());			
			*/

			return XMMatrixAffineTransformation(m_scale.xmLoad(), Vector3::zero().xmLoad(), m_rotation.xmLoad(), m_translation.xmLoad());
		}

		Transform Transform::getRelativeTransform(const Transform& other) const
		{
			Transform result;

			Vector3 safeReciprocalScale = other.getSafeScaleReciprocal();
			Quat inversedRotation = other.getRotation().inverse();

			result.setScale(getScale() * safeReciprocalScale);
			result.setRotation(inversedRotation * getRotation());
			result.setTranslation((inversedRotation * (getTranslation() - other.getTranslation()) * safeReciprocalScale));

			return result;
		}

		Vector3 Transform::getSafeScaleReciprocal(float tolerance) const
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
	}
}