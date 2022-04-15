#pragma once

#include "MathCommon.h"

namespace Engine
{

	class Vector3
	{
	public:
		// ----------------------------------------------------------------------
		// Predefined Vector
		// ----------------------------------------------------------------------


		static const Vector3 zero()
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}

		static const Vector3 one()
		{
			return Vector3(1.0f, 1.0f, 1.0f);
		}

		static const Vector3 up()
		{
			return Vector3(0.0f, 0.0f, 1.0f);
		}

		static const Vector3 down()
		{
			return Vector3(0.0f, 0.0f, -1.0f);
		}

		static const Vector3 forward()
		{
			return Vector3(1.0f, 0.0f, 0.0f);
		}

		static const Vector3 backward()
		{
			return Vector3(-1.0f, 0.0f, 0.0f);
		}

		static const Vector3 right()
		{
			return Vector3(0.0f, 1.0f, 0.0f);
		}

		static const Vector3 left()
		{
			return Vector3(0.0f, -1.0f, 0.0f);
		}

		static const Vector3 xAxis()
		{
			return Vector3(1.0f, 0.0f, 0.0f);
		}

		static const Vector3 yAxis()
		{
			return Vector3(0.0f, 1.0f, 0.0f);
		}

		static const Vector3 zAxis()
		{
			return Vector3(0.0f, 0.0f, 1.0f);
		}

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		inline Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		{
			setX(x);
			setY(y);
			setZ(z);
		}

		inline Vector3(const XMFLOAT3* other)
		{
			xmStore(other);
		}

		inline Vector3(const XMFLOAT3& other)
		{
			xmStore(other);
		}

		inline Vector3(const XMVECTOR& other)
		{
			xmStore(other);
		}

		inline Vector3(const Vector3& other)
		{
			xmStore(other);
		}

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		inline const XMFLOAT3* getDXVector() const
		{
			return &m_dxVector;
		}

		inline XMFLOAT3* getDXVectorUnsafe()
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

	public:
		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		inline bool operator==(const Vector3& v) const
		{
			return XMVector3Equal(xmLoad(), v.xmLoad());
		}

		inline bool operator!=(const Vector3& v) const
		{
			return XMVector3NotEqual(xmLoad(), v.xmLoad());
		}

		inline bool operator>(const Vector3& v) const
		{
			return XMVector3Greater(xmLoad(), v.xmLoad());
		}

		inline bool operator<(const Vector3& v) const
		{
			return XMVector3Less(xmLoad(), v.xmLoad());
		}

		inline bool operator>=(const Vector3& v) const
		{
			return XMVector3GreaterOrEqual(xmLoad(), v.xmLoad());
		}

		inline bool operator<=(const Vector3& v) const
		{
			return XMVector3LessOrEqual(xmLoad(), v.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		inline Vector3 operator+(const Vector3& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() + v.xmLoad());

			return Vector3(dxResult);
		}

		inline Vector3 operator+(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));


			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Vector3(dxResult);
		}

		inline Vector3 operator-(const Vector3& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() - v.xmLoad());

			return Vector3(dxResult);
		}

		inline Vector3 operator-(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() - xmLoad(dxVector));

			return Vector3(dxResult);
		}

		inline Vector3 operator*(const Vector3& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() * v.xmLoad());

			return Vector3(dxResult);
		}

		inline Vector3 operator*(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Vector3(dxResult);
		}

		inline Vector3 operator/(const Vector3& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() / v.xmLoad());

			return Vector3(dxResult);
		}

		inline Vector3 operator/(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() / xmLoad(dxVector));

			return Vector3(dxResult);
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		inline Vector3& operator=(const Vector3& other)
		{
			xmStore(other);

			return *this;
		}

		inline Vector3& operator+=(const Vector3& other)
		{
			xmStore(xmLoad() + other.xmLoad());

			return *this;
		}

		inline Vector3& operator+=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() + xmLoad(dxVector));

			return *this;
		}

		inline Vector3& operator-=(const Vector3& other)
		{
			xmStore(xmLoad() - other.xmLoad());

			return *this;
		}

		inline Vector3& operator-=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		inline Vector3& operator*=(const Vector3& other)
		{
			xmStore(xmLoad() * other.xmLoad());

			return *this;
		}

		inline Vector3& operator*=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));

			return *this;
		}

		inline Vector3& operator/=(const Vector3& other)
		{
			xmStore(xmLoad() / other.xmLoad());

			return *this;
		}

		inline Vector3& operator/=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() / xmLoad(dxVector));

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		inline float operator[](int index)
		{
			assert(index >= 0 && index <= 2);

			float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
			return v[index];
		}

		inline float operator[](int index) const
		{
			assert(index >= 0 && index <= 2);
			float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
			return v[index];
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		inline void set(float x, float y, float z)
		{
			setX(x);
			setY(y);
			setZ(z);
		}

		inline void set(const XMFLOAT3* other)
		{
			xmStore(other);
		}

		inline void set(const XMFLOAT3& other)
		{
			xmStore(other);
		}

		inline void set(const XMVECTOR& other)
		{
			xmStore(other);
		}

		inline void set(const Vector3& other)
		{
			xmStore(other);
		}

		inline bool equals(const Vector3& other, float tolerance = VECTOR_TOLERANCE)
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

			return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance;
		}

		inline float dotProduct(const Vector3& other) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVector3Dot(xmLoad(), other.xmLoad()));

			return dxResult.x;
		}

		inline Vector3 crossProduct(const Vector3& other) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVector3Cross(xmLoad(), other.xmLoad()));

			return Vector3(dxResult);
		}

		inline Vector3 abs()
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad()));

			return Vector3(dxResult);
		}

		inline Vector3 normalize() const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVector3Normalize(xmLoad()));

			return Vector3(dxResult);
		}

		inline float length() const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVector3Length(xmLoad()));

			return dxResult.x;
		}

		inline float distance(const Vector3& other) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVector3Length(xmLoad() - other.xmLoad()));

			return dxResult.x;
		}

		inline Vector3 clamp(const Vector3& min, const Vector3& max) const
		{
			return Vector3(
				fminf(fmaxf(min.getX(), getX()), max.getX()),
				fminf(fmaxf(min.getY(), getY()), max.getY()),
				fminf(fmaxf(min.getZ(), getZ()), max.getZ())
			);
		}

		inline Vector3 clamp(float min, float max) const
		{
			return Vector3(XMVector3ClampLength(xmLoad(), min, max));
		}

		inline bool isNearlyZero(float tolerance = VECTOR_TOLERANCE) const
		{
			return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance;
		}

		inline bool isZero() const
		{
			return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f;
		}

		inline bool isNaN() const
		{
			return XMVector3IsNaN(xmLoad());
		}

		inline bool isInfinite() const
		{
			return XMVector3IsInfinite(xmLoad());
		}

	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		inline void xmStore(const XMFLOAT3& other)
		{
			m_dxVector = other;
		}

		inline void xmStore(const XMFLOAT3* other)
		{
			m_dxVector = *other;
		}

		inline void xmStore(const XMVECTOR& other)
		{
			XMStoreFloat3(&m_dxVector, other);
		}

		inline void xmStore(const Vector3& other)
		{
			XMStoreFloat3(&m_dxVector, other.xmLoad());
		}

		inline XMVECTOR xmLoad() const
		{
			return XMLoadFloat3(&m_dxVector);
		}

	public:
		// ----------------------------------------------------------------------
		// For Vector3
		// ----------------------------------------------------------------------

		inline static void xmStore(Vector3& v, const XMFLOAT3& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector3& v, const XMFLOAT3* other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector3& v, const XMVECTOR& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector3& v, const Vector3& other)
		{
			v.xmStore(other);
		}

		inline static XMVECTOR xmLoad(const Vector3& v)
		{
			return v.xmLoad();
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Reference
		// ----------------------------------------------------------------------

		inline static void xmStore(XMFLOAT3& v, const XMFLOAT3& other)
		{
			v = other;
		}

		inline static void xmStore(XMFLOAT3& v, const XMFLOAT3* other)
		{
			v = *other;
		}

		inline static void xmStore(XMFLOAT3& v, const XMVECTOR& other)
		{
			XMStoreFloat3(&v, other);
		}

		inline static void xmStore(XMFLOAT3& v, const Vector3& other)
		{
			XMStoreFloat3(&v, other.xmLoad());
		}

		inline static XMVECTOR xmLoad(const XMFLOAT3& v)
		{
			return XMLoadFloat3(&v);
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Pointer
		// ----------------------------------------------------------------------

		inline static void xmStore(XMFLOAT3* v, const XMFLOAT3& other)
		{
			XMStoreFloat3(v, XMLoadFloat3(&other));
		}

		inline static void xmStore(XMFLOAT3* v, const XMFLOAT3* other)
		{
			XMStoreFloat3(v, XMLoadFloat3(other));
		}

		inline static void xmStore(XMFLOAT3* v, const XMVECTOR& other)
		{
			XMStoreFloat3(v, other);
		}

		inline static void xmStore(XMFLOAT3* v, const Vector3& other)
		{
			XMStoreFloat3(v, other.xmLoad());
		}

		inline static XMVECTOR xmLoad(const XMFLOAT3* v)
		{
			return XMLoadFloat3(v);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT3 m_dxVector;
	};
}
