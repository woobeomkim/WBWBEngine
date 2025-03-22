#include "BattleManager.h"
#include "wbMonster.h"
#include "wbTexture.h"
#include "wbAnimation.h"
#include "wbAnimator.h"
#include "wbObject.h"
#include "wbResources.h"
#include "wbResource.h"
#include "wbPlayer.h"
#include "BattleAtaho.h"
#include "MoveBase.h"
#include "Move.h"
#include "BattleBase.h"

namespace wb
{
	std::queue<std::function<void()>> BattleManager::mActionQueue = {};
	std::map<std::wstring, Monster*> BattleManager::mMonster = {};

	Player* BattleManager::mAtaho = nullptr;
	Player* BattleManager::mRinShan = nullptr;
	Player* BattleManager::mSmisu = nullptr;

	BattleManager::BattleManager()
	{
	}
	BattleManager::~BattleManager()
	{
	}
	void BattleManager::Initialize()
	{
		initMonster();
		initAtaho();
	}
	void BattleManager::Update()
	{
	}
	void BattleManager::LateUpdate()
	{
	}
	void BattleManager::Destroy()
	{
	}
	void BattleManager::Release()
	{
	}
	void BattleManager::startBattle()
	{
	}
	void BattleManager::actionSelection()
	{
	}
	void BattleManager::moveSelection()
	{
	}
	void BattleManager::RunTurns()
	{
	}
	void BattleManager::enemyMove()
	{
	}
	void BattleManager::runMove()
	{
	}
	void BattleManager::battleOver()
	{
	}
	void BattleManager::initMonster()
	{
		Monster* monkey = Instantiate<Monster>(eLayerType::Player, Vector2(320.0f, 240.0f));
		Texture* tex = Resources::Find<Texture>(L"MONKEY");
		Animator* animator = monkey->AddComponent<Animator>();
		animator->CreateAnimation(L"MONKEY_IDLE", tex, Vector2(0, 0), Vector2(40.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		animator->CreateAnimation(L"MONKEY_ATTACK", tex, Vector2(41.0f, 0), Vector2(70.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		animator->CreateAnimation(L"MONKEY_BE_ATTACK", tex, Vector2(110.0f, 0), Vector2(40.0f, 64.0f), Vector2::Zero, 1, 0.1f);
		mMonster.insert(std::make_pair(tex->GetName(), monkey));
	}
	void BattleManager::initAtaho()
	{
		mAtaho = Instantiate<Player>(eLayerType::Player, Vector2(128.0f, 120.0f));
		Texture* atahoTex = Resources::Find<Texture>(L"BATTLE_AT");
		Animator* atahoAnimator = mAtaho->AddComponent<Animator>();
		BattleAtaho* atahoScript = mAtaho->AddComponent<BattleAtaho>();

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_IDLE");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_IDLE", atahoTex, Vector2(0.0f, 0.0f), Vector2(45.0f, 63.0f), Vector2::Zero, 1, 2.0f);
		

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_PUNCH");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_PUNCH", atahoTex, Vector2(0.0f, 0.0f), Vector2(67.5f, 61.0f), Vector2::Zero, 2, 5.0f);

		// 임시값
		MoveBase* moveBase = new MoveBase();
		moveBase->SetAnimation(atahoAnimator->FindAnimation(L"ATAHO_BATTLE_PUNCH"));
		moveBase->SetName(L"정권");
		moveBase->SetPower(10);
		moveBase->SetPriority(1);
		moveBase->SetAccuracy(100);
		
		BattleBase* atahoBattleBase = atahoScript->GetBattleBase();
		atahoBattleBase->AddMove(L"정권", new Move(moveBase));

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
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_WIN", atahoTex, Vector2(0.0f, 0.0f), Vector2(69.2f, 186.0f), Vector2::Zero, 13, 5.0f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_LEGKICK");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_LEGKICK", atahoTex, Vector2(0.0f, 0.0f), Vector2(61.0f, 66.0f), Vector2::Zero, 2, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_ROAR");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_ROAR", atahoTex, Vector2(0.0f, 0.0f), Vector2(100.0f, 144.0f), Vector2::Zero, 4, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_HOGYUKGWON");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_HOGYUKGWON", atahoTex, Vector2(0.0f, 0.0f), Vector2(58.0f, 64.0f), Vector2::Zero, 4, 0.1f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_HOPOGWON");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_HOPOGWON", atahoTex, Vector2(0.0f, 0.0f), Vector2(80.0f, 91.0f), Vector2::Zero, 3, 0.1f);
	}
}