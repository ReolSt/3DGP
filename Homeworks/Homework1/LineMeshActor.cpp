#include "LineMeshActor.h"

LineMeshActor::LineMeshActor(ActorDefaultParamDef, Engine::LineMesh* mesh) : Engine::Actor(ActorDefaultParams)
{
	setMesh(mesh);

	addEventListener(
		Engine::ActorEventType::Load,
		Engine::ActorEventCallback(BindEventFunction(LineMeshActor::initialize)));
}

void LineMeshActor::initialize(Engine::ActorEvent* evt)
{
	m_root = dynamic_cast<Engine::SceneComponent*>(getFirstComponentByTypeId(GetTypeId(Engine::SceneComponent)));

	m_meshComponent = new Engine::LineMeshComponent(this, "Mesh", m_mesh);
	m_root->addComponent(m_meshComponent);
}

Engine::LineMesh* LineMeshActor::getMesh()
{
	return m_mesh;
}

void LineMeshActor::setMesh(Engine::LineMesh* mesh)
{
	m_mesh = mesh;
}
