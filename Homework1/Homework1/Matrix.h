#pragma once

#include "MathCommon.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	class Matrix
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		inline Matrix(float scale)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					m_dxMatrix.m[i][j] = scale;
				}
			}
		}

		inline Matrix(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4)
		{
			m_dxMatrix.m[0][0] = v1[0];
			m_dxMatrix.m[0][1] = v1[1];
			m_dxMatrix.m[0][2] = v1[2];
			m_dxMatrix.m[0][3] = 0.0f;

			m_dxMatrix.m[1][0] = v2[0];
			m_dxMatrix.m[1][1] = v2[1];
			m_dxMatrix.m[1][2] = v2[2];
			m_dxMatrix.m[1][3] = 0.0f;


			m_dxMatrix.m[2][0] = v3[0];
			m_dxMatrix.m[2][1] = v3[1];
			m_dxMatrix.m[2][2] = v3[2];
			m_dxMatrix.m[2][3] = 0.0f;


			m_dxMatrix.m[3][0] = v4[0];
			m_dxMatrix.m[3][1] = v4[1];
			m_dxMatrix.m[3][2] = v4[2];
			m_dxMatrix.m[3][3] = 0.0f;
		}


		inline Matrix(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4)
		{
			m_dxMatrix.m[0][0] = v1[0];
			m_dxMatrix.m[0][1] = v1[1];
			m_dxMatrix.m[0][2] = v1[2];
			m_dxMatrix.m[0][3] = v1[3];

			m_dxMatrix.m[1][0] = v2[0];
			m_dxMatrix.m[1][1] = v2[1];
			m_dxMatrix.m[1][2] = v2[2];
			m_dxMatrix.m[1][3] = v2[3];


			m_dxMatrix.m[2][0] = v3[0];
			m_dxMatrix.m[2][1] = v3[1];
			m_dxMatrix.m[2][2] = v3[2];
			m_dxMatrix.m[2][3] = v3[3];


			m_dxMatrix.m[3][0] = v4[0];
			m_dxMatrix.m[3][1] = v4[1];
			m_dxMatrix.m[3][2] = v4[2];
			m_dxMatrix.m[3][3] = v4[3];
		}

		inline Matrix(const XMFLOAT4X4& other)
		{
			xmStore(other);
		}

		inline Matrix(const XMFLOAT4X4* other)
		{
			xmStore(other);
		}

		inline Matrix(const XMMATRIX& other)
		{
			xmStore(other);
		}

		inline Matrix(const Matrix& other)
		{
			xmStore(other);
		}

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		inline const XMFLOAT4X4* getDXMatrix() const
		{
			return &m_dxMatrix;
		}

		inline XMFLOAT4X4* getDXMatrixUnsafe()
		{
			return &m_dxMatrix;
		}

	public:
		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		inline bool operator==(const Matrix& other) const
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (m_dxMatrix.m[i][j] != other[i][j])
					{
						return false;
					}
				}
			}

			return true;
		}

		inline bool operator!=(const Matrix& other) const
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (m_dxMatrix.m[i][j] == other[i][j])
					{
						return false;
					}
				}
			}

			return true;
		}

		// ----------------------------------------------------------------------
		// Arthimetric Operator
		// ----------------------------------------------------------------------

		inline Matrix&& operator+(const Matrix& other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) + other.xmLoad());

			return std::move(Matrix(dxResult));
		}

		inline Matrix&& operator+(float other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) + Matrix(other).xmLoad());

			return std::move(Matrix(dxResult));
		}

		inline Matrix operator-(const Matrix& other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) - other.xmLoad());

			return Matrix(dxResult);
		}

		inline Matrix&& operator-(float other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) - Matrix(other).xmLoad());

			return std::move(Matrix(dxResult));
		}

		inline Matrix operator*(const Matrix& other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) * other.xmLoad());

			return Matrix(dxResult);
		}

		inline Matrix&& operator*(float other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) * Matrix(other).xmLoad());

			return std::move(Matrix(dxResult));
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		inline Matrix& operator=(const Matrix& other)
		{
			xmStore(m_dxMatrix, other.xmLoad());

			return *this;
		}

		inline Matrix& operator+=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() + other.xmLoad());

			return *this;
		}

		inline Matrix& operator+=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() + Matrix(other).xmLoad());

			return *this;
		}

		inline Matrix& operator-=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() - other.xmLoad());

			return *this;
		}

		inline Matrix& operator-=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() - Matrix(other).xmLoad());

			return *this;
		}

		inline Matrix& operator*=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() * other.xmLoad());

			return *this;
		}

		inline Matrix& operator*=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() * Matrix(other).xmLoad());

			return *this;
		}

		// ----------------------------------------------------------------------
		// Assignment Operator
		// ----------------------------------------------------------------------

		inline float* operator[](int index)
		{
			assert(index >= 0 && index <= 3);

			return m_dxMatrix.m[index];
		}

		inline const float* operator[](int index) const
		{
			assert(index >= 0 && index <= 3);

			return m_dxMatrix.m[index];
		}
	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		inline bool equals(const Matrix& other, float tolerance = MATRIX_TOLERANCE) const
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (fabsf(m_dxMatrix.m[i][j] - other[i][j]) > tolerance)
					{
						return false;
					}
				}
			}

			return true;
		}

		inline bool isIdentity() const
		{
			return XMMatrixIsIdentity(XMLoadFloat4x4(&m_dxMatrix));
		}

		inline bool isInfinite() const
		{
			return XMMatrixIsInfinite(XMLoadFloat4x4(&m_dxMatrix));
		}

		inline bool isNaN() const
		{
			return XMMatrixIsNaN(XMLoadFloat4x4(&m_dxMatrix));
		}

		inline float determinant() const
		{
			XMFLOAT4 dxResult;
			Vector4::xmStore(dxResult, XMMatrixDeterminant(xmLoad()));

			return dxResult.x;
		}

		inline Matrix&& Inverse() const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixInverse(NULL, xmLoad()));

			return std::move(Matrix(dxResult));
		}

		inline Matrix&& transpose() const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixTranspose(xmLoad()));

			return std::move(Matrix(dxResult));
		}

	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

		inline static Matrix&& identity()
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixIdentity());

			return std::move(Matrix(dxResult));
		}

	protected:
		// ----------------------------------------------------------------------
		// Protected Member Variable
		// ----------------------------------------------------------------------

	public:
		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		inline void xmStore(const XMMATRIX& other)
		{
			XMStoreFloat4x4(&m_dxMatrix, other);
		}

		inline void xmStore(const XMFLOAT4X4& other)
		{
			m_dxMatrix = other;
		}

		inline void xmStore(const XMFLOAT4X4* other)
		{
			m_dxMatrix = *other;
		}

		inline void xmStore(const Matrix& other)
		{
			XMStoreFloat4x4(&m_dxMatrix, other.xmLoad());
		}

		inline XMMATRIX xmLoad() const
		{
			return XMLoadFloat4x4(&m_dxMatrix);
		}

	public:
		// ----------------------------------------------------------------------
		// For Matrix
		// ----------------------------------------------------------------------

		inline static void xmStore(Matrix& m, const XMFLOAT4X4& other)
		{
			m.xmStore(other);
		}

		inline static void xmStore(Matrix& m, const XMFLOAT4X4* other)
		{
			m.xmStore(other);
		}

		inline static void xmStore(Matrix& m, const XMMATRIX& other)
		{
			m.xmStore(other);
		}

		inline static void xmStore(Matrix& m, const Matrix& other)
		{
			m.xmStore(other);
		}

		inline static XMMATRIX xmLoad(const Matrix& m)
		{
			return m.xmLoad();
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT4X4 Reference
		// ----------------------------------------------------------------------

		inline static void xmStore(XMFLOAT4X4& m, const XMFLOAT4X4& other)
		{
			m = other;
		}

		inline static void xmStore(XMFLOAT4X4& m, const XMFLOAT4X4* other)
		{
			m = *other;
		}

		inline static void xmStore(XMFLOAT4X4& m, const XMMATRIX& other)
		{
			XMStoreFloat4x4(&m, other);
		}

		inline static void xmStore(XMFLOAT4X4& m, const Matrix& other)
		{
			XMStoreFloat4x4(&m, other.xmLoad());
		}

		inline static XMMATRIX xmLoad(const XMFLOAT4X4& m)
		{
			return XMLoadFloat4x4(&m);
		}

		// ----------------------------------------------------------------------
		// For XMFLOAT4X4 Pointer
		// ----------------------------------------------------------------------

		inline static void xmStore(XMFLOAT4X4* m, const XMFLOAT4X4& other)
		{
			XMStoreFloat4x4(m, xmLoad(other));
		}

		inline static void xmStore(XMFLOAT4X4* m, const XMFLOAT4X4* other)
		{
			XMStoreFloat4x4(m, xmLoad(other));
		}

		inline static void xmStore(XMFLOAT4X4* m, const XMMATRIX& other)
		{
			XMStoreFloat4x4(m, other);
		}

		inline static void xmStore(XMFLOAT4X4* m, const Matrix& other)
		{
			XMStoreFloat4x4(m, other.xmLoad());
		}

		inline static XMMATRIX xmLoad(const XMFLOAT4X4* m)
		{
			return XMLoadFloat4x4(m);
		}


	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT4X4 m_dxMatrix;
	};
}