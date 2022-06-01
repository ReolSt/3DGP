#pragma once

#include "DirectX/d3dx12.h"

namespace Engine
{
	namespace DirectX
	{
		ID3D12Resource* CreateBufferResource(void* data, UINT nBytes, D3D12_HEAP_TYPE heapType, D3D12_RESOURCE_STATES resourceStates, ID3D12Resource** uploadBuffer);
	}	
}