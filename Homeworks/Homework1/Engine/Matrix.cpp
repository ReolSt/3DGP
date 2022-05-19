#include "Matrix.h"

namespace Engine
{
	namespace Math
	{
		// ----------------------------------------------------------------------
// Constructor, Destructor
// ----------------------------------------------------------------------

		Matrix::Matrix(float value)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					m_dxMatrix.m[i][j] = 0.0f;
				}

				m_dxMatrix.m[i][i] = value;
			}
		}

		Matrix::Matrix(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4)
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

		Matrix::Matrix(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4)
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

		Matrix::Matrix(const XMFLOAT4X4& other)
		{
			xmStore(other);
		}

		Matrix::Matrix(const XMFLOAT4X4* other)
		{
			xmStore(other);
		}

		Matrix::Matrix(const XMMATRIX& other)
		{
			xmStore(other);
		}

		Matrix::Matrix(const Matrix& other)
		{
			xmStore(other);
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT4X4* Matrix::getDXMatrix() const
		{
			return &m_dxMatrix;
		}

		XMFLOAT4X4* Matrix::getDXMatrixUnsafe()
		{
			return &m_dxMatrix;
		}

		// ----------------------------------------------------------------------
		// Comparison Operator
		// ----------------------------------------------------------------------

		bool Matrix::operator==(const Matrix& other) const
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

		bool Matrix::operator!=(const Matrix& other) const
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

		Matrix Matrix::operator+(const Matrix& other) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) + other.xmLoad());

			return Matrix(dxResult);
		}

		Matrix Matrix::operator+(float other) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) + Matrix(other).xmLoad());

			return Matrix(dxResult);
		}

		Matrix Matrix::operator-(const Matrix& other) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) - other.xmLoad());

			return Matrix(dxResult);
		}

		Matrix Matrix::operator-(float other) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) - Matrix(other).xmLoad());

			return Matrix(dxResult);
		}

		Matrix Matrix::operator*(const Matrix& other) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) * other.xmLoad());

			return Matrix(dxResult);
		}

		Matrix Matrix::operator*(float other)
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, xmLoad(m_dxMatrix) * Matrix(other).xmLoad());

			return Matrix(dxResult);
		}

		Vector4 Matrix::operator*(const Vector4& other)
		{
			XMFLOAT4 dxResult;
			Vector4::xmStore(dxResult, XMVector4Transform(Vector4::xmLoad(other), xmLoad()));

			return Vector4(dxResult);
		}

		Matrix& Matrix::operator=(const Matrix& other)
		{
			xmStore(m_dxMatrix, other.xmLoad());

			return *this;
		}

		Matrix& Matrix::operator+=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() + other.xmLoad());

			return *this;
		}

		Matrix& Matrix::operator+=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() + Matrix(other).xmLoad());

			return *this;
		}

		Matrix& Matrix::operator-=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() - other.xmLoad());

			return *this;
		}

		Matrix& Matrix::operator-=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() - Matrix(other).xmLoad());

			return *this;
		}

		Matrix& Matrix::operator*=(const Matrix& other)
		{
			xmStore(m_dxMatrix, xmLoad() * other.xmLoad());

			return *this;
		}

		Matrix& Matrix::operator*=(float other)
		{
			xmStore(m_dxMatrix, xmLoad() * Matrix(other).xmLoad());

			return *this;
		}

		// ----------------------------------------------------------------------
		// Subscript Matrix::operator
		// ----------------------------------------------------------------------

		float* Matrix::operator[](int index)
		{
			assert(index >= 0 && index <= 3);

			return m_dxMatrix.m[index];
		}

		const float* Matrix::operator[](int index) const
		{
			assert(index >= 0 && index <= 3);

			return m_dxMatrix.m[index];
		}

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		bool Matrix::equals(const Matrix& other, float tolerance) const
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

		bool Matrix::isIdentity() const
		{
			return XMMatrixIsIdentity(XMLoadFloat4x4(&m_dxMatrix));
		}

		bool Matrix::isInfinite() const
		{
			return XMMatrixIsInfinite(XMLoadFloat4x4(&m_dxMatrix));
		}

		bool Matrix::isNaN() const
		{
			return XMMatrixIsNaN(XMLoadFloat4x4(&m_dxMatrix));
		}

		float Matrix::determinant() const
		{
			XMFLOAT4 dxResult;
			Vector4::xmStore(dxResult, XMMatrixDeterminant(xmLoad()));

			return dxResult.x;
		}

		Matrix Matrix::Inverse() const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixInverse(NULL, xmLoad()));

			return Matrix(dxResult);
		}

		Matrix Matrix::transpose() const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixTranspose(xmLoad()));

			return Matrix(dxResult);
		}

		Matrix Matrix::translate(const Vector3& translation) const
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixTranslationFromVector(Vector3::xmLoad(translation)));

			Matrix result = *this * dxResult;
			return result;
		}

		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------


		Matrix Matrix::identity()
		{
			XMFLOAT4X4 dxResult;
			xmStore(dxResult, XMMatrixIdentity());

			return Matrix(dxResult);
		}

		// ----------------------------------------------------------------------
		// XMMATH Helper
		// ----------------------------------------------------------------------

		void Matrix::xmStore(const XMMATRIX& other)
		{
			XMStoreFloat4x4(&m_dxMatrix, other);
		}

		void Matrix::xmStore(const XMFLOAT4X4& other)
		{
			m_dxMatrix = other;
		}

		void Matrix::xmStore(const XMFLOAT4X4* other)
		{
			m_dxMatrix = *other;
		}

		void Matrix::xmStore(const Matrix& other)
		{
			XMStoreFloat4x4(&m_dxMatrix, other.xmLoad());
		}

		XMMATRIX Matrix::xmLoad() const
		{
			return XMLoadFloat4x4(&m_dxMatrix);
		}

		void Matrix::xmStore(Matrix& m, const XMFLOAT4X4& other)
		{
			m.xmStore(other);
		}

		void Matrix::xmStore(Matrix& m, const XMFLOAT4X4* other)
		{
			m.xmStore(other);
		}

		void Matrix::xmStore(Matrix& m, const XMMATRIX& other)
		{
			m.xmStore(other);
		}

		void Matrix::xmStore(Matrix& m, const Matrix& other)
		{
			m.xmStore(other);
		}

		XMMATRIX Matrix::xmLoad(const Matrix& m)
		{
			return m.xmLoad();
		}

		void Matrix::xmStore(XMFLOAT4X4& m, const XMFLOAT4X4& other)
		{
			m = other;
		}

		void Matrix::xmStore(XMFLOAT4X4& m, const XMFLOAT4X4* other)
		{
			m = *other;
		}

		void Matrix::xmStore(XMFLOAT4X4& m, const XMMATRIX& other)
		{
			XMStoreFloat4x4(&m, other);
		}

		void Matrix::xmStore(XMFLOAT4X4& m, const Matrix& other)
		{
			XMStoreFloat4x4(&m, other.xmLoad());
		}

		XMMATRIX Matrix::xmLoad(const XMFLOAT4X4& m)
		{
			return XMLoadFloat4x4(&m);
		}

		void Matrix::xmStore(XMFLOAT4X4* m, const XMFLOAT4X4& other)
		{
			XMStoreFloat4x4(m, xmLoad(other));
		}

		void Matrix::xmStore(XMFLOAT4X4* m, const XMFLOAT4X4* other)
		{
			XMStoreFloat4x4(m, xmLoad(other));
		}

		void Matrix::xmStore(XMFLOAT4X4* m, const XMMATRIX& other)
		{
			XMStoreFloat4x4(m, other);
		}

		void Matrix::xmStore(XMFLOAT4X4* m, const Matrix& other)
		{
			XMStoreFloat4x4(m, other.xmLoad());
		}

		XMMATRIX Matrix::xmLoad(const XMFLOAT4X4* m)
		{
			return XMLoadFloat4x4(m);
		}
	}
}