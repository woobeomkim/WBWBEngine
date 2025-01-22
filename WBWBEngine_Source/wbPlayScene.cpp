#include "wbPlayScene.h"
#include "wbGameObject.h"
#include "wbTransfrom.h"
#include "wbSpriteRenderer.h"
#include "wbPlayer.h"

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

		Player* pl = new Player();
		Transform* tr
			= pl->AddComponent<Transform>();
		tr->SetPos(800, 450);

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);
		Scene::Initialize();
		
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