#pragma once

#include "Engine/Actor/Actor.h"
#include "Engine/Actor/ActorEvent.h"

#include "Engine/System/SystemEvent.h"

#include "Engine/Mesh/DX12Mesh.h"
#include "Engine/Component/SceneComponent.h"
#include "Engine/Component/CameraComponent.h"
#include "Engine/Component/InputComponent.h"
#include "Engine/Component/DX12MeshComponent.h"

#include "MeshActor.h"

using Engine::Actor;
using Engine::ActorEvent;

using Engine::KeyEvent;
using Engine::MouseEvent;

using Engine::SceneComponent;
using Engine::CameraComponent;
using Engine::InputComponent;

using Engine::DX12Mesh;
using Engine::DX12MeshComponent;
using Engine::DX12Shader;

class CarActor : public MeshActor
{
public:
	CarActor(ActorDefaultParamDef);
public:
	void initialize(ActorEvent* evt);
	void update(ActorEvent* evt);

	void keyDown(KeyEvent* evt);
	void keyUp(KeyEvent* evt);
	void mouseMove(MouseEvent* evt);
	void mouseDown(MouseEvent* evt);
	void mouseUp(MouseEvent* evt);

private:
	CameraComponent* m_camera;
	InputComponent* m_input;

	bool m_isDragging = false;

	float m_carAngle = -90.0f;
};

