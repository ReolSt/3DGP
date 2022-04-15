#pragma once

#include "ObjectBase.h"

namespace Engine
{
	class Actor;

	class Component : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		explicit Component(Actor* owner, const std::string& name) : ObjectBase(name)
		{
			m_owner = owner;
		}

		virtual ~Component() { }

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Actor* getOwner() const
		{
			return m_owner;
		}

		void setOwner(Actor* owner)
		{
			m_owner = owner;
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Actor* m_owner;
	};

}