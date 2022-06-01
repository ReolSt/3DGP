#pragma once

#include "Engine/Actor/Actor.h"
#include "Engine/Actor/ActorEvent.h"
#include "Engine/System/SystemEvent.h"

#include "System/SystemEvent.h"

#include "Component/SceneComponent.h"
#include "Component/CameraComponent.h"
#include "Component/InputComponent.h"

using namespace Engine;

class ObserverActor : public Actor
{
public:
	ObserverActor(ActorDefaultParamDef);

	void initialize(ActorEvent* evt);
	void update(ActorEvent* evt);
	void keyDown(KeyEvent* evt);
	void keyUp(KeyEvent* evt);
	void mouseMove(MouseEvent* evt);
	void mouseDown(MouseEvent* evt);
	void mouseUp(MouseEvent* evt);

private:
	SceneComponent* m_sceneRoot = nullptr;
	CameraComponent* m_camera = nullptr;
	InputComponent* m_input = nullptr;

	bool m_isDragging;
};

