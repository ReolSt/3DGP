#include "DirectX/DX12Helpers.h"
#include "Render/DX12Renderer.h"

namespace Engine
{
	namespace DirectX
	{
		ID3D12Resource* CreateBufferResource(void* data, UINT nBytes, D3D12_HEAP_TYPE heapType, D3D12_RESOURCE_STATES resourceStates, ID3D12Resource** uploadBuffer)
		{
			auto renderer = DX12Renderer::GetInstance();
			auto device = renderer->getDevice();
			auto commandList = renderer->getCommandList();

			ID3D12Resource* buffer = NULL;

			D3D12_HEAP_PROPERTIES heapPropertiesDesc;
			ZeroMemory(&heapPropertiesDesc, sizeof(D3D12_HEAP_PROPERTIES));
			heapPropertiesDesc.Type = heapType;
			heapPropertiesDesc.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
			heapPropertiesDesc.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
			heapPropertiesDesc.CreationNodeMask = 1;
			heapPropertiesDesc.VisibleNodeMask = 1;

			D3D12_RESOURCE_DESC resourceDesc;
			ZeroMemory(&resourceDesc, sizeof(D3D12_RESOURCE_DESC));
			resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
			resourceDesc.Alignment = 0;
			resourceDesc.Width = nBytes;
			resourceDesc.Height = 1;
			resourceDesc.DepthOrArraySize = 1;
			resourceDesc.MipLevels = 1;
			resourceDesc.Format = DXGI_FORMAT_UNKNOWN;
			resourceDesc.SampleDesc.Count = 1;
			resourceDesc.SampleDesc.Quality = 0;
			resourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
			resourceDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

			D3D12_RESOURCE_STATES resourceInitialStates = D3D12_RESOURCE_STATE_COPY_DEST;
			if (heapType == D3D12_HEAP_TYPE_UPLOAD) resourceInitialStates = D3D12_RESOURCE_STATE_GENERIC_READ;
			else if (heapType == D3D12_HEAP_TYPE_READBACK) resourceInitialStates = D3D12_RESOURCE_STATE_COPY_DEST;

			HRESULT hResult = device->CreateCommittedResource(&heapPropertiesDesc, D3D12_HEAP_FLAG_NONE, &resourceDesc, resourceInitialStates, NULL, IID_PPV_ARGS(&buffer));

			if (data)
			{
				switch (heapType)
				{
				case D3D12_HEAP_TYPE_DEFAULT:
				{
					if (uploadBuffer)
					{
						heapPropertiesDesc.Type = D3D12_HEAP_TYPE_UPLOAD;
						device->CreateCommittedResource(&heapPropertiesDesc, D3D12_HEAP_FLAG_NONE, &resourceDesc, D3D12_RESOURCE_STATE_GENERIC_READ, NULL, IID_PPV_ARGS(uploadBuffer));

						D3D12_RANGE readRange = { 0, 0 };
						UINT8* bufferDataBegin = NULL;
						(*uploadBuffer)->Map(0, &readRange, (void**)&bufferDataBegin);
						memcpy(bufferDataBegin, data, nBytes);
						(*uploadBuffer)->Unmap(0, NULL);

						commandList->CopyResource(buffer, *uploadBuffer);

						D3D12_RESOURCE_BARRIER resourceBarrier;
						ZeroMemory(&resourceBarrier, sizeof(D3D12_RESOURCE_BARRIER));
						resourceBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
						resourceBarrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
						resourceBarrier.Transition.pResource = buffer;
						resourceBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
						resourceBarrier.Transition.StateAfter = resourceStates;
						resourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

						commandList->ResourceBarrier(1, &resourceBarrier);
					}

					break;
				}
				case D3D12_HEAP_TYPE_UPLOAD:
				{
					D3D12_RANGE readRange = { 0, 0 };
					UINT8* bufferDataBegin = NULL;
					buffer->Map(0, &readRange, (void**)&bufferDataBegin);
					memcpy(bufferDataBegin, data, nBytes);
					buffer->Unmap(0, NULL);

					break;
				}
				case D3D12_HEAP_TYPE_READBACK:
					break;
				}
			}

			return buffer;
		}
	}
}