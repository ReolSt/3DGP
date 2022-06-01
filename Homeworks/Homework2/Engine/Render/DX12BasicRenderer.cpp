#include "Render/DX12BasicRenderer.h"

#include "GameEngine.h"
#include "World.h"
#include "Component/DX12BasicMeshComponent.h"
#include "Component/CameraComponent.h"

#include "DirectX/DX12Helpers.h"

#include "debug.h"

namespace Engine
{
    IDXGIFactory4* DX12BasicRenderer::getFactory()
    {
        return m_factory.Get();
    }

    ID3D12Device* DX12BasicRenderer::getDevice()
    {
        return m_device.Get();
    }

    ID3D12RootSignature* DX12BasicRenderer::getRootSignature()
    {
        return m_rootSignature.Get();
    }

    ID3D12CommandQueue* DX12BasicRenderer::getCommandQueue()
    {
        return m_commandQueue.Get();
    }

    ID3D12CommandAllocator* DX12BasicRenderer::getCommandAllocator()
    {
        return m_commandAllocator.Get();
    }

    ID3D12GraphicsCommandList* DX12BasicRenderer::getCommandList()
    {
        return m_commandList.Get();
    }
    void DX12BasicRenderer::initialize(HINSTANCE instance, HWND window)
    {
        m_instance = instance;
        m_window = window;

        GetClientRect(window, &m_rcClient);             

        createDevice();
        createFence();
        createRootSignature();
        createCommandQueue();
        createConstantBuffer();
        createRTVHeap();
        createDSVHeap();
        createCBVHeap();
        createSwapChain();
        createRenderTargetView();
        createDepthStencilView();

        waitForGPUComplete();
    }

    void DX12BasicRenderer::destroy()
    {

    }

