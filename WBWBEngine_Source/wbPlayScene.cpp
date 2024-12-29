#include "wbPlayScene.h"
#include "wbGameObject.h"

namespace wb
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Scene::Initialize();

		GameObject* obj = new GameObject();
		obj->SetPosition(800, 600);
		obj->SetSize(100);
		obj->SetSpeed(500);
		AddGameObject(obj);
		
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}