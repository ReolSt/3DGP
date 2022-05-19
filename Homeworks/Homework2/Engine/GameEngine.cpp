#include "GameEngine.h"
#include "Actor/Actor.h"
#include "Component/InputComponent.h"
#include "System/SystemEvent.h"
#include "World.h"

#include <iostream>
#include <string>

namespace Engine
{
	// ----------------------------------------------------------------------
	// Static Getter, Setter
	// ----------------------------------------------------------------------
	World* GameEngine::GetWorld()
	{
		return GetInstance()->getWorld();
	}

	Array<Renderer*> GameEngine::GetRenderers()
	{
		return GetInstance()->getRenderers();
	}

	Int64 GameEngine::GetRendererCount()
	{
		return GetInstance()->getRendererCount();
	}

	Float GameEngine::GetDeltaTime()
	{
		return GetInstance()->getDeltaTime();
	}

	void GameEngine::SetWorld(World* world)
	{
		GetInstance()->SetWorld(world);
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	World* GameEngine::getWorld()
	{
		return m_world;
	}

	Array<Renderer*> GameEngine::getRenderers()
	{
		auto instance = GameEngine::GetInstance();
		return instance->getRenderers();
	}

	Int64 GameEngine::getRendererCount() const
	{
		return m_renderers.size();
	}

	Float GameEngine::getDeltaTime() const
	{
		return m_deltaTime;
	}	

	void GameEngine::setWorld(World* world)
	{
		m_world = world;
	}

	void GameEngine::setDeltaTime(Float deltaTime)
	{
		m_deltaTime = deltaTime;
	}	

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void GameEngine::dispatchEvent(SystemEvent* evt)
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
		case SystemEventType::MouseMove:
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

	void GameEngine::dispatchWindowEvent(WindowEvent* evt)
	{
		//__debugPrintWindowEvent(evt);
	}

	void GameEngine::dispatchMouseEvent(MouseEvent* evt)
	{
		__debugPrintMouseEvent(evt);

		auto world = getWorld();
		if (world == nullptr)
		{
			return;
		}

		auto components = Array<Component*>();
		world->getRegisteredComponentsByTypeId(GetTypeId(InputComponent), components);

		for (auto& component : components)
		{
			auto inputComponent = dynamic_cast<InputComponent*>(component);
			inputComponent->onMouseEvent(evt);
		}
	}

	void GameEngine::dispatchKeyEvent(KeyEvent* evt)
	{
		__debugPrintKeyEvent(evt);

		auto world = getWorld();

		if (world == nullptr)
		{
			return;
		}

		auto components = Array<Component*>();
		world->getRegisteredComponentsByTypeName(GetTypeName(InputComponent), components);

		for (auto& component : components)
		{
			auto inputComponent = dynamic_cast<InputComponent*>(component);
			inputComponent->onKeyEvent(evt);
		}
	}

	void GameEngine::update(float deltaTime)
	{
		setDeltaTime(deltaTime);


		auto evt = ActorEvent(ActorEventType::Update);

		auto world = getWorld();
		if (world == nullptr)
		{
			return;
		}

		for (auto& pair : world->getActors())
		{
			auto& id = pair.first;
			auto& actor = pair.second;


			actor->onUpdate(&evt);
		}
	}

	void GameEngine::render()
	{
		for (auto& pair : m_renderers)
		{
			auto& uuid = pair.first;
			auto& renderer = pair.second;

			renderer->render(this);
		}
	}

	void GameEngine::addRenderer(Renderer* renderer)
	{
		m_renderers[renderer->getId()] = renderer;
	}

	void GameEngine::removeRenderer(const UUID& uuid)
	{
		m_renderers.erase(uuid);
	}

	void GameEngine::removeRenderer(Renderer* renderer)
	{
		m_renderers.erase(renderer->getId());
	}

	// ----------------------------------------------------------------------
	// Private Member Method
	// ----------------------------------------------------------------------

	void GameEngine::__debugPrintWindowEvent(WindowEvent* evt)
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

	void GameEngine::__debugPrintMouseEvent(MouseEvent* evt)
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

	void GameEngine::__debugPrintKeyEvent(KeyEvent* evt)
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