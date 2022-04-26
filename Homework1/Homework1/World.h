#pragma once

#include <unordered_map>
#include <string>

namespace Engine
{
	class Actor;
	class Component;

	class World
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

		Actor* getActorById(const std::string& id);
		std::vector<Actor*>&& getActorsByTypeId(size_t typeId);
		std::vector<Actor*>&& getActorsByTypeName(const std::string& typeName);

		void addActor(Actor* actor);
		void removeActor(Actor* actor);

		Component* getRegisteredComponentById(const std::string& id);
		std::vector<Component*>&& getRegisteredComponentsByTypeId(size_t typeId);
		std::vector<Component*>&& getRegisteredComponentsByTypeName(const std::string& typeName);

		void registerComponent(Component* component);
		void unRegisterComponent(Component* component);

		void update();
		void updateComponents();
	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		std::unordered_map<std::string, Actor*> m_actors;
		std::unordered_map<std::string, Component*> m_registeredComponents;
	};
}