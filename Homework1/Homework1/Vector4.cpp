#include "Vector4.h"
#include "Vector3.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
    // ----------------------------------------------------------------------

	Vector4::Vector4(float x, float y, float z, float w)
	{
		m_dxVector.x = x;
		m_dxVector.y = y;
		m_dxVector.z = z;
		m_dxVector.w = w;
	}

	Vector4::Vector4(const XMFLOAT4* other)
	{
		xmStore(other);
	}

	Vector4::Vector4(const XMFLOAT4& other)
	{
		xmStore(other);
	}

	Vector4::Vector4(const XMVECTOR& other)
	{
		xmStore(other);
	}

	Vector4::Vector4(const Vector3& other, float w)
	{
		xmStore(m_dxVector, Vector3::xmLoad(other));

		setW(w);
	}

	Vector4::Vector4(const Vector4& other)
	{
		xmStore(other);
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	const XMFLOAT4* Vector4::getDXVector() const
	{
		return &m_dxVector;
	}

	XMFLOAT4* Vector4::getDXVectorUnsafe()
	{
		return &m_dxVector;
	}

	float Vector4::getX() const
	{
		return m_dxVector.x;
	}

	float Vector4::getY() const
	{
		return m_dxVector.y;
	}

	float Vector4::getZ() const
	{
		return m_dxVector.z;
	}

	float Vector4::getW() const
	{
		return m_dxVector.w;
	}

	void Vector4::setX(float x)
	{
		m_dxVector.x = x;
	}

	void Vector4::setY(float y)
	{
		m_dxVector.y = y;
	}

	void Vector4::setZ(float z)
	{
		m_dxVector.z = z;
	}

	void Vector4::setW(float w)
	{
		m_dxVector.w = w;
	}

	// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

	bool Vector4::operator==(const Vector4& other) const
	{
		return XMVector4Equal(xmLoad(), other.xmLoad());
	}

	bool Vector4::operator!=(const Vector4& other) const
	{
		return XMVector4NotEqual(xmLoad(), other.xmLoad());
	}

	bool Vector4::operator>(const Vector4& other) const
	{
		return XMVector4Greater(xmLoad(), other.xmLoad());
	}

	bool Vector4::operator<(const Vector4& other) const
	{
		return XMVector4Less(xmLoad(), other.xmLoad());
	}

	bool Vector4::operator>=(const Vector4& other) const
	{
		return XMVector4GreaterOrEqual(xmLoad(), other.xmLoad());
	}

	bool Vector4::operator<=(const Vector4& other) const
	{
		return XMVector4LessOrEqual(xmLoad(), other.xmLoad());
	}

	// ----------------------------------------------------------------------
	// Arthimetric Operator
	// ----------------------------------------------------------------------

	Vector4 Vector4::operator-() const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVectorNegate(xmLoad()));

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator+(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() + other.xmLoad());

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator+(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() + xmLoad(dxVector));

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator-(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() - other.xmLoad());

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator-(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() - xmLoad(dxVector));

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator*(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() * other.xmLoad());

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator*(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() * xmLoad(dxVector));

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator/(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() / other.xmLoad());

		return Vector4(dxResult);
	}

	Vector4 Vector4::operator/(float other) const
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

	Vector4& Vector4::operator=(const Vector4& other)
	{
		xmStore(other);

		return *this;
	}

	Vector4& Vector4::operator+=(const Vector4& other)
	{
		xmStore(xmLoad() + other.xmLoad());

		return *this;
	}

	Vector4& Vector4::operator+=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() - xmLoad(dxVector));

		return *this;
	}

	Vector4& Vector4::operator-=(const Vector4& other)
	{
		xmStore(xmLoad() - other.xmLoad());

		return *this;
	}

	Vector4& Vector4::operator-=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() - xmLoad(dxVector));

		return *this;
	}

	Vector4& Vector4::operator*=(const Vector4& other)
	{
		xmStore(xmLoad() * other.xmLoad());

		return *this;
	}

	Vector4& Vector4::operator*=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() * xmLoad(dxVector));

		return *this;
	}

	Vector4& Vector4::operator/=(const Vector4& other)
	{
		xmStore(xmLoad() / other.xmLoad());

		return *this;
	}

	Vector4& Vector4::operator/=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() / xmLoad(dxVector));

		return *this;
	}

	// ----------------------------------------------------------------------
	// Subscript Operator
	// ----------------------------------------------------------------------

	float Vector4::operator[](int index)
	{
		assert(index >= 0 && index <= 3);

		float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
		return v[index];
	}

	float Vector4::operator[](int index) const
	{
		assert(index >= 0 && index <= 3);

		float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
		return v[index];
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void Vector4::set(float x, float y, float z, float w)
	{
		setX(x);
		setY(y);
		setZ(z);
		setW(w);
	}


	void Vector4::set(const XMFLOAT4* other)
	{
		xmStore(other);
	}

	void Vector4::set(const XMFLOAT4& other)
	{
		xmStore(other);
	}

	void Vector4::set(const XMVECTOR& other)
	{
		xmStore(other);
	}

	void Vector4::set(const Vector4& other)
	{
		xmStore(other);
	}

	bool Vector4::equals(const Vector4& other, float tolerance) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

		return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance && dxResult.w <= tolerance;
	}

	float Vector4::dotProduct(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVector4Dot(xmLoad(), other.xmLoad()));

		return dxResult.x;
	}

	Vector4 Vector4::crossProduct(const Vector4& v1, const Vector4& v2) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVector4Cross(xmLoad(), v1.xmLoad(), v2.xmLoad()));

		return Vector4(dxResult);
	}

	Vector4 Vector4::abs() const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVectorAbs(xmLoad()));

		return Vector4(dxResult);
	}

	Vector4 Vector4::normalize() const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVector4Normalize(xmLoad()));

		return dxResult;
	}

	float Vector4::length() const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVector4Length(xmLoad(m_dxVector)));

		return dxResult.x;
	}

	float Vector4::distance(const Vector4& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVector4Length(xmLoad() - other.xmLoad()));

		return dxResult.x;
	}

	Vector4 Vector4::clamp(const Vector4& min, const Vector4& max) const
	{
		return Vector4(
			fminf(fmaxf(min.getX(), getX()), max.getX()),
			fminf(fmaxf(min.getY(), getY()), max.getY()),
			fminf(fmaxf(min.getZ(), getZ()), max.getZ()),
			fminf(fmaxf(min.getW(), getW()), max.getW())
		);
	}

	Vector4 Vector4::clamp(float min, float max) const
	{
		return Vector4(XMVector4ClampLength(xmLoad(), min, max));
	}

	bool Vector4::isNearlyZero(float tolerance) const
	{
		return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance && fabsf(m_dxVector.w) <= tolerance;
	}

	bool Vector4::isZero() const
	{
		return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f && m_dxVector.w == 0.0f;
	}

	bool Vector4::isNaN() const
	{
		return XMVector4IsNaN(xmLoad());
	}

	bool Vector4::isInfinite() const
	{
		return XMVector4IsInfinite(xmLoad());
	}

	// ----------------------------------------------------------------------
	// XMMATH Helper
	// ----------------------------------------------------------------------

	void Vector4::xmStore(const XMFLOAT4& other)
	{
		m_dxVector = other;
	}

	void Vector4::xmStore(const XMFLOAT4* other)
	{
		m_dxVector = *other;
	}

	void Vector4::xmStore(const XMVECTOR* other)
	{
		XMStoreFloat4(&m_dxVector, *other);
	}

	void Vector4::xmStore(const XMVECTOR& other)
	{
		XMStoreFloat4(&m_dxVector, other);
	}

	void Vector4::xmStore(const Vector4& other)
	{
		XMStoreFloat4(&m_dxVector, other.xmLoad());
	}

	XMVECTOR Vector4::xmLoad() const
	{
		return XMLoadFloat4(&m_dxVector);
	}

	void Vector4::xmStore(Vector4& v, const XMFLOAT4& other)
	{
		v.xmStore(other);
	}

	void Vector4::xmStore(Vector4& v, const XMFLOAT4* other)
	{
		v.xmStore(other);
	}

	void Vector4::xmStore(Vector4& v, const XMVECTOR& other)
	{
		v.xmStore(other);
	}

	void Vector4::xmStore(Vector4& v, const Vector4& other)
	{
		v.xmStore(other);
	}

	XMVECTOR Vector4::xmLoad(const Vector4& v)
	{
		return v.xmLoad();
	}

	void Vector4::xmStore(XMFLOAT4& v, const XMFLOAT4& other)
	{
		v = other;
	}

	void Vector4::xmStore(XMFLOAT4& v, const XMFLOAT4* other)
	{
		v = *other;
	}

	void Vector4::xmStore(XMFLOAT4& v, const XMVECTOR& other)
	{
		XMStoreFloat4(&v, other);
	}

	void Vector4::xmStore(XMFLOAT4& v, const Vector4& other)
	{
		XMStoreFloat4(&v, other.xmLoad());
	}

	XMVECTOR Vector4::xmLoad(const XMFLOAT4& v)
	{
		return XMLoadFloat4(&v);
	}

	void Vector4::xmStore(XMFLOAT4* v, const XMFLOAT4& other)
	{
		XMStoreFloat4(v, XMLoadFloat4(&other));
	}

	void Vector4::xmStore(XMFLOAT4* v, const XMFLOAT4* other)
	{
		XMStoreFloat4(v, XMLoadFloat4(other));
	}

	void Vector4::xmStore(XMFLOAT4* v, const XMVECTOR& other)
	{
		XMStoreFloat4(v, other);
	}

	void Vector4::xmStore(XMFLOAT4* v, const Vector4& other)
	{
		XMStoreFloat4(v, other.xmLoad());
	}

	XMVECTOR Vector4::xmLoad(const XMFLOAT4* v)
	{
		return XMLoadFloat4(v);
	}

}