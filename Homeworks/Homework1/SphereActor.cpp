#include "SphereActor.h"
#include "SphereMesh.h"

using namespace Engine;

SphereActor::SphereActor(ActorDefaultParamDef) : LineMeshActor(ActorDefaultParams)
{
	setMesh(new SphereMesh());
}
