#pragma once

#include <functional>

#include "Event.h"
#include "ObjectBase.h"

namespace Engine
{
	enum class ActorEventType
	{
		None,
		Update,
		Create,
		Load,
		Unload,
		Destroy
	};

	class ActorEvent : public Event
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		ActorEvent() { setType(ActorEventType::None); }
		ActorEvent(ActorEventType type) { setType(type); }

		virtual ~ActorEvent() { }
	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		ActorEventType getType() const { return m_type; }

		void setType(ActorEventType type) { m_type = type; }

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		ActorEventType m_type;
	};

	using ActorEventFunction = std::function<void(ActorEvent*)>;

	class ActorEventCallback : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		ActorEventCallback() { }
		ActorEventCallback(const ActorEventFunction& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const ActorEventFunction& getFunction() const
		{
			return m_func;
		}

		void setFunction(const ActorEventFunction& func)
		{
			m_func = func;
		}

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(ActorEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		ActorEventFunction m_func;
	};
}