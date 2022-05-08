#include "Math.h"

#include "SceneComponent.h"
#include "Actor.h"
#include "Math.h"

#include <windows.h>

namespace Engine
{
    // ----------------------------------------------------------------------
    // Constructor, Destructor
    // ----------------------------------------------------------------------

    SceneComponent::SceneComponent(__ComponentDefaultParamsDef) : Component(owner, name)
    {
        
    }

    // ----------------------------------------------------------------------
    // Get Transform
    // ----------------------------------------------------------------------

    Transform SceneComponent::getWorldTransform()
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            return getRelativeTransform();
        }

        Transform worldTransform;
        worldTransform.setScale(getWorldScale());
        worldTransform.setRotation(getWorldRotation());
        worldTransform.setTranslation(getWorldTranlation());

        return worldTransform;
    }

    Transform SceneComponent::getRelativeTransform()
    {
        return m_relativeTransform;
    }

    Vector3 SceneComponent::getWorldTranlation()
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            return getRelativeTranslation();
        }

        auto parentWorldTransform = dynamic_cast<SceneComponent*>(parent)->getWorldTransform();

        return Vector3(parentWorldTransform.toMatrix() * Vector4(getRelativeTranslation(), 1.0f));
    }

    Vector3 SceneComponent::getRelativeTranslation()
    {
        return m_relativeTransform.getTranslation();
    }

    Quat SceneComponent::getWorldRotation()
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            return getRelativeRotation();
        }

        return dynamic_cast<SceneComponent*>(parent)->getWorldRotation() * getRelativeRotation();
    }

    Quat SceneComponent::getRelativeRotation()
    {
        return m_relativeTransform.getRotation();
    }

    Vector3 SceneComponent::getWorldScale()
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            return getRelativeScale();
        }

        return dynamic_cast<SceneComponent*>(parent)->getWorldScale() * getRelativeScale();
    }

    Vector3 SceneComponent::getRelativeScale()
    {
        return m_relativeTransform.getScale();
    }

    // ----------------------------------------------------------------------
    // Set Transform
    // ----------------------------------------------------------------------

    void SceneComponent::setWorldTransform(const Transform& newTransform)
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            setRelativeTransform(newTransform);
            return;
        }

        setWorldScale(newTransform.getScale());
        setWorldRotation(newTransform.getRotation());
        setWorldTranslation(newTransform.getTranslation());
    }

    void SceneComponent::setRelativeTransform(const Transform& newTransform)
    {
        m_relativeTransform = newTransform;
    }

    void SceneComponent::setWorldTranslation(const Vector3& newTranslation)
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            setRelativeTranslation(newTranslation);
            return;
        }
    }

    void SceneComponent::setRelativeTranslation(const Vector3& newTranslation)
    {
        m_relativeTransform.setTranslation(newTranslation);
    }

    void SceneComponent::setWorldRotation(const Quat& newRotation)
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            setRelativeRotation(newRotation);
            return;
        }
    }

    void SceneComponent::setRelativeRotation(const Quat& newRotation)
    {
        m_relativeTransform.setRotation(newRotation);
    }

    void SceneComponent::setWorldScale(const Vector3& newScale)
    {
        auto parent = getParentComponent();
        if (parent == nullptr)
        {
            setRelativeScale(newScale);
            return;
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
