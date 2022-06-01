#include "ObserverActor.h"

#include "Engine/Math/Math.h"
#include "Engine/Render/Viewport.h"
#include "Engine/GameEngine.h"

using namespace Engine::Math;

ObserverActor::ObserverActor(ActorDefaultParamDef) : Actor(ActorDefaultParams)
{
	addEventListener(
		ActorEventType::Load,
		ActorEventCallback(BindEventFunction(ObserverActor::initialize)));

}

void ObserverActor::initialize(ActorEvent* evt)
{
	auto sceneRoot = getFirstComponentByTypeId(GetTypeId(SceneComponent));

	auto camera = new CameraComponent(this, "Camera");
	auto input = new InputComponent(this, "Input");

	sceneRoot->addComponent(camera);
	sceneRoot->addComponent(input);

	camera->setViewport(Viewport(0.0f, 0.0f, 1.0f, 1.0f));
	camera->setAspectRatio(1200.0f / 700.0f);

	auto cameraTransform = camera->getRelativeTransform();
	cameraTransform.setRotation(Quat(Rotator(0.0f, 0.0f, 0.0f)));

	camera->setRelativeTransform(cameraTransform);

	input->addMouseEventListener(
		SystemEventType::MouseMove,
		MouseEventCallback(BindEventFunction(ObserverActor::mouseMove)));

	input->addMouseEventListener(
		SystemEventType::MouseDown,
		MouseEventCallback(BindEventFunction(ObserverActor::mouseDown)));

	input->addMouseEventListener(
		SystemEventType::MouseUp,
		MouseEventCallback(BindEventFunction(ObserverActor::mouseUp)));

	input->addKeyEventListener(
		SystemEventType::KeyDown,
		KeyEventCallback(BindEventFunction(ObserverActor::keyDown)));

	addEventListener(
		ActorEventType::Update,
		ActorEventCallback(BindEventFunction(ObserverActor::update)));

	m_sceneRoot = dynamic_cast<SceneComponent*>(sceneRoot);
	m_camera = camera;
	m_input = input;
}

void ObserverActor::update(ActorEvent* evt)
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

void ObserverActor::keyDown(KeyEvent* evt)
{
}

void ObserverActor::keyUp(KeyEvent* evt)
{
}

void ObserverActor::mouseMove(MouseEvent* evt)
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
		cameraTransform.setRotation(Quat(Rotator(xAngle, yAngle, 0.0f)).normalize());

		m_camera->setRelativeTransform(cameraTransform);

		auto forward = m_camera->getRelativeRotation().getForwardVector();
	}

	px = x;
	py = y;
}

void ObserverActor::mouseDown(MouseEvent* evt)
{
	for (const auto& button : evt->getButtons())
	{
		if (button == Engine::KeyCode::LeftMouseButton)
		{
			m_isDragging = true;
		}
	}
}

void ObserverActor::mouseUp(MouseEvent* evt)
{
	m_isDragging = false;
}
