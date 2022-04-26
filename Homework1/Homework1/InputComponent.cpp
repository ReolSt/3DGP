#include "InputComponent.h"

namespace Engine
{
	InputComponent::InputComponent(Actor* owner, const std::string& name) : Component(owner, name)
	{
		m_keyHandlers[EventType::KeyDown] = std::unordered_map<std::string, KeyEventCallback>();
		m_keyHandlers[EventType::KeyUp] = std::unordered_map<std::string, KeyEventCallback>();

		m_mouseHandlers[EventType::MouseDown] = std::unordered_map<std::string, MouseEventCallback>();
		m_mouseHandlers[EventType::MouseUp] = std::unordered_map<std::string, MouseEventCallback>();
		m_mouseHandlers[EventType::MouseWheel] = std::unordered_map<std::string, MouseEventCallback>();
		m_mouseHandlers[EventType::MouseMove] = std::unordered_map<std::string, MouseEventCallback>();
		m_mouseHandlers[EventType::MouseHover] = std::unordered_map<std::string, MouseEventCallback>();
		m_mouseHandlers[EventType::MouseLeave] = std::unordered_map<std::string, MouseEventCallback>();
	}

	inline void InputComponent::addKeyHandler(EventType& eventType, KeyEventCallback& callback)
	{
		m_keyHandlers[eventType][callback.getId()] = callback;
	}

	inline void InputComponent::removeKeyHandler(EventType& eventType, KeyEventCallback& callback)
	{
		m_keyHandlers[eventType].erase(callback.getId());
	}

	inline void InputComponent::addMouseHandler(EventType& eventType, MouseEventCallback& callback)
	{
		m_mouseHandlers[eventType][callback.getId()] = callback;
	}

	inline void InputComponent::removeMouseHandler(EventType& eventType, MouseEventCallback& callback)
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

