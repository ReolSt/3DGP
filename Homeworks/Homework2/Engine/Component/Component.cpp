#include "Component/Component.h"
#include "Actor/Actor.h"
#include "World.h"

#include "debug.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	Component::Component(__ComponentDefaultParamsDef) : ObjectBase(name)
	{
		m_owner = owner;
	}

	Component::~Component() { }

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	Actor* Component::getOwner()
	{
		return m_owner;
	}

	Component* Component::getParentComponent()
	{
		return m_parent;
	}

	bool Component::isActive() const
	{
		return m_isActive;
	}

	void Component::setOwner(Actor* owner)
	{
		m_owner = owner;
	}

	void Component::setParentComponent(Component* parent)
	{
		m_parent = parent;
	}

	void Component::setActive(bool value)
	{
		m_isActive = value;
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void Component::Activate()
	{
		setActive(true);
	}

	void Component::Deactivate()
	{
		setActive(false);
	}

	// ----------------------------------------------------------------------
	// Child Component Method
	// ----------------------------------------------------------------------

	Component* Component::getComponentById(const String& id)
	{
		if (m_children.find(id) == m_children.end())
		{
			return nullptr;
		}

		return m_children[id];
	}

	UUIDMap<Component*>& Component::getComponents()
	{
		return m_children;
	}

	UUIDMap<Component*>::iterator Component::getComponentIterator()
	{
		return m_children.begin();
	}

	Array<Component*>& Component::getComponentsByTypeName(const String& typeName, Array<Component*>& container)
	{
		for (const auto& element : m_children)
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

	Array<Component*>& Component::getComponentsByTypeId(UInt64 typeId, Array<Component*>& container)
	{
		for (const auto& element : m_children)
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

	Component* Component::getFirstComponentByTypeName(const String& typeName)
	{
		for (const auto& element : m_children)
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

	Component* Component::getFirstComponentByTypeId(UInt64 typeId)
	{
		for (const auto& element : m_children)
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

	Array<Component*>& Component::getComponentsByName(const String& name, Array<Component*>& container)
	{
		for (const auto& element : m_children)
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

	void Component::addComponent(Component* component)
	{
		VERIFY(component != nullptr);

		if (isChildComponent(component))
		{
			return;
		}

		m_children[component->getId()] = component;

		component->setOwner(getOwner());
		component->setParentComponent(this);

		getOwner()->getWorld()->registerComponent(component);
	}

	void Component::removeComponent(Component* component)
	{
		VERIFY(component != nullptr);

		if (!isChildComponent(component))
		{
			return;
		}

		component->setOwner(nullptr);
		component->setParentComponent(nullptr);

		m_children.erase(component->getId());

		getOwner()->getWorld()->unRegisterComponent(component);
	}

	void Component::deleteComponent(Component* component)
	{
		removeComponent(component);
		
		delete component;
	}

	void Component::clearComponents()
	{
		m_children.clear();
	}

	void Component::deleteComponents()
	{
		for (auto& pair : m_children)
		{
			String id = pair.first;
			Component* component = pair.second;

			VERIFY(component != nullptr);

			delete(component);
		}

		clearComponents();
	}

	bool Component::isChildComponent(Component* component)
	{
		VERIFY(component != nullptr);

		return getComponentById(component->getId()) != nullptr;
	}

	bool Component::isParentComponent(Component* component)
	{
		VERIFY(component != nullptr);

		auto parentComponent = getParentComponent();
		if (parentComponent == nullptr)
		{
			return false;
		}

		return parentComponent->getId() == component->getId();
	}

	bool Component::isOwner(Actor* actor)
	{
		VERIFY(actor != nullptr);

		auto owner = getOwner();
		if (owner == nullptr)
		{
			return false;
		}

		return actor->getId() == getOwner()->getId();
	}

}