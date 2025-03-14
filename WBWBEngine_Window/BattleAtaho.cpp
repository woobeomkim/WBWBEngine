#include "BattleAtaho.h"
#include "wbObject.h"
#include "wbAnimator.h"
#include "wbInput.h"
#include "wbAnimation.h"
#include "..\\WBWBEngine_Window\\BattleManager.h"

void test()
{
	int a = 0;
}

namespace wb
{
	BattleAtaho::BattleAtaho()
		:Component(eComponentType::BattleAtaho)
		, mState(State::Idle)
		, atahoAnimator(nullptr)
	{
	}
	BattleAtaho::~BattleAtaho()
	{
	}
	void BattleAtaho::Initialize()
	{
	}
	void BattleAtaho::Update()
	{
		if (!atahoAnimator)
			atahoAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case State::Idle:
			idle();
			break;
		case State::Punch:
			punch();
			break;
		case State::RotateKick:
			rotateKick();
			break;
		case State::Defense:
			defense();
			break;
		case State::Drinking:
			drinking();
			break;
		case State::Sleep:
			sleep();
			break;
		case State::Guard:
			guard();
			break;
		case State::BeAttacked:
			beAttacked();
			break;
		case State::FlyingKick:
			flyingKick();
			break;
		case State::Fainting:
			fainting();
			break;
		case State::Win:
			win();
			break;
		case State::LegKick:
			legKick();
			break;
		case State::Roar:
			roar();
			break;
		case State::HogyukGwon:
			hogyukGwon();
			break;
		case State::HopoGwon:
			hopoGwon();
			break;

		}
	}
	void BattleAtaho::LateUpdate()
	{
		
	}
	void BattleAtaho::Render(HDC hdc)
	{
	}
	void BattleAtaho::idle()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_IDLE",false);

		Animation* anim = atahoAnimator->GetActiveAnimation();

		bool temp = anim->IsComplete();
		

		if (Input::GetKeyDown(eKeycode::Q))
				mState = State::Punch;
		else if (Input::GetKeyDown(eKeycode::W))
				mState = State::RotateKick;
		else if (Input::GetKeyDown(eKeycode::E))
			mState = State::Defense;
		else if (Input::GetKeyDown(eKeycode::R))
			mState = State::Drinking;
		else if(Input::GetKeyDown(eKeycode::T))
			mState = State::Sleep;
		else if (Input::GetKeyDown(eKeycode::Y))
			mState = State::Guard;
		else if (Input::GetKeyDown(eKeycode::U))
			mState = State::BeAttacked;
		else if (Input::GetKeyDown(eKeycode::I))
			mState = State::FlyingKick;
		else if (Input::GetKeyDown(eKeycode::O))
			mState = State::Fainting;
		else if (Input::GetKeyDown(eKeycode::P))
			mState = State::Win;
		else if (Input::GetKeyDown(eKeycode::A))
			mState = State::LegKick;
		else if (Input::GetKeyDown(eKeycode::S))
			mState = State::Roar;
		else if (Input::GetKeyDown(eKeycode::D))
			mState = State::HogyukGwon;
		else if (Input::GetKeyDown(eKeycode::F))
			mState = State::HopoGwon;
	}
	void BattleAtaho::punch()
	{
		
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_PUNCH", false);

		Animation* anim = atahoAnimator->GetActiveAnimation();
		
		std::function<void()> f;
		f = test;
		f();
		BattleManager::mActionQueue.push(f);
		BattleManager::mActionQueue.front()();
		mState = State::Idle;
	}
	void BattleAtaho::rotateKick()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_ROTATEKICK",false);
		
		mState = State::Idle;
	}
	void BattleAtaho::defense()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_GUARD", false);
		mState = State::Idle;
	}
	void BattleAtaho::drinking()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_DRINKING", false);
		mState = State::Idle;
	}
	void BattleAtaho::sleep()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_SLEEP", false);
		mState = State::Idle;
	}
	void BattleAtaho::guard()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_GUARD", false);
		mState = State::Idle;
	}
	void BattleAtaho::beAttacked()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_BEATTACKED", false);
		mState = State::Idle;
	}
	void BattleAtaho::flyingKick()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_FLYINGKICK", false);
		mState = State::Idle;

	}
	void BattleAtaho::fainting()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_FAINTING", true);
		//mState = State::Idle;

	}
	void BattleAtaho::win()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_WIN", false);
		mState = State::Idle;

	}
	void BattleAtaho::legKick()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_LEGKICK", false);
		mState = State::Idle;

	}
	void BattleAtaho::roar()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_ROAR", false);
		mState = State::Idle;
	}
	void BattleAtaho::hogyukGwon()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_HOGYUKGWON", false);
		mState = State::Idle;
	}
	void BattleAtaho::hopoGwon()
	{
		atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_HOPOGWON", false);
		mState = State::Idle;
	}
}