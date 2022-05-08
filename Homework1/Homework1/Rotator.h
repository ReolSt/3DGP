#pragma once

#include "MathCommon.h"

namespace Engine
{
	class Rotator
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Rotator(float yaw = 0.0f, float pitch = 0.0f, float roll = 0.0f);
		Rotator(const Rotator& r);

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

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT3 m_dxVector;
	};
}