#pragma once

#include "Engine/Actor.h"

#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"

#include "Engine/LineMesh.h"
#include "Engine/LineMeshComponent.h"

#include "LineMeshActor.h"

class LineMeshActor : public Engine::Actor
{
public:
	LineMeshActor(ActorDefaultParamDef, Engine::LineMesh* mesh = nullptr);

	void initialize(Engine::ActorEvent* evt);

	Engine::LineMesh* getMesh();
	void setMesh(Engine::LineMesh* mesh);

private:
	Engine::SceneComponent* m_root;
	Engine::LineMesh* m_mesh;
	Engine::LineMeshComponent* m_meshComponent;
};