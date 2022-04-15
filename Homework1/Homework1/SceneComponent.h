#pragma once

#include <string>

#include "Component.h"

namespace Engine
{
	class Vector3;
	class Quat;
	class Transform;

	class Actor;

	class SceneComponent : public Component
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		explicit SceneComponent(Actor* owner, const std::string& name);

		// ----------------------------------------------------------------------
		// Get Transform
		// ----------------------------------------------------------------------

		Transform getWorldTransform() const;
		Transform getRelativeTransform() const;

		Vector3 getWorldTranlation() const;
		Vector3 getRelativeTranslation() const;

		Quat getWorldRotation() const;
		Quat getRelativeRotation() const;

		Vector3 getWorldScale() const;
		Vector3 getRelativeScale() const;

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

		SceneComponent* m_attachedParent;
		Transform m_relativeTransform;
	};
}