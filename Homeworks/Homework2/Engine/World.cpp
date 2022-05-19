#include "Actor/Actor.h"
#include "Component/Component.h"
#include "World.h"

#include <utility>
#include <iostream>

namespace Engine
{
    World::World()
    {
    }

    World::~World()
    {
    }

    // ----------------------------------------------------------------------
    // Actor Method
    // ----------------------------------------------------------------------

    UUIDMap<Actor*>& World::getActors()
    {
        return m_actors;
    }

    UUIDMap<Actor*>::iterator World::getActorIterator()
    {
        return m_actors.begin();
    }

    Actor* World::getActorById(const String& id)
    {
        if (m_actors.find(id) == m_actors.end())
        {
            return nullptr;
        }

        return m_actors[id];
    }

    Array<Actor*>& World::getActorsByTypeId(UInt64 typeId, Array<Actor*>& container)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeId() == typeId)
            {
                container.push_back(actor);
            }
        }

        return container;
    }

    Array<Actor*>& World::getActorsByTypeName(const String& typeName, Array<Actor*>& container)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeName() == typeName)
            {
                container.push_back(actor);
            }
        }

        return container;
    }

    Array<Actor*>& World::getActorsByName(const String& name, Array<Actor*>& container)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getName() == name)
            {
                container.push_back(actor);
            }
        }

        return container;
    }

    Actor* World::getFirstActorByTypeId(UInt64 typeId)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeId() == typeId)
            {
                return actor;
            }
        }

        return nullptr;
    }

    Actor* World::getFirstActorByTypeName(const String& typeName)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeName() == typeName)
            {
                return actor;
            }
        }

        return nullptr;
    }

    Actor* World::getFirstActorByName(const String& name)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getName() == name)
            {
                return actor;
            }
        }

        return nullptr;
    }

    void World::addActor(Actor* actor)
    {
        assert(actor != nullptr);

        String actorId = actor->getId();
        m_actors[actorId] = actor;

        auto evt = ActorEvent(ActorEventType::Load);

        actor->setWorld(this);
        actor->onLoad(&evt);

        for (auto& pair : actor->getComponents())
        {
            auto& id = pair.first;
            auto& childComponent = pair.second;

            registerComponent(childComponent);
        }
    }

    void World::removeActor(Actor* actor)
    {
        assert(actor != nullptr);

        String actorId = actor->getId();
        m_actors.erase(actorId);

        auto evt = ActorEvent(ActorEventType::Unload);

        actor->setWorld(nullptr);
        actor->onUnload(&evt);

        for (auto& pair : actor->getChildren())
        {
            auto& id = pair.first;
            auto& childActor = pair.second;

            removeActor(childActor);
        }

        for (auto& pair : actor->getComponents())
        {
            auto& id = pair.first;
            auto& childComponent = pair.second;

            unRegisterComponent(childComponent);
        }
    }

    // ----------------------------------------------------------------------
    // Registered Component Method
    // ----------------------------------------------------------------------

    UUIDMap<Component*>& World::getRegisteredComponents()
    {
        return m_registeredComponents;
    }

    UUIDMap<Component*>::iterator World::getRegisteredComponentIterator()
    {
        return m_registeredComponents.begin();
    }

    Component* World::getRegisteredComponentById(const String& id)
    {
        if (m_registeredComponents.find(id) == m_registeredComponents.end())
        {
            return nullptr;
        }

        return m_registeredComponents[id];
    }

    Array<Component*>& World::getRegisteredComponentsByTypeId(UInt64 typeId, Array<Component*>& container)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeId() == typeId)
            {
                container.push_back(component);
            }
        }

        return container;
    }

    Array<Component*>& World::getRegisteredComponentsByTypeName(const String& typeName, Array<Component*>& container)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeName() == typeName)
            {
                container.push_back(component);
            }
        }

        return container;
    }

    Array<Component*>& World::getRegisteredComponentsByName(const String& name, Array<Component*>& container)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getName() == name)
            {
                container.push_back(component);
            }
        }

        return container;
    }

    Component* World::getFirstRegisteredComponentByTypeId(UInt64 typeId)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeId() == typeId)
            {
                return component;
            }
        }

        return nullptr;
    }

    Component* World::getFirstRegisteredComponentByTypeName(const String& typeName)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeName() == typeName)
            {
                return component;
            }
        }

        return nullptr;
    }

    Component* World::getFirstRegisteredComponentByName(const String& name)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getName() == name)
            {
                return component;
            }
        }

        return nullptr;
    }

    void World::registerComponent(Component* component)
    {
        assert(component != nullptr);

        String componentId = component->getId();
        m_registeredComponents[componentId] = component;

        for (auto& pair : component->getComponents())
        {
            auto& id = pair.first;
            auto& childComponent = pair.second;

            registerComponent(childComponent);
        }
    }

    void World::unRegisterComponent(Component* component)
    {
        assert(component != nullptr);

        String componentId = component->getId();
        m_registeredComponents.erase(componentId);

        for (auto& pair : component->getComponents())
        {
            auto& id = pair.first;
            auto& childComponent = pair.second;

            unRegisterComponent(childComponent);
        }
    }
}