#include "PlayerActor.h"

#include "Engine/Math.h"
#include "Engine/Viewport.h"
#include "Engine/Engine.h"
#include "Engine/LineMeshComponent.h"

#include "CubeMesh.h"

#include <functional>
#include <iostream>
 
using namespace Engine::Math;

PlayerActor::PlayerActor(ActorDefaultParamDef) : Actor(ActorDefaultParams)
{
	addEventListener(
		Engine::ActorEventType::Load,
		Engine::ActorEventCallback(BindEventFunction(PlayerActor::initialize)));
}

void PlayerActor::initialize(Engine::ActorEvent* evt)
{
	auto sceneRoot = getFirstComponentByTypeId(GetTypeId(Engine::SceneComponent));

	auto meshComponent = new Engine::LineMeshComponent(this, "Mesh");
	auto camera = new Engine::CameraComponent(this, "Camera");
	auto input = new Engine::InputComponent(this, "Input");

	meshComponent->setMesh(new CubeMesh());

	sceneRoot->addComponent(meshComponent);
	sceneRoot->addComponent(camera);
	sceneRoot->addComponent(input);

	camera->setViewport(Engine::Viewport(0, 0, 1280, 720));

	auto meshTransform = meshComponent->getRelativeTransform();
	meshTransform.setScale(Vector3(0.1f, 0.1f, 0.1f));
	meshComponent->setRelativeTransform(meshTransform);

	auto cameraTransform = camera->getRelativeTransform();
	cameraTransform.setRotation(Quat(Rotator(degreeToRads(180.0f), degreeToRads(-60.0f), 0.0f)));
	cameraTransform.translate(0.0f, -0.5f, 0.0f);

	camera->setRelativeTransform(cameraTransform);

	input->addMouseEventListener(
		Engine::SystemEventType::MouseMove,
		Engine::MouseEventCallback(BindEventFunction(PlayerActor::mouseMove)));

	input->addMouseEventListener(
		Engine::SystemEventType::MouseDown,
		Engine::MouseEventCallback(BindEventFunction(PlayerActor::mouseDown)));

	input->addMouseEventListener(
		Engine::SystemEventType::MouseUp,
		Engine::MouseEventCallback(BindEventFunction(PlayerActor::mouseUp)));

	input->addKeyEventListener(
		Engine::SystemEventType::KeyDown,
		Engine::KeyEventCallback(BindEventFunction(PlayerActor::keyDown)));

	addEventListener(
		Engine::ActorEventType::Update,
		Engine::ActorEventCallback(BindEventFunction(PlayerActor::update)));

	m_sceneRoot = dynamic_cast<Engine::SceneComponent*>(sceneRoot);
	m_mesh = meshComponent;
	m_camera = camera;
	m_input = input;
}

void PlayerActor::update(Engine::ActorEvent* evt)
{
	auto cameraTransform = m_camera->getRelativeTransform();
	auto cameraRotation = cameraTransform.getRotation();
	auto forwardVector = cameraRotation.getForwardVector();
	auto rightVector = cameraRotation.getRightVector();

	auto rootTransform = m_sceneRoot->getWorldTransform();

	float speed = 0.05f;

	if (m_input->isPressed("W"))
	{
		rootTransform.translate(forwardVector * speed);
	}
	else if (m_input->isPressed("S"))
	{
		rootTransform.translate(-forwardVector * speed);
	}
	else if (m_input->isPressed("A"))
	{
		rootTransform.translate(-rightVector * speed);
	}
	else if (m_input->isPressed("D"))
	{
		rootTransform.translate(rightVector * speed);
	}

	m_sceneRoot->setWorldTransform(rootTransform);
}

void PlayerActor::mouseMove(Engine::MouseEvent* evt)
{
	static int px = evt->getX();
	static int py = evt->getY();

	static float xAngle = 180.0f;
	static float yAngle = -60.0f;

	int x = evt->getX();
	int y = evt->getY();	

	int dx = x - px;
	int dy = y - py;

	float sensitivity = 100.0f;
	float deltaTime = Engine::Engine::getInstance()->getDeltaTime();

	if (m_isDragging)
	{
		xAngle += degreeToRads(dx) * sensitivity * deltaTime;
		yAngle -= degreeToRads(dy) * sensitivity * deltaTime;

		yAngle = clamp(yAngle, degreeToRads(-60.0f), degreeToRads(60.0f));

		auto cameraTransform = m_camera->getRelativeTransform();
		cameraTransform.setRotation(Quat(Rotator(xAngle, yAngle, 0.0f)));

		m_camera->setRelativeTransform(cameraTransform);
	}

	px = x;
	py = y;
}

void PlayerActor::mouseDown(Engine::MouseEvent* evt)
{
	for (const auto& button : evt->getButtons())
	{
		if (button == Engine::KeyCode::LeftMouseButton)
		{
			m_isDragging = true;
		}
	}
}

void PlayerActor::mouseUp(Engine::MouseEvent* evt)
{
	m_isDragging = false;
}

void PlayerActor::keyDown(Engine::KeyEvent* evt)
{
	
}

Engine::SceneComponent* PlayerActor::getSceneRoot()
{
	return m_sceneRoot;
}

Engine::LineMeshComponent* PlayerActor::getMeshComponent()
{
	return m_mesh;
}

Engine::CameraComponent* PlayerActor::getCameraComponent()
{
	return m_camera;
}
