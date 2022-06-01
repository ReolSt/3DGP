#include "CarActor.h"

#include "Engine/GameEngine.h"
#include "Engine/Core/Types.h"
#include "Engine/Math/Math.h"
#include "Engine/System/SystemEvent.h"

#include "Engine/Asset/AssetStorage.h"
#include "Engine/Asset/MeshAsset.h"

#include "Engine/Component/InputComponent.h"

using namespace Engine;
using namespace Engine::Math;

CarActor::CarActor(ActorDefaultParamDef) : MeshActor(ActorDefaultParams)
{
	addEventListener(
		ActorEventType::Load,
		ActorEventCallback(BindEventFunction(CarActor::initialize))
	);

	addEventListener(
		ActorEventType::Update,
		ActorEventCallback(BindEventFunction(CarActor::update))
	);
}

void CarActor::initialize(ActorEvent* evt)
{
	MeshActor::initialize(evt);

	m_input = new InputComponent(this, "Input");
	m_camera = new CameraComponent(this, "Camera");

	getRoot()->addComponent(m_input);
	getRoot()->addComponent(m_camera);

	m_input->addKeyEventListener(
		SystemEventType::KeyDown,
		KeyEventCallback(BindEventFunction(CarActor::keyDown))
	);

	m_input->addKeyEventListener(
		SystemEventType::KeyUp,
		KeyEventCallback(BindEventFunction(CarActor::keyUp))
	);

	m_input->addMouseEventListener(
		SystemEventType::MouseMove,
		MouseEventCallback(BindEventFunction(CarActor::mouseMove))
	);

	m_input->addMouseEventListener(
		SystemEventType::MouseDown,
		MouseEventCallback(BindEventFunction(CarActor::mouseDown))
	);

	m_input->addMouseEventListener(
		SystemEventType::MouseUp,
		MouseEventCallback(BindEventFunction(CarActor::mouseUp))
	);

	loadFromAsset(L"Assets\\Car.obj");

	m_camera->setViewport(Viewport(0.0f, 0.0f, 1.0f, 1.0f));
	m_camera->setAspectRatio(1200.0f / 700.0f);
	m_camera->setFar(1000.0f);
}

void CarActor::update(ActorEvent* evt)
{
	auto root = getRoot();
	auto rootTransform = root->getWorldTransform();
	auto meshComponent = getMeshComponent();

	auto meshTransform = meshComponent->getRelativeTransform();
	auto meshRotation = meshTransform.getRotation();

	auto cameraTransform = m_camera->getRelativeTransform();

	auto forwardVector = meshRotation.getForwardVector();
	auto rightVector = meshRotation.getRightVector();	

	forwardVector = Vector3(forwardVector.getX(), 0.0f, forwardVector.getZ()).normalize();
	rightVector = Vector3(rightVector.getX(), 0.0f, rightVector.getZ()).normalize();

	float speed = 0.1f;
	float rotationSpeed = 0.3f;

	if (m_input->isPressed("W"))
	{
		rootTransform.translate(forwardVector * speed);
	}
	if (m_input->isPressed("S"))
	{
		rootTransform.translate(-forwardVector * speed);
	}
	if (m_input->isPressed("A"))
	{
		m_carAngle -= rotationSpeed;
	}
	if (m_input->isPressed("D"))
	{
		m_carAngle += rotationSpeed;
	}

	meshTransform.setRotation(Quat(Rotator(0.0f, degreeToRads(m_carAngle), 0.0f)));
	meshComponent->setRelativeTransform(meshTransform);

	auto cameraPosition = -forwardVector * 3.0f;
	cameraPosition.setY(1.2f);

	cameraTransform.setTranslation(cameraPosition);	
	if (!m_input->isPressed("Space"))
	{
		cameraTransform.setRotation(Quat(Rotator(0.0f, degreeToRads(m_carAngle), 0.0f)));
	}
	m_isDragging = m_input->isPressed("Space");
	m_camera->setRelativeTransform(cameraTransform);

	root->setWorldTransform(rootTransform);	
}

void CarActor::keyDown(KeyEvent* evt)
{
	
}

void CarActor::keyUp(KeyEvent* evt)
{
}

void CarActor::mouseMove(MouseEvent* evt)
{
	static int px = evt->getX();
	static int py = evt->getY();

	static float xAngle = 0.0f;
	static float yAngle = 0.0f;

	int x = evt->getX();
	int y = evt->getY();

	int dx = x - px;
	int dy = y - py;

	float sensitivity = 100.0f;
	float deltaTime = Engine::GameEngine::GetInstance()->getDeltaTime();

	if (m_isDragging)
	{
		xAngle += degreeToRads(dx) * sensitivity * deltaTime;
		yAngle += degreeToRads(dy) * sensitivity * deltaTime;

		yAngle = clamp(yAngle, degreeToRads(-60.0f), degreeToRads(60.0f));

		auto cameraTransform = m_camera->getRelativeTransform();
		cameraTransform.setRotation(Quat(Rotator(yAngle, xAngle, 0.0f)).normalize());

		m_camera->setRelativeTransform(cameraTransform);

		auto forward = m_camera->getRelativeRotation().getForwardVector();

		char str[128];
		sprintf(str, "%.2f %.2f %.2f\n", forward.getX(), forward.getY(), forward.getZ());
		OutputDebugStringA(str);
	}

	px = x;
	py = y;
}

void CarActor::mouseDown(MouseEvent* evt)
{
	
}

void CarActor::mouseUp(MouseEvent* evt)
{
	
}
