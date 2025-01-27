#include "wbPlayScene.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbSpriteRenderer.h"
#include "wbPlayer.h"
#include "wbObject.h"

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
		Player* bg = Instantiate<Player>(eLayerType::Player, Vector2(100.0f, 100.0f));

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\woobu\\OneDrive\\πŸ≈¡ »≠∏È\\WBWBEngine\\WBWBEngine\\Resources\\bmp\\aaa.cns.bmp");
		AddGameObject(bg, eLayerType::BackGround);
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
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{

	}
}