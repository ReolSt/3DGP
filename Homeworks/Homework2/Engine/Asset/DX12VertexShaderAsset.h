#pragma once

#include "Asset/DX12ShaderAsset.h"

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <wrl.h>

namespace Engine
{
	class DX12VertexShaderAsset : public DX12ShaderAsset
	{
		AssetDefaultMacro(DX12VertexShaderAsset)

	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12VertexShaderAsset();
		virtual ~DX12VertexShaderAsset();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		D3D12_SHADER_BYTECODE getBytecode();

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void load(const WString& assetFilePath) override;
		void unload() override;

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		D3D12_SHADER_BYTECODE m_bytecode;
	};
}

