#include "World.h"
#include "Actor.h"
#include "Component.h"

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

    Actor* World::getActorById(const String& id)
    {
        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getId() == id)
            {
                return actor;
            }
        }

        return nullptr;
    }

    Array<Actor*>&& World::getActorsByTypeId(UInt64 typeId)
    {
        Array<Actor*> container;

        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeId() == typeId)
            {
                container.push_back(actor);
            }
        }

        return std::move(container);
    }

    Array<Actor*>&& World::getActorsByTypeName(const String& typeName)
    {
        Array<Actor*> container;

        for (auto pair : m_actors)
        {
            Actor* actor = pair.second;
            if (actor->getTypeName() == typeName)
            {
                container.push_back(actor);
            }
        }

        return std::move(container);
    }

    void World::addActor(Actor* actor)
    {
        assert(actor != nullptr);

        String actorId = actor->getId();
        m_actors[actorId] = actor;
    }

    void World::removeActor(Actor* actor)
    {
        assert(actor != nullptr);

        String actorId = actor->getId();
        m_actors.erase(actorId);
    }

    Component* World::getRegisteredComponentById(const String& id)
    {
        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getId() == id)
            {
                return component;
            }
        }

        return nullptr;
    }

    Array<Component*>&& World::getRegisteredComponentsByTypeId(UInt64 typeId)
    {
        Array<Component*> container;

        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeId() == typeId)
            {
                container.push_back(component);
            }
        }

        return std::move(container);
    }

    Array<Component*>&& World::getRegisteredComponentsByTypeName(const String& typeName)
    {
        Array<Component*> container;

        for (const auto& pair : m_registeredComponents)
        {
            Component* component = pair.second;
            if (component->getTypeName() == typeName)
            {
                container.push_back(component);
            }
        }

        return std::move(container);
    }

    void World::registerComponent(Component* component)
    {
        assert(component != nullptr);

        String componentId = component->getId();
        m_registeredComponents[componentId] = component;
    }

    void World::unRegisterComponent(Component* component)
    {
        assert(component != nullptr);       

        String componentId = component->getId();
        m_registeredComponents.erase(componentId);
    }
}