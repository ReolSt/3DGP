#pragma once

#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <DirectXCollision.h>

using namespace DirectX;
using namespace DirectX::PackedVector;

#include <cmath>
#include <utility>
#include <algorithm>
#include <ctime>

#define VECTOR_TOLERANCE 1e-6
#define MATRIX_TOLERANCE 1e-6
#define PLANE_TOLERANCE 1e-6
#define QUAT_TOLERANCE 1e-6
#define ROTATOR_TOLERANCE 1e-6
#define TRANSFORM_TOLERANCE 1e-6

#undef max
#undef min

namespace Engine
{
	namespace Math
	{
		// ----------------------------------------------------------------------
		// Common Mathmatical Function
		// ----------------------------------------------------------------------

		template <typename T>
		inline T max(T a, T b)
		{
			return a > b ? a : b;
		}

		template <typename T>
		inline T min(T a, T b)
		{
			return a < b ? a : b;
		}

		inline int clamp(int value, int low, int high)
		{
			return max(min(value, high), low);
		}
		
		inline float clamp(float value, float low, float high)
		{
			return max(min(value, high), low);
		}

		inline double clamp(double value, double low, double high)
		{
			return max(min(value, high), low);
		}

		template <typename T>
		inline int sign(const T& value)
		{
			return value > 0 ? 1 : (value == 0 ? 0 : -1);
		}

		template <typename T>
		inline T abs(const T& value)
		{
			return std::abs(value);
		}

		template <typename T>
		inline double sqrt(const T& value)
		{
			return std::sqrt((double)value);
		}

		template <typename T>
		inline double pow(const T& x, const T& y)
		{
			return std::pow(x, y);
		}

		template <typename T>
		inline double floor(const T& value)
		{
			return std::floor(value);
		}

		template <typename T>
		inline double ceil(const T& value)
		{
			return std::ceil(value);
		}

		template <typename T>
		inline double round(const T& value)
		{
			return std::round(value);
		}

		template <typename T>
		inline double exp(const T& value)
		{
			return std::exp(value);
		}

		template <typename T>
		inline double exp2(const T& value)
		{
			return std::exp2(value);
		}

		template <typename T>
		inline T rand(const T& min, const T& max)
		{
			static bool initialized = false;
			if (!initialized)
			{
				std::srand(time(NULL));
				initialized = true;
			}

			return (T)std::rand() / (T)(RAND_MAX / (max - min)) + min;
		}

		// ----------------------------------------------------------------------
		// Trigonometric Funtion
		// ----------------------------------------------------------------------

		constexpr float PI = XM_PI;
		constexpr float PI2 = XM_2PI;

		inline float radsToDegree(float rads)
		{
			return XMConvertToDegrees(rads);
		}

		inline float degreeToRads(float degree)
		{
			return XMConvertToRadians(degree);
		}

		inline double sin(double value)
		{
			return std::sin(value);
		}

		inline double cos(double value)
		{
			return std::cos(value);
		}
			
		inline double sinh(double value)
		{
			return std::sinh(value);
		}

		inline double cosh(double value)
		{
			return std::cosh(value);
		}

		inline double asin(double value)
		{
			return std::asin(value);
		}

		inline double acos(double value)
		{
			return std::acos(value);
		}		

		inline double tan(double value)
		{
			return std::tan(value);
		}

		inline double tanh(double value)
		{
			return std::tanh(value);
		}

		inline double atan(double value)
		{
			return std::atan(value);
		}

		inline double atan2(double y, double x)
		{
			return std::atan2(y, x);
		}		
	}
}