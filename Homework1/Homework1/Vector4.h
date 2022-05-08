#pragma once

#include "MathCommon.h"

namespace Engine
{
	class Vector3;

	class Vector4
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
		Vector4(const XMFLOAT4* other);
		Vector4(const XMFLOAT4& other);
		Vector4(const XMVECTOR& other);
		Vector4(const Vector3& other, float w = 0.0f);
		Vector4(const Vector4& other);

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
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool operator==(const Vector4& other) const;
		bool operator!=(const Vector4& other) const;
		bool operator>(const Vector4& other) const;
		bool operator<(const Vector4& other) const;
		bool operator>=(const Vector4& other) const;
		bool operator<=(const Vector4& other) const;

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		Vector4 operator-() const;
		Vector4 operator+(const Vector4& other) const;
		Vector4 operator+(float other) const;
		Vector4 operator-(const Vector4& other) const;
		Vector4 operator-(float other) const;
		Vector4 operator*(const Vector4& other) const;
		Vector4 operator*(float other) const;
		Vector4 operator/(const Vector4& other) const;
		Vector4 operator/(float other) const;

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		Vector4& operator=(const Vector4& other);
		Vector4& operator+=(const Vector4& other);
		Vector4& operator+=(float other);
		Vector4& operator-=(const Vector4& other);
		Vector4& operator-=(float other);
		Vector4& operator*=(const Vector4& other);
		Vector4& operator*=(float other);
		Vector4& operator/=(const Vector4& other);
		Vector4& operator/=(float other);

		// ----------------------------------------------------------------------
		// Subscript Operator
		// ----------------------------------------------------------------------

		float operator[](int index);
		float operator[](int index) const;

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void set(float x, float y, float z, float w);
		void set(const XMFLOAT4* other);
		void set(const XMFLOAT4& other);
		void set(const XMVECTOR& other);
		void set(const Vector4& other);

		bool equals(const Vector4& other, float tolerance = VECTOR_TOLERANCE) const;
		bool isNearlyZero(float tolerance = VECTOR_TOLERANCE) const;
		bool isZero() const;
		bool isNaN() const;
		bool isInfinite() const;

		float dotProduct(const Vector4& other) const;
		Vector4 crossProduct(const Vector4& v1, const Vector4& v2) const;
		Vector4 abs() const;
		Vector4 normalize() const;
		float length() const;
		float distance(const Vector4& other) const;
		Vector4 clamp(const Vector4& min, const Vector4& max) const;
		Vector4 clamp(float min, float max) const;		

	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void xmStore(const XMFLOAT4& other);
		void xmStore(const XMFLOAT4* other);
		void xmStore(const XMVECTOR* other);
		void xmStore(const XMVECTOR& other);
		void xmStore(const Vector4& other);

		XMVECTOR xmLoad() const;

	public:
		// ----------------------------------------------------------------------
		// For Vector4
		// ----------------------------------------------------------------------

		static void xmStore(Vector4& v, const XMFLOAT4& other);
		static void xmStore(Vector4& v, const XMFLOAT4* other);
		static void xmStore(Vector4& v, const XMVECTOR& other);
		static void xmStore(Vector4& v, const Vector4& other);

		static XMVECTOR xmLoad(const Vector4& v);

		// ----------------------------------------------------------------------
		// For XMFLOAT4 Reference
		// ----------------------------------------------------------------------

		static void xmStore(XMFLOAT4& v, const XMFLOAT4& other);
		static void xmStore(XMFLOAT4& v, const XMFLOAT4* other);
		static void xmStore(XMFLOAT4& v, const XMVECTOR& other);
		static void xmStore(XMFLOAT4& v, const Vector4& other);

		static XMVECTOR xmLoad(const XMFLOAT4& v);

		// ----------------------------------------------------------------------
		// For XMFLOAT4 Pointer
		// ----------------------------------------------------------------------

		static void xmStore(XMFLOAT4* v, const XMFLOAT4& other);
		static void xmStore(XMFLOAT4* v, const XMFLOAT4* other);
		static void xmStore(XMFLOAT4* v, const XMVECTOR& other);
		static void xmStore(XMFLOAT4* v, const Vector4& other);

		static XMVECTOR xmLoad(const XMFLOAT4* v);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT4 m_dxVector;
	};
}