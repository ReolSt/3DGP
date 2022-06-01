#pragma once

#include "Renderer.h"

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <wrl.h>

#include "Core/Singleton.h"
#include "Math/Math.h"
#include "DirectX/d3dx12.h"

namespace Engine
{
	using Microsoft::WRL::ComPtr;

	class DX12BasicRenderer : public Renderer, public Singleton<DX12BasicRenderer>
	{
	private:
		// ----------------------------------------------------------------------
		// Private Inner Struct / Class Definition
		// ----------------------------------------------------------------------
		struct CameraConstantBuffer
		{
			XMFLOAT4X4 view;
			XMFLOAT4X4 projection;
			XMFLOAT3 position;
		};

		struct ObjectConstantBuffer
		{
			XMFLOAT4X4 localToWorld;
		};

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		IDXGIFactory4* getFactory();
		ID3D12Device* getDevice();
		ID3D12RootSignature* getRootSignature();
		ID3D12CommandQueue* getCommandQueue();
		ID3D12CommandAllocator* getCommandAllocator();
		ID3D12GraphicsCommandList* getCommandList();

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void initialize(HINSTANCE instance, HWND window);
		void destroy();
		void render(GameEngine* engine) override;

	protected:
		// ----------------------------------------------------------------------
		// Protected Member Method
		// ----------------------------------------------------------------------

		void createDevice();
		void createRootSignature();
		void createCommandQueue();		

		void createConstantBuffer();
		void createRTVHeap();
		void createDSVHeap();
		void createCBVHeap();
		void createSwapChain();
		void createRenderTargetView();
		void createDepthStencilView();
		void createFence();

		void waitForGPUComplete();
		void moveToNextFrame();
		
	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		HINSTANCE m_instance;
		HWND m_window;

		RECT m_rcClient;

		ComPtr<IDXGIFactory4> m_factory = NULL;
		ComPtr<ID3D12Device> m_device = NULL;
		ComPtr<ID3D12RootSignature> m_rootSignature = NULL;
		ComPtr<ID3D12CommandAllocator> m_commandAllocator = NULL;
		ComPtr<ID3D12CommandQueue> m_commandQueue = NULL;
		ComPtr<ID3D12GraphicsCommandList> m_commandList = NULL;

		ComPtr<IDXGISwapChain3> m_swapChain = NULL;
		ComPtr<ID3D12Resource> m_renderTargets[2] = { NULL, NULL };
		ComPtr<ID3D12DescriptorHeap> m_rtvHeap = NULL;
		ComPtr<ID3D12DescriptorHeap> m_dsvHeap = NULL;
		ComPtr<ID3D12DescriptorHeap> m_cbvHeap = NULL;
		ComPtr<ID3D12PipelineState> m_pipelineState = NULL;

		UINT m_rtvDescriptorSize = 0;
		UINT m_dsvDescriptorSize = 0;
		UINT m_cbvDescriptorSize = 0;

		ComPtr<ID3D12Resource> m_depthStencilBuffer = NULL;
		ComPtr<ID3D12Resource> m_cameraConstantBuffer = NULL;
		ComPtr<ID3D12Resource> m_objectConstantBuffer = NULL;

		CameraConstantBuffer* m_mappedCameraBuffer;
		ObjectConstantBuffer* m_mappedObjectBuffer;

		// Synchronization objects.
		UINT m_frameIndex = 0;
		HANDLE m_fenceEvent = NULL;
		ComPtr<ID3D12Fence> m_fence = NULL;
		UINT64 m_fenceValues[2] = { 0, 0 };
	};
}

