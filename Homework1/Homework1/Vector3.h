#pragma once

#include "MathCommon.h"

namespace Engine
{
	class Vector4;

	class Vector3
	{
	public:
		// ----------------------------------------------------------------------
		// Predefined Vector
		// ----------------------------------------------------------------------

		static Vector3 zero();
		static Vector3 one();
		static Vector3 up();
		static Vector3 down();
		static Vector3 forward();
		static Vector3 backward();
		static Vector3 right();
		static Vector3 left();
		static Vector3 xAxis();
		static Vector3 yAxis();
		static Vector3 zAxis();

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		Vector3(const XMFLOAT3* other);
		Vector3(const XMFLOAT3& other);
		Vector3(const XMVECTOR& other);
		Vector3(const Vector3& other);
		Vector3(const Vector4& other);

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT3* getDXVector() const;
		XMFLOAT3* getDXVectorUnsafe();
		float getX() const;
		float getY() const;
		float getZ() const;
		void setX(float x);
		void setY(float y);
		void setZ(float z);

	public:
		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool operator==(const Vector3& v) const;
		bool operator!=(const Vector3& v) const;
		bool operator>(const Vector3& v) const;
		bool operator<(const Vector3& v) const;
		bool operator>=(const Vector3& v) const;
		bool operator<=(const Vector3& v) const;

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Vector3 operator-() const;
		Vector3 operator+(const Vector3& v) const;
		Vector3 operator+(float scale) const;
		Vector3 operator-(const Vector3& v) const;
		Vector3 operator-(float scale) const;
		Vector3 operator*(const Vector3& v) const;
		Vector3 operator*(float scale) const;
		Vector3 operator/(const Vector3& v) const;
		Vector3 operator/(float scale) const;

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		Vector3& operator=(const Vector3& other);
		Vector3& operator+=(const Vector3& other);
		Vector3& operator+=(float other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator-=(float other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator*=(float other);
		Vector3& operator/=(const Vector3& other);
		Vector3& operator/=(float other);

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		float operator[](int index);
		float operator[](int index) const;

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void set(float x, float y, float z);
		void set(const XMFLOAT3* other);
		void set(const XMFLOAT3& other);
		void set(const XMVECTOR& other);
		void set(const Vector3& other);

		bool equals(const Vector3& other, float tolerance = VECTOR_TOLERANCE);
		bool isNearlyZero(float tolerance = VECTOR_TOLERANCE) const;
		bool isZero() const;
		bool isNaN() const;
		bool isInfinite() const;

		float dotProduct(const Vector3& other) const;
		Vector3 crossProduct(const Vector3& other) const;
		Vector3 abs();
		Vector3 normalize() const;
		float length() const;
		float distance(const Vector3& other) const;
		Vector3 clamp(const Vector3& min, const Vector3& max) const;
		Vector3 clamp(float min, float max) const;
	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void xmStore(const XMFLOAT3& other);
		void xmStore(const XMFLOAT3* other);
		void xmStore(const XMVECTOR& other);
		void xmStore(const Vector3& other);

		XMVECTOR xmLoad() const;

	public:
		// ----------------------------------------------------------------------
		// For Vector3
		// ----------------------------------------------------------------------

		static void xmStore(Vector3& v, const XMFLOAT3& other);
		static void xmStore(Vector3& v, const XMFLOAT3* other);
		static void xmStore(Vector3& v, const XMVECTOR& other);
		static void xmStore(Vector3& v, const Vector3& other);

		static XMVECTOR xmLoad(const Vector3& v);

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Reference
		// ----------------------------------------------------------------------

		static void xmStore(XMFLOAT3& v, const XMFLOAT3& other);
		static void xmStore(XMFLOAT3& v, const XMFLOAT3* other);
		static void xmStore(XMFLOAT3& v, const XMVECTOR& other);
		static void xmStore(XMFLOAT3& v, const Vector3& other);

		static XMVECTOR xmLoad(const XMFLOAT3& v);

		// ----------------------------------------------------------------------
		// For XMFLOAT3 Pointer
		// ----------------------------------------------------------------------

		static void xmStore(XMFLOAT3* v, const XMFLOAT3& other);
		static void xmStore(XMFLOAT3* v, const XMFLOAT3* other);
		static void xmStore(XMFLOAT3* v, const XMVECTOR& other);
		static void xmStore(XMFLOAT3* v, const Vector3& other);

		static XMVECTOR xmLoad(const XMFLOAT3* v);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT3 m_dxVector;
	};
}
