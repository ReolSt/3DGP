#pragma once

#include "Component/SceneComponent.h"
#include "Render/Viewport.h"
#include "Math/Math.h"

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
		float getAspectRatio();

		void setViewport(const Viewport& viewport);
		void setFov(float fov);
		void setNear(float near);
		void setFar(float far);
		void setAspectRatio(float aspectRatio);

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

		float m_fov = 90.0f;
		float m_near = 0.1f;
		float m_far = 100.0f;
		float m_aspectRatio = 1.0f;

		Viewport m_viewport;
	};
}