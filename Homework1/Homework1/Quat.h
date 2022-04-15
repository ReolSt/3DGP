#pragma once

#include "MathCommon.h"
#include "Vector4.h"
#include "Rotator.h"
#include "Matrix.h"

namespace Engine
{
	class Quat
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		inline Quat(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
		{
			m_dxVector.x = x;
			m_dxVector.y = y;
			m_dxVector.z = z;
			m_dxVector.w = w;
		}

		inline Quat(const Vector3& axis, float angle)
		{
			xmStore(XMQuaternionRotationAxis(axis.xmLoad(), angle));
		}

		inline Quat(const Rotator& r)
		{
			xmStore(XMQuaternionRotationRollPitchYaw(r.getRoll(), r.getPitch(), r.getYaw()));
		}

		inline Quat(const XMFLOAT4& v)
		{
			xmStore(v);
		}

		inline Quat(const XMFLOAT4* v)
		{
			xmStore(v);
		}

		inline Quat(const XMVECTOR& v)
		{
			xmStore(v);
		}

		inline Quat(const Vector4& v)
		{
			xmStore(v);
		}

		inline Quat(const Quat& q)
		{
			xmStore(q);
		}

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		inline const XMFLOAT4* getDXVector() const
		{
			return &m_dxVector;
		}

		inline XMFLOAT4* getDXVectorUnsafe()
		{
			return &m_dxVector;
		}

		inline float getX() const
		{
			return m_dxVector.x;
		}

		inline float getY() const
		{
			return m_dxVector.y;
		}

		inline float getZ() const
		{
			return m_dxVector.z;
		}

		inline float getW() const
		{
			return m_dxVector.w;
		}

		inline void setX(float x)
		{
			m_dxVector.x = x;
		}

		inline void setY(float y)
		{
			m_dxVector.y = y;
		}

		inline void setZ(float z)
		{
			m_dxVector.z = z;
		}

		inline void setW(float w)
		{
			m_dxVector.w = w;
		}

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		inline bool operator==(const Quat& other) const
		{
			return XMVector4Equal(xmLoad(), other.xmLoad());
		}

		inline bool operator!=(const Quat& other) const
		{
			return XMVector4NotEqual(xmLoad(), other.xmLoad());
		}

		inline bool operator>(const Quat& other) const
		{
			return XMVector4Greater(xmLoad(), other.xmLoad());
		}

		inline bool operator<(const Quat& other) const
		{
			return XMVector4Less(xmLoad(), other.xmLoad());
		}

		inline bool operator>=(const Quat& other) const
		{
			return XMVector4GreaterOrEqual(xmLoad(), other.xmLoad());
		}

		inline bool operator<=(const Quat& other) const
		{
			return XMVector4LessOrEqual(xmLoad(), other.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		inline Quat operator+(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + other.xmLoad());

			return Quat(dxResult);
		}

		inline Quat operator+(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Quat(dxResult);
		}

		inline Quat operator-(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() - other.xmLoad());

			return Quat(dxResult);
		}

		inline Quat operator-(float other) const
		{
			XMFLOAT4 dxVector(other, other, other, other);

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() - xmLoad(dxVector));

			return Quat(dxResult);
		}

		inline Quat operator*(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() * other.xmLoad());

			return Quat(dxResult);
		}

		inline Quat operator*(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Quat(dxResult);
		}

		inline Quat operator/(const Quat& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / other.xmLoad());

			return Quat(dxResult);
		}

		inline Quat operator/(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / xmLoad(dxVector));

			return Quat(dxResult);
		}

		inline Vector3 operator*(const Vector3& other) const
		{
			return rotate(other);
		}

		inline Matrix operator*(const Matrix& other) const
		{
			return rotate(other);
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		inline Quat& operator+=(const Quat& other)
		{
			xmStore(xmLoad() + other.xmLoad());

			return *this;
		}

		inline Quat& operator+=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		inline Quat& operator-=(const Quat& other)
		{
			xmStore(xmLoad() - other.xmLoad());

			return *this;
		}

		inline Quat& operator-=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		inline Quat& operator*=(const Quat& other)
		{
			xmStore(xmLoad() * other.xmLoad());

			return *this;
		}

		inline Quat& operator*=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));

			return *this;
		}

		inline Quat& operator/=(const Quat& other)
		{
			xmStore(xmLoad() / other.xmLoad());

			return *this;
		}

		inline Quat& operator/=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() / xmLoad(dxVector));

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		inline float operator[](int index)
		{
			assert(index >= 0 && index <= 3);

			float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
			return v[index];
		}

		inline float operator[](int index) const
		{
			assert(index >= 0 && index <= 3);

			float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
			return v[index];
		}

		// ----------------------------------------------------------------------
		// Mathmatical Getter
		// ----------------------------------------------------------------------

		inline float getAngle() const
		{
			XMVECTOR dxAxisResult;
			float dxAngleResult;

			XMQuaternionToAxisAngle(&dxAxisResult, &dxAngleResult, xmLoad());

			return dxAngleResult;
		}

		inline Vector3 getAxis() const
		{
			XMVECTOR dxAxisResult;
			float dxAngleResult;

			XMQuaternionToAxisAngle(&dxAxisResult, &dxAngleResult, xmLoad());

			return Vector3(dxAxisResult);
		}

		inline Vector3 getAxisX() const
		{
			return rotate(Vector3(1.0f, 0.0f, 0.0f));
		}

		inline Vector3 getAxisY() const
		{
			return rotate(Vector3(0.0f, 1.0f, 0.0f));
		}

		inline Vector3 getAxisZ() const
		{
			return rotate(Vector3(0.0f, 0.0f, 1.0f));
		}

		inline Vector3 getForwardVector() const
		{
			return getAxisX();
		}

		inline Vector3 getRightVector() const
		{
			return getAxisY();
		}

		inline Vector3 getUpVector() const
		{
			return getAxisZ();
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		inline bool equals(Quat& other, float tolerance = QUAT_TOLERANCE) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

			return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance && dxResult.w <= tolerance;
		}

		inline Vector3 rotate(const Vector3& v) const
		{
			XMFLOAT3 dxResult;
			Vector3::xmStore(dxResult, XMVector3Rotate(v.xmLoad(), xmLoad()));

			return Vector3(dxResult);
		}

		inline Matrix rotate(const Matrix& m) const
		{
			return Matrix(m.xmLoad() * XMMatrixRotationQuaternion(xmLoad()));
		}

		inline Vector4 normalize() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMQuaternionNormalize(xmLoad()));

			return dxResult;
		}

		inline float length() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMQuaternionLength(xmLoad(m_dxVector)));

			return dxResult.x;
		}

		inline Quat inverse() const
		{
			return Quat(XMQuaternionInverse(xmLoad()));
		}

		inline bool isNearlyZero(float tolerance = QUAT_TOLERANCE) const
		{
			return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance && fabsf(m_dxVector.w) <= tolerance;
		}

		inline bool isZero() const
		{
			return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f && m_dxVector.w == 0.0f;
		}

		inline bool isNaN() const
		{
			return XMQuaternionIsNaN(xmLoad());
		}

		inline bool isInfinite() const
		{
			return XMQuaternionIsInfinite(xmLoad());
		}

	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		inline void xmStore(const XMFLOAT4& other)
		{
			m_dxVector = other;
		}

		inline void xmStore(const XMFLOAT4* other)
		{
			m_dxVector = *other;
		}

		inline void xmStore(const XMVECTOR* other)
		{
			XMStoreFloat4(&m_dxVector, *other);
		}

		inline void xmStore(const XMVECTOR& other)
		{
			XMStoreFloat4(&m_dxVector, other);
		}

		inline void xmStore(const Vector4& other)
		{
			XMStoreFloat4(&m_dxVector, other.xmLoad());
		}

		inline void xmStore(const Quat& other)
		{
			XMStoreFloat4(&m_dxVector, other.xmLoad());
		}

		inline XMVECTOR xmLoad() const
		{
			return XMLoadFloat4(&m_dxVector);
		}

	public:
		inline static void xmStore(Quat& v, const XMFLOAT4& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Quat& v, const XMFLOAT4* other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Quat& v, const XMVECTOR& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Quat& v, const Vector4& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Quat& v, const Quat& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(XMFLOAT4& v, const XMFLOAT4& other)
		{
			v = other;
		}

		inline static void xmStore(XMFLOAT4& v, const XMFLOAT4* other)
		{
			v = *other;
		}

		inline static void xmStore(XMFLOAT4& v, const XMVECTOR& other)
		{
			XMStoreFloat4(&v, other);
		}

		inline static void xmStore(XMFLOAT4& v, const Vector4& other)
		{
			XMStoreFloat4(&v, other.xmLoad());
		}

		inline static void xmStore(XMFLOAT4& v, const Quat& other)
		{
			XMStoreFloat4(&v, other.xmLoad());
		}

		inline static void xmStore(XMFLOAT4* v, const XMFLOAT4& other)
		{
			XMStoreFloat4(v, XMLoadFloat4(&other));
		}

		inline static void xmStore(XMFLOAT4* v, const XMFLOAT4* other)
		{
			XMStoreFloat4(v, XMLoadFloat4(other));
		}

		inline static void xmStore(XMFLOAT4* v, const XMVECTOR& other)
		{
			XMStoreFloat4(v, other);
		}

		inline static void xmStore(XMFLOAT4* v, const Vector4& other)
		{
			XMStoreFloat4(v, other.xmLoad());
		}

		inline static void xmStore(XMFLOAT4* v, const Quat& other)
		{
			XMStoreFloat4(v, other.xmLoad());
		}

		inline static XMVECTOR xmLoad(const XMFLOAT4& v)
		{
			return XMLoadFloat4(&v);
		}

		inline static XMVECTOR xmLoad(const XMFLOAT4* v)
		{
			return XMLoadFloat4(v);
		}

		inline static XMVECTOR xmLoad(const Quat& v)
		{
			return v.xmLoad();
		}

	public:

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT4 m_dxVector;
	};
}