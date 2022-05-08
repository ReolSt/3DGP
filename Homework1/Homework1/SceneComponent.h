#pragma once

#include <string>

#include "Component.h"
#include "Math.h"

namespace Engine
{
	class Actor;

	class SceneComponent : public Component
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		SceneComponent(__ComponentDefaultParamsDef);

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		// ----------------------------------------------------------------------
		// Get Transform
		// ----------------------------------------------------------------------

		Transform getWorldTransform();
		Transform getRelativeTransform();

		Vector3 getWorldTranlation();
		Vector3 getRelativeTranslation();

		Quat getWorldRotation();
		Quat getRelativeRotation();

		Vector3 getWorldScale();
		Vector3 getRelativeScale();

		// ----------------------------------------------------------------------
		// Set Transform
		// ----------------------------------------------------------------------

		void setWorldTransform(const Transform& newTransform);
		void setRelativeTransform(const Transform& newTransform);

		void setWorldTranslation(const Vector3& newTranslation);
		void setRelativeTranslation(const Vector3& newTranslation);

		void setWorldRotation(const Quat& newRotation);
		void setRelativeRotation(const Quat& newRotation);

		void setWorldScale(const Vector3& newScale);
		void setRelativeScale(const Vector3& newScale);

		// ----------------------------------------------------------------------
		// Add Transform
		// ----------------------------------------------------------------------

		void addWorldTranslation(const Vector3& deltaTranslation);
		void addRelativeTranslation(const Vector3& deltaTranslation);

		void addWorldRotation(const Quat& deltaRotation);
		void addRelativeRotation(const Quat& deltaRotation);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variables
		// ----------------------------------------------------------------------

		Transform m_relativeTransform;
	};
}