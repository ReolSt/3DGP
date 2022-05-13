#include "InputComponent.h"
#include "SystemEvent.h"

namespace Engine
{
	InputComponent::InputComponent(__ComponentDefaultParamsDef)
		: Component(ComponentDefaultParams)
	{
		m_keyHandlers[SystemEventType::KeyDown] = UUIDMap<KeyEventCallback>();
		m_keyHandlers[SystemEventType::KeyUp] = UUIDMap<KeyEventCallback>();

		m_mouseHandlers[SystemEventType::MouseDown] = UUIDMap<MouseEventCallback>();
		m_mouseHandlers[SystemEventType::MouseUp] = UUIDMap<MouseEventCallback>();
		m_mouseHandlers[SystemEventType::MouseWheel] = UUIDMap<MouseEventCallback>();
		m_mouseHandlers[SystemEventType::MouseMove] = UUIDMap<MouseEventCallback>();
		m_mouseHandlers[SystemEventType::MouseHover] = UUIDMap<MouseEventCallback>();
		m_mouseHandlers[SystemEventType::MouseLeave] = UUIDMap<MouseEventCallback>();
	}

	void InputComponent::addKeyEventListener(const SystemEventType& eventType, const KeyEventCallback& callback)
	{
		m_keyHandlers[eventType][callback.getId()] = callback;
	}

	void InputComponent::removeKeyEventListener(const SystemEventType& eventType, const KeyEventCallback& callback)
	{
		m_keyHandlers[eventType].erase(callback.getId());
	}

	void InputComponent::removeKeyEventListener(const SystemEventType& eventType, const UUID& id)
	{
		m_keyHandlers[eventType].erase(id);
	}

	void InputComponent::addMouseEventListener(const SystemEventType& eventType, const MouseEventCallback& callback)
	{
		m_mouseHandlers[eventType][callback.getId()] = callback;
	}

	void InputComponent::removeMouseEventListener(const SystemEventType& eventType, const MouseEventCallback& callback)
	{
		m_mouseHandlers[eventType][callback.getId()] = callback;
	}

	void InputComponent::removeMouseEventListener(const SystemEventType& eventType, const UUID& id)
	{
		m_mouseHandlers[eventType].erase(id);
	}

	void InputComponent::onKeyEvent(KeyEvent* evt)
	{
		if (evt->getType() == SystemEventType::KeyDown)
		{
			m_keyPressed[evt->getKeyCode()] = true;
		}
		else if (evt->getType() == SystemEventType::KeyUp)
		{
			m_keyPressed[evt->getKeyCode()] = false;
		}

		for (auto& pair : m_keyHandlers[evt->getType()])
		{
			auto& callback = pair.second;
			callback(evt);
		}
	}

	void InputComponent::onMouseEvent(MouseEvent* evt)
	{
		for (auto& pair : m_mouseHandlers[evt->getType()])
		{
			auto& callback = pair.second;
			callback(evt);
		}
	}

	void InputComponent::lockCursor()
	{
	}

	void InputComponent::unLockCursor()
	{
	}

	bool InputComponent::isPressed(const KeyCode& keyCode)
	{
		if (m_keyPressed.find(keyCode) == m_keyPressed.end())
		{
			return false;
		}

		return m_keyPressed[keyCode];
	}

	bool InputComponent::isPressed(const String& keyCodeStr)
	{
		return isPressed(GetKeyCodeFromString(keyCodeStr));
	}

}

