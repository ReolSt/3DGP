#pragma once

#include "Core/ObjectBase.h"

#include <d3d12.h>

namespace Engine
{
	enum struct DX12ShaderInputElementType
	{
		Int = DXGI_FORMAT_R32_SINT,
		UInt = DXGI_FORMAT_R32_UINT,
		Float = DXGI_FORMAT_R32_FLOAT,
		Vector2 = DXGI_FORMAT_R32G32_FLOAT,
		Vector3 = DXGI_FORMAT_R32G32B32_FLOAT,
		Vector4 = DXGI_FORMAT_R32G32B32A32_FLOAT
	};

	struct DX12ShaderInputElement
	{
		UInt index;
		UInt offset;
		String name;
		DX12ShaderInputElementType type;
	};

	class DX12ShaderInputLayout : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		DX12ShaderInputLayout();
		~DX12ShaderInputLayout();

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		DX12ShaderInputElement getInputElement(Int index);
		Array<DX12ShaderInputElement>& getInputElements();
		UInt getInputElementCount();
		D3D12_INPUT_LAYOUT_DESC getDXLayout();

		void setInputElement(Int index, const DX12ShaderInputElement& inputElement);
		void setInputElements(const Array<DX12ShaderInputElement>& inputElements);

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void addInputElement(const DX12ShaderInputElement& inputElement);
		void removeInputElement(const DX12ShaderInputElement& inputElement);
		void removeInputElement(const String& name);

		void update();

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		D3D12_INPUT_LAYOUT_DESC m_layoutDesc;
		D3D12_INPUT_ELEMENT_DESC* m_dxInputElements = nullptr;

		Array<DX12ShaderInputElement> m_inputElements;
	};
}


