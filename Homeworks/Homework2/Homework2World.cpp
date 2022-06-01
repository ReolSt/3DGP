#include "Homework2World.h"

#include "Component/CameraComponent.h"

#include "MeshActor.h"
#include "CarActor.h"
#include "ObserverActor.h"

#include "SphereMesh.h"

using namespace Engine;

Homework2World::Homework2World()
{
	
	auto car = new CarActor(this, "Car");
	addActor(car);

	auto course = new MeshActor(this, "Course", nullptr);
	addActor(course);	

	course->loadFromAsset(L"Assets\\Course.obj");
}

Homework2World::~Homework2World()
{

}
