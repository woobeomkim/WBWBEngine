#pragma once
#include "CommonInclude.h"

namespace wb
{
	class BattleManager
	{
	public:

		BattleManager();
		~BattleManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Destroy();
		static void Release();

		static std::queue<std::function<void()>> mActionQueue;
	private:
		static bool mIsturn;
	};
}
