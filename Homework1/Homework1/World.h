#pragma once

#include <vector>
#include <string>

#include "BasicTypes.h"

namespace Engine
{
	class Actor;
	class Component;

	class World
	{
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		World();
		virtual ~World();

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		std::vector<Actor*>& getActors();
		std::vector<Actor*>& getActorById();

		std::vector<Component*> getRegisteredComponents();
		std::vector<Component*> getRegisteredComponentById(ObjectId id);
		std::vector<Component*> getRegisteredComponentByTypeId(size_t typeId);
		std::vector<Component*> getRegisteredComponentByTypeName(const std::string& typeName);

		void update();
		void updateComponents();

		void render();

		void addActor();
		void registerComponent();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		std::vector<Actor*> m_actors;
		std::vector<Component*> m_registeredComponents;
	};
}