#pragma once
#include "CommonInclude.h"

namespace wb
{
	class Player;
	class BattleManager
	{
	public:
		enum class BattleState
		{
			Start,
			ActionSelection,
			MoveSelection,
			RunningTurn,
			Busy,
			BattleOver
		};

		enum class BattleAction
		{
			Move,
			UseItem,
			Run
		};
		BattleManager();
		~BattleManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Destroy();
		static void Release();

		static std::queue<std::function<void()>> mActionQueue;

		static Player* GetAtaho() { return mAtaho; }

	private:
		void startBattle();
		void actionSelection();
		void moveSelection();
		void RunTurns();
		void enemyMove();
		void runMove();
		void battleOver();
	private:
		static void initMonster();
		static void initAtaho();
	private:
		BattleState mBattleState;
		BattleAction mBattleAction;
		int currentAction;
		int currentMove;
		static bool mIsturn;
		static std::map<std::wstring, class Monster*> mMonster;
		static Player* mAtaho;
		static Player* mRinShan;
		static Player* mSmisu;
	};
}
