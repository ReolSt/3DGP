#pragma once

#include "MathCommon.h"

namespace Engine
{
	namespace Math
	{
		class Vector3;
		class Quat;

		class Rotator
		{
		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Rotator();
			Rotator(float yaw, float pitch, float roll);
			Rotator(const Rotator& rotator);
			Rotator(const Vector3& vector);
			Rotator(const Quat& quat);

			// ----------------------------------------------------------------------
			// Getter, Setter
			// ----------------------------------------------------------------------

			const XMFLOAT3* getDXVector() const;
			XMFLOAT3* getDXVectorUnsafe();

			float getYaw() const;
			float getPitch() const;
			float getRoll() const;

			void setYaw(float yaw);
			void setPitch(float pitch);
			void setRoll(float roll);

		public:
			// ----------------------------------------------------------------------
			// Comparison Operator
			// ----------------------------------------------------------------------

			bool operator==(const Rotator& rotator) const;
			bool operator!=(const Rotator& rotator) const;
			bool operator>(const Rotator& rotator) const;
			bool operator<(const Rotator& rotator) const;
			bool operator>=(const Rotator& rotator) const;
			bool operator<=(const Rotator& rotator) const;

			// ----------------------------------------------------------------------
			// Arthimetric Operator
			// ----------------------------------------------------------------------

			Rotator operator-() const;
			Rotator operator+(const Rotator& rotator) const;
			Rotator operator+(float scale) const;
			Rotator operator-(const Rotator& rotator) const;
			Rotator operator-(float scale) const;
			Rotator operator*(const Rotator& rotator) const;
			Rotator operator*(float scale) const;
			Rotator operator/(const Rotator& rotator) const;
			Rotator operator/(float scale) const;

			// ----------------------------------------------------------------------
			// Assignment Operator
			// ----------------------------------------------------------------------

			Rotator& operator=(const Rotator& other);
			Rotator& operator+=(const Rotator& other);
			Rotator& operator+=(float other);
			Rotator& operator-=(const Rotator& other);
			Rotator& operator-=(float other);
			Rotator& operator*=(const Rotator& other);
			Rotator& operator*=(float other);
			Rotator& operator/=(const Rotator& other);
			Rotator& operator/=(float other);

			// ----------------------------------------------------------------------
			// Subscript Operator
			// ----------------------------------------------------------------------

			float operator[](int index);
			float operator[](int index) const;

		public:
			// ----------------------------------------------------------------------
			// Public Member Method
			// ----------------------------------------------------------------------

			void set(float yaw, float pitch, float roll);
			void set(const Rotator& rotator);
			void set(const Vector3& vector);
			void set(const Quat& quat);

			Rotator rotate(const Rotator& rotator);
			Quat rotate(const Quat& quat);

		public:
			// ----------------------------------------------------------------------
			// XMMATH Helper
			// ----------------------------------------------------------------------

			void xmStore(const XMFLOAT3& other);
			void xmStore(const XMFLOAT3* other);
			void xmStore(const XMVECTOR& other);
			void xmStore(const Rotator& other);
			void xmStore(const Vector3& other);

			XMVECTOR xmLoad() const;

		public:
			// ----------------------------------------------------------------------
			// For Rotator
			// ----------------------------------------------------------------------

			static void xmStore(Rotator& v, const XMFLOAT3& other);
			static void xmStore(Rotator& v, const XMFLOAT3* other);
			static void xmStore(Rotator& v, const XMVECTOR& other);
			static void xmStore(Rotator& v, const Rotator& other);
			static void xmStore(Rotator& v, const Vector3& other);

			static XMVECTOR xmLoad(const Rotator& v);

			// ----------------------------------------------------------------------
			// For XMFLOAT3 Reference
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT3& v, const XMFLOAT3& other);
			static void xmStore(XMFLOAT3& v, const XMFLOAT3* other);
			static void xmStore(XMFLOAT3& v, const XMVECTOR& other);
			static void xmStore(XMFLOAT3& v, const Rotator& other);
			static void xmStore(XMFLOAT3& v, const Vector3& other);

			static XMVECTOR xmLoad(const XMFLOAT3& v);

			// ----------------------------------------------------------------------
			// For XMFLOAT3 Pointer
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT3* v, const XMFLOAT3& other);
			static void xmStore(XMFLOAT3* v, const XMFLOAT3* other);
			static void xmStore(XMFLOAT3* v, const XMVECTOR& other);
			static void xmStore(XMFLOAT3* v, const Rotator& other);
			static void xmStore(XMFLOAT3* v, const Vector3& other);

			static XMVECTOR xmLoad(const XMFLOAT3* v);

		private:
			// ----------------------------------------------------------------------
			// Private Member Variable
			// ----------------------------------------------------------------------

			XMFLOAT3 m_dxVector;
		};
	}
}