#pragma once
#include "wbComponent.h"
#include "wbGameObject.h"
#include "wbLayer.h"
#include "wbScene.h"
#include "wbSceneManager.h"
#include "wbTransform.h"

namespace wb
{
	template<typename T>
	static T* Instantiate(wb::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
	
		return gameObject;
	}

	template<typename T>
	static T* Instantiate(wb::eLayerType type,wb::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		gameObject->Death();
	}
}