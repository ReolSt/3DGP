#pragma once

#include "Core/Types.h"
#include "Component/Component.h"
#include "System/SystemEvent.h"

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

		void addKeyEventListener(const SystemEventType& eventType, const KeyEventCallback& callback);
		void removeKeyEventListener(const SystemEventType& eventType, const KeyEventCallback& callback);
		void removeKeyEventListener(const SystemEventType& eventType, const UUID& id);

		void addMouseEventListener(const SystemEventType& eventType, const MouseEventCallback& callback);
		void removeMouseEventListener(const SystemEventType& eventType, const MouseEventCallback& callback);
		void removeMouseEventListener(const SystemEventType& eventType, const UUID& id);

	public:
		// ----------------------------------------------------------------------
		// Event Listeners
		// ----------------------------------------------------------------------

		void onKeyEvent(KeyEvent* evt);
		void onMouseEvent(MouseEvent* evt);

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void lockCursor();
		void unLockCursor();

		bool isPressed(const KeyCode& keyCode);
		bool isPressed(const String& keyCodeStr);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Map<SystemEventType, UUIDMap<KeyEventCallback>> m_keyHandlers;
		Map<SystemEventType, UUIDMap<MouseEventCallback>> m_mouseHandlers;

		Map<KeyCode, bool> m_keyPressed;
	};
}

