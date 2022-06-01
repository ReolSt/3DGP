#pragma once

#include "Core/ObjectBase.h"
#include "Shader/DX12ShaderInputLayout.h"

#include <windows.h>
#include <d3d12.h>
#include <D3Dcompiler.h>
#include <wrl.h>

namespace Engine
{
	class DX12VertexShaderAsset;
	class DX12PixelShaderAsset;

	using Microsoft::WRL::ComPtr;

	class DX12Shader : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12Shader();
		~DX12Shader();

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		DX12VertexShaderAsset* getVertexShaderAsset();
		DX12PixelShaderAsset* getPixelShaderAsset();
		DX12ShaderInputLayout* getShaderInputLayout();
		ID3D12PipelineState* getPipelineState();

		void setVertexShaderAsset(DX12VertexShaderAsset* vertexShaderAsset);
		void setPixelShaderAsset(DX12PixelShaderAsset* pixelShaderAsset);
		void setShaderInputLayout(DX12ShaderInputLayout* layout);

		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void initialize();

	protected:
		// ----------------------------------------------------------------------
		// Protected Member Method
		// ----------------------------------------------------------------------

		void createRasterizerState();
		void createBlendState();
		void createDepthStencilState();
		void createPipelineState();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		DX12VertexShaderAsset* m_vertexShaderAsset;
		DX12PixelShaderAsset* m_pixelShaderAsset;
		DX12ShaderInputLayout* m_layout;

		D3D12_RASTERIZER_DESC m_rasterizerDesc;
		D3D12_BLEND_DESC m_blendDesc;
		D3D12_DEPTH_STENCIL_DESC m_depthStencilDesc;
		
		ComPtr<ID3D12PipelineState> m_pipelineState;

		bool m_isInitialized = false;
	};
}


