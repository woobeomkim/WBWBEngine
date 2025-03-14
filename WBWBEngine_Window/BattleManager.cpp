#include "BattleManager.h"

namespace wb
{
	std::queue<std::function<void()>> BattleManager::mActionQueue = {};
	bool mIsturn = true;
	BattleManager::BattleManager()
	{
	}
	BattleManager::~BattleManager()
	{
	}
	void BattleManager::Initialize()
	{
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
}