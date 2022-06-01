#include "GameEngine.h"
#include "World.h"
#include "Actor/Actor.h"
#include "Component/Component.h"
#include "Component/SceneComponent.h"

#include "debug.h"

// ----------------------------------------------------------------------
// Constructor, Destructor
// ----------------------------------------------------------------------

namespace Engine
{
	Actor::Actor(__ActorDefaultParamDef) : ObjectBase(name)
	{
		setWorld(world);
		if (world != nullptr)
		{
			world->addActor(this);
		}		

		SceneComponent* sceneComponent = new SceneComponent(this, "SceneRoot");
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

	Actor* Actor::getOwner() const
	{
		return m_owner;
	}

	World* Actor::getWorld() const
	{
		return m_world;
	}

	bool Actor::isActive() const
	{
		return m_isActive;
	}

	void Actor::setOwner(Actor* owner)
	{
		m_owner = owner;
	}

	void Actor::setWorld(World* world)
	{
		m_world = world;

		for (auto& pair : m_children)
		{
			auto& id = pair.first;
			auto& child = pair.second;

			child->setWorld(world);
		}
	}

	void Actor::setActive(bool value)
	{
		m_isActive = value;
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void Actor::Activate()
	{
		setActive(true);
	}

	void Actor::Deactivate()
	{
		setActive(false);
	}

	// ----------------------------------------------------------------------
	// Child Actor Method
	// ----------------------------------------------------------------------

	Actor* Actor::getChildById(const String& id)
	{
		if (m_children.find(id) == m_children.end())
		{
			return nullptr;
		}

		return m_children[id];
	}

	UUIDMap<Actor*>& Actor::getChildren()
	{
		return m_children;
	}

	UUIDMap<Actor*>::iterator Actor::getChildIterator()
	{
		return m_children.begin();
	}

	Array<Actor*>& Actor::getChildrenByTypeName(const String& typeName, Array<Actor*>& container)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getTypeName() == typeName)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	Array<Actor*>& Actor::getChildrenByTypeId(UInt64 typeId, Array<Actor*>& container)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getTypeId() == typeId)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	Array<Actor*>& Actor::getChildrenByName(const String& name, Array<Actor*>& container)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getName() == name)
			{
				container.push_back(actor);
			}
		}

		return container;
	}

	Actor* Actor::getFirstChildByTypeName(const String& typeName)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getTypeName() == typeName)
			{
				return actor;
			}
		}

		return nullptr;
	}

	Actor* Actor::getFirstChildByTypeId(UInt64 typeId)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getTypeId() == typeId)
			{
				return actor;
			}
		}

		return nullptr;
	}

	Actor* Actor::getFirstChildByName(const String& name)
	{
		for (const auto& element : m_children)
		{
			auto& id = element.first;
			auto& actor = element.second;

			if (actor->getName() == name)
			{
				return actor;
			}
		}

		return nullptr;
	}

	void Actor::addChild(Actor* actor)
	{
		if (isChild(actor))
		{
			return;
		}

		m_children[actor->getId()] = actor;
		actor->setOwner(this);
		actor->setWorld(getWorld());
	}

	void Actor::removeChild(Actor* actor)
	{
		if (!isChild(actor))
		{
			return;
		}

		m_children.erase(actor->getId());
		actor->setOwner(nullptr);
		actor->setWorld(nullptr);
	}

	void Actor::deleteChild(Actor* actor)
	{
		removeChild(actor);

		delete actor;
	}

	void Actor::clearChildren()
	{
		m_children.clear();
	}

	void Actor::deleteChildren()
	{
		for (auto pair : m_children)
		{
			String id = pair.first;
			Actor* child = pair.second;

			VERIFY(child != nullptr);

			delete(child);
		}

		clearChildren();
	}

	bool Actor::isOwner(Actor* actor)
	{
		VERIFY(actor != nullptr);

		auto owner = getOwner();
		if (owner == nullptr)
		{
			return false;
		}

		return owner->getId() == actor->getId();
	}

	bool Actor::isChild(Actor* actor)
	{
		VERIFY(actor != nullptr);

		return getChildById(actor->getId()) != nullptr;
	}

	bool Actor::isChildComponent(Component* component)
	{
		VERIFY(component != nullptr);

		return getComponentById(component->getId());
	}

	// ----------------------------------------------------------------------
	// Child Component Method
	// ----------------------------------------------------------------------

	UUIDMap<Component*>& Actor::getComponents()
	{
		return m_components;
	}

	UUIDMap<Component*>::iterator Actor::getComponentIterator()
	{
		return m_components.begin();
	}

	Component* Actor::getComponentById(const String& id)
	{
		if (m_components.find(id) == m_components.end())
		{
			return nullptr;
		}

		return m_components[id];
	}

	Array<Component*>& Actor::getComponentsByTypeName(const String& typeName, Array<Component*>& container)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getTypeName() == typeName)
			{
				container.push_back(component);
			}
		}

		return container;
	}

	Array<Component*>& Actor::getComponentsByTypeId(UInt64 typeId, Array<Component*>& container)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getTypeId() == typeId)
			{
				container.push_back(component);
			}
		}

		return container;
	}	

	Array<Component*>& Actor::getComponentsByName(const String& name, Array<Component*>& container)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getName() == name)
			{
				container.push_back(component);
			}
		}

		return container;
	}

	Component* Actor::getFirstComponentByTypeName(const String& typeName)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getTypeName() == typeName)
			{
				return component;
			}
		}

		return nullptr;
	}

	Component* Actor::getFirstComponentByTypeId(UInt64 typeId)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getTypeId() == typeId)
			{
				return component;
			}
		}

		return nullptr;
	}

	Component* Actor::getFirstComponentByName(const String& name)
	{
		for (const auto& element : m_components)
		{
			auto& id = element.first;
			auto& component = element.second;

			if (component->getName() == name)
			{
				return component;
			}
		}

		return nullptr;
	}

	void Actor::addComponent(Component* component)
	{
		if (isChildComponent(component))
		{
			return;
		}

		m_components[component->getId()] = component;
		component->setOwner(this);

		if (getWorld() != nullptr)
		{
			getWorld()->registerComponent(component);
		}		
	}

	void Actor::removeComponent(Component* component)
	{
		if (!isChildComponent(component))
		{
			return;
		}

		m_components.erase(component->getId());
		component->setOwner(nullptr);

		if (getWorld() != nullptr)
		{
			getWorld()->unRegisterComponent(component);
		}		
	}

	void Actor::deleteComponent(Component* component)
	{
		removeComponent(component);

		delete component;
	}

	void Actor::clearComponents()
	{
		m_components.clear();
	}

	void Actor::deleteComponents()
	{
		for (auto pair : m_components)
		{
			String id = pair.first;
			Component* component = pair.second;

			VERIFY(component != nullptr);

			delete component;
		}

		clearComponents();
	}
	void Actor::onUpdate(ActorEvent* evt)
	{
		for (auto& pair : m_callbacks[ActorEventType::Update])
		{
			auto& id = pair.first;
			auto& callback = pair.second;

			callback(evt);
		}
		
		for (auto& pair : m_children)
		{
			auto& id = pair.first;
			auto& child = pair.second;

		    child->onUpdate(evt);
		}
	}

	void Actor::onLoad(ActorEvent* evt)
	{
		for (auto& pair : m_callbacks[ActorEventType::Load])
		{
			auto& id = pair.first;
			auto& callback = pair.second;

			callback(evt);
		}

		for (auto& pair : m_children)
		{
			auto& id = pair.first;
			auto& child = pair.second;

			child->onLoad(evt);
		}
	}

	void Actor::onUnload(ActorEvent* evt)
	{
		for (auto& pair : m_callbacks[ActorEventType::Unload])
		{
			auto& id = pair.first;
			auto& callback = pair.second;

			callback(evt);
		}

		for (auto& pair : m_children)
		{
			auto& id = pair.first;
			auto& child = pair.second;

			child->onUnload(evt);
		}
	}

	void Actor::addEventListener(const ActorEventType& eventType, const ActorEventCallback& callback)
	{
		m_callbacks[eventType][callback.getId()] = callback;
	}

	void Actor::removeEventListener(const ActorEventType& eventType, const ActorEventCallback& callback)
	{
		m_callbacks[eventType].erase(callback.getId());
	}

	void Actor::removeEventListener(const ActorEventType& eventType, const UUID& id)
	{
		m_callbacks[eventType].erase(id);
	}

}