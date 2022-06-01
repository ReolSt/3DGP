#pragma once

#include "MathCommon.h"

namespace Engine
{
	namespace Math
	{
		class Vector4;
		class Vector3;

		class Vector2
		{
		public:
			// ----------------------------------------------------------------------
			// Predefined Vector
			// ----------------------------------------------------------------------

			static Vector2 zero();
			static Vector2 one();

		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Vector2();
			Vector2(float scale);
			Vector2(float x, float y);
			Vector2(const XMFLOAT2* other);
			Vector2(const XMFLOAT2& other);
			Vector2(const XMVECTOR& other);
			Vector2(const Vector2& other);
			Vector2(const Vector3& other);

		public:
			// ----------------------------------------------------------------------
			// Getter, Setter
			// ----------------------------------------------------------------------

			const XMFLOAT2* getDXVector() const;
			XMFLOAT2* getDXVectorUnsafe();
			float getX() const;
			float getY() const;
			void setX(float x);
			void setY(float y);

		public:
			// ----------------------------------------------------------------------
			// Comparison Operator
			// ----------------------------------------------------------------------

			bool operator==(const Vector2& v) const;
			bool operator!=(const Vector2& v) const;
			bool operator>(const Vector2& v) const;
			bool operator<(const Vector2& v) const;
			bool operator>=(const Vector2& v) const;
			bool operator<=(const Vector2& v) const;

			// ----------------------------------------------------------------------
			// Arthimetric Operator
			// ----------------------------------------------------------------------

			Vector2 operator-() const;
			Vector2 operator+(const Vector2& v) const;
			Vector2 operator+(float scale) const;
			Vector2 operator-(const Vector2& v) const;
			Vector2 operator-(float scale) const;
			Vector2 operator*(const Vector2& v) const;
			Vector2 operator*(float scale) const;
			Vector2 operator/(const Vector2& v) const;
			Vector2 operator/(float scale) const;

			// ----------------------------------------------------------------------
			// Assignment Operator
			// ----------------------------------------------------------------------

			Vector2& operator=(const Vector2& other);
			Vector2& operator+=(const Vector2& other);
			Vector2& operator+=(float other);
			Vector2& operator-=(const Vector2& other);
			Vector2& operator-=(float other);
			Vector2& operator*=(const Vector2& other);
			Vector2& operator*=(float other);
			Vector2& operator/=(const Vector2& other);
			Vector2& operator/=(float other);

			// ----------------------------------------------------------------------
			// Subscript Operator
			// ----------------------------------------------------------------------

			float operator[](int index);
			float operator[](int index) const;

			// ----------------------------------------------------------------------
			// Public Member Method
			// ----------------------------------------------------------------------

			void set(float x, float y);
			void set(float scale);
			void set(const XMFLOAT2* other);
			void set(const XMFLOAT2& other);
			void set(const XMVECTOR& other);
			void set(const Vector2& other);
			void set(const Vector3& other);

			bool equals(const Vector2& other, float tolerance = VECTOR_TOLERANCE);
			bool isNearlyZero(float tolerance = VECTOR_TOLERANCE) const;
			bool isZero() const;
			bool isNaN() const;
			bool isInfinite() const;

			float dotProduct(const Vector2& other) const;
			Vector2 crossProduct(const Vector2& other) const;
			Vector2 abs();
			Vector2 normalize() const;
			float length() const;
			float distance(const Vector2& other) const;
			Vector2 clamp(const Vector2& min, const Vector2& max) const;
			Vector2 clamp(float min, float max) const;
		public:
			// ----------------------------------------------------------------------
			// XMMATH Helper
			// ----------------------------------------------------------------------

			void xmStore(const XMFLOAT2& other);
			void xmStore(const XMFLOAT2* other);
			void xmStore(const XMVECTOR& other);
			void xmStore(const Vector2& other);

			XMVECTOR xmLoad() const;

		public:
			// ----------------------------------------------------------------------
			// For Vector2
			// ----------------------------------------------------------------------

			static void xmStore(Vector2& vector, const XMFLOAT2& other);
			static void xmStore(Vector2& vector, const XMFLOAT2* other);
			static void xmStore(Vector2& vector, const XMVECTOR& other);
			static void xmStore(Vector2& vector, const Vector2& other);

			static XMVECTOR xmLoad(const Vector2& v);

			// ----------------------------------------------------------------------
			// For XMFLOAT2 Reference
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT2& vector, const XMFLOAT2& other);
			static void xmStore(XMFLOAT2& vector, const XMFLOAT2* other);
			static void xmStore(XMFLOAT2& vector, const XMVECTOR& other);
			static void xmStore(XMFLOAT2& vector, const Vector2& other);

			static XMVECTOR xmLoad(const XMFLOAT2& v);

			// ----------------------------------------------------------------------
			// For XMFLOAT2 Pointer
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT2* vector, const XMFLOAT2& other);
			static void xmStore(XMFLOAT2* vector, const XMFLOAT2* other);
			static void xmStore(XMFLOAT2* vector, const XMVECTOR& other);
			static void xmStore(XMFLOAT2* vector, const Vector2& other);

			static XMVECTOR xmLoad(const XMFLOAT2* v);

		private:
			// ----------------------------------------------------------------------
			// Private Member Variable
			// ----------------------------------------------------------------------

			XMFLOAT2 m_dxVector;
		};
	}
}
