#include "Quat.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Rotator.h"
#include "Matrix.h"

namespace Engine
{
	namespace Math
	{
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Quat::Quat(float x, float y, float z, float w)
		{
			set(x, y, z, w);
		}

		Quat::Quat(const Vector3& axis, float angle)
		{
			set(axis, angle);
		}

		Quat::Quat(const Rotator& rotator)
		{
			set(rotator);
		}

		Quat::Quat(const XMFLOAT4& dxVector)
		{
			set(dxVector);
		}

		Quat::Quat(const XMFLOAT4* dxVector)
		{
			set(dxVector);
		}

		Quat::Quat(const XMVECTOR& dxVector)
		{
			set(dxVector);
		}

		Quat::Quat(const Vector4& vector)
		{
			set(vector);
		}

		Quat::Quat(const Quat& quat)
		{
			set(quat);
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT4* Quat::getDXVector() const
		{
			return &m_dxVector;
		}

		XMFLOAT4* Quat::getDXVectorUnsafe()
		{
			return &m_dxVector;
		}

		float Quat::getX() const
		{
			return m_dxVector.x;
		}

		float Quat::getY() const
		{
			return m_dxVector.y;
		}

		float Quat::getZ() const
		{
			return m_dxVector.z;
		}

		float Quat::getW() const
		{
			return m_dxVector.w;
		}

		void Quat::setX(float x)
		{
			m_dxVector.x = x;
		}

		void Quat::setY(float y)
		{
			m_dxVector.y = y;
		}

		void Quat::setZ(float z)
		{
			m_dxVector.z = z;
		}

		void Quat::setW(float w)
		{
			m_dxVector.w = w;
		}

		// ----------------------------------------------------------------------
		// Mathmatical Getter
		// ----------------------------------------------------------------------

		float Quat::getAngle() const
		{
			XMVECTOR dxAxisResult;
			float dxAngleResult;

			XMQuaternionToAxisAngle(&dxAxisResult, &dxAngleResult, xmLoad());

			return dxAngleResult;
		}

		Vector3 Quat::getAxis() const
		{
			XMVECTOR dxAxisResult;
			float dxAngleResult;

			XMQuaternionToAxisAngle(&dxAxisResult, &dxAngleResult, xmLoad());

			return Vector3(dxAxisResult);
		}

		Vector3 Quat::getAxisX() const
		{
			return rotate(Vector3(1.0f, 0.0f, 0.0f));
		}

		Vector3 Quat::getAxisY() const
		{
			return rotate(Vector3(0.0f, 1.0f, 0.0f));
		}

		Vector3 Quat::getAxisZ() const
		{
			return rotate(Vector3(0.0f, 0.0f, 1.0f));
		}

		Vector3 Quat::getRightVector() const
		{
			return getAxisX();
		}

		Vector3 Quat::getForwardVector() const
		{
			return getAxisZ();
		}		

		Vector3 Quat::getUpVector() const
		{
			return getAxisY();
		}

		Rotator Quat::getRotator() const
		{
			XMFLOAT3 dxResult;
			Vector3::xmStore(dxResult, XMQuaternionRotationRollPitchYawFromVector(xmLoad()));

			float yaw = 0.0f;
			float pitch = 0.0f;
			float roll = 0.0f;

			return Rotator(dxResult.y, dxResult.x, dxResult.z);
		}

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool Quat::operator==(const Quat& other) const
		{
			return XMVector4Equal(xmLoad(), other.xmLoad());
		}

		bool Quat::operator!=(const Quat& other) const
		{
			return XMVector4NotEqual(xmLoad(), other.xmLoad());
		}

		bool Quat::operator>(const Quat& other) const
		{
			return XMVector4Greater(xmLoad(), other.xmLoad());
		}

		bool Quat::operator<(const Quat& other) const
		{
			return XMVector4Less(xmLoad(), other.xmLoad());
		}

		bool Quat::operator>=(const Quat& other) const
		{
			return XMVector4GreaterOrEqual(xmLoad(), other.xmLoad());
		}

		bool Quat::operator<=(const Quat& other) const
		{
			return XMVector4LessOrEqual(xmLoad(), other.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Quat Quat::operator+(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + other.xmLoad());

			return Quat(dxResult).normalize();
		}

		Quat Quat::operator+(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Quat(dxResult).normalize();
		}

		Quat Quat::operator-(const Quat& other) const
		{
			return Quat(xmLoad() - other.xmLoad()).normalize();
		}

		Quat Quat::operator-(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			return Quat(xmLoad() - xmLoad(dxVector)).normalize();
		}

		Quat Quat::operator*(const Quat& other) const
		{
			return Quat(XMQuaternionMultiply(xmLoad(), other.xmLoad())).normalize();
		}

		Quat Quat::operator*(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Quat(dxResult).normalize();
		}

		Quat Quat::operator/(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / other.xmLoad());

			return Quat(dxResult).normalize();
		}

		Quat Quat::operator/(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / xmLoad(dxVector));

			return Quat(dxResult).normalize();
		}

		Vector3 Quat::operator*(const Vector3& other) const
		{
			return rotate(other);
		}

		Matrix Quat::operator*(const Matrix& other) const
		{
			return rotate(other);
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		Quat& Quat::operator+=(const Quat& other)
		{
			xmStore(xmLoad() + other.xmLoad());
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator+=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(normalize());
			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		Quat& Quat::operator-=(const Quat& other)
		{
			xmStore(xmLoad() - other.xmLoad());
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator-=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator*=(const Quat& other)
		{
			xmStore(XMQuaternionMultiply(xmLoad(), other.xmLoad()));
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator*=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator/=(const Quat& other)
		{
			xmStore(xmLoad() / other.xmLoad());
			xmStore(normalize());

			return *this;
		}

		Quat& Quat::operator/=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() / xmLoad(dxVector));
			xmStore(normalize());

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		float Quat::operator[](int index)
		{
			VERIFY(index >= 0 && index <= 3);

			float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
			return v[index];
		}

		float Quat::operator[](int index) const
		{
			VERIFY(index >= 0 && index <= 3);

			float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
			return v[index];
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void Quat::set(float x, float y, float z, float w)
		{
			setX(x);
			setY(y);
			setZ(z);
			setW(w);

			xmStore(normalize());
		}

		void Quat::set(const Quat& quat)
		{
			xmStore(quat.normalize());
		}

		void Quat::set(const XMFLOAT4& vector)
		{
			xmStore(vector);
			xmStore(normalize());
		}

		void Quat::set(const XMFLOAT4* vector)
		{
			xmStore(vector);
			xmStore(normalize());
		}

		void Quat::set(const XMVECTOR& vector)
		{
			xmStore(vector);
			xmStore(normalize());
		}

		void Quat::set(const Vector4& vector)
		{
			xmStore(vector);
			xmStore(normalize());
		}

		void Quat::set(const Rotator& rotator)
		{
			xmStore(XMQuaternionRotationRollPitchYaw(rotator.getPitch(), rotator.getYaw(), rotator.getRoll()));
			xmStore(normalize());
		}

		void Quat::set(const Vector3& axis, float angle)
		{
			xmStore(XMQuaternionRotationAxis(axis.xmLoad(), angle));
			xmStore(normalize());
		}

		bool Quat::equals(const Quat& other, float tolerance) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

			return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance && dxResult.w <= tolerance;
		}

		Vector3 Quat::rotate(const Vector3& vector) const
		{
			XMFLOAT3 dxResult;
			Vector3::xmStore(dxResult, Vector3(Matrix(XMMatrixRotationQuaternion(xmLoad())) * Vector4(vector, 1.0f)));

			return Vector3(dxResult);
		}

		Matrix Quat::rotate(const Matrix& matrix) const
		{
			return Matrix(matrix.xmLoad() * XMMatrixRotationQuaternion(xmLoad()));
		}

		Vector4 Quat::normalize() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMQuaternionNormalize(xmLoad()));

			return dxResult;
		}

		float Quat::length() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMQuaternionLength(xmLoad(m_dxVector)));

			return dxResult.x;
		}

		Quat Quat::inverse() const
		{
			return Quat(XMQuaternionInverse(xmLoad())).normalize();
		}

		bool Quat::isNearlyZero(float tolerance) const
		{
			return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance && fabsf(m_dxVector.w) <= tolerance;
		}

		bool Quat::isZero() const
		{
			return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f && m_dxVector.w == 0.0f;
		}

		bool Quat::isNaN() const
		{
			return XMQuaternionIsNaN(xmLoad());
		}

		bool Quat::isInfinite() const
		{
			return XMQuaternionIsInfinite(xmLoad());
		}

		Matrix Quat::toMatrix() const
		{
			Matrix matrix;
			matrix.xmStore(XMMatrixRotationQuaternion(xmLoad()));

			return matrix;
		}

		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void Quat::xmStore(const XMFLOAT4& other)
		{
			m_dxVector = other;
		}

		void Quat::xmStore(const XMFLOAT4* other)
		{
			m_dxVector = *other;
		}

		void Quat::xmStore(const XMVECTOR* other)
		{
			XMStoreFloat4(&m_dxVector, *other);
		}

		void Quat::xmStore(const XMVECTOR& other)
		{
			XMStoreFloat4(&m_dxVector, other);
		}

		void Quat::xmStore(const Vector4& other)
		{
			XMStoreFloat4(&m_dxVector, other.xmLoad());
		}

		void Quat::xmStore(const Quat& other)
		{
			XMStoreFloat4(&m_dxVector, other.xmLoad());
		}

		XMVECTOR Quat::xmLoad() const
		{
			return XMLoadFloat4(&m_dxVector);
		}

		void Quat::xmStore(Quat& quat, const XMFLOAT4& other)
		{
			quat.xmStore(other);
		}

		void Quat::xmStore(Quat& quat, const XMFLOAT4* other)
		{
			quat.xmStore(other);
		}

		void Quat::xmStore(Quat& quat, const XMVECTOR& other)
		{
			quat.xmStore(other);
		}

		void Quat::xmStore(Quat& quat, const Vector4& other)
		{
			quat.xmStore(other);
		}

		void Quat::xmStore(Quat& quat, const Quat& other)
		{
			quat.xmStore(other);
		}

		void Quat::xmStore(XMFLOAT4& dxVector, const XMFLOAT4& other)
		{
			dxVector = other;
		}

		void Quat::xmStore(XMFLOAT4& dxVector, const XMFLOAT4* other)
		{
			dxVector = *other;
		}

		void Quat::xmStore(XMFLOAT4& dxVector, const XMVECTOR& other)
		{
			XMStoreFloat4(&dxVector, other);
		}

		void Quat::xmStore(XMFLOAT4& dxVector, const Vector4& other)
		{
			XMStoreFloat4(&dxVector, other.xmLoad());
		}

		void Quat::xmStore(XMFLOAT4& dxVector, const Quat& other)
		{
			XMStoreFloat4(&dxVector, other.xmLoad());
		}

		void Quat::xmStore(XMFLOAT4* dxVector, const XMFLOAT4& other)
		{
			XMStoreFloat4(dxVector, XMLoadFloat4(&other));
		}

		void Quat::xmStore(XMFLOAT4* dxVector, const XMFLOAT4* other)
		{
			XMStoreFloat4(dxVector, XMLoadFloat4(other));
		}

		void Quat::xmStore(XMFLOAT4* dxVector, const XMVECTOR& other)
		{
			XMStoreFloat4(dxVector, other);
		}

		void Quat::xmStore(XMFLOAT4* dxVector, const Vector4& other)
		{
			XMStoreFloat4(dxVector, other.xmLoad());
		}

		void Quat::xmStore(XMFLOAT4* dxVector, const Quat& other)
		{
			XMStoreFloat4(dxVector, other.xmLoad());
		}

		XMVECTOR Quat::xmLoad(const XMFLOAT4& dxVector)
		{
			return XMLoadFloat4(&dxVector);
		}

		XMVECTOR Quat::xmLoad(const XMFLOAT4* dxVector)
		{
			return XMLoadFloat4(dxVector);
		}

		XMVECTOR Quat::xmLoad(const Quat& dxVector)
		{
			return dxVector.xmLoad();
		}
	}
}