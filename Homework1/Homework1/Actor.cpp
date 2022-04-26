#include <string>

#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include "Component.h"
#include "SceneComponent.h"

// ----------------------------------------------------------------------
// Constructor, Destructor
// ----------------------------------------------------------------------

namespace Engine
{
	Actor::Actor(Actor* owner, const std::string& name) : ObjectBase(name)
	{
		setOwner(owner);
		if (owner != nullptr)
		{
			setWorld(owner->getWorld());
		}
		else
		{
			World* world = Engine::getInstance()->getWorld();

			setWorld(world);
		}

		World* world = getWorld();
		world->addActor(this);

		SceneComponent* sceneComponent = new SceneComponent(this, "Transform");
		addComponent(sceneComponent);
	}

	Actor::~Actor()
	{
		getWorld()->removeActor(this);

		deleteChildren();
		deleteComponents();
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	Actor* Actor::getOwner()
	{
		return m_owner;
	}

	World* Actor::getWorld()
	{
		return m_world;
	}

	void Actor::setOwner(Actor* owner)
	{
		m_owner = owner;
	}

	void Actor::setWorld(World* world)
	{
		m_world = world;
	}

	// ----------------------------------------------------------------------
	// Child Function
	// ----------------------------------------------------------------------

	std::vector<Actor*>& Actor::getChildrenByTypeName(const std::string& typeName, std::vector<Actor*>& container)
	{
		for (const auto& element : this->m_children)
		{
			auto id = element.first;
			auto actor = element.second;

			if (actor->getTypeName() == typeName)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	Actor* Actor::getFirstChildByTypeName(const std::string& typeName)
	{
		for (const auto& element : this->m_children)
		{
			auto id = element.first;
			auto actor = element.second;

			if (actor->getTypeName() == typeName)
			{
				return actor;
			}
		}

		return nullptr;
	}

	Actor* Actor::getFirstChildByTypeId(size_t typeId)
	{
		for (const auto& element : this->m_children)
		{
			auto id = element.first;
			auto actor = element.second;

			if (actor->getTypeId() == typeId)
			{
				return actor;
			}
		}

		return nullptr;
	}

	std::vector<Actor*>& Actor::getChildrenByTypeId(size_t typeId, std::vector<Actor*>& container)
	{
		for (const auto& element : this->m_children)
		{
			auto id = element.first;
			auto actor = element.second;

			if (actor->getTypeId() == typeId)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	Actor* Actor::getChildById(const std::string& id)
	{
		auto item = this->m_children.find(id);
		if (item == this->m_children.end())
		{
			return nullptr;
		}

		return item->second;
	}

	std::vector<Actor*>& Actor::getChildrenByName(const std::string& name, std::vector<Actor*>& container)
	{
		for (const auto& element : this->m_children)
		{
			auto id = element.first;
			auto actor = element.second;

			if (actor->getName() == name)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	void Actor::addChild(Actor* actor)
	{
		auto actorId = actor->getId();
		if (getChildById(actorId) != nullptr)
		{
			return;
		}

		this->m_children[actorId] = actor;
	}

	void Actor::removeChild(Actor* actor)
	{
		auto actorId = actor->getId();
		if (getChildById(actorId) == nullptr)
		{
			return;
		}

		this->m_children.erase(actorId);
	}

	void Actor::clearChildren()
	{
		this->m_children.clear();
	}

	void Actor::deleteChildren()
	{
		for (auto pair : m_children)
		{
			std::string id = pair.first;
			Actor* child = pair.second;

			assert(child != nullptr);

			delete(child);
		}

		clearChildren();
	}

	// ----------------------------------------------------------------------
	// Component Function
	// ----------------------------------------------------------------------

	std::vector<Component*>& Actor::getComponentsByTypeName(const std::string& typeName, std::vector<Component*>& container)
	{
		for (const auto& element : this->m_components)
		{
			auto id = element.first;
			auto component = element.second;

			if (component->getTypeName() == typeName)
			{
				container.push_back(component);
			}
		}

		return container;
	}

	std::vector<Component*>& Actor::getComponentsByTypeId(size_t typeId, std::vector<Component*>& container)
	{
		for (const auto& element : this->m_components)
		{
			auto id = element.first;
			auto component = element.second;

			if (component->getTypeId() == typeId)
			{
				container.push_back(component);
			}
		}

		return container;
	}

	Component* Actor::getFirstComponentByTypeName(const std::string& typeName)
	{
		for (const auto& element : this->m_components)
		{
			auto id = element.first;
			auto component = element.second;

			if (component->getTypeName() == typeName)
			{
				return component;
			}
		}

		return nullptr;
	}

	Component* Actor::getFirstComponentByTypeId(size_t typeId)
	{
		for (const auto& element : this->m_components)
		{
			auto id = element.first;
			auto component = element.second;

			if (component->getTypeId() == typeId)
			{
				return component;
			}
		}

		return nullptr;
	}

	Component* Actor::getComponentById(const std::string& id)
	{
		auto item = this->m_components.find(id);
		if (item == this->m_components.end())
		{
			return nullptr;
		}

		return item->second;
	}

	std::vector<Component*>& Actor::getComponentsByName(const std::string& name, std::vector<Component*>& container)
	{
		for (const auto& element : this->m_components)
		{
			auto id = element.first;
			auto component = element.second;

			if (component->getName() == name)
			{
				container.push_back(component);
			}
		}

		return container;
	}

	void Actor::addComponent(Component* component)
	{
		auto componentId = component->getId();
		if (getComponentById(componentId) != nullptr)
		{
			return;
		}

		m_components[componentId] = component;

		getWorld()->registerComponent(component);
	}

	void Actor::removeComponent(Component* component)
	{
		auto componentId = component->getId();
		if (getComponentById(componentId) == nullptr)
		{
			return;
		}

		getWorld()->unRegisterComponent(component);

		m_components.erase(componentId);		
	}

	void Actor::clearComponents()
	{
		this->m_components.clear();
	}

	void Actor::deleteComponents()
	{
		for (auto pair : m_components)
		{
			std::string id = pair.first;
			Component* component = pair.second;

			assert(component != nullptr);

			delete(component);
		}

		clearComponents();
	}
}