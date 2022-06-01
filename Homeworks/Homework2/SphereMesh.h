#pragma once

#include "Engine/Mesh/DX12Mesh.h"

class SphereMesh : public Engine::DX12Mesh
{
public:
	SphereMesh(int rings = 16, int segments = 32);
};


