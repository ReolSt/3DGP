#include "Rotator.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Quat.h"

namespace Engine
{
	namespace Math
	{
		// ----------------------------------------------------------------------
// Constructor, Destructor
// ----------------------------------------------------------------------

		Rotator::Rotator()
		{
			set(0.0f, 0.0f, 0.0f);
		}

		Rotator::Rotator(float yaw, float pitch, float roll)
		{
			set(pitch, yaw, roll);
		}

		Rotator::Rotator(const Rotator& rotator)
		{
			set(rotator);
		}

		Rotator::Rotator(const Vector3& vector)
		{
			set(vector);
		}

		Rotator::Rotator(const Quat& quat)
		{
			set(quat);
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT3* Rotator::getDXVector() const
		{
			return &m_dxVector;
		}

		XMFLOAT3* Rotator::getDXVectorUnsafe()
		{
			return &m_dxVector;
		}

		float Rotator::getYaw() const
		{
			return m_dxVector.y;
		}

		float Rotator::getPitch() const
		{
			return m_dxVector.x;
		}

		float Rotator::getRoll() const
		{
			return m_dxVector.z;
		}

		void Rotator::setYaw(float yaw)
		{
			m_dxVector.y = yaw;
		}

		void Rotator::setPitch(float pitch)
		{
			m_dxVector.x = pitch;
		}

		void Rotator::setRoll(float roll)
		{
			m_dxVector.z = roll;
		}

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool Rotator::operator==(const Rotator& v) const
		{
			return XMVector3Equal(xmLoad(), v.xmLoad());
		}

		bool Rotator::operator!=(const Rotator& v) const
		{
			return XMVector3NotEqual(xmLoad(), v.xmLoad());
		}

		bool Rotator::operator>(const Rotator& v) const
		{
			return XMVector3Greater(xmLoad(), v.xmLoad());
		}

		bool Rotator::operator<(const Rotator& v) const
		{
			return XMVector3Less(xmLoad(), v.xmLoad());
		}

		bool Rotator::operator>=(const Rotator& v) const
		{
			return XMVector3GreaterOrEqual(xmLoad(), v.xmLoad());
		}

		bool Rotator::operator<=(const Rotator& v) const
		{
			return XMVector3LessOrEqual(xmLoad(), v.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Rotator Rotator::operator-() const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, XMVectorNegate(xmLoad()));

			return Rotator(dxResult);
		}

		Rotator Rotator::operator+(const Rotator& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() + v.xmLoad());

			return Rotator(dxResult);
		}

		Rotator Rotator::operator+(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Rotator(dxResult);
		}

		Rotator Rotator::operator-(const Rotator& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() - v.xmLoad());

			return Rotator(dxResult);
		}

		Rotator Rotator::operator-(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() - xmLoad(dxVector));

			return Vector3(dxResult);
		}

		Rotator Rotator::operator*(const Rotator& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() * v.xmLoad());

			return Rotator(dxResult);
		}

		Rotator Rotator::operator*(float scale) const
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Rotator(dxResult);
		}

		Rotator Rotator::operator/(const Rotator& v) const
		{
			XMFLOAT3 dxResult;
			xmStore(dxResult, xmLoad() / v.xmLoad());

			return Rotator(dxResult);
		}

		Rotator Rotator::operator/(float scale) const
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

		Rotator& Rotator::operator=(const Rotator& other)
		{
			xmStore(other);

			return *this;
		}

		Rotator& Rotator::operator+=(const Rotator& other)
		{
			xmStore(xmLoad() + other.xmLoad());

			return *this;
		}

		Rotator& Rotator::operator+=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() + xmLoad(dxVector));

			return *this;
		}

		Rotator& Rotator::operator-=(const Rotator& other)
		{
			xmStore(xmLoad() - other.xmLoad());

			return *this;
		}

		Rotator& Rotator::operator-=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		Rotator& Rotator::operator*=(const Rotator& other)
		{
			xmStore(xmLoad() * other.xmLoad());

			return *this;
		}

		Rotator& Rotator::operator*=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));

			return *this;
		}

		Rotator& Rotator::operator/=(const Rotator& other)
		{
			xmStore(xmLoad() / other.xmLoad());

			return *this;
		}

		Rotator& Rotator::operator/=(float other)
		{
			XMFLOAT3 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() / xmLoad(dxVector));

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Opeartor
		// ----------------------------------------------------------------------

		float Rotator::operator[](int index)
		{
			VERIFY(index >= 0 && index <= 2);

			float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
			return v[index];
		}

		float Rotator::operator[](int index) const
		{
			VERIFY(index >= 0 && index <= 2);
			float v[3] = { m_dxVector.x, m_dxVector.y, m_dxVector.z };
			return v[index];
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void Rotator::set(float yaw, float pitch, float roll)
		{
			setYaw(yaw);
			setPitch(pitch);
			setRoll(roll);
		}

		void Rotator::set(const Rotator& rotator)
		{
			xmStore(rotator.xmLoad());
		}

		void Rotator::set(const Vector3& vector)
		{
			xmStore(vector.xmLoad());
		}

		void Rotator::set(const Quat& quat)
		{
			set(quat.getRotator());
		}

		Rotator Rotator::rotate(const Rotator& rotator)
		{
			return *this + rotator;
		}

		Quat Rotator::rotate(const Quat& quat)
		{
			return (quat * Quat(*this)).normalize();
		}

		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void Rotator::xmStore(const XMFLOAT3& other)
		{
			m_dxVector = other;
		}

		void Rotator::xmStore(const XMFLOAT3* other)
		{
			m_dxVector = *other;
		}

		void Rotator::xmStore(const XMVECTOR& other)
		{
			XMStoreFloat3(&m_dxVector, other);
		}

		void Rotator::xmStore(const Rotator& other)
		{
			XMStoreFloat3(&m_dxVector, other.xmLoad());
		}

		void Rotator::xmStore(const Vector3& other)
		{
			XMStoreFloat3(&m_dxVector, other.xmLoad());
		}

		XMVECTOR Rotator::xmLoad() const
		{
			return XMLoadFloat3(&m_dxVector);
		}

		// ----------------------------------------------------------------------
		// For Rotator
		// ----------------------------------------------------------------------

		void Rotator::xmStore(Rotator& rotator, const XMFLOAT3& other)
		{
			rotator.xmStore(other);
		}

		void Rotator::xmStore(Rotator& rotator, const XMFLOAT3* other)
		{
			rotator.xmStore(other);
		}

		void Rotator::xmStore(Rotator& rotator, const XMVECTOR& other)
		{
			rotator.xmStore(other);
		}

		void Rotator::xmStore(Rotator& rotator, const Rotator& other)
		{
			rotator.xmStore(other);
		}

		void Rotator::xmStore(Rotator& rotator, const Vector3& other)
		{
			rotator.xmStore(other);
		}

		XMVECTOR Rotator::xmLoad(const Rotator& v)
		{
			return v.xmLoad();
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Reference
		// ----------------------------------------------------------------------

		void Rotator::xmStore(XMFLOAT3& v, const XMFLOAT3& other)
		{
			v = other;
		}

		void Rotator::xmStore(XMFLOAT3& v, const XMFLOAT3* other)
		{
			v = *other;
		}

		void Rotator::xmStore(XMFLOAT3& v, const XMVECTOR& other)
		{
			XMStoreFloat3(&v, other);
		}

		void Rotator::xmStore(XMFLOAT3& v, const Rotator& other)
		{
			XMStoreFloat3(&v, other.xmLoad());
		}

		void Rotator::xmStore(XMFLOAT3& v, const Vector3& other)
		{
			XMStoreFloat3(&v, other.xmLoad());
		}

		XMVECTOR Rotator::xmLoad(const XMFLOAT3& v)
		{
			return XMLoadFloat3(&v);
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Pointer
		// ----------------------------------------------------------------------

		void Rotator::xmStore(XMFLOAT3* v, const XMFLOAT3& other)
		{
			XMStoreFloat3(v, XMLoadFloat3(&other));
		}

		void Rotator::xmStore(XMFLOAT3* v, const XMFLOAT3* other)
		{
			XMStoreFloat3(v, XMLoadFloat3(other));
		}

		void Rotator::xmStore(XMFLOAT3* v, const XMVECTOR& other)
		{
			XMStoreFloat3(v, other);
		}

		void Rotator::xmStore(XMFLOAT3* v, const Rotator& other)
		{
			XMStoreFloat3(v, other.xmLoad());
		}

		void Rotator::xmStore(XMFLOAT3* v, const Vector3& other)
		{
			XMStoreFloat3(v, other.xmLoad());
		}

		XMVECTOR Rotator::xmLoad(const XMFLOAT3* v)
		{
			return XMLoadFloat3(v);
		}
	}
}

