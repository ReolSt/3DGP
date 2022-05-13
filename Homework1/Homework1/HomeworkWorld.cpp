#include "HomeworkWorld.h"

#include "LineMeshActor.h"
#include "PlayerActor.h"
#include "PlaneActor.h"
#include "CubeActor.h"
#include "SphereActor.h"
#include "RollerCoasterActor.h"

#include "CircleMesh.h"
#include "SinCurveMesh.h"

using namespace Engine;

HomeworkWorld::HomeworkWorld() : World()
{
	auto player = new PlayerActor(nullptr, "Player");
	auto plane = new PlaneActor(nullptr, "Plane");
	auto circle = new LineMeshActor(nullptr, "Circle", new CircleMesh());
	auto cube = new CubeActor(nullptr, "Cube");
	auto sinCurve = new LineMeshActor(nullptr, "Circle", new SinCurveMesh(-Math::PI * 5, Math::PI * 5));	
	auto sphere = new SphereActor(nullptr, "Sphere");
	
	auto rollerCoaster = new RollerCoasterActor(nullptr, "RollerCoaster", 30);

	addActor(cube);
	addActor(sphere);
	addActor(rollerCoaster);

	auto root = dynamic_cast<SceneComponent*>(sinCurve->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
	auto transform = root->getRelativeTransform();
	transform.translate(-25.0f, 5.0f, -25.0f);
	transform.setScale(Math::Vector3(1.0f, 5.0f, 1.0f));
	root->setRelativeTransform(transform);

	root = dynamic_cast<SceneComponent*>(circle->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
	transform = root->getRelativeTransform();
	transform.translate(3.0f, 2.0f, 5.0f);
	root->setRelativeTransform(transform);

	root = dynamic_cast<SceneComponent*>(sphere->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
	transform = root->getRelativeTransform();
	transform.translate(3.0f, 2.0f, -4.0f);
	transform.setScale(Math::Vector3(5.0f, 5.0f, 5.0f));
	root->setRelativeTransform(transform);

	root = dynamic_cast<SceneComponent*>(rollerCoaster ->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
	transform = root->getRelativeTransform();
	transform.setScale(Math::Vector3(3.0f, 3.0f, 3.0f));
	root->setRelativeTransform(transform);

	root = dynamic_cast<SceneComponent*>(cube->getFirstComponentByTypeId(GetTypeId(SceneComponent)));
	transform = root->getRelativeTransform();
	transform.translate(Math::Vector3(1.0f, 1.0f, 1.0f));	
	root->setRelativeTransform(transform);
}
