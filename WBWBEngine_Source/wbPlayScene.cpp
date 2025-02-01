#include "wbPlayScene.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbSpriteRenderer.h"
#include "wbPlayer.h"
#include "wbObject.h"
#include "wbTexture.h"
#include "wbResource.h"
#include "wbResources.h"
#include "wbAnimation.h"
#include "wbAnimator.h"
#include "..\\WBWBEngine_Window\\\wbPlayerScript.h"

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
		Player* player = Instantiate<Player>(eLayerType::Player, Vector2(320.0f, 240.0f));
		

		Texture* tex = Resources::Find<Texture>(L"PLAYER1");
		Animator* animator = player->AddComponent<Animator>();
		player->AddComponent<PlayerScript>();

		animator->CreateAnimation(L"DOWNWALK", tex, Vector2(0, 0), Vector2(48.0f, 64.0f), Vector2::Zero, 5, 0.1f);
		//animator->PlayAnimation(L"DOWNWALK", true);
		
		animator->CreateAnimation(L"LEFTWALK", tex, Vector2(240.0f, 0), Vector2(48.0f, 64.0f), Vector2::Zero, 5, 0.1f);

		animator->CreateAnimation(L"UPWALK", tex, Vector2(0.0f, 64.0f), Vector2(48.0f, 64.0f), Vector2::Zero, 5, 0.1f);
		animator->CreateAnimation(L"RIGHTWALK", tex, Vector2(240.0f, 64.0f), Vector2(48.0f, 64.0f), Vector2::Zero, 5, 0.1f);
		animator->PlayAnimation(L"UPWALK", true);

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