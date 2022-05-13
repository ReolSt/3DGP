#pragma once

#include "LineMeshActor.h"
#include "PlayerActor.h"

#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"

#include "Engine/InputComponent.h"

class RollerCoasterActor : public LineMeshActor
{
public:
	RollerCoasterActor(ActorDefaultParamDef, int pointCount=8);

	void initialize(Engine::ActorEvent* evt);
	void update(Engine::ActorEvent* evt);
	void keyDown(Engine::KeyEvent* evt);
private:
	int m_pointCount = 8;
	int m_direction = 1.0f;

	PlayerActor* m_player;
	Engine::SceneComponent* m_playerSceneRoot;
	Engine::InputComponent* m_input;
};

