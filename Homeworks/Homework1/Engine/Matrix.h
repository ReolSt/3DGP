#pragma once

#include "MathCommon.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	namespace Math
	{
		class Matrix
		{
		public:
			// ----------------------------------------------------------------------
			// Constructor, Destructor
			// ----------------------------------------------------------------------

			Matrix(float value = 1.0f);
			Matrix(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4);
			Matrix(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4);
			Matrix(const XMFLOAT4X4& other);
			Matrix(const XMFLOAT4X4* other);
			Matrix(const XMMATRIX& other);
			Matrix(const Matrix& other);

		public:
			// ----------------------------------------------------------------------
			// Getter, Setter
			// ----------------------------------------------------------------------

			const XMFLOAT4X4* getDXMatrix() const;
			XMFLOAT4X4* getDXMatrixUnsafe();

		public:
			// ----------------------------------------------------------------------
			// Comparison Operator
			// ----------------------------------------------------------------------

			bool operator==(const Matrix& other) const;
			bool operator!=(const Matrix& other) const;

			// ----------------------------------------------------------------------
			// Arthimetric Operator
			// ----------------------------------------------------------------------

			Matrix operator+(const Matrix& other) const;
			Matrix operator+(float other) const;
			Matrix operator-(const Matrix& other) const;
			Matrix operator-(float other) const;
			Matrix operator*(const Matrix& other) const;
			Matrix operator*(float other);
			Vector4 operator*(const Vector4& other);

			// ----------------------------------------------------------------------
			// Assignment Operator
			// ----------------------------------------------------------------------

			Matrix& operator=(const Matrix& other);
			Matrix& operator+=(const Matrix& other);
			Matrix& operator+=(float other);
			Matrix& operator-=(const Matrix& other);
			Matrix& operator-=(float other);
			Matrix& operator*=(const Matrix& other);
			Matrix& operator*=(float other);

			// ----------------------------------------------------------------------
			// Subscript Operator
			// ----------------------------------------------------------------------

			float* operator[](int index);
			const float* operator[](int index) const;

		public:
			// ----------------------------------------------------------------------
			// Public Member Method
			// ----------------------------------------------------------------------

			bool equals(const Matrix& other, float tolerance = MATRIX_TOLERANCE) const;
			bool isIdentity() const;
			bool isInfinite() const;
			bool isNaN() const;

			float determinant() const;
			Matrix inverse() const;
			Matrix transpose() const;
			Matrix translate(const Vector3& translation) const;

		public:
			// ----------------------------------------------------------------------
			// Public Static Method
			// ----------------------------------------------------------------------

			static Matrix identity();

		public:
			// ----------------------------------------------------------------------
			// XMMATH Helper
			// ----------------------------------------------------------------------

			void xmStore(const XMMATRIX& other);
			void xmStore(const XMFLOAT4X4& other);
			void xmStore(const XMFLOAT4X4* other);
			void xmStore(const Matrix& other);

			XMMATRIX xmLoad() const;

		public:
			// ----------------------------------------------------------------------
			// For Matrix
			// ----------------------------------------------------------------------

			static void xmStore(Matrix& m, const XMFLOAT4X4& other);
			static void xmStore(Matrix& m, const XMFLOAT4X4* other);
			static void xmStore(Matrix& m, const XMMATRIX& other);
			static void xmStore(Matrix& m, const Matrix& other);

			static XMMATRIX xmLoad(const Matrix& m);

			// ----------------------------------------------------------------------
			// For XMFLOAT4X4 Reference
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT4X4& m, const XMFLOAT4X4& other);
			static void xmStore(XMFLOAT4X4& m, const XMFLOAT4X4* other);
			static void xmStore(XMFLOAT4X4& m, const XMMATRIX& other);
			static void xmStore(XMFLOAT4X4& m, const Matrix& other);

			static XMMATRIX xmLoad(const XMFLOAT4X4& m);

			// ----------------------------------------------------------------------
			// For XMFLOAT4X4 Pointer
			// ----------------------------------------------------------------------

			static void xmStore(XMFLOAT4X4* m, const XMFLOAT4X4& other);
			static void xmStore(XMFLOAT4X4* m, const XMFLOAT4X4* other);
			static void xmStore(XMFLOAT4X4* m, const XMMATRIX& other);
			static void xmStore(XMFLOAT4X4* m, const Matrix& other);

			static XMMATRIX xmLoad(const XMFLOAT4X4* m);

		private:
			// ----------------------------------------------------------------------
			// Private Member Variable
			// ----------------------------------------------------------------------

			XMFLOAT4X4 m_dxMatrix;
		};
	}
}