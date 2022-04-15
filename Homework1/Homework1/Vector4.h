#pragma once

namespace Engine
{
	class Vector4
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		inline Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
		{
			m_dxVector.x = x;
			m_dxVector.y = y;
			m_dxVector.z = z;
			m_dxVector.w = w;
		}

		inline Vector4(const XMFLOAT4* other)
		{
			xmStore(other);
		}

		inline Vector4(const XMFLOAT4& other)
		{
			xmStore(other);
		}

		inline Vector4(const XMVECTOR& other)
		{
			xmStore(other);
		}

		inline Vector4(const Vector4& other)
		{
			xmStore(other);
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

		inline bool operator==(const Vector4& other) const
		{
			return XMVector4Equal(xmLoad(), other.xmLoad());
		}

		inline bool operator!=(const Vector4& other) const
		{
			return XMVector4NotEqual(xmLoad(), other.xmLoad());
		}

		inline bool operator>(const Vector4& other) const
		{
			return XMVector4Greater(xmLoad(), other.xmLoad());
		}

		inline bool operator<(const Vector4& other) const
		{
			return XMVector4Less(xmLoad(), other.xmLoad());
		}

		inline bool operator>=(const Vector4& other) const
		{
			return XMVector4GreaterOrEqual(xmLoad(), other.xmLoad());
		}

		inline bool operator<=(const Vector4& other) const
		{
			return XMVector4LessOrEqual(xmLoad(), other.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		inline Vector4 operator+(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + other.xmLoad());

			return Vector4(dxResult);
		}

		inline Vector4 operator+(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Vector4(dxResult);
		}

		inline Vector4 operator-(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() - other.xmLoad());

			return Vector4(dxResult);
		}

		inline Vector4 operator-(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() - xmLoad(dxVector));

			return Vector4(dxResult);
		}

		inline Vector4 operator*(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() * other.xmLoad());

			return Vector4(dxResult);
		}

		inline Vector4 operator*(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Vector4(dxResult);
		}

		inline Vector4 operator/(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / other.xmLoad());

			return Vector4(dxResult);
		}

		inline Vector4 operator/(float other) const
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			XMFLOAT4 dxResult;
			xmStore(dxResult, xmLoad() / xmLoad(dxVector));

			return Vector4(dxResult);
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		inline Vector4& operator=(const Vector4& other)
		{
			xmStore(other);

			return *this;
		}

		inline Vector4& operator+=(const Vector4& other)
		{
			xmStore(xmLoad() + other.xmLoad());

			return *this;
		}

		inline Vector4& operator+=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		inline Vector4& operator-=(const Vector4& other)
		{
			xmStore(xmLoad() - other.xmLoad());

			return *this;
		}

		inline Vector4& operator-=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		inline Vector4& operator*=(const Vector4& other)
		{
			xmStore(xmLoad() * other.xmLoad());

			return *this;
		}

		inline Vector4& operator*=(float other)
		{
			XMFLOAT4 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));

			return *this;
		}

		inline Vector4& operator/=(const Vector4& other)
		{
			xmStore(xmLoad() / other.xmLoad());

			return *this;
		}

		inline Vector4& operator/=(float other)
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
		// Public Member Method
		// ----------------------------------------------------------------------

		inline void set(float x, float y, float z, float w)
		{
			setX(x);
			setY(y);
			setZ(z);
			setW(w);
		}

		inline void set(const XMFLOAT4* other)
		{
			xmStore(other);
		}

		inline void set(const XMFLOAT4& other)
		{
			xmStore(other);
		}

		inline void set(const XMVECTOR& other)
		{
			xmStore(other);
		}

		inline void set(const Vector4& other)
		{
			xmStore(other);
		}

		inline bool equals(const Vector4& other, float tolerance = VECTOR_TOLERANCE) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

			return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance && dxResult.w <= tolerance;
		}

		inline float dotProduct(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVector4Dot(xmLoad(), other.xmLoad()));

			return dxResult.x;
		}

		inline Vector4 crossProduct(const Vector4& v1, const Vector4& v2) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVector4Cross(xmLoad(), v1.xmLoad(), v2.xmLoad()));

			return Vector4(dxResult);
		}

		inline Vector4 getAbs() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad()));

			return Vector4(dxResult);
		}

		inline Vector4 normalize() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVector4Normalize(xmLoad()));

			return dxResult;
		}

		inline float length() const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVector4Length(xmLoad(m_dxVector)));

			return dxResult.x;
		}

		inline float distance(const Vector4& other) const
		{
			XMFLOAT4 dxResult;
			xmStore(dxResult, XMVector4Length(xmLoad() - other.xmLoad()));

			return dxResult.x;
		}

		inline Vector4 clamp(const Vector4& min, const Vector4& max) const
		{
			return Vector4(
				fminf(fmaxf(min.getX(), getX()), max.getX()),
				fminf(fmaxf(min.getY(), getY()), max.getY()),
				fminf(fmaxf(min.getZ(), getZ()), max.getZ()),
				fminf(fmaxf(min.getW(), getW()), max.getW())
			);
		}

		inline Vector4 clamp(float min, float max) const
		{
			return Vector4(XMVector4ClampLength(xmLoad(), min, max));
		}

		inline bool isNearlyZero(float tolerance = VECTOR_TOLERANCE) const
		{
			return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance && fabsf(m_dxVector.w) <= tolerance;
		}

		inline bool isZero() const
		{
			return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f && m_dxVector.w == 0.0f;
		}

		inline bool isNaN() const
		{
			return XMVector4IsNaN(xmLoad());
		}

		inline bool isInfinite() const
		{
			return XMVector4IsInfinite(xmLoad());
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

		inline XMVECTOR xmLoad() const
		{
			return XMLoadFloat4(&m_dxVector);
		}

	public:
		// ----------------------------------------------------------------------
		// For Vector4
		// ----------------------------------------------------------------------

		inline static void xmStore(Vector4& v, const XMFLOAT4& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector4& v, const XMFLOAT4* other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector4& v, const XMVECTOR& other)
		{
			v.xmStore(other);
		}

		inline static void xmStore(Vector4& v, const Vector4& other)
		{
			v.xmStore(other);
		}

		inline static XMVECTOR xmLoad(const Vector4& v)
		{
			return v.xmLoad();
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT4 Reference
		// ----------------------------------------------------------------------

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

		inline static XMVECTOR xmLoad(const XMFLOAT4& v)
		{
			return XMLoadFloat4(&v);
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT4 Pointer
		// ----------------------------------------------------------------------

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

		inline static XMVECTOR xmLoad(const XMFLOAT4* v)
		{
			return XMLoadFloat4(v);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT4 m_dxVector;
	};
}