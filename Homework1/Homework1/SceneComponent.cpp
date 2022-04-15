#include "Math.h"

#include "SceneComponent.h"
#include "Actor.h"

namespace Engine
{
    // ----------------------------------------------------------------------
    // Constructor, Destructor
    // ----------------------------------------------------------------------

    SceneComponent::SceneComponent(Actor* owner, const std::string& name) : Component(owner, name)
    {
        SceneComponent* parent = dynamic_cast<SceneComponent*>(owner->getFirstComponentByTypeId(getTypeId()));
        assert(parent == nullptr);

        m_attachedParent = parent;
    }

    // ----------------------------------------------------------------------
    // Get Transform
    // ----------------------------------------------------------------------

    Transform SceneComponent::getWorldTransform() const
    {
        if (getOwner() == nullptr)
        {
            return getRelativeTransform();
        }

        return Transform();
    }

    Transform SceneComponent::getRelativeTransform() const
    {
        return m_relativeTransform;
    }

    Vector3 SceneComponent::getWorldTranlation() const
    {
        if (getOwner() == nullptr)
        {
            return getRelativeTranslation();
        }

        return Vector3();
    }

    Vector3 SceneComponent::getRelativeTranslation() const
    {
        return m_relativeTransform.getTranslation();
    }

    Quat SceneComponent::getWorldRotation()const
    {
        if (getOwner() == nullptr)
        {
            return getRelativeRotation();
        }

        return Quat();
    }

    Quat SceneComponent::getRelativeRotation() const
    {
        return m_relativeTransform.getRotation();
    }

    Vector3 SceneComponent::getWorldScale() const
    {
        auto owner = getOwner();
        if (owner == nullptr)
        {
            return getRelativeScale();
        }

        return Vector3();
    }

    Vector3 SceneComponent::getRelativeScale() const
    {
        return m_relativeTransform.getScale();
    }

    // ----------------------------------------------------------------------
    // Set Transform
    // ----------------------------------------------------------------------

    void SceneComponent::setWorldTransform(const Transform& newTransform)
    {
        auto owner = getOwner();
        if (owner == nullptr)
        {
            return setRelativeTransform(newTransform);
        }
    }

    void SceneComponent::setRelativeTransform(const Transform& newTransform)
    {
        m_relativeTransform = newTransform;
    }

    void SceneComponent::setWorldTranslation(const Vector3& newTranslation)
    {
        auto owner = getOwner();
        if (owner == nullptr)
        {
            return setRelativeTranslation(newTranslation);
        }
    }

    void SceneComponent::setRelativeTranslation(const Vector3& newTranslation)
    {
        m_relativeTransform.setTranslation(newTranslation);
    }

    void SceneComponent::setWorldRotation(const Quat& newRotation)
    {
        auto owner = getOwner();
        if (owner == nullptr)
        {
            return setRelativeRotation(newRotation);
        }
    }

    void SceneComponent::setRelativeRotation(const Quat& newRotation)
    {
        m_relativeTransform.setRotation(newRotation);
    }

    void SceneComponent::setWorldScale(const Vector3& newScale)
    {
        auto owner = getOwner();
        if (owner == nullptr)
        {
            return setRelativeScale(newScale);
        }
    }

    void SceneComponent::setRelativeScale(const Vector3& newScale)
    {
        m_relativeTransform.setScale(newScale);
    }

    // ----------------------------------------------------------------------
    // Add Transform
    // ----------------------------------------------------------------------

    void SceneComponent::addWorldTranslation(const Vector3& deltaTranslation)
    {
        setWorldTranslation(getWorldTranlation() + deltaTranslation);
    }

    void SceneComponent::addRelativeTranslation(const Vector3& deltaTranslation)
    {
        setRelativeTranslation(getRelativeTranslation() + deltaTranslation);
    }

    void SceneComponent::addWorldRotation(const Quat& deltaRotation)
    {
        setWorldRotation(getWorldRotation() + deltaRotation);
    }

    void SceneComponent::addRelativeRotation(const Quat& deltaRotation)
    {
        setRelativeRotation(getRelativeRotation() + deltaRotation);
    }
}
