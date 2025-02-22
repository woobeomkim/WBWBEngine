#include "wbBattleScene.h"
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
#include "wbMonster.h"

namespace wb
{
	BattleScene::BattleScene()
	{
	}
	BattleScene::~BattleScene()
	{
	}
	void BattleScene::Initialize()
	{
		Monster* monkey = Instantiate<Monster>(eLayerType::Player, Vector2(320.0f, 240.0f));
		Texture* tex = Resources::Find<Texture>(L"MONKEY");
		Animator* animator = monkey->AddComponent<Animator>();
		animator->CreateAnimation(L"MONKEY_IDLE", tex, Vector2(0, 0), Vector2(40.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		animator->CreateAnimation(L"MONKEY_ATTACK", tex, Vector2(41.0f, 0), Vector2(70.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		animator->CreateAnimation(L"MONKEY_BE_ATTACK", tex, Vector2(110.0f, 0), Vector2(40.0f, 64.0f), Vector2::Zero, 1, 0.1f);

		animator->PlayAnimation(L"MONKEY_BE_ATTACK", true);

		// 640 , 480 640//5 480 /4 
		
		// 45 68
		Player* ataho = Instantiate<Player>(eLayerType::Player, Vector2(128.0f, 120.0f));
 		Texture* atahoTex = Resources::Find<Texture>(L"BATTLE_AT");
		Animator* atahoAnimator = ataho->AddComponent<Animator>();
		atahoAnimator->CreateAnimation(L"ATAHO_IDLE", atahoTex, Vector2(0, 0), Vector2(47.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		atahoAnimator->CreateAnimation(L"ATAHO_BEATTACK", atahoTex, Vector2(47.0f, 0), Vector2(47.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		atahoAnimator->CreateAnimation(L"ATAHO_GUARD", atahoTex, Vector2(94.0f, 0), Vector2(47.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		
		// 하나의 기술
		atahoAnimator->CreateAnimation(L"ATAHO_KICK_0", atahoTex, Vector2(142.0f, 0), Vector2(48.0f, 66.0f), Vector2::Zero, 2, 0.1f);
		atahoAnimator->CreateAnimation(L"ATAHO_KICK_1", atahoTex, Vector2(240.0f, 0), Vector2(80.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		atahoAnimator->CreateAnimation(L"ATAHO_KICK_2", atahoTex, Vector2(320.0f, 0), Vector2(60.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		
		// 날라차기
		atahoAnimator->CreateAnimation(L"ATAHO_FLYKICK", atahoTex, Vector2(380.0f, 0), Vector2(68.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		// 68
		// 38 66 4장
		atahoAnimator->CreateAnimation(L"ATAHO_ROTATEKICK_0", atahoTex, Vector2(450.0f, 0), Vector2(40.0f, 66.0f), Vector2::Zero, 1, 0.1f);
		atahoAnimator->CreateAnimation(L"ATAHO_ROTATEKICK_1", atahoTex, Vector2(490.0f, 0), Vector2(50.0f, 66.0f), Vector2::Zero, 3, 0.1f);

		atahoAnimator->PlayAnimation(L"ATAHO_KICK_0", true);

		//BattleScene* battlescene = this;
		//atahoAnimator->GetCompleteEvent(L"ATAHO_KICK") = std::bind(&BattleScene::OnExit, battlescene);
		//60

		
		
		Scene::Initialize();
	}
	void BattleScene::Update()
	{
		Scene::Update();
	}
	void BattleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void BattleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void BattleScene::OnEnter()
	{
	}
	void BattleScene::OnExit()
	{

	}
}