#include "CameraComponent.h"
#include "Math.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	CameraComponent::CameraComponent(__ComponentDefaultParamsDef)
		: SceneComponent(ComponentDefaultParams)
	{

	}

	Matrix CameraComponent::getOrthographicProjectionMatrix()
	{
		XMMATRIX dxMatrix = XMMatrixOrthographicLH(
			m_viewport.getWidth(), m_viewport.getHeight(), m_near, m_far);

		return Matrix(dxMatrix);
	}

	Matrix CameraComponent::getPerspectiveProjectionMatrix()
	{
		XMMATRIX dxMatrix = XMMatrixPerspectiveFovLH(
			XMConvertToRadians(m_fov), m_viewport.getX() / m_viewport.getY(), m_near, m_far);
		return Matrix(dxMatrix);
	}

	Matrix CameraComponent::getViewMatrix()
	{
		auto transform = getWorldTransform();
		
		Matrix rotation = transform.getRotation().inverse().toMatrix();
		Matrix translation = Matrix(1.0f).translate(-transform.getTranslation());
		return translation * rotation;
	}

	Matrix CameraComponent::getOrthgraphicScreenTransformMatrix()
	{
		Matrix projection = getOrthographicProjectionMatrix();
		Matrix view = getViewMatrix();
		return projection * view;
	}

	Matrix CameraComponent::getPerspectiveScreenTransformMatrix()
	{
		Matrix projection = getPerspectiveProjectionMatrix();
		Matrix view = getViewMatrix();
		return projection * view;
	}
}