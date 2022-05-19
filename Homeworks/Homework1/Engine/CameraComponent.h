#pragma once

#include "SceneComponent.h"
#include "Viewport.h"
#include "Math.h"

namespace Engine
{
	class CameraComponent : public SceneComponent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		CameraComponent(__ComponentDefaultParamsDef);

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Viewport getViewport();
		float getFov();
		float getNear();
		float getFar();

		void setViewport(const Viewport& viewport);
		void setFov(float fov);
		void setNear(float near);
		void setFar(float far);

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		Math::Matrix getOrthographicProjectionMatrix();
		Math::Matrix getPerspectiveProjectionMatrix();

		Math::Matrix getViewMatrix();

		Math::Matrix getOrthographicScreenTransformMatrix();
		Math::Matrix getPerspectiveScreenTransformMatrix();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Math::Matrix m_projectionMatrix;
		Math::Matrix m_viewMatrix;

		float m_fov = 90.0f;
		float m_near = 1.001f;
		float m_far = 100.0f;

		Viewport m_viewport;
	};
}