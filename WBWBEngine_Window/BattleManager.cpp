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
#include "BattleBase.h"
#include "wbInput.h"
#include "wbTime.h"

namespace wb
{
	std::queue<std::function<void()>> BattleManager::mActionQueue = {};
	std::map<std::wstring, Monster*> BattleManager::mMonster = {};

	BattleManager::BattleState BattleManager::mBattleState;
	BattleManager::BattleAction BattleManager::mBattleAction;
	int BattleManager::currentAction;
	int BattleManager::currentMove;
	bool BattleManager::mIsturn;

	Animator* BattleManager::atahoAnimator = nullptr;
	Animator* BattleManager::monsterAnimator = nullptr;

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

		atahoAnimator = mAtaho->GetComponent<Animator>();
		monsterAnimator = mMonster[L"MONKEY"]->GetComponent<Animator>();
	}
	void BattleManager::Update()
	{
		switch (mBattleState)
		{
		case wb::BattleManager::BattleState::Start:
			startBattle();
			break;
		case wb::BattleManager::BattleState::ActionSelection:
			actionSelection();
			break;
		case wb::BattleManager::BattleState::MoveSelection:
			moveSelection();
			break;
		case wb::BattleManager::BattleState::RunningTurn:
			RunTurns();
			break;
		case wb::BattleManager::BattleState::Busy:
			break;
		case wb::BattleManager::BattleState::BattleOver:
			break;
		default:
			break;
		}
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
		BattleManager::mMonster[L"MONKEY"]->GetComponent<Animator>()->PlayAnimation(L"MONKEY_IDLE");
		BattleManager::mAtaho->GetComponent<Animator>()->PlayAnimation(L"ATAHO_BATTLE_IDLE");

		mBattleState = BattleState::ActionSelection;
	}
	void BattleManager::actionSelection()
	{
		if (Input::GetKeyDown(eKeycode::Right))
			currentAction++;
		else if (Input::GetKeyDown(eKeycode::Left))
			currentAction--;


		if(Input::GetKeyDown(eKeycode::Z))
			mBattleState = BattleState::MoveSelection;
	}
	void BattleManager::moveSelection()
	{
		if (Input::GetKeyDown(eKeycode::Down))
			currentMove++;
		else if (Input::GetKeyDown(eKeycode::Up))
			currentMove--;

		if(Input::GetKeyDown(eKeycode::Z))
			mBattleState = BattleState::RunningTurn;
		else if(Input::GetKeyDown(eKeycode::X))
			mBattleState = BattleState::ActionSelection;

	}
	void BattleManager::RunTurns()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_PUNCH", false);
		
			atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_IDLE",false);

			enemyMove();
			if(Input::GetKeyDown(eKeycode::Z))
			mBattleState = BattleState::Start;
		
	}
	void BattleManager::enemyMove()
	{
		BattleManager::mMonster[L"MONKEY"]->GetComponent<Animator>()->PlayAnimation(L"MONKEY_ATTACK");
	}
	void BattleManager::runMove()
	{
	}
	void BattleManager::battleOver()
	{
	}
	void BattleManager::initMonster()
	{
		Monster* monkey = Instantiate<Monster>(eLayerType::Player, Vector2(540.0f, 240.0f));
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
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_IDLE", atahoTex, Vector2(0.0f, 0.0f), Vector2(45.0f, 63.0f), Vector2::Zero, 1, 1.0f);
		

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_PUNCH");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_PUNCH", atahoTex, Vector2(0.0f, 0.0f), Vector2(67.5f, 61.0f), Vector2::Zero, 2, 1.0f);

		atahoTex = Resources::Find<Texture>(L"ATAHO_BATTLE_ROTATEKICK");
		atahoAnimator->CreateAnimation(L"ATAHO_BATTLE_ROTATEKICK", atahoTex, Vector2(0.0f, 0.0f), Vector2(70.0f, 101.0f), Vector2::Zero, 4, 1.0f);

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