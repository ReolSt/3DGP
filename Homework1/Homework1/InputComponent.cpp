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

	inline void InputComponent::addKeyHandler(const SystemEventType& eventType, KeyEventCallback callback)
	{
		m_keyHandlers[eventType][callback.getId()] = callback;
	}

	inline void InputComponent::removeKeyHandler(const SystemEventType& eventType, KeyEventCallback callback)
	{
		m_keyHandlers[eventType].erase(callback.getId());
	}

	inline void InputComponent::addMouseHandler(const SystemEventType& eventType, MouseEventCallback callback)
	{
		m_mouseHandlers[eventType][callback.getId()] = callback;
	}

	inline void InputComponent::removeMouseHandler(const SystemEventType& eventType, MouseEventCallback callback)
	{
		m_mouseHandlers[eventType][callback.getId()] = callback;
	}

	void InputComponent::onKeyEvent(KeyEvent* evt)
	{
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

}

