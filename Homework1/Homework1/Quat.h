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

		Quat(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
		Quat(const Vector3& axis, float angle);
		Quat(const Rotator& r);
		Quat(const XMFLOAT4& v);
		Quat(const XMFLOAT4* v);
		Quat(const XMVECTOR& v);
		Quat(const Vector4& v);
		Quat(const Quat& q);

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT4* getDXVector() const;
		XMFLOAT4* getDXVectorUnsafe();

		float getX() const;
		float getY() const;
		float getZ() const;
		float getW() const;
		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setW(float w);

		// ----------------------------------------------------------------------
		// Mathmatical Getter
		// ----------------------------------------------------------------------

		float getAngle() const;
		Vector3 getAxis() const;
		Vector3 getAxisX() const;
		Vector3 getAxisY() const;
		Vector3 getAxisZ() const;
		Vector3 getForwardVector() const;
		Vector3 getRightVector() const;
		Vector3 getUpVector() const;

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool operator==(const Quat& other) const;
		bool operator!=(const Quat& other) const;
		bool operator>(const Quat& other) const;
		bool operator<(const Quat& other) const;
		bool operator>=(const Quat& other) const;
		bool operator<=(const Quat& other) const;

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Quat operator+(const Quat& other) const;
		Quat operator+(float other) const;
		Quat operator-(const Quat& other) const;
		Quat operator-(float other) const;
		Quat operator*(const Quat& other) const;
		Quat operator*(float other) const;
		Quat operator/(const Quat& other) const;
		Quat operator/(float other) const;
		Vector3 operator*(const Vector3& other) const;
		Matrix operator*(const Matrix& other) const;

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		Quat& operator+=(const Quat& other);
		Quat& operator+=(float other);
		Quat& operator-=(const Quat& other);
		Quat& operator-=(float other);
		Quat& operator*=(const Quat& other);
		Quat& operator*=(float other);
		Quat& operator/=(const Quat& other);
		Quat& operator/=(float other);

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		float operator[](int index);
		float operator[](int index) const;

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		bool equals(Quat& other, float tolerance = QUAT_TOLERANCE) const;
		Vector3 rotate(const Vector3& v) const;
		Matrix rotate(const Matrix& m) const;
		Vector4 normalize() const;
		float length() const;
		Quat inverse() const;
		bool isNearlyZero(float tolerance = QUAT_TOLERANCE) const;
		bool isZero() const;
		bool isNaN() const;
		bool isInfinite() const;
		Matrix toMatrix() const;

	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void xmStore(const XMFLOAT4& other);
		void xmStore(const XMFLOAT4* other);
		void xmStore(const XMVECTOR* other);
		void xmStore(const XMVECTOR& other);
		void xmStore(const Vector4& other);
		void xmStore(const Quat& other);
		XMVECTOR xmLoad() const;

	public:
		static void xmStore(Quat& v, const XMFLOAT4& other);
		static void xmStore(Quat& v, const XMFLOAT4* other);
		static void xmStore(Quat& v, const XMVECTOR& other);
		static void xmStore(Quat& v, const Vector4& other);
		static void xmStore(Quat& v, const Quat& other);
		static void xmStore(XMFLOAT4& v, const XMFLOAT4& other);
		static void xmStore(XMFLOAT4& v, const XMFLOAT4* other);
		static void xmStore(XMFLOAT4& v, const XMVECTOR& other);
		static void xmStore(XMFLOAT4& v, const Vector4& other);
		static void xmStore(XMFLOAT4& v, const Quat& other);
		static void xmStore(XMFLOAT4* v, const XMFLOAT4& other);
		static void xmStore(XMFLOAT4* v, const XMFLOAT4* other);
		static void xmStore(XMFLOAT4* v, const XMVECTOR& other);
		static void xmStore(XMFLOAT4* v, const Vector4& other);
		static void xmStore(XMFLOAT4* v, const Quat& other);

		static XMVECTOR xmLoad(const XMFLOAT4& v);
		static XMVECTOR xmLoad(const XMFLOAT4* v);
		static XMVECTOR xmLoad(const Quat& v);

	public:

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT4 m_dxVector;
	};
}