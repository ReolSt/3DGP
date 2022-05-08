#pragma once

#include "ObjectBase.h"
#include "Alias.h"

#define __ComponentDefaultParamsDef Actor* owner, const String& name
#define ComponentDefaultParamsDef Engine::Actor* owner, const Engine::String& name
#define ComponentDefaultParams owner, name

namespace Engine
{
	class Actor;

	class Component : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Component(__ComponentDefaultParamsDef);
		virtual ~Component();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Actor* getOwner();
		Component* getParentComponent();
		bool isActive() const;


		void setOwner(Actor* owner);
		void setParentComponent(Component* parent);
		void setActive(bool value);

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void Activate();
		void Deactivate();

		// ----------------------------------------------------------------------
		// Child Component Method
		// ----------------------------------------------------------------------

		Array<Component*>& getComponentsByTypeName(const String& typeName, Array<Component*>& container);
		Array<Component*>& getComponentsByTypeId(UInt64 typeId, Array<Component*>& container);
		Component* getFirstComponentByTypeName(const String& typeName);
		Component* getFirstComponentByTypeId(UInt64 typeId);
		Component* getComponentById(const String& id);
		Array<Component*>& getComponentsByName(const String& name, Array<Component*>& container);

		void addComponent(Component* component);
		void removeComponent(Component* component);
		void deleteComponent(Component* component);
		void clearComponents();
		void deleteComponents();

		bool isChildComponent(Component* component);
		bool isParentComponent(Component* component);
		bool isOwner(Actor* actor);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Actor* m_owner = nullptr;
		Component* m_parent = nullptr;

		UUIDMap<Component*> m_children;
		
		bool m_isActive = true;
	};

}