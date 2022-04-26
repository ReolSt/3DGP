#include "World.h"
#include "Actor.h"
#include "Component.h"

#include <utility>

namespace Engine
{
    World::World()
    {
    }

    World::~World()
    {
    }

    Actor* World::getActorById(const std::string& id)
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

    std::vector<Actor*>&& World::getActorsByTypeId(size_t typeId)
    {
        std::vector<Actor*> container;

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

    std::vector<Actor*>&& World::getActorsByTypeName(const std::string& typeName)
    {
        std::vector<Actor*> container;

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

        std::string actorId = actor->getId();
        m_actors[actorId] = actor;
    }

    void World::removeActor(Actor* actor)
    {
        assert(actor != nullptr);

        std::string actorId = actor->getId();
        m_actors.erase(actorId);
    }

    Component* World::getRegisteredComponentById(const std::string& id)
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

    std::vector<Component*>&& World::getRegisteredComponentsByTypeId(size_t typeId)
    {
        std::vector<Component*> container;

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

    std::vector<Component*>&& World::getRegisteredComponentsByTypeName(const std::string& typeName)
    {
        std::vector<Component*> container;

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

        std::string componentId = component->getId();
        m_registeredComponents[componentId] = component;
    }

    void World::unRegisterComponent(Component* component)
    {
        assert(component != nullptr);       

        std::string componentId = component->getId();
        m_registeredComponents.erase(componentId);
    }

    void World::update()
    {
    }

    void World::updateComponents()
    {
    }
}