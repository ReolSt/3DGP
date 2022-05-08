#include "Quat.h"
#include "Vector4.h"
#include "Rotator.h"
#include "Matrix.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	Quat::Quat(float x, float y, float z, float w)
	{
		m_dxVector.x = x;
		m_dxVector.y = y;
		m_dxVector.z = z;
		m_dxVector.w = w;
	}

	Quat::Quat(const Vector3& axis, float angle)
	{
		xmStore(XMQuaternionRotationAxis(axis.xmLoad(), angle));
	}

	Quat::Quat(const Rotator& r)
	{
		xmStore(XMQuaternionRotationRollPitchYaw(r.getRoll(), r.getPitch(), r.getYaw()));
	}

	Quat::Quat(const XMFLOAT4& v)
	{
		xmStore(v);
	}

	Quat::Quat(const XMFLOAT4* v)
	{
		xmStore(v);
	}

	Quat::Quat(const XMVECTOR& v)
	{
		xmStore(v);
	}

	Quat::Quat(const Vector4& v)
	{
		xmStore(v);
	}

	Quat::Quat(const Quat& q)
	{
		xmStore(q);
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

	Vector3 Quat::getForwardVector() const
	{
		return getAxisX();
	}

	Vector3 Quat::getRightVector() const
	{
		return getAxisY();
	}

	Vector3 Quat::getUpVector() const
	{
		return getAxisZ();
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

		return Quat(dxResult);
	}

	Quat Quat::operator+(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() + xmLoad(dxVector));

		return Quat(dxResult);
	}

	Quat Quat::operator-(const Quat& other) const
	{
		return Quat(xmLoad() - other.xmLoad());
	}

	Quat Quat::operator-(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		return Quat(xmLoad() - xmLoad(dxVector));
	}

	Quat Quat::operator*(const Quat& other) const
	{
		return Quat(XMQuaternionMultiply(xmLoad(), other.xmLoad()));
	}

	Quat Quat::operator*(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() * xmLoad(dxVector));

		return Quat(dxResult);
	}

	Quat Quat::operator/(const Quat& other) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() / other.xmLoad());

		return Quat(dxResult);
	}

	Quat Quat::operator/(float other) const
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		XMFLOAT4 dxResult;
		xmStore(dxResult, xmLoad() / xmLoad(dxVector));

		return Quat(dxResult);
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

		return *this;
	}

	Quat& Quat::operator+=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() - xmLoad(dxVector));

		return *this;
	}

	Quat& Quat::operator-=(const Quat& other)
	{
		xmStore(xmLoad() - other.xmLoad());

		return *this;
	}

	Quat& Quat::operator-=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() - xmLoad(dxVector));

		return *this;
	}

	Quat& Quat::operator*=(const Quat& other)
	{
		xmStore(XMQuaternionMultiply(xmLoad(), other.xmLoad()));

		return *this;
	}

	Quat& Quat::operator*=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() * xmLoad(dxVector));

		return *this;
	}

	Quat& Quat::operator/=(const Quat& other)
	{
		xmStore(xmLoad() / other.xmLoad());

		return *this;
	}

	Quat& Quat::operator/=(float other)
	{
		XMFLOAT4 dxVector;
		xmStore(dxVector, XMVectorReplicate(other));

		xmStore(xmLoad() / xmLoad(dxVector));

		return *this;
	}

	// ----------------------------------------------------------------------
	// Subscript Operator
	// ----------------------------------------------------------------------

	float Quat::operator[](int index)
	{
		assert(index >= 0 && index <= 3);

		float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
		return v[index];
	}

	float Quat::operator[](int index) const
	{
		assert(index >= 0 && index <= 3);

		float v[4] = { m_dxVector.x, m_dxVector.y, m_dxVector.z, m_dxVector.w };
		return v[index];
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	bool Quat::equals(Quat& other, float tolerance) const
	{
		XMFLOAT4 dxResult;
		xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

		return dxResult.x <= tolerance && dxResult.y <= tolerance && dxResult.z <= tolerance && dxResult.w <= tolerance;
	}

	Vector3 Quat::rotate(const Vector3& v) const
	{
		XMFLOAT3 dxResult;
		Vector3::xmStore(dxResult, XMVector3Rotate(v.xmLoad(), xmLoad()));

		return Vector3(dxResult);
	}

	Matrix Quat::rotate(const Matrix& m) const
	{
		return Matrix(m.xmLoad() * XMMatrixRotationQuaternion(xmLoad()));
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
		return Quat(XMQuaternionInverse(xmLoad()));
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
		Matrix::xmStore(matrix, XMMatrixRotationQuaternion(xmLoad()));

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

	void Quat::xmStore(Quat& v, const XMFLOAT4& other)
	{
		v.xmStore(other);
	}

	void Quat::xmStore(Quat& v, const XMFLOAT4* other)
	{
		v.xmStore(other);
	}

	void Quat::xmStore(Quat& v, const XMVECTOR& other)
	{
		v.xmStore(other);
	}

	void Quat::xmStore(Quat& v, const Vector4& other)
	{
		v.xmStore(other);
	}

	void Quat::xmStore(Quat& v, const Quat& other)
	{
		v.xmStore(other);
	}

	void Quat::xmStore(XMFLOAT4& v, const XMFLOAT4& other)
	{
		v = other;
	}

	void Quat::xmStore(XMFLOAT4& v, const XMFLOAT4* other)
	{
		v = *other;
	}

	void Quat::xmStore(XMFLOAT4& v, const XMVECTOR& other)
	{
		XMStoreFloat4(&v, other);
	}

	void Quat::xmStore(XMFLOAT4& v, const Vector4& other)
	{
		XMStoreFloat4(&v, other.xmLoad());
	}

	void Quat::xmStore(XMFLOAT4& v, const Quat& other)
	{
		XMStoreFloat4(&v, other.xmLoad());
	}

	void Quat::xmStore(XMFLOAT4* v, const XMFLOAT4& other)
	{
		XMStoreFloat4(v, XMLoadFloat4(&other));
	}

	void Quat::xmStore(XMFLOAT4* v, const XMFLOAT4* other)
	{
		XMStoreFloat4(v, XMLoadFloat4(other));
	}

	void Quat::xmStore(XMFLOAT4* v, const XMVECTOR& other)
	{
		XMStoreFloat4(v, other);
	}

	void Quat::xmStore(XMFLOAT4* v, const Vector4& other)
	{
		XMStoreFloat4(v, other.xmLoad());
	}

	void Quat::xmStore(XMFLOAT4* v, const Quat& other)
	{
		XMStoreFloat4(v, other.xmLoad());
	}

	XMVECTOR Quat::xmLoad(const XMFLOAT4& v)
	{
		return XMLoadFloat4(&v);
	}

	XMVECTOR Quat::xmLoad(const XMFLOAT4* v)
	{
		return XMLoadFloat4(v);
	}

	XMVECTOR Quat::xmLoad(const Quat& v)
	{
		return v.xmLoad();
	}

}