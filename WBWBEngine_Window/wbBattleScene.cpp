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
#include "..\\WBWBEngine_Window\\BattleAtaho.h"
#include "..\\WBWBEngine_Window\\BattleRinshan.h"
#include "..\\WBWBEngine_Window\\BattleSmisu.h"
#include "..\\WBWBEngine_Window\\wbStat.h"

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
		BattleAtaho* atahoScript = ataho->AddComponent<BattleAtaho>();
		Stat* stat = ataho->AddComponent<Stat>();

		/*
		* Resources::Load<Texture>(L"ATAHO_BATTLE_IDLE",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_IDLE.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_PUNCH",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_PUNCH.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_ROTATEKICK",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_ROTATEKICK.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_SLEEP",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_SLEEP.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_WIN",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_WIN.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_GAURD",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_GUARD.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_BEATTACKED",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_BEATTACKED.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_FLYINGKICK",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_FLYINGKICK.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_FAINTING",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_FAINTING.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_DRINKING",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_DRINKING.bmp");
		Resources::Load<Texture>(L"ATAHO_BATTLE_DRUNKSTATE",L"..\\Resources\\Bmp\\Battle_modified\\ATAHO_STATE_DRUNK.bmp");
		*/
		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_IDLE");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_IDLE", atahoTex, Vector2(0.0f, 0.0f), Vector2(45.0f, 63.0f), Vector2::Zero, 1, 2.0f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_PUNCH");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_PUNCH", atahoTex, Vector2(0.0f, 0.0f), Vector2(67.5f, 61.0f), Vector2::Zero, 2, 0.3f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_ROTATEKICK");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_ROTATEKICK", atahoTex, Vector2(0.0f, 0.0f), Vector2(70.0f, 101.0f), Vector2::Zero, 4, 3.0f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_SLEEP");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_SLEEP", atahoTex, Vector2(0.0f, 0.0f), Vector2(62.0f, 49.0f), Vector2::Zero, 3, 0.1f);
		
		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_GUARD");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_GUARD", atahoTex, Vector2(0.0f, 0.0f), Vector2(48.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		
		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_BEATTACKED");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_BEATTACKED", atahoTex, Vector2(0.0f, 0.0f), Vector2(45.0f, 65.0f), Vector2::Zero, 1, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_FLYINGKICK");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_FLYINGKICK", atahoTex, Vector2(0.0f, 0.0f), Vector2(68.0f, 65.0f), Vector2::Zero, 1, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_FAINTING");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_FAINTING", atahoTex, Vector2(0.0f, 0.0f), Vector2(100.0f, 81.0f), Vector2::Zero, 3, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_DRINKING");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_DRINKING", atahoTex, Vector2(0.0f, 0.0f), Vector2(75.0f, 95.0f), Vector2::Zero, 4, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_DRUNKSTATE");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_DRUNKSTATE", atahoTex, Vector2(0.0f, 0.0f), Vector2(50.0f, 66.0f), Vector2::Zero, 1, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_WIN");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_WIN", atahoTex, Vector2(0.0f, 0.0f), Vector2(69.2f, 186.0f), Vector2::Zero, 13, 1.0f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_LEGKICK");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_LEGKICK", atahoTex, Vector2(0.0f, 0.0f), Vector2(61.0f, 66.0f), Vector2::Zero, 2, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_ROAR");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_ROAR", atahoTex, Vector2(0.0f, 0.0f), Vector2(100.0f, 144.0f), Vector2::Zero, 4, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_HOGYUKGWON");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_HOGYUKGWON", atahoTex, Vector2(0.0f, 0.0f), Vector2(58.0f, 64.0f), Vector2::Zero, 4, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_HOPOGWON");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_HOPOGWON", atahoTex, Vector2(0.0f, 0.0f), Vector2(80.0f, 91.0f), Vector2::Zero, 3, 0.1f);

		//->PlayAnimation(L"ATAHO_BATTLE_DRINKING", true);
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