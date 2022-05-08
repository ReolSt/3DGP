#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

#include "Alias.h"
#include "ObjectBase.h"
#include "Transform.h"
#include "ActorEvent.h"

#define __ActorDefaultParamDef World* world, const String& name
#define ActorDefaultParamDef Engine::World* world, const Engine::String& name
#define ActorDefaultParams world, name

namespace Engine
{
	class Component;
	class World;

	class Actor : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Actor(__ActorDefaultParamDef);
		virtual ~Actor();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Actor* getOwner() const;
		World* getWorld() const;
		bool isActive() const;

		void setOwner(Actor* owner);
		void setWorld(World* world);
		void setActive(bool value);

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void Activate();
		void Deactivate();

		// ----------------------------------------------------------------------
		// Child Actor Method
		// ----------------------------------------------------------------------

		Array<Actor*>& getChildrenByTypeName(const String& typeName, Array<Actor*>& container);
		Array<Actor*>& getChildrenByTypeId(UInt64 typeId, Array<Actor*>& container);
		Actor* getChildById(const String& id);
		Array<Actor*>& getChildrenByName(const String& name, Array<Actor*>& container);

		Actor* getFirstChildByTypeName(const String& typeName);
		Actor* getFirstChildByTypeId(UInt64 typeId);
		Actor* getFirstChildByName(const String& name);

		void addChild(Actor* actor);
		void removeChild(Actor* actor);
		void deleteChild(Actor* actor);
		void clearChildren();
		void deleteChildren();

		bool isOwner(Actor* actor);
		bool isChild(Actor* actor);
		bool isChildComponent(Component* component);

		// ----------------------------------------------------------------------
		// Child Component Method
		// ----------------------------------------------------------------------

		Component* getComponentById(const String& id);
		Array<Component*>& getComponentsByTypeName(const String& typeName, Array<Component*>& container);
		Array<Component*>& getComponentsByTypeId(UInt64 typeId, Array<Component*>& container);		
		Array<Component*>& getComponentsByName(const String& name, Array<Component*>& container);

		Component* getFirstComponentByTypeName(const String& typeName);
		Component* getFirstComponentByTypeId(UInt64 typeId);
		Component* getFirstComponentByName(const String& name);

		void addComponent(Component* component);
		void removeComponent(Component* component);
		void deleteComponent(Component* component);
		void clearComponents();
		void deleteComponents();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Actor* m_owner = nullptr;
		World* m_world = nullptr;

		bool m_isActive;

		UUIDMap<Actor*> m_children;
		UUIDMap<Component*> m_components;
		Map<ActorEventType, UUIDMap<ActorEventCallback>> m_callbacks;
	};
}