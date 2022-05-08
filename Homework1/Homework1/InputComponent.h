#pragma once

#include "Alias.h"
#include "Component.h"
#include "SystemEvent.h"

#include <unordered_map>
#include <functional>

namespace Engine
{
	class KeyEventCallback;
	class MouseEventCallback;

	class InputComponent : public Component
	{
	public:
		// ----------------------------------------------------------------------
		// Consturctor, Destructor
		// ----------------------------------------------------------------------

		InputComponent(__ComponentDefaultParamsDef);

	public:
		// ----------------------------------------------------------------------
		// Event Handler Management
		// ----------------------------------------------------------------------

		void addKeyHandler(const SystemEventType& eventType, KeyEventCallback callback);
		void removeKeyHandler(const SystemEventType& eventType, KeyEventCallback callback);

		void addMouseHandler(const SystemEventType& eventType, MouseEventCallback callback);
		void removeMouseHandler(const SystemEventType& eventType, MouseEventCallback callback);

	public:
		// ----------------------------------------------------------------------
		// Event Listeners
		// ----------------------------------------------------------------------

		void onKeyEvent(KeyEvent* evt);
		void onMouseEvent(MouseEvent* evt);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Map<SystemEventType, UUIDMap<KeyEventCallback>> m_keyHandlers;
		Map<SystemEventType, UUIDMap<MouseEventCallback>> m_mouseHandlers;
	};
}

