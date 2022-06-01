#include "Math.h"

#include "Component/SceneComponent.h"
#include "Actor/Actor.h"
#include "Math/Math.h"

#include <windows.h>


namespace Engine
{
    using namespace Math;
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
        Math::Transform worldTransform;
        worldTransform.setScale(getWorldScale());
        worldTransform.setRotation(getWorldRotation());
        worldTransform.setTranslation(getWorldTranslation());

        return worldTransform;
    }

    Transform SceneComponent::getRelativeTransform()
    {
        return m_relativeTransform;
    }

    Vector3 SceneComponent::getWorldTranslation()
    {
        auto relativeTranslation = getRelativeTranslation();

        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            return Vector3(parent->getWorldTransform().toMatrix() * Vector4(relativeTranslation, 1.0f));
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            return relativeTranslation;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            return relativeTranslation;
        }
        
        return Vector3(ownerParentSceneRoot->getWorldTransform().toMatrix() * Vector4(relativeTranslation, 1.0f));
    }

    Vector3 SceneComponent::getRelativeTranslation()
    {
        return m_relativeTransform.getTranslation();
    }

    Quat SceneComponent::getWorldRotation()
    {
        auto relativeRotation = getRelativeRotation();

        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            return parent->getWorldRotation() * relativeRotation;
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            return relativeRotation;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            return relativeRotation;
        }

        return ownerParentSceneRoot->getWorldRotation() * relativeRotation;
    }

    Quat SceneComponent::getRelativeRotation()
    {
        return m_relativeTransform.getRotation();
    }

    Vector3 SceneComponent::getWorldScale()
    {
        auto relativeScale = getRelativeScale();

        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            return parent->getWorldScale() * relativeScale;
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            return relativeScale;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            return relativeScale;
        }

        return ownerParentSceneRoot->getWorldScale() * relativeScale;
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
        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            setRelativeTranslation(Vector3(parent->getWorldTransform().toMatrix().inverse() * Vector4(newTranslation, 1.0f)));
            return;
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            setRelativeTranslation(newTranslation);
            return;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            setRelativeTranslation(newTranslation);
            return;
        }

        setRelativeTranslation(Vector3(ownerParentSceneRoot->getWorldTransform().toMatrix().inverse() * Vector4(newTranslation, 1.0f)));
    }

    void SceneComponent::setRelativeTranslation(const Vector3& newTranslation)
    {
        m_relativeTransform.setTranslation(newTranslation);
    }

    void SceneComponent::setWorldRotation(const Quat& newRotation)
    {
        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            setRelativeRotation(parent->getWorldRotation().inverse() * newRotation);
            return;
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            setRelativeRotation(newRotation);
            return;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            setRelativeRotation(newRotation);
            return;
        }

        setRelativeRotation(ownerParentSceneRoot->getWorldRotation() * newRotation);
    }

    void SceneComponent::setRelativeRotation(const Quat& newRotation)
    {
        m_relativeTransform.setRotation(newRotation);
    }

    void SceneComponent::setWorldScale(const Vector3& newScale)
    {
        auto parent = dynamic_cast<SceneComponent*>(getParentComponent());
        if (parent != nullptr)
        {
            setRelativeScale(parent->getWorldTransform().getSafeScaleReciprocal() * newScale);
            return;
        }

        auto owner = getOwner();
        auto ownerParent = owner->getOwner();
        if (owner == nullptr || ownerParent == nullptr)
        {
            setRelativeScale(newScale);
            return;
        }

        auto ownerParentSceneRoot = dynamic_cast<SceneComponent*>(ownerParent->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
        if (ownerParentSceneRoot == nullptr)
        {
            setRelativeScale(newScale);
            return;
        }

        setRelativeScale(ownerParentSceneRoot->getWorldTransform().getSafeScaleReciprocal() * newScale);
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
        setWorldTranslation(getWorldTranslation() + deltaTranslation);
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
