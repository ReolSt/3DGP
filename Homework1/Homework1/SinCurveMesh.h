#pragma once

#include "Engine/LineMesh.h"

class SinCurveMesh : public Engine::LineMesh
{
public:
	SinCurveMesh(float left, float right, float dx=0.1f);
};

