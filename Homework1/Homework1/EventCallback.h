#pragma once

#include "ObjectBase.h"
#include "Event.h"

#include <functional>


namespace Engine
{
	class EventCallback : public ObjectBase
	{
	private:
		using __EventCallback = std::function<void(Event*)>;

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		EventCallback(__EventCallback& func) : m_func(func) { }

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(Event* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		__EventCallback m_func;
	};

	class WindowEventCallback : public ObjectBase
	{
	private:
		using __WindowEventCallback = std::function<void(WindowEvent*)>;

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		WindowEventCallback(__WindowEventCallback& func) : m_func(func) { }

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(WindowEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		__WindowEventCallback m_func;
	};

	class KeyEventCallback : public ObjectBase
	{
	private:
		using __KeyEventCallback = std::function<void(KeyEvent*)>;

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		KeyEventCallback(__KeyEventCallback& func) : m_func(func) { }

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(KeyEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		__KeyEventCallback m_func;
	};

	class MouseEventCallback : public ObjectBase
	{
	private:
		using __MouseEventCallback = std::function<void(MouseEvent*)>;

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		MouseEventCallback(__MouseEventCallback& func) : m_func(func) { }

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(MouseEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		__MouseEventCallback m_func;
	};
}
