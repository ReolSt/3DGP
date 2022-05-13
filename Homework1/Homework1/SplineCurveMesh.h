#pragma once

#include "Engine/LineMesh.h"
#include "Engine/Math.h"

class SplineCurveMesh : public Engine::LineMesh
{ 
public:
	SplineCurveMesh(const Engine::Array<Engine::Math::Vector3>& points, int iteration = 10);
};