    void DX12BasicRenderer::createDevice()
    {
        UINT dxgiFactoryFlags = 0;

#if defined(_DEBUG)
        // Enable the debug layer (requires the Graphics Tools "optional feature").
        // NOTE: Enabling the debug layer after device creation will invalidate the active device.
        {
            ComPtr<ID3D12Debug> debugController;
            if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
            {
                debugController->EnableDebugLayer();

                // Enable additional debug layers.
                dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
            }
        }
#endif

        VERIFY(SUCCEEDED(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory))));

        ComPtr<IDXGIAdapter1> hardwareAdapter;
        for (UINT i = 0; SUCCEEDED(m_factory->EnumAdapters1(i, &hardwareAdapter)); ++i)
        {
            DXGI_ADAPTER_DESC1 dxgiAdapterDesc;
            hardwareAdapter->GetDesc1(&dxgiAdapterDesc);

            if (dxgiAdapterDesc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;

            if (SUCCEEDED(D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_device)))) break;
        }

        if (!hardwareAdapter)
        {
            m_factory->EnumWarpAdapter(IID_PPV_ARGS(&hardwareAdapter));
            D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_device));
        }
    }

    void DX12BasicRenderer::createRootSignature()
    {
        D3D12_ROOT_PARAMETER rootParameters[2];

        rootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
        rootParameters[0].Descriptor.ShaderRegister = 1;
        rootParameters[0].Descriptor.RegisterSpace = 0;
        rootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

        rootParameters[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
        rootParameters[1].Descriptor.ShaderRegister = 2;
        rootParameters[1].Descriptor.RegisterSpace = 0;
        rootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

        D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc;
        ZeroMemory(&rootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
        rootSignatureDesc.NumParameters = _countof(rootParameters);
        rootSignatureDesc.pParameters = rootParameters;
        rootSignatureDesc.NumStaticSamplers = 0;
        rootSignatureDesc.pStaticSamplers = NULL;
        rootSignatureDesc.Flags =
            D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

        ComPtr<ID3DBlob> signatureBlob = NULL;
        ComPtr<ID3DBlob> errorBlob = NULL;
        D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signatureBlob, &errorBlob);

        if (errorBlob)
        {
            OutputDebugStringA((char*)errorBlob->GetBufferPointer());
        }

        m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(), signatureBlob->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature));
    }

    void DX12BasicRenderer::createCommandQueue()
    {
        // Describe and create the command queue.
        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        ZeroMemory(&queueDesc, sizeof(D3D12_COMMAND_QUEUE_DESC));
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

        VERIFY(SUCCEEDED(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue))));
        VERIFY(SUCCEEDED(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator))));
        VERIFY(SUCCEEDED(m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), NULL, IID_PPV_ARGS(&m_commandList))));
        m_commandList->Close();
    }

    void DX12BasicRenderer::createConstantBuffer()
    {
        UInt cameraBufferSize = ((sizeof(CameraConstantBuffer) + 255) & -255);
        m_cameraConstantBuffer = DirectX::CreateBufferResource(NULL, cameraBufferSize, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
        m_cameraConstantBuffer->Map(0, NULL, (void**)&m_mappedCameraBuffer);

        UInt objectBufferSize = ((sizeof(ObjectConstantBuffer) + 255) & -255);
        m_objectConstantBuffer = DirectX::CreateBufferResource(NULL, objectBufferSize, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
        m_objectConstantBuffer->Map(0, NULL, (void**)&m_mappedObjectBuffer);

    }

    void DX12BasicRenderer::createRTVHeap()
    {
        D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc;
        ZeroMemory(&descriptorHeapDesc, sizeof(D3D12_DESCRIPTOR_HEAP_DESC));
        descriptorHeapDesc.NumDescriptors = 2;
        descriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        descriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        descriptorHeapDesc.NodeMask = 0;
        m_device->CreateDescriptorHeap(&descriptorHeapDesc, IID_PPV_ARGS(&m_rtvHeap));
        m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);        
    }

    void DX12BasicRenderer::createDSVHeap()
    {
        auto renderer = DX12BasicRenderer::GetInstance();
        auto device = renderer->getDevice();

        D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc;
        ZeroMemory(&descriptorHeapDesc, sizeof(D3D12_DESCRIPTOR_HEAP_DESC));

        descriptorHeapDesc.NumDescriptors = 1;
        descriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
        descriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        descriptorHeapDesc.NodeMask = 0;

        device->CreateDescriptorHeap(&descriptorHeapDesc, IID_PPV_ARGS(&m_dsvHeap));
        m_dsvDescriptorSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
    }

    void DX12BasicRenderer::createCBVHeap()
    {
        D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc;
        ZeroMemory(&descriptorHeapDesc, sizeof(D3D12_DESCRIPTOR_HEAP_DESC));

        descriptorHeapDesc.NumDescriptors = 1;
        descriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        descriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        descriptorHeapDesc.NodeMask = 0;

        VERIFY(SUCCEEDED(m_device->CreateDescriptorHeap(&descriptorHeapDesc, IID_PPV_ARGS(&m_cbvHeap))));
        m_cbvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    }

    void DX12BasicRenderer::createSwapChain()
    {
        // Describe and create the swap chain.
        DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
        ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
        swapChainDesc.BufferCount = 2;
        swapChainDesc.BufferDesc.Width = m_rcClient.right - m_rcClient.left;
        swapChainDesc.BufferDesc.Height = m_rcClient.bottom - m_rcClient.top;
        swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
        swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.OutputWindow = m_window;
        swapChainDesc.SampleDesc.Count = 1;
        swapChainDesc.SampleDesc.Quality = 0;
        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainDesc.Windowed = TRUE;
        swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

        ComPtr<IDXGISwapChain> swapChain;

        VERIFY(SUCCEEDED(m_factory->CreateSwapChain(
            m_commandQueue.Get(),
            &swapChainDesc,
            (IDXGISwapChain**)&swapChain
        )));

        // This sample does not support fullscreen transitions.
        VERIFY(SUCCEEDED(m_factory->MakeWindowAssociation(m_window, DXGI_MWA_NO_ALT_ENTER)));

        VERIFY(SUCCEEDED(swapChain.As(&m_swapChain)));
        m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    }

    void DX12BasicRenderer::createRenderTargetView()
    {
        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = m_rtvHeap->GetCPUDescriptorHandleForHeapStart();

        for (int i = 0; i < 2; ++i)
        {
            VERIFY(SUCCEEDED(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]))));
            m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
            rtvHandle.ptr += m_rtvDescriptorSize;
        }
    }

    void DX12BasicRenderer::createDepthStencilView()
    {
        D3D12_RESOURCE_DESC resourceDesc;
        resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        resourceDesc.Alignment = 0;
        resourceDesc.Width = m_rcClient.right - m_rcClient.left;
        resourceDesc.Height = m_rcClient.bottom - m_rcClient.top;
        resourceDesc.DepthOrArraySize = 1;
        resourceDesc.MipLevels = 1;
        resourceDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        resourceDesc.SampleDesc.Count = 1;
        resourceDesc.SampleDesc.Quality = 0;
        resourceDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
		resourceDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

        D3D12_HEAP_PROPERTIES heapProperties;
        ZeroMemory(&heapProperties, sizeof(D3D12_HEAP_PROPERTIES));
        heapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;
        heapProperties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
        heapProperties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
        heapProperties.CreationNodeMask = 1;
        heapProperties.VisibleNodeMask = 1;

        D3D12_CLEAR_VALUE clearValue;
        clearValue.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        clearValue.DepthStencil.Depth = 1.0f;
        clearValue.DepthStencil.Stencil = 0;

        m_device->CreateCommittedResource(&heapProperties, D3D12_HEAP_FLAG_NONE, &resourceDesc, D3D12_RESOURCE_STATE_DEPTH_WRITE, &clearValue, IID_PPV_ARGS(&m_depthStencilBuffer));

        D3D12_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
        ZeroMemory(&depthStencilViewDesc, sizeof(D3D12_DEPTH_STENCIL_VIEW_DESC));
        depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        depthStencilViewDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
        depthStencilViewDesc.Flags = D3D12_DSV_FLAG_NONE;

        D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = m_dsvHeap->GetCPUDescriptorHandleForHeapStart();
        m_device->CreateDepthStencilView(m_depthStencilBuffer.Get(), &depthStencilViewDesc, cpuHandle);
    }

    void DX12BasicRenderer::createFence()
    {
        m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));

        m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_fenceEvent == nullptr)
        {
            VERIFY(SUCCEEDED(HRESULT_FROM_WIN32(GetLastError())));
        }
    }

    void DX12BasicRenderer::waitForGPUComplete()
    {
        const UINT64 fenceValue = ++m_fenceValues[m_frameIndex];
        m_commandQueue->Signal(m_fence.Get(), fenceValue);

        if (m_fence->GetCompletedValue() < fenceValue)
        {
            m_fence->SetEventOnCompletion(fenceValue, m_fenceEvent);
            ::WaitForSingleObject(m_fenceEvent, INFINITE);
        }
    }

    void DX12BasicRenderer::moveToNextFrame()
    {
        m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

        UINT64 nFenceValue = ++m_fenceValues[m_frameIndex];
        m_commandQueue->Signal(m_fence.Get(), nFenceValue);

        if (m_fence->GetCompletedValue() < nFenceValue)
        {
            m_fence->SetEventOnCompletion(nFenceValue, m_fenceEvent);
            ::WaitForSingleObject(m_fenceEvent, INFINITE);
        }
    }
   

    void DX12BasicRenderer::render(GameEngine* engine)
    {
        auto world = engine->getWorld();
        if (world == nullptr)
        {
            return;
        }

        Array<Component*> cameras;
        world->getRegisteredComponentsByTypeId(GetTypeId(CameraComponent), cameras);

        Array<Component*> meshes;
        world->getRegisteredComponentsByTypeId(GetTypeId(DX12BasicMeshComponent), meshes);

        for (auto& component : meshes)
        {
            if (!component->isActive())
            {
                continue;
            }

            auto meshComponent = dynamic_cast<DX12BasicMeshComponent*>(component);
            auto shader = meshComponent->getShader();

            if (shader == nullptr)
            {
                continue;
            }

            shader->initialize();
        }

        m_commandAllocator->Reset();
        m_commandList->Reset(m_commandAllocator.Get(), NULL);

        m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

        D3D12_RESOURCE_BARRIER resourceBarrier;
        ZeroMemory(&resourceBarrier, sizeof(D3D12_RESOURCE_BARRIER));
        resourceBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        resourceBarrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        resourceBarrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
        resourceBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        resourceBarrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        resourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        m_commandList->ResourceBarrier(1, &resourceBarrier);

        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = m_rtvHeap->GetCPUDescriptorHandleForHeapStart();
        rtvHandle.ptr += m_frameIndex * m_rtvDescriptorSize;

        D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = m_dsvHeap->GetCPUDescriptorHandleForHeapStart();

        const float backgroundColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        m_commandList->ClearRenderTargetView(rtvHandle, backgroundColor, 0, nullptr);
        m_commandList->ClearDepthStencilView(dsvHandle, D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, nullptr);

        m_commandList->OMSetRenderTargets(1, &rtvHandle, TRUE, &dsvHandle);

        m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        auto windowWidth = m_rcClient.right - m_rcClient.left;
        auto windowHeight = m_rcClient.bottom - m_rcClient.top;

        for (auto& component : cameras)
        {
            if (!component->isActive())
            {
                continue;
            }

            auto camera = dynamic_cast<CameraComponent*>(component);
            auto view = camera->getViewMatrix();
            auto projection = camera->getPerspectiveProjectionMatrix();
            auto cameraPosition = camera->getWorldTranslation();

            Viewport viewport = camera->getViewport();

            auto viewportX = viewport.getX();
            auto viewportY = viewport.getY();
            auto viewportWidth = viewport.getWidth();
            auto viewportHeight = viewport.getHeight();

            D3D12_VIEWPORT dxViewport;
            dxViewport.TopLeftX = viewportX * windowWidth;
            dxViewport.TopLeftY = viewportY * windowHeight;
            dxViewport.Width = viewportWidth * windowWidth;
            dxViewport.Height = viewportHeight * windowHeight;
            dxViewport.MinDepth = 0.0f;
            dxViewport.MaxDepth = 1.0f;

            D3D12_RECT dxRect;
            dxRect.left = dxViewport.TopLeftX;
            dxRect.right = dxRect.left + dxViewport.Width;
            dxRect.top = dxViewport.TopLeftY;
            dxRect.bottom = dxRect.top + dxViewport.Height;

            m_commandList->RSSetViewports(1, &dxViewport);
            m_commandList->RSSetScissorRects(1, &dxRect);

            memcpy(&m_mappedCameraBuffer->view, view.transpose().getDXMatrix(), sizeof(XMFLOAT4X4));
            memcpy(&m_mappedCameraBuffer->projection, projection.transpose().getDXMatrix(), sizeof(XMFLOAT4X4));
            memcpy(&m_mappedCameraBuffer->position, cameraPosition.getDXVector(), sizeof(XMFLOAT3));

            m_commandList->SetGraphicsRootConstantBufferView(0, m_cameraConstantBuffer->GetGPUVirtualAddress());            

            for (auto& component : meshes)
            {
                if (!component->isActive())
                {
                    continue;
                }

                auto meshComponent = dynamic_cast<DX12BasicMeshComponent*>(component);
                auto meshWorldTransform = meshComponent->getWorldTransform();

                auto mesh = meshComponent->getMesh();
                auto shader = meshComponent->getShader();

                if (mesh == nullptr)
                {
                    continue;
                }

                if (shader == nullptr)
                {
                    continue;
                }

                mesh->initialize();
                shader->initialize();

                memcpy(&m_mappedObjectBuffer->localToWorld, meshWorldTransform.toMatrix().transpose().getDXMatrix(), sizeof(XMFLOAT4X4));

                m_commandList->SetPipelineState(shader->getPipelineState());
                m_commandList->SetGraphicsRootConstantBufferView(1, m_objectConstantBuffer->GetGPUVirtualAddress());

                auto vertexBuffer = mesh->getVertexBuffer();
                auto vertexColorBuffer = mesh->getVertexColorBuffer();
                auto indexBuffer = mesh->getIndexBuffer();

                auto& vertexBufferView = mesh->getVertexBufferView();
                auto& vertexColorBufferView = mesh->getVertexColorBufferView();
                auto& indexBufferView = mesh->getIndexBufferView();

                m_commandList->IASetVertexBuffers(0, 1, &vertexBufferView);
                m_commandList->IASetVertexBuffers(1, 1, &vertexColorBufferView);
                m_commandList->IASetIndexBuffer(&indexBufferView);

                m_commandList->DrawIndexedInstanced(mesh->getIndexCount(), 1, 0, 0, 0);
            }
        }

        resourceBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        resourceBarrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        resourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        m_commandList->ResourceBarrier(1, &resourceBarrier);

        m_commandList->Close();

        ID3D12CommandList* commandLists[] = { m_commandList.Get()};
        m_commandQueue->ExecuteCommandLists(_countof(commandLists), commandLists);

        waitForGPUComplete();

        DXGI_PRESENT_PARAMETERS dxgiPresentParameters;
        dxgiPresentParameters.DirtyRectsCount = 0;
        dxgiPresentParameters.pDirtyRects = NULL;
        dxgiPresentParameters.pScrollRect = NULL;
        dxgiPresentParameters.pScrollOffset = NULL;
        m_swapChain->Present1(1, 0, &dxgiPresentParameters);

        moveToNextFrame();
    }
}