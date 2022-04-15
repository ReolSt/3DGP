#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

#include "BasicTypes.h"
#include "ObjectBase.h"
#include "Transform.h"

namespace Engine
{
	class Component;

	class Actor : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Actor(Actor* owner, const std::string& name);
		virtual ~Actor();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Actor* getOwner();

		void setOwner(Actor* owner);

		// ----------------------------------------------------------------------
		// Child Function
		// ----------------------------------------------------------------------

		std::vector<Actor*>& getChildrenByTypeName(const std::string& typeName, std::vector<Actor*>& container);
		std::vector<Actor*>& getChildrenByTypeId(size_t typeId, std::vector<Actor*>& container);
		Actor* getFirstChildByTypeName(const std::string& typeName);
		Actor* getFirstChildByTypeId(size_t typeId);
		Actor* getChildById(const std::string& id);
		std::vector<Actor*>& getChildrenByName(const std::string& name, std::vector<Actor*>& container);

		void addChild(Actor* actor);
		void removeChild(Actor* actor);
		void clearChildren();
		void deleteChildren();

		// ----------------------------------------------------------------------
		// Component Function
		// ----------------------------------------------------------------------

		std::vector<Component*>& getComponentsByTypeName(const std::string& typeName, std::vector<Component*>& container);
		std::vector<Component*>& getComponentsByTypeId(size_t typeId, std::vector<Component*>& container);
		Component* getFirstComponentByTypeName(const std::string& typeName);
		Component* getFirstComponentByTypeId(size_t typeIdr);
		Component* getComponentById(const std::string& id);
		std::vector<Component*>& getComponentsByName(const std::string& name, std::vector<Component*>& container);

		void addComponent(Component* component);
		void removeComponent(Component* component);
		void clearComponents();
		void deleteComponents();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Actor* m_owner;

		std::unordered_map<std::string, Actor*> m_children;
		std::unordered_map<std::string, Component*> m_components;
	};


}