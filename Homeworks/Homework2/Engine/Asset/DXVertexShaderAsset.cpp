#include "DXVertexShaderAsset.h"

#include "DirectX/d3dx12.h"

#include <cassert>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;

namespace Engine
{
	DXVertexShaderAsset::DXVertexShaderAsset()
	{

	}

	DXVertexShaderAsset::~DXVertexShaderAsset()
	{

	}

	void DXVertexShaderAsset::load(const WString& assetFilePath)
	{
		ComPtr<ID3DBlob> shaderBlob;

#if defined(_DEBUG)
		// Enable better shader debugging with the graphics debugging tools.
		UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
		UINT compileFlags = 0;
#endif

		assert(SUCCEEDED(D3DCompileFromFile(assetFilePath.c_str(), nullptr, nullptr, "VSMain", "vs_5_0", compileFlags, 0, &shaderBlob, nullptr)));

		D3D12_SHADER_BYTECODE d3dShaderByteCode;
		d3dShaderByteCode.BytecodeLength = shaderBlob->GetBufferSize();
		d3dShaderByteCode.pShaderBytecode = shaderBlob->GetBufferPointer();
	}

	void DXVertexShaderAsset::unload()
	{

	}
}
