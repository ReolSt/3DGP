#include "DX12VertexShaderAsset.h"

#include "debug.h"

using Microsoft::WRL::ComPtr;

namespace Engine
{
	DX12VertexShaderAsset::DX12VertexShaderAsset()
	{
		m_bytecode.BytecodeLength = 0;
		m_bytecode.pShaderBytecode = NULL;
	}

	DX12VertexShaderAsset::~DX12VertexShaderAsset()
	{

	}

	D3D12_SHADER_BYTECODE DX12VertexShaderAsset::getBytecode()
	{
		return m_bytecode;
	}

	void DX12VertexShaderAsset::load(const WString& assetFilePath)
	{
		DX12ShaderAsset::load(assetFilePath);

		ID3DBlob* shaderBlob;
		ComPtr<ID3DBlob> errorBlob;

#if defined(_DEBUG)
		// Enable better shader debugging with the graphics debugging tools.
		UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
		UINT compileFlags = 0;
#endif

		D3DCompileFromFile(assetFilePath.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "vs_5_0", compileFlags, 0, &shaderBlob, &errorBlob);
		
		if (errorBlob)
		{
			char* errorString = (char*)errorBlob->GetBufferPointer();
			OutputDebugStringA(errorString);
		}

		m_bytecode.BytecodeLength = shaderBlob->GetBufferSize();
		m_bytecode.pShaderBytecode = shaderBlob->GetBufferPointer();
	}

	void DX12VertexShaderAsset::unload()
	{
		DX12ShaderAsset::unload();
	}
}
