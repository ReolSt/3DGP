#pragma once

#include <unordered_map>
#include <string>

#include "Alias.h"
#include "ObjectBase.h"

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
		// Public Member Method
		// ----------------------------------------------------------------------

		Actor* getActorById(const String& id);
		Array<Actor*>&& getActorsByTypeId(UInt64 typeId);
		Array<Actor*>&& getActorsByTypeName(const String& typeName);

		void addActor(Actor* actor);
		void removeActor(Actor* actor);

		Component* getRegisteredComponentById(const String& id);
		Array<Component*>&& getRegisteredComponentsByTypeId(UInt64 typeId);
		Array<Component*>&& getRegisteredComponentsByTypeName(const String& typeName);

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