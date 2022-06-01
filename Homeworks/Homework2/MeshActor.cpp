#include "MeshActor.h"

#include "Engine/Core/Types.h"

#include "Engine/System/SystemEvent.h"

#include "Engine/Asset/AssetStorage.h"
#include "Engine/Asset/MeshAsset.h"
#include "Engine/Asset/DX12VertexShaderAsset.h"
#include "Engine/Asset/DX12PixelShaderAsset.h"

#include "Engine/Shader/DX12Shader.h"
#include "Engine/Shader/DX12ShaderInputLayout.h"

#include <string>

using namespace Engine;
using namespace Engine::Math;

MeshActor::MeshActor(ActorDefaultParamDef, DX12Mesh* mesh) : Actor(ActorDefaultParams)
{
	m_mesh = mesh;

	addEventListener(
		ActorEventType::Load,
		ActorEventCallback(BindEventFunction(MeshActor::initialize))
	);

	addEventListener(
		ActorEventType::Update,
		ActorEventCallback(BindEventFunction(MeshActor::update))
	);
}

SceneComponent* MeshActor::getRoot()
{
	return m_root;
}

DX12MeshComponent* MeshActor::getMeshComponent()
{
	return m_meshComponent;
}

DX12Mesh* MeshActor::getMesh()
{
	return m_mesh;
}

void MeshActor::setMesh(DX12Mesh* mesh)
{
	m_mesh = mesh;
}

void MeshActor::initialize(ActorEvent* evt)
{
	if (m_initialized)
	{
		return;
	}

	m_root = dynamic_cast<SceneComponent*>(getFirstComponentByTypeId(GetTypeId(SceneComponent)));

	m_meshComponent = new DX12MeshComponent(this, "Mesh", m_mesh);
	m_root->addComponent(m_meshComponent);

	DX12VertexShaderAsset* vertexShaderAsset = DX12VertexShaderAsset::Load(L"Assets\\VertexShader.hlsl");
	DX12PixelShaderAsset* pixelShaderAsset = DX12PixelShaderAsset::Load(L"Assets\\PixelShader.hlsl");

	m_shader = new DX12Shader();
	m_shader->setVertexShaderAsset(vertexShaderAsset);
	m_shader->setPixelShaderAsset(pixelShaderAsset);

	m_meshComponent->setShader(m_shader);

	DX12ShaderInputLayout* shaderInputLayout = new DX12ShaderInputLayout();
	Array<DX12ShaderInputElement> shaderInputElements;

	shaderInputElements.push_back({
		0,
		0,
		"POSITION",
		DX12ShaderInputElementType::Vector3
	});

	shaderInputElements.push_back({
		1,
		0,
		"NORMAL",
		DX12ShaderInputElementType::Vector3
	});

	shaderInputElements.push_back({
		2,
		0,
		"UV",
		DX12ShaderInputElementType::Vector2
	});

	shaderInputLayout->setInputElements(shaderInputElements);
	m_shader->setShaderInputLayout(shaderInputLayout);

	m_initialized = true;
}

void MeshActor::update(ActorEvent* evt)
{

}

void MeshActor::loadFromAsset(const WString& assetFilePath)
{
	auto mesh = new DX12Mesh();
	auto meshAsset = MeshAsset::Load(assetFilePath);

	auto vertices = meshAsset->getVertices();
	auto normals = meshAsset->getNormals();
	auto uvs = meshAsset->getUVs();
	auto indices = meshAsset->getIndices();

	mesh->setVertexData(vertices);
	mesh->setNormalData(normals);
	mesh->setUVData(uvs);
	mesh->setIndices(indices);

	setMesh(mesh);
	getMeshComponent()->setMesh(mesh);
}
