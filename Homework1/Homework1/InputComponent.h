#pragma once

#include "Component.h"
#include "Event.h"
#include "EventCallback.h"

#include <unordered_map>
#include <functional>

namespace Engine
{
	class InputComponent : public Component
	{
	public:
		// ----------------------------------------------------------------------
		// Consturctor, Destructor
		// ----------------------------------------------------------------------

		InputComponent(Actor* owner, const std::string& name);

	public:
		// ----------------------------------------------------------------------
		// Event Handler Management
		// ----------------------------------------------------------------------

		void addKeyHandler(EventType& eventType, KeyEventCallback& callback);
		void removeKeyHandler(EventType& eventType, KeyEventCallback& callback);

		void addMouseHandler(EventType& eventType, MouseEventCallback& callback);
		void removeMouseHandler(EventType& eventType, MouseEventCallback& callback);

	protected:
		// ----------------------------------------------------------------------
		// Event Listeners
		// ----------------------------------------------------------------------

		void onKeyEvent(KeyEvent* evt);
		void onMouseEvent(MouseEvent* evt);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		std::unordered_map<EventType, std::unordered_map<std::string, KeyEventCallback>> m_keyHandlers;
		std::unordered_map<EventType, std::unordered_map<std::string, MouseEventCallback>> m_mouseHandlers;
	};
}

