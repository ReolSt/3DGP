#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
	namespace Math
	{
		// ----------------------------------------------------------------------
		// Predefined Vector
		// ----------------------------------------------------------------------

		Vector2 Vector2::zero()
		{
			return Vector2(0.0f, 0.0f);
		}

		Vector2 Vector2::one()
		{
			return Vector2(1.0f, 1.0f);
		}

		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Vector2::Vector2()
		{
			set(0.0f);
		}

		Vector2::Vector2(float x, float y)
		{
			set(x, y);
		}

		Vector2::Vector2(float scale)
		{
			set(scale);
		}

		Vector2::Vector2(const XMFLOAT2* other)
		{
			xmStore(other);
		}

		Vector2::Vector2(const XMFLOAT2& other)
		{
			xmStore(other);
		}

		Vector2::Vector2(const XMVECTOR& other)
		{
			xmStore(other);
		}

		Vector2::Vector2(const Vector2& other)
		{
			xmStore(other);
		}

		Vector2::Vector2(const Vector3& other)
		{
			set(other);
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT2* Vector2::getDXVector() const
		{
			return &m_dxVector;
		}

		XMFLOAT2* Vector2::getDXVectorUnsafe()
		{
			return &m_dxVector;
		}

		float Vector2::getX() const
		{
			return m_dxVector.x;
		}

		float Vector2::getY() const
		{
			return m_dxVector.y;
		}

		void Vector2::setX(float x)
		{
			m_dxVector.x = x;
		}

		void Vector2::setY(float y)
		{
			m_dxVector.y = y;
		}

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool Vector2::operator==(const Vector2& v) const
		{
			return XMVector2Equal(xmLoad(), v.xmLoad());
		}

		bool Vector2::operator!=(const Vector2& v) const
		{
			return XMVector2NotEqual(xmLoad(), v.xmLoad());
		}

		bool Vector2::operator>(const Vector2& v) const
		{
			return XMVector2Greater(xmLoad(), v.xmLoad());
		}

		bool Vector2::operator<(const Vector2& v) const
		{
			return XMVector2Less(xmLoad(), v.xmLoad());
		}

		bool Vector2::operator>=(const Vector2& v) const
		{
			return XMVector2GreaterOrEqual(xmLoad(), v.xmLoad());
		}

		bool Vector2::operator<=(const Vector2& v) const
		{
			return XMVector2LessOrEqual(xmLoad(), v.xmLoad());
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Vector2 Vector2::operator-() const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVectorNegate(xmLoad()));

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator+(const Vector2& v) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() + v.xmLoad());

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator+(float scale) const
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() + xmLoad(dxVector));

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator-(const Vector2& v) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() - v.xmLoad());

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator-(float scale) const
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() - xmLoad(dxVector));

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator*(const Vector2& v) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() * v.xmLoad());

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator*(float scale) const
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() * xmLoad(dxVector));

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator/(const Vector2& v) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() / v.xmLoad());

			return Vector2(dxResult);
		}

		Vector2 Vector2::operator/(float scale) const
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(scale));

			XMFLOAT2 dxResult;
			xmStore(dxResult, xmLoad() / xmLoad(dxVector));

			return Vector2(dxResult);
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		Vector2& Vector2::operator=(const Vector2& other)
		{
			xmStore(other);

			return *this;
		}

		Vector2& Vector2::operator+=(const Vector2& other)
		{
			xmStore(xmLoad() + other.xmLoad());

			return *this;
		}

		Vector2& Vector2::operator+=(float other)
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() + xmLoad(dxVector));

			return *this;
		}

		Vector2& Vector2::operator-=(const Vector2& other)
		{
			xmStore(xmLoad() - other.xmLoad());

			return *this;
		}

		Vector2& Vector2::operator-=(float other)
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() - xmLoad(dxVector));

			return *this;
		}

		Vector2& Vector2::operator*=(const Vector2& other)
		{
			xmStore(xmLoad() * other.xmLoad());

			return *this;
		}

		Vector2& Vector2::operator*=(float other)
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() * xmLoad(dxVector));

			return *this;
		}

		Vector2& Vector2::operator/=(const Vector2& other)
		{
			xmStore(xmLoad() / other.xmLoad());

			return *this;
		}

		Vector2& Vector2::operator/=(float other)
		{
			XMFLOAT2 dxVector;
			xmStore(dxVector, XMVectorReplicate(other));

			xmStore(xmLoad() / xmLoad(dxVector));

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Opeartor
		// ----------------------------------------------------------------------

		float Vector2::operator[](int index)
		{
			VERIFY(index >= 0 && index <= 1);

			float v[2] = { m_dxVector.x, m_dxVector.y };
			return v[index];
		}

		float Vector2::operator[](int index) const
		{
			VERIFY(index >= 0 && index <= 1);
			float v[2] = { m_dxVector.x, m_dxVector.y };
			return v[index];
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void Vector2::set(float x, float y)
		{
			setX(x);
			setY(y);
		}

		void Vector2::set(float scale)
		{
			setX(scale);
			setY(scale);
		}

		void Vector2::set(const XMFLOAT2* other)
		{
			xmStore(other);
		}

		void Vector2::set(const XMFLOAT2& other)
		{
			xmStore(other);
		}

		void Vector2::set(const XMVECTOR& other)
		{
			xmStore(other);
		}

		void Vector2::set(const Vector2& other)
		{
			xmStore(other);
		}

		void Vector2::set(const Vector3& other)
		{
			set(other.getX(), other.getY());
		}

		bool Vector2::equals(const Vector2& other, float tolerance)
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad() - other.xmLoad()));

			return dxResult.x <= tolerance && dxResult.y <= tolerance;
		}

		bool Vector2::isNearlyZero(float tolerance) const
		{
			return fabsf(m_dxVector.x) <= tolerance && fabsf(m_dxVector.y) <= tolerance;
		}

		bool Vector2::isZero() const
		{
			return m_dxVector.x == 0.0f && m_dxVector.y == 0.0f;
		}

		bool Vector2::isNaN() const
		{
			return XMVector2IsNaN(xmLoad());
		}

		bool Vector2::isInfinite() const
		{
			return XMVector2IsInfinite(xmLoad());
		}

		float Vector2::dotProduct(const Vector2& other) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVector2Dot(xmLoad(), other.xmLoad()));

			return dxResult.x;
		}

		Vector2 Vector2::crossProduct(const Vector2& other) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVector2Cross(xmLoad(), other.xmLoad()));

			return Vector2(dxResult);
		}

		Vector2 Vector2::abs()
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVectorAbs(xmLoad()));

			return Vector2(dxResult);
		}

		Vector2 Vector2::normalize() const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVector2Normalize(xmLoad()));

			return Vector2(dxResult);
		}

		float Vector2::length() const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVector2Length(xmLoad()));

			return dxResult.x;
		}

		float Vector2::distance(const Vector2& other) const
		{
			XMFLOAT2 dxResult;
			xmStore(dxResult, XMVector2Length(xmLoad() - other.xmLoad()));

			return dxResult.x;
		}

		Vector2 Vector2::clamp(const Vector2& min, const Vector2& max) const
		{
			return Vector2(
				fminf(fmaxf(min.getX(), getX()), max.getX()),
				fminf(fmaxf(min.getY(), getY()), max.getY())
			);
		}

		Vector2 Vector2::clamp(float min, float max) const
		{
			return Vector2(XMVector2ClampLength(xmLoad(), min, max));
		}

		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void Vector2::xmStore(const XMFLOAT2& other)
		{
			m_dxVector = other;
		}

		void Vector2::xmStore(const XMFLOAT2* other)
		{
			m_dxVector = *other;
		}

		void Vector2::xmStore(const XMVECTOR& other)
		{
			XMStoreFloat2(&m_dxVector, other);
		}

		void Vector2::xmStore(const Vector2& other)
		{
			XMStoreFloat2(&m_dxVector, other.xmLoad());
		}

		XMVECTOR Vector2::xmLoad() const
		{
			return XMLoadFloat2(&m_dxVector);
		}

		// ----------------------------------------------------------------------
		// For Vector2
		// ----------------------------------------------------------------------

		void Vector2::xmStore(Vector2& vector, const XMFLOAT2& other)
		{
			vector.xmStore(other);
		}

		void Vector2::xmStore(Vector2& vector, const XMFLOAT2* other)
		{
			vector.xmStore(other);
		}

		void Vector2::xmStore(Vector2& vector, const XMVECTOR& other)
		{
			vector.xmStore(other);
		}

		void Vector2::xmStore(Vector2& vector, const Vector2& other)
		{
			vector.xmStore(other);
		}

		XMVECTOR Vector2::xmLoad(const Vector2& vector)
		{
			return vector.xmLoad();
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT2 Reference
		// ----------------------------------------------------------------------

		void Vector2::xmStore(XMFLOAT2& vector, const XMFLOAT2& other)
		{
			vector = other;
		}

		void Vector2::xmStore(XMFLOAT2& vector, const XMFLOAT2* other)
		{
			vector = *other;
		}

		void Vector2::xmStore(XMFLOAT2& vector, const XMVECTOR& other)
		{
			XMStoreFloat2(&vector, other);
		}

		void Vector2::xmStore(XMFLOAT2& vector, const Vector2& other)
		{
			XMStoreFloat2(&vector, other.xmLoad());
		}

		XMVECTOR Vector2::xmLoad(const XMFLOAT2& vector)
		{
			return XMLoadFloat2(&vector);
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT2 Pointer
		// ----------------------------------------------------------------------

		void Vector2::xmStore(XMFLOAT2* vector, const XMFLOAT2& other)
		{
			XMStoreFloat2(vector, XMLoadFloat2(&other));
		}

		void Vector2::xmStore(XMFLOAT2* vector, const XMFLOAT2* other)
		{
			XMStoreFloat2(vector, XMLoadFloat2(other));
		}

		void Vector2::xmStore(XMFLOAT2* vector, const XMVECTOR& other)
		{
			XMStoreFloat2(vector, other);
		}

		void Vector2::xmStore(XMFLOAT2* vector, const Vector2& other)
		{
			XMStoreFloat2(vector, other.xmLoad());
		}

		XMVECTOR Vector2::xmLoad(const XMFLOAT2* vector)
		{
			return XMLoadFloat2(vector);
		}
	}	
}