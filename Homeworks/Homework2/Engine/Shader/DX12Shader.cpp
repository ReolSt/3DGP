#include "DX12Shader.h"

#include "Render/DX12Renderer.h"
#include "Asset/DX12VertexShaderAsset.h"
#include "Asset/DX12PixelShaderAsset.h"

#include "debug.h"

namespace Engine
{
	DX12Shader::DX12Shader()
	{

	}

	DX12Shader::~DX12Shader()
	{

	}

	DX12VertexShaderAsset* DX12Shader::getVertexShaderAsset()
	{
		return m_vertexShaderAsset;
	}

	DX12PixelShaderAsset* DX12Shader::getPixelShaderAsset()
	{
		return m_pixelShaderAsset;
	}

	DX12ShaderInputLayout* DX12Shader::getShaderInputLayout()
	{
		return m_layout;
	}

	ID3D12PipelineState* DX12Shader::getPipelineState()
	{
		return m_pipelineState.Get();
	}

	void DX12Shader::setVertexShaderAsset(DX12VertexShaderAsset* vertexShaderAsset)
	{
		m_vertexShaderAsset = vertexShaderAsset;
	}

	void DX12Shader::setPixelShaderAsset(DX12PixelShaderAsset* pixelShaderAsset)
	{
		m_pixelShaderAsset = pixelShaderAsset;
	}

	void DX12Shader::setShaderInputLayout(DX12ShaderInputLayout* layout)
	{
		m_layout = layout;
	}

	void DX12Shader::createRasterizerState()
	{
		ZeroMemory(&m_rasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));

		//	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_WIREFRAME;
		m_rasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
		m_rasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
		m_rasterizerDesc.FrontCounterClockwise = FALSE;
		m_rasterizerDesc.DepthBias = 0;
		m_rasterizerDesc.DepthBiasClamp = 0.0f;
		m_rasterizerDesc.SlopeScaledDepthBias = 0.0f;
		m_rasterizerDesc.DepthClipEnable = TRUE;
		m_rasterizerDesc.MultisampleEnable = FALSE;
		m_rasterizerDesc.AntialiasedLineEnable = FALSE;
		m_rasterizerDesc.ForcedSampleCount = 0;
		m_rasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
	}

	void DX12Shader::createBlendState()
	{
		ZeroMemory(&m_blendDesc, sizeof(D3D12_BLEND_DESC));

		m_blendDesc.AlphaToCoverageEnable = FALSE;
		m_blendDesc.IndependentBlendEnable = FALSE;
		m_blendDesc.RenderTarget[0].BlendEnable = FALSE;
		m_blendDesc.RenderTarget[0].LogicOpEnable = FALSE;
		m_blendDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_ONE;
		m_blendDesc.RenderTarget[0].DestBlend = D3D12_BLEND_ZERO;
		m_blendDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
		m_blendDesc.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_ONE;
		m_blendDesc.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_ZERO;
		m_blendDesc.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
		m_blendDesc.RenderTarget[0].LogicOp = D3D12_LOGIC_OP_NOOP;
		m_blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	}

	void DX12Shader::createDepthStencilState()
	{
		::ZeroMemory(&m_depthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));

		m_depthStencilDesc.DepthEnable = TRUE;
		m_depthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
		m_depthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
		m_depthStencilDesc.StencilEnable = FALSE;
		m_depthStencilDesc.StencilReadMask = 0x00;
		m_depthStencilDesc.StencilWriteMask = 0x00;
		m_depthStencilDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
		m_depthStencilDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
		m_depthStencilDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	}

	void DX12Shader::createPipelineState()
	{
		auto renderer = DX12Renderer::GetInstance();
		auto device = renderer->getDevice();
		auto rootSignature = renderer->getRootSignature();

 		D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
		ZeroMemory(&psoDesc, sizeof(D3D12_GRAPHICS_PIPELINE_STATE_DESC));
		psoDesc.InputLayout = m_layout->getDXLayout();
		psoDesc.pRootSignature = rootSignature;
		psoDesc.VS = CD3DX12_SHADER_BYTECODE(m_vertexShaderAsset->getBytecode());
		psoDesc.PS = CD3DX12_SHADER_BYTECODE(m_pixelShaderAsset->getBytecode());
		psoDesc.RasterizerState = m_rasterizerDesc;
		psoDesc.BlendState = m_blendDesc;
		psoDesc.DepthStencilState = m_depthStencilDesc;
		psoDesc.SampleMask = UINT_MAX;
		psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
		psoDesc.NumRenderTargets = 1;
		psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
		psoDesc.DSVFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
		psoDesc.SampleDesc.Count = 1;
		psoDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

		VERIFY(SUCCEEDED(device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState))));

	}
	void DX12Shader::initialize()
	{
		VERIFY(m_vertexShaderAsset != nullptr && m_pixelShaderAsset != nullptr);

		if (!m_isInitialized)
		{
			createRasterizerState();
			createBlendState();
			createDepthStencilState();
			createPipelineState();

			m_isInitialized = true;
		}		
	}
}