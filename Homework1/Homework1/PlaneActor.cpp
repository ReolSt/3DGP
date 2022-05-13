#include "PlaneActor.h"

#include "Engine/Math.h"
#include "Engine/ActorEvent.h"
#include "Engine/SystemEvent.h"

#include "Engine/LineMeshComponent.h"

#include "PlaneMesh.h"

using namespace Engine;

PlaneActor::PlaneActor(ActorDefaultParamDef) : LineMeshActor(ActorDefaultParams)
{
	setMesh(new PlaneMesh());
}
