#include "wbScene.h"
#include "wbGameObject.h"
#include "wbApplication.h"

namespace wb
{

	Scene::Scene()
		: mLayers{}
	{
		createLayers();
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* obj, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(obj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)eLayerType::Max);
		for (UINT i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
}