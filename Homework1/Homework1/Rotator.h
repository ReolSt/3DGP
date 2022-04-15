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

		inline Rotator(float yaw, float pitch, float roll)
		{
			setYaw(yaw);
			setPitch(pitch);
			setRoll(roll);
		}

		inline Rotator(const Rotator& r)
		{
			setYaw(r.getYaw());
			setPitch(r.getPitch());
			setRoll(r.getRoll());
		}

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const XMFLOAT3* getDXVector() const
		{
			return &m_dxVector;
		}

		XMFLOAT3* getDXVectorUnsafe()
		{
			return &m_dxVector;
		}

		float getYaw() const
		{
			return m_dxVector.x;
		}

		float getPitch() const
		{
			return m_dxVector.y;
		}

		float getRoll() const
		{
			return m_dxVector.z;
		}

		void setYaw(float yaw)
		{
			m_dxVector.x = yaw;
		}

		void setPitch(float pitch)
		{
			m_dxVector.y = pitch;
		}

		void setRoll(float roll)
		{
			m_dxVector.z = roll;
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		XMFLOAT3 m_dxVector;
	};
}