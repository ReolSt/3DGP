#include "Rotator.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	Rotator::Rotator(float yaw, float pitch, float roll)
	{
		setYaw(yaw);
		setPitch(pitch);
		setRoll(roll);
	}

	Rotator::Rotator(const Rotator& r)
	{
		setYaw(r.getYaw());
		setPitch(r.getPitch());
		setRoll(r.getRoll());
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	const XMFLOAT3* Rotator::getDXVector() const
	{
		return &m_dxVector;
	}

	XMFLOAT3* Rotator::getDXVectorUnsafe()
	{
		return &m_dxVector;
	}

	float Rotator::getYaw() const
	{
		return m_dxVector.x;
	}

	float Rotator::getPitch() const
	{
		return m_dxVector.y;
	}

	float Rotator::getRoll() const
	{
		return m_dxVector.z;
	}

	void Rotator::setYaw(float yaw)
	{
		m_dxVector.x = yaw;
	}

	void Rotator::setPitch(float pitch)
	{
		m_dxVector.y = pitch;
	}

	void Rotator::setRoll(float roll)
	{
		m_dxVector.z = roll;
	}
}

