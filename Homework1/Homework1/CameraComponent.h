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

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		Matrix getOrthographicProjectionMatrix();
		Matrix getPerspectiveProjectionMatrix();

		Matrix getViewMatrix();

		Matrix getOrthgraphicScreenTransformMatrix();
		Matrix getPerspectiveScreenTransformMatrix();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Matrix m_projectionMatrix;
		Matrix m_viewMatrix;

		float m_fov = 90.0f;
		float m_near = 0.1f;
		float m_far = 100.0f;

		Viewport m_viewport;
	};
}