#include "CameraComponent.h"
#include "Math.h"

namespace Engine
{
	using namespace Math;

	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	CameraComponent::CameraComponent(__ComponentDefaultParamsDef)
		: SceneComponent(ComponentDefaultParams)
	{

	}

	Viewport CameraComponent::getViewport()
	{
		return m_viewport;
	}

	float CameraComponent::getFov()
	{
		return m_fov;
	}

	float CameraComponent::getNear()
	{
		return m_near;
	}

	float CameraComponent::getFar()
	{
		return m_far;
	}

	void CameraComponent::setViewport(const Viewport& viewport)
	{
		m_viewport = viewport;
	}

	void CameraComponent::setFov(float fov)
	{
		m_fov = fov;
	}

	void CameraComponent::setNear(float near)
	{
		m_near = near;
	}

	void CameraComponent::setFar(float far)
	{
		m_far = far;
	}

	Matrix CameraComponent::getOrthographicProjectionMatrix()
	{
		Matrix projection;
		projection.xmStore(XMMatrixOrthographicLH((float)m_viewport.getWidth() / (float)m_viewport.getHeight(), 1.0f, m_near, m_far));

		return projection;
	}

	Matrix CameraComponent::getPerspectiveProjectionMatrix()
	{
		Matrix projection;

		/*

		projection.xmStore(
			XMMatrixPerspectiveLH((float)m_viewport.getWidth() / (float)m_viewport.getHeight(), 1.0f, m_near, m_far));

		*/
		
		projection.xmStore(
			XMMatrixPerspectiveFovLH(degreeToRads(m_fov), (float)m_viewport.getWidth() / (float)m_viewport.getHeight(), m_near, m_far));


		return projection;
	}

	Matrix CameraComponent::getViewMatrix()
	{
		auto transform = getWorldTransform();		
		
		auto translation = transform.getTranslation();
		auto rotation = transform.getRotation();
		auto forward = rotation.getForwardVector().normalize();
		auto right = rotation.getRightVector().normalize();
		auto up = rotation.getUpVector().normalize();

		auto view = Matrix(XMMatrixLookToLH(translation.xmLoad(), forward.xmLoad(), up.xmLoad()));

		/*

		Matrix rotation = transform.getRotation().inverse().toMatrix();
		Matrix translation = Matrix(1.0f).translate(-transform.getTranslation());
		Matrix view = translation * rotation;

		*/

		return view;		
	}

	Matrix CameraComponent::getOrthographicScreenTransformMatrix()
	{
		Matrix projection = getOrthographicProjectionMatrix();
		Matrix view = getViewMatrix();
		return view * projection;
	}

	Matrix CameraComponent::getPerspectiveScreenTransformMatrix()
	{
		Matrix projection = getPerspectiveProjectionMatrix();
		Matrix view = getViewMatrix();
		return view * projection;
	}
}