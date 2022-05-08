#include "Engine.h"
#include "SystemEvent.h"
#include "World.h"
#include "Actor.h"
#include "InputComponent.h"

#include <iostream>
#include <string>

namespace Engine
{

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	World* Engine::getWorld()
	{
		return m_world;
	}

	Array<Renderer*>&& Engine::getRenderers()
	{
		Array<Renderer*> container;
		
		for (auto& pair : m_renderers)
		{
			auto& uuid = pair.first;
			auto& renderer = pair.second;

			container.push_back(renderer);
		}

		return std::move(container);
	}

	Int64 Engine::getRendererCount() const
	{
		return m_renderers.size();
	}

	void Engine::setWorld(World* world)
	{
		m_world = world;
	}

	void Engine::addRenderer(Renderer* renderer)
	{
		m_renderers[renderer->getId()] = renderer;
	}

	void Engine::removeRenderer(const UUID& uuid)
	{
		m_renderers.erase(uuid);
	}

	void Engine::removeRenderer(Renderer* renderer)
	{
		m_renderers.erase(renderer->getId());
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void Engine::dispatchEvent(SystemEvent* evt)
	{
		SystemEventType eventType = evt->getType();

		switch (eventType)
		{
		case SystemEventType::WindowMove:
		case SystemEventType::WindowResize:
			dispatchWindowEvent(dynamic_cast<WindowEvent*>(evt));
			break;
		case SystemEventType::MouseDown:
		case SystemEventType::MouseUp:
		case SystemEventType::MouseWheel:
		case SystemEventType::MouseHover:
		case SystemEventType::MouseLeave:
			dispatchMouseEvent(dynamic_cast<MouseEvent*>(evt));
			break;
		case SystemEventType::KeyDown:
		case SystemEventType::KeyUp:
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

		auto world = getWorld();
		if (world == nullptr)
		{
			return;
		}

		auto components = world->getRegisteredComponentsByTypeId(GetTypeId(InputComponent));
		for (auto& component : components)
		{
			auto inputComponent = dynamic_cast<InputComponent*>(component);
			inputComponent->onMouseEvent(evt);
		}
	}

	void Engine::dispatchKeyEvent(KeyEvent* evt)
	{
		__debugPrintKeyEvent(evt);

		auto world = getWorld();

		if (world == nullptr)
		{
			return;
		}

		auto components = world->getRegisteredComponentsByTypeId(GetTypeId(InputComponent));
		for (auto& component : components)
		{
			auto inputComponent = dynamic_cast<InputComponent*>(component);
			inputComponent->onKeyEvent(evt);
		}
	}

	void Engine::update(float deltaTime)
	{

	}

	void Engine::render()
	{
		for (auto& pair : m_renderers)
		{
			auto& uuid = pair.first;
			auto& renderer = pair.second;

			renderer->render(this);
		}
	}

	// ----------------------------------------------------------------------
	// Private Member Method
	// ----------------------------------------------------------------------

	void Engine::__debugPrintWindowEvent(WindowEvent* evt)
	{
		SystemEventType eventType = evt->getType();
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
		SystemEventType eventType = evt->getType();
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
		SystemEventType eventType = evt->getType();
		assert(__isKeyEvent(eventType));

		char debugStr[100];
		snprintf(debugStr, 100, "EventType: %s, ", GetStringFromEventType(eventType).c_str());

		OutputDebugStringA(debugStr);

		char detailStr[100];
		snprintf(detailStr, 100, "KeyCode: %s\n", GetStringFromKeyCode(evt->getKeyCode()).c_str());

		OutputDebugStringA(detailStr);
	}
}