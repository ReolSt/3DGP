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

		Math::Transform getWorldTransform();
		Math::Transform getRelativeTransform();

		Math::Vector3 getWorldTranslation();
		Math::Vector3 getRelativeTranslation();

		Math::Quat getWorldRotation();
		Math::Quat getRelativeRotation();

		Math::Vector3 getWorldScale();
		Math::Vector3 getRelativeScale();

		// ----------------------------------------------------------------------
		// Set Transform
		// ----------------------------------------------------------------------

		void setWorldTransform(const Math::Transform& newTransform);
		void setRelativeTransform(const Math::Transform& newTransform);

		void setWorldTranslation(const Math::Vector3& newTranslation);
		void setRelativeTranslation(const Math::Vector3& newTranslation);

		void setWorldRotation(const Math::Quat& newRotation);
		void setRelativeRotation(const Math::Quat& newRotation);

		void setWorldScale(const Math::Vector3& newScale);
		void setRelativeScale(const Math::Vector3& newScale);

		// ----------------------------------------------------------------------
		// Add Transform
		// ----------------------------------------------------------------------

		void addWorldTranslation(const Math::Vector3& deltaTranslation);
		void addRelativeTranslation(const Math::Vector3& deltaTranslation);

		void addWorldRotation(const Math::Quat& deltaRotation);
		void addRelativeRotation(const Math::Quat& deltaRotation);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variables
		// ----------------------------------------------------------------------

		Math::Transform m_relativeTransform;
	};
}