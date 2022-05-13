#include "CubeActor.h"

#include "Engine/Math.h"
#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"
#include "Engine/Engine.h"

#include "CubeMesh.h"

using namespace Engine::Math;

CubeActor::CubeActor(ActorDefaultParamDef) : LineMeshActor(ActorDefaultParams)
{
	setMesh(new CubeMesh());

	addEventListener(
		Engine::ActorEventType::Load,
		Engine::ActorEventCallback(BindEventFunction(CubeActor::initialize)));

	addEventListener(
		Engine::ActorEventType::Update,
		Engine::ActorEventCallback(BindEventFunction(CubeActor::update)));
}

void CubeActor::initialize(Engine::ActorEvent* evt)
{
	m_sceneRoot = dynamic_cast<Engine::SceneComponent*>(getFirstComponentByTypeId(GetTypeId(Engine::SceneComponent)));
}

void CubeActor::update(Engine::ActorEvent* evt)
{
	static float xAngle = 0.0f;
	static float yAngle = 0.0f;

	float deltaTime = Engine::Engine::getInstance()->getDeltaTime();
	float rotationSpeed = 1.0f * deltaTime;

	xAngle += rotationSpeed;
	yAngle += rotationSpeed;

	if (xAngle > degreeToRads(90.0f))
	{
		rotationSpeed = -0.01f;
	}

	if (yAngle > degreeToRads(-90.0f))
	{
		rotationSpeed = -0.01f;
	}

	auto transform = m_sceneRoot->getRelativeTransform();
	transform.setRotation(Quat(Rotator(xAngle, yAngle, 0.0f)));

	m_sceneRoot->setRelativeTransform(transform);
}