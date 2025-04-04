#pragma once
#include "wbComponent.h"

namespace wb
{
	class BattleScene;
	class Animator;
	class BattleBase;

	//enum State
	//{
	//	Idle,
	//	Punch,
	//	RotateKick,
	//	Defense,
	//	Drinking,
	//	Sleep,
	//	Guard,
	//	BeAttacked,
	//	FlyingKick,
	//	Fainting,
	//	Win,
	//	LegKick,
	//	Roar,
	//	HogyukGwon,
	//	HopoGwon

	//};

    class BattleAtaho : public Component
    {
    public:
		BattleAtaho();
		~BattleAtaho();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		BattleBase* GetBattleBase()
		{
			return mBattleBase;
		}
	private:
		void idle();
		void punch();
		void rotateKick();
		void defense();
		void drinking();
		void sleep();
		void guard();
		void beAttacked();
		void flyingKick();
		void fainting();
		void win();
		void legKick();
		void roar();
		void hogyukGwon();
		void hopoGwon();

	private:
		Animator* atahoAnimator;
		//State mState;
		BattleBase* mBattleBase;
		std::map<std::wstring, class MoveBase*> moves;

		friend class BattleScene;
    };
}

