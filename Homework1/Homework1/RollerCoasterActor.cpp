#include "RollerCoasterActor.h"
#include "PlayerActor.h"

#include "Engine/Math.h"

#include "Engine/Engine.h"
#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"

#include "SplineCurveMesh.h"

#include <random>

using namespace Engine::Math;

bool compare(const Vector3& a, const Vector3& b)
{
	float ax = a.getX();
	float ay = a.getY();
	float az = a.getZ();

	float bx = b.getX();
	float by = b.getY();
	float bz = b.getZ();

	if (ax != bx)
	{
		return ax < bx;
	}
	else if (ay != by)
	{
		return ay < by;
	}

	return az < bz;
}

RollerCoasterActor::RollerCoasterActor(ActorDefaultParamDef, int pointCount) : LineMeshActor(ActorDefaultParams)
{
	m_pointCount = pointCount;

	Engine::Array<Vector3> curvePoints;
	for (int i = 0; i < m_pointCount; ++i)
	{
		curvePoints.push_back(Vector3(i * 1.0f, rand(-5.0f, 5.0f), rand(-5.0f, 5.0f)));
	}

	auto mesh = new SplineCurveMesh(curvePoints, 200);
	setMesh(mesh);

	addEventListener(
		Engine::ActorEventType::Load,
		Engine::ActorEventCallback(BindEventFunction(RollerCoasterActor::initialize)));

	addEventListener(
		Engine::ActorEventType::Update,
		Engine::ActorEventCallback(BindEventFunction(RollerCoasterActor::update)));
}

void RollerCoasterActor::initialize(Engine::ActorEvent* evt)
{
	auto root = getFirstComponentByTypeId(GetTypeId(Engine::SceneComponent));

	m_input = new Engine::InputComponent(this, "Input");
	root->addComponent(m_input);

	m_input->addKeyEventListener(
		Engine::SystemEventType::KeyDown,
		Engine::KeyEventCallback(BindEventFunction(RollerCoasterActor::keyDown)));

	m_player = new PlayerActor(nullptr, "Player");
	addChild(m_player);

	m_playerSceneRoot = dynamic_cast<Engine::SceneComponent*>(m_player->getFirstComponentByTypeId(GetTypeId(Engine::SceneComponent)));
}

void RollerCoasterActor::update(Engine::ActorEvent* evt)
{
	static float elapsedTime = 0.0f;
	auto playerTransform = m_playerSceneRoot->getRelativeTransform();

	int index = (int)(elapsedTime * 30.0f);

	auto mesh = getMesh();
	auto v1 = mesh->getVertex(max(min(index * 2, mesh->getVertexCount() - 1), 0));
	auto v2 = mesh->getVertex(max(min(index * 2 + 1, mesh->getVertexCount() - 1), 0));

	playerTransform.setTranslation((v1 + v2) / 2.0f);
	m_playerSceneRoot->setRelativeTransform(playerTransform);

	elapsedTime += Engine::Engine::getInstance()->getDeltaTime() * m_direction;
}

void RollerCoasterActor::keyDown(Engine::KeyEvent* evt)
{
	if (evt->getKeyCodeString() == "Space")
	{
		m_direction = -m_direction;
	}
}
