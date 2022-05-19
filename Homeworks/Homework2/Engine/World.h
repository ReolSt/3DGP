#pragma once

#include <unordered_map>
#include <string>

#include "Core/Types.h"
#include "Core/ObjectBase.h"

namespace Engine
{
	class Actor;
	class Component;

	class World : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		World();
		virtual ~World();

	public:
		// ----------------------------------------------------------------------
		// Actor Method
		// ----------------------------------------------------------------------

		UUIDMap<Actor*>& getActors();
		UUIDMap<Actor*>::iterator getActorIterator();
		Actor* getActorById(const String& id);
		Array<Actor*>& getActorsByTypeId(UInt64 typeId, Array<Actor*>& container);
		Array<Actor*>& getActorsByTypeName(const String& typeName, Array<Actor*>& container);
		Array<Actor*>& getActorsByName(const String& name, Array<Actor*>& container);

		Actor* getFirstActorByTypeId(UInt64 typeId);
		Actor* getFirstActorByTypeName(const String& typeName);
		Actor* getFirstActorByName(const String& name);

		void addActor(Actor* actor);
		void removeActor(Actor* actor);

		// ----------------------------------------------------------------------
		// Registered Component Method
		// ----------------------------------------------------------------------

		UUIDMap<Component*>& getRegisteredComponents();
		UUIDMap<Component*>::iterator getRegisteredComponentIterator();
		Component* getRegisteredComponentById(const String& id);
		Array<Component*>& getRegisteredComponentsByTypeId(UInt64 typeId, Array<Component*>& conatiner);
		Array<Component*>& getRegisteredComponentsByTypeName(const String& typeName, Array<Component*>& container);
		Array<Component*>& getRegisteredComponentsByName(const String& name, Array<Component*>& container);

		Component* getFirstRegisteredComponentByTypeId(UInt64 typeId);
		Component* getFirstRegisteredComponentByTypeName(const String& typeName);
		Component* getFirstRegisteredComponentByName(const String& name);

		void registerComponent(Component* component);
		void unRegisterComponent(Component* component);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		UUIDMap<Actor*> m_actors;
		UUIDMap<Component*> m_registeredComponents;
	};
}