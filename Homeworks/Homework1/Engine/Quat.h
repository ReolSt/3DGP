#pragma once

#include "MathCommon.h"

namespace Engine
{
	namespace Math
	{
		class Vector3;
		class Vector4;
		class Rotator;
		class Matrix;

		class Quat
		{
		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Quat(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);
			Quat(const Vector3& axis, float angle);
			Quat(const Rotator& rotator);
			Quat(const XMFLOAT4& dxVector);
			Quat(const XMFLOAT4* dxVector);
			Quat(const XMVECTOR& dxVector);
			Quat(const Vector4& vector);
			Quat(const Quat& quat);

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
			// Mathmatical Getter, Setter
			// ----------------------------------------------------------------------

			float getAngle() const;
			Vector3 getAxis() const;
			Vector3 getAxisX() const;
			Vector3 getAxisY() const;
			Vector3 getAxisZ() const;
			Vector3 getRightVector() const;
			Vector3 getForwardVector() const;
			Vector3 getUpVector() const;

			Rotator getRotator() const;

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

			void set(float x, float y, float z, float w);
			void set(const Quat& quat);
			void set(const XMFLOAT4& vector);
			void set(const XMFLOAT4* vector);
			void set(const XMVECTOR& vector);
			void set(const Vector4& vector);
			void set(const Rotator& rotator);
			void set(const Vector3& axis, float angle);

			bool equals(const Quat& other, float tolerance = QUAT_TOLERANCE) const;
			Vector3 rotate(const Vector3& vector) const;
			Matrix rotate(const Matrix& matrix) const;
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
			static void xmStore(Quat& quat, const XMFLOAT4& other);
			static void xmStore(Quat& quat, const XMFLOAT4* other);
			static void xmStore(Quat& quat, const XMVECTOR& other);
			static void xmStore(Quat& quat, const Vector4& other);
			static void xmStore(Quat& quat, const Quat& other);
			static void xmStore(XMFLOAT4& dxVector, const XMFLOAT4& other);
			static void xmStore(XMFLOAT4& dxVector, const XMFLOAT4* other);
			static void xmStore(XMFLOAT4& dxVector, const XMVECTOR& other);
			static void xmStore(XMFLOAT4& dxVector, const Vector4& other);
			static void xmStore(XMFLOAT4& dxVector, const Quat& other);
			static void xmStore(XMFLOAT4* dxVector, const XMFLOAT4& other);
			static void xmStore(XMFLOAT4* dxVector, const XMFLOAT4* other);
			static void xmStore(XMFLOAT4* dxVector, const XMVECTOR& other);
			static void xmStore(XMFLOAT4* dxVector, const Vector4& other);
			static void xmStore(XMFLOAT4* dxVector, const Quat& other);

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
}