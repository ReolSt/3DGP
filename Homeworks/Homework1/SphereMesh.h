#pragma once

#include "Engine/LineMesh.h"

class SphereMesh : public Engine::LineMesh
{
public:
	SphereMesh(int rings = 16, int segments = 32);
};

