#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Predefined Vector
	// ----------------------------------------------------------------------

	Vector3 Vector3::zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::one()
	{
		return Vector3(1.0f, 1.0f, 1.0f);
	}

	Vector3 Vector3::up()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	Vector3 Vector3::down()
	{
		return Vector3(0.0f, 0.0f, -1.0f);
	}

	Vector3 Vector3::forward()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::backward()
	{
		return Vector3(-1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::right()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	Vector3 Vector3::left()
	{
		return Vector3(0.0f, -1.0f, 0.0f);
	}

	Vector3 Vector3::xAxis()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::yAxis()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	Vector3 Vector3::zAxis()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	Vector3::Vector3(float x, float y, float z)
	{
		setX(x);
		setY(y);
		setZ(z);
	}

	Vector3::Vector3(const XMFLOAT3* other)
	{
		xmStore(other);
	}

	Vector3::Vector3(const XMFLOAT3& other)
	{
		xmStore(other);
	}

	Vector3::Vector3(const XMVECTOR& other)
	{
		xmStore(other);
	}

	Vector3::Vector3(const Vector3& other)
	{
		xmStore(other);
	}

	Vector3::Vector3(const Vector4& other)
	{
		xmStore(Vector4::xmLoad(other));
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	const XMFLOAT3* Vector3::getDXVector() const
	{
		return &m_dxVector;
	}

	XMFLOAT3* Vector3::getDXVectorUnsafe()
	{
		return &m_dxVector;
	}

	float Vector3::getX() const
	{
		return m_dxVector.x;
	}

	float Vector3::getY() const
	{
		return m_dxVector.y;
	}

	float Vector3::getZ() const
	{
		return m_dxVector.z;
	}

	void Vector3::setX(float x)
	{
		m_dxVector.x = x;
	}

	void Vector3::setY(float y)
	{
		m_dxVector.y = y;
	}

	void Vector3::setZ(float z)
	{
		m_dxVector.z = z;
	}

	// ----------------------------------------------------------------------
	// Comparison Operator
	// ----------------------------------------------------------------------

	bool Vector3::operator==(const Vector3& v) const
	{
		return XMVector3Equal(xmLoad(), v.xmLoad());
	}

	bool Vector3::operator!=(const Vector3& v) const
	{
		return XMVector3NotEqual(xmLoad(), v.xmLoad());
	}

	bool Vector3::operator>(const Vector3& v) const
	{
		return XMVector3Greater(xmLoad(), v.xmLoad());
	}

	bool Vector3::operator<(const Vector3& v) const
	{
		return XMVector3Less(xmLoad(), v.xmLoad());
	}

	bool Vector3::operator>=(const Vector3& v) const
	{
		return XMVector3GreaterOrEqual(xmLoad(), v.xmLoad());
	}

	bool Vector3::operator<=(const Vector3& v) const
	{
		return XMVector3LessOrEqual(xmLoad(), v.xmLoad());
	}

	// ----------------------------------------------------------------------
	// Arthimetric Operator
	// ----------------------------------------------------------------------

	Vector3 Vector3::operator-() const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVectorNegate(xmLoad()));

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator+(const Vector3& v) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() + v.xmLoad());

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator+(float scale) const
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(scale));


		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() + xmLoad(dxVector));

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator-(const Vector3& v) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() - v.xmLoad());

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator-(float scale) const
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(scale));

		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() - xmLoad(dxVector));

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator*(const Vector3& v) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() * v.xmLoad());

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator*(float scale) const
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(scale));

		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() * xmLoad(dxVector));

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator/(const Vector3& v) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, xmLoad() / v.xmLoad());

		return Vector3(dxResult);
	}

	Vector3 Vector3::operator/(float scale) const
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

	Vector3& Vector3::operator=(const Vector3& other)
	{
		xmStore(other);

		return *this;
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		xmStore(xmLoad() + other.xmLoad());

		return *this;
	}

	Vector3& Vector3::operator+=(float other)
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() + xmLoad(dxVector));

		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		xmStore(xmLoad() - other.xmLoad());

		return *this;
	}

	Vector3& Vector3::operator-=(float other)
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() - xmLoad(dxVector));

		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3& other)
	{
		xmStore(xmLoad() * other.xmLoad());

		return *this;
	}

	Vector3& Vector3::operator*=(float other)
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() * xmLoad(dxVector));

		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3& other)
	{
		xmStore(xmLoad() / other.xmLoad());

		return *this;
	}

	Vector3& Vector3::operator/=(float other)
	{
		XMFLOAT3 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() / xmLoad(dxVector));

		return *this;
	}

	// ----------------------------------------------------------------------
	// Subscript Opeartor
	// ----------------------------------------------------------------------

	float Vector3::operator[](int index)
	{
		assert(index >= 0 && index <= 2);

		float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
		return v[index];
	}

	float Vector3::operator[](int index) const
	{
		assert(index >= 0 && index <= 2);
		float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
		return v[index];
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void Vector3::set(float x, float y, float z)
	{
		setX(x);
		setY(y);
		setZ(z);
	}

	void Vector3::set(const XMFLOAT3* other)
	{
		xmStore(other);
	}

	void Vector3::set(const XMFLOAT3& other)
	{
		xmStore(other);
	}

	void Vector3::set(const XMVECTOR& other)
	{
		xmStore(other);
	}

	void Vector3::set(const Vector3& other)
	{
		xmStore(other);
	}

	bool Vector3::equals(const Vector3& other, float tolerance)
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

		return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance;
	}

	bool Vector3::isNearlyZero(float tolerance) const
	{
		return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance && fabsf(m_dxVector.z) <= tolerance;
	}

	bool Vector3::isZero() const
	{
		return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f && m_dxVector.z == 0.0f;
	}

	bool Vector3::isNaN() const
	{
		return XMVector3IsNaN(xmLoad());
	}

	bool Vector3::isInfinite() const
	{
		return XMVector3IsInfinite(xmLoad());
	}

	float Vector3::dotProduct(const Vector3& other) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVector3Dot(xmLoad(), other.xmLoad()));

		return dxResult.x;
	}

	Vector3 Vector3::crossProduct(const Vector3& other) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVector3Cross(xmLoad(), other.xmLoad()));

		return Vector3(dxResult);
	}

	Vector3 Vector3::abs()
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVectorAbs(xmLoad()));

		return Vector3(dxResult);
	}

	Vector3 Vector3::normalize() const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVector3Normalize(xmLoad()));

		return Vector3(dxResult);
	}

	float Vector3::length() const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVector3Length(xmLoad()));

		return dxResult.x;
	}

	float Vector3::distance(const Vector3& other) const
	{
		XMFLOAT3 dxResult;
		xmStore(dxResult, XMVector3Length(xmLoad() - other.xmLoad()));

		return dxResult.x;
	}

	Vector3 Vector3::clamp(const Vector3& min, const Vector3& max) const
	{
		return Vector3(
			fminf(fmaxf(min.getX(), getX()), max.getX()),
			fminf(fmaxf(min.getY(), getY()), max.getY()),
			fminf(fmaxf(min.getZ(), getZ()), max.getZ())
		);
	}

	Vector3 Vector3::clamp(float min, float max) const
	{
		return Vector3(XMVector3ClampLength(xmLoad(), min, max));
	}

	// ----------------------------------------------------------------------
	// XMMATH Helper
	// ----------------------------------------------------------------------

	void Vector3::xmStore(const XMFLOAT3& other)
	{
		m_dxVector = other;
	}

	void Vector3::xmStore(const XMFLOAT3* other)
	{
		m_dxVector = *other;
	}

	void Vector3::xmStore(const XMVECTOR& other)
	{
		XMStoreFloat3(&m_dxVector, other);
	}

	void Vector3::xmStore(const Vector3& other)
	{
		XMStoreFloat3(&m_dxVector, other.xmLoad());
	}

	XMVECTOR Vector3::xmLoad() const
	{
		return XMLoadFloat3(&m_dxVector);
	}

	void Vector3::xmStore(Vector3& v, const XMFLOAT3& other)
	{
		v.xmStore(other);
	}

	void Vector3::xmStore(Vector3& v, const XMFLOAT3* other)
	{
		v.xmStore(other);
	}

	void Vector3::xmStore(Vector3& v, const XMVECTOR& other)
	{
		v.xmStore(other);
	}

	void Vector3::xmStore(Vector3& v, const Vector3& other)
	{
		v.xmStore(other);
	}

	XMVECTOR Vector3::xmLoad(const Vector3& v)
	{
		return v.xmLoad();
	}

	void Vector3::xmStore(XMFLOAT3& v, const XMFLOAT3& other)
	{
		v = other;
	}

	void Vector3::xmStore(XMFLOAT3& v, const XMFLOAT3* other)
	{
		v = *other;
	}

	void Vector3::xmStore(XMFLOAT3& v, const XMVECTOR& other)
	{
		XMStoreFloat3(&v, other);
	}

	void Vector3::xmStore(XMFLOAT3& v, const Vector3& other)
	{
		XMStoreFloat3(&v, other.xmLoad());
	}

	XMVECTOR Vector3::xmLoad(const XMFLOAT3& v)
	{
		return XMLoadFloat3(&v);
	}

	void Vector3::xmStore(XMFLOAT3* v, const XMFLOAT3& other)
	{
		XMStoreFloat3(v, XMLoadFloat3(&other));
	}

	void Vector3::xmStore(XMFLOAT3* v, const XMFLOAT3* other)
	{
		XMStoreFloat3(v, XMLoadFloat3(other));
	}

	void Vector3::xmStore(XMFLOAT3* v, const XMVECTOR& other)
	{
		XMStoreFloat3(v, other);
	}

	void Vector3::xmStore(XMFLOAT3* v, const Vector3& other)
	{
		XMStoreFloat3(v, other.xmLoad());
	}

	XMVECTOR Vector3::xmLoad(const XMFLOAT3* v)
	{
		return XMLoadFloat3(v);
	}
}