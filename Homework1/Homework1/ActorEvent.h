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

	class ActorEventCallback : public ObjectBase
	{
	private:
		using __ActorEventCallback = std::function<void(ActorEvent*)>;

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		ActorEventCallback() { }
		ActorEventCallback(__ActorEventCallback& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const __ActorEventCallback& getFunction() const
		{
			return m_func;
		}

		void setFunction(__ActorEventCallback& func)
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

		__ActorEventCallback m_func;
	};
}