#pragma once

#include "Engine/SceneComponent.h"

#include "LineMeshActor.h"

class CubeActor : public LineMeshActor
{
public:
	CubeActor(ActorDefaultParamDef);

	void initialize(Engine::ActorEvent* evt);
	void update(Engine::ActorEvent* evt);

private:
	Engine::SceneComponent* m_sceneRoot = nullptr;
};

