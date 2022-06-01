#pragma once

#include "Engine/Actor/Actor.h"
#include "Engine/Actor/ActorEvent.h"

#include "Engine/Core/Types.h"

#include "Engine/Mesh/DX12Mesh.h"
#include "Engine/Component/SceneComponent.h"
#include "Engine/Component/DX12MeshComponent.h"

#include "Engine/Shader/DX12Shader.h"

using Engine::WString;
using Engine::Actor;
using Engine::SceneComponent;
using Engine::DX12Mesh;
using Engine::DX12MeshComponent;
using Engine::ActorEvent;
using Engine::DX12Shader;

class MeshActor : public Actor
{
public:
	MeshActor(ActorDefaultParamDef, DX12Mesh* mesh = nullptr);

public:
	SceneComponent* getRoot();
	DX12MeshComponent* getMeshComponent();
	DX12Mesh* getMesh();

	void setMesh(DX12Mesh* mesh);

public:
	void initialize(ActorEvent* evt);
	void update(ActorEvent* evt);

	void loadFromAsset(const WString& assetFilePath);

private:
	SceneComponent* m_root;
	DX12MeshComponent* m_meshComponent;
	DX12Mesh* m_mesh;

	DX12Shader* m_shader;

	bool m_initialized = false;
};

