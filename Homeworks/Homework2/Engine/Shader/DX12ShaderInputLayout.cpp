#include "Shader/DX12ShaderInputLayout.h"

namespace Engine
{
	DX12ShaderInputLayout::DX12ShaderInputLayout()
	{

	}

	DX12ShaderInputLayout::~DX12ShaderInputLayout()
	{

	}

	DX12ShaderInputElement DX12ShaderInputLayout::getInputElement(Int index)
	{
		return m_inputElements.at(index);
	}

	Array<DX12ShaderInputElement>& DX12ShaderInputLayout::getInputElements()
	{
		return m_inputElements;
	}

	UInt DX12ShaderInputLayout::getInputElementCount()
	{
		return m_inputElements.size();
	}

	D3D12_INPUT_LAYOUT_DESC DX12ShaderInputLayout::getDXLayout()
	{
		return m_layoutDesc;
	}

	void DX12ShaderInputLayout::setInputElement(Int index, const DX12ShaderInputElement& inputElement)
	{
		m_inputElements[index] = inputElement;
	}

	void DX12ShaderInputLayout::setInputElements(const Array<DX12ShaderInputElement>& inputElements)
	{
		m_inputElements = inputElements;
		update();
	}

	void DX12ShaderInputLayout::addInputElement(const DX12ShaderInputElement& inputElement)
	{
		m_inputElements.push_back(inputElement);
		update();
	}

	void DX12ShaderInputLayout::removeInputElement(const DX12ShaderInputElement& inputElement)
	{
		removeInputElement(inputElement.name);
		update();
	}

	void DX12ShaderInputLayout::removeInputElement(const String& name)
	{
		for (auto itr = m_inputElements.begin(); itr != m_inputElements.end(); ++itr)
		{
			if (itr->name == name)
			{
				m_inputElements.erase(itr);
				break;
			}
		}

		update();
	}

	void DX12ShaderInputLayout::update()
	{
		if (m_dxInputElements != nullptr)
		{
			delete m_dxInputElements;
		}
		
		m_dxInputElements = new D3D12_INPUT_ELEMENT_DESC[m_inputElements.size()];
		for (UInt i = 0; i < m_inputElements.size(); ++i)
		{
			m_dxInputElements[i].SemanticName = m_inputElements[i].name.c_str();
			m_dxInputElements[i].SemanticIndex = (UINT)0;
			m_dxInputElements[i].Format = (DXGI_FORMAT)m_inputElements[i].type;
			m_dxInputElements[i].InputSlot = m_inputElements[i].index;;
			m_dxInputElements[i].AlignedByteOffset = m_inputElements[i].offset;
			m_dxInputElements[i].InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
			m_dxInputElements[i].InstanceDataStepRate = 0;
		}

		m_layoutDesc.NumElements = m_inputElements.size();
		m_layoutDesc.pInputElementDescs = m_dxInputElements;
	}
}