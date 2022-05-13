#pragma once

#include "Engine/Actor.h"

#include "Engine/LineMeshComponent.h"
#include "Engine/CameraComponent.h"
#include "Engine/InputComponent.h"
#include "Engine/SceneComponent.h"

#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"

class PlayerActor : public Engine::Actor
{
public:
	PlayerActor(ActorDefaultParamDef);

	void initialize(Engine::ActorEvent* evt);
	void update(Engine::ActorEvent* evt);
	void mouseMove(Engine::MouseEvent* evt);
	void mouseDown(Engine::MouseEvent* evt);
	void mouseUp(Engine::MouseEvent* evt);
	void keyDown(Engine::KeyEvent* evt);

	Engine::SceneComponent* getSceneRoot();
	Engine::LineMeshComponent* getMeshComponent();
	Engine::CameraComponent* getCameraComponent();

private:
	Engine::SceneComponent* m_sceneRoot;
	Engine::LineMeshComponent* m_mesh;
	Engine::CameraComponent* m_camera;
	Engine::InputComponent* m_input;

	bool m_isDragging = false;
};

