#include "Engine.h"
#include "Event.h"
#include "World.h"
#include "Actor.h"
#include "InputComponent.h"

#include <iostream>
#include <string>

namespace Engine
{

	void Engine::__debugPrintWindowEvent(WindowEvent* evt)
	{
		EventType eventType = evt->getType();
		assert(__isWindowEvent(eventType));

		char debugStr[100];
		snprintf(debugStr, 100, "EventType: %s, ", GetStringFromEventType(eventType).c_str());

		OutputDebugStringA(debugStr);

		char detailStr[100];
		snprintf(detailStr, 100, "x: %d, y: %d, width: %d, height: %d\n", evt->getX(), evt->getY(), evt->getWidth(), evt->getHeight());

		OutputDebugStringA(detailStr);
	}

	void Engine::__debugPrintMouseEvent(MouseEvent* evt)
	{
		EventType eventType = evt->getType();
		assert(__isMouseEvent(eventType));

		char debugStr[100];
		snprintf(debugStr, 100, "EventType: %s, ", GetStringFromEventType(eventType).c_str());

		OutputDebugStringA(debugStr);

		OutputDebugStringA("buttons: ");

		for (KeyCode button : evt->getButtons())
		{
			OutputDebugStringA((GetStringFromKeyCode(button) + " ").c_str());
		}

		char detailStr[100];
		snprintf(detailStr, 100, ", x: %d, y: %d, wheelDelta: %d\n", evt->getX(), evt->getY(), evt->getWheelDelta());

		OutputDebugStringA(detailStr);
	}

	void Engine::__debugPrintKeyEvent(KeyEvent* evt)
	{
		EventType eventType = evt->getType();
		assert(__isKeyEvent(eventType));

		char debugStr[100];
		snprintf(debugStr, 100, "EventType: %s, ", GetStringFromEventType(eventType).c_str());

		OutputDebugStringA(debugStr);

		char detailStr[100];
		snprintf(detailStr, 100, "KeyCode: %s\n", GetStringFromKeyCode(evt->getKeyCode()).c_str());

		OutputDebugStringA(detailStr);
	}	


	World* Engine::getWorld()
	{
		return m_world;
	}

	void Engine::setWorld(World* world)
	{
		assert(world != nullptr);

		m_world = world;
	}

	void Engine::dispatchEvent(Event* evt)
	{
		EventType eventType = evt->getType();

		switch (eventType)
		{
		case EventType::WindowMove:
		case EventType::WindowResize:
			dispatchWindowEvent(dynamic_cast<WindowEvent*>(evt));
			break;
		case EventType::MouseDown:
		case EventType::MouseUp:
		case EventType::MouseWheel:
		case EventType::MouseHover:
		case EventType::MouseLeave:
			dispatchMouseEvent(dynamic_cast<MouseEvent*>(evt));
			break;
		case EventType::KeyDown:
		case EventType::KeyUp:
			dispatchKeyEvent(dynamic_cast<KeyEvent*>(evt));
			break;
		}			
	}

	void Engine::dispatchWindowEvent(WindowEvent* evt)
	{
		__debugPrintWindowEvent(evt);
	}

	void Engine::dispatchMouseEvent(MouseEvent* evt)
	{
		__debugPrintMouseEvent(evt);

		if (m_world != nullptr)
		{
			
		}
	}

	void Engine::dispatchKeyEvent(KeyEvent* evt)
	{
		__debugPrintKeyEvent(evt);

		if (m_world != nullptr)
		{

		}
	}

	void Engine::renderWorld()
	{

	}	
}