#include "wbMonster.h"
#include "..\\WBWBEngine_Window\\BattleBase.h"

namespace wb
{
	Monster::Monster()
	{
		mBase = new BattleBase();
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
}