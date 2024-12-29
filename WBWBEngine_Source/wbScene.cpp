#include "wbScene.h"
#include "wbGameObject.h"

namespace wb
{
	Scene::Scene()
		: mGameObjects{}
		, mName{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* obj)
	{
		mGameObjects.push_back(obj);
	}
}