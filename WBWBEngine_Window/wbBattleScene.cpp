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
#include "BattleManager.h"
#include "..\\WBWBEngine_Source\\wbTime.h"
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
		

		BattleManager::Initialize();
		
		BattleManager::mBattleState = BattleManager::BattleState::Start;
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
		
		Scene::Initialize();
	}
	void BattleScene::Update()
	{
		//// 1/4 ?? 160 80

		//Animator* atahoAnimator = BattleManager::GetAtaho()->GetComponent<Animator>();
		//atahoAnimator->PlayAnimation(L"ATAHO_BATTLE_FAINTING");
		//Time::WaitForSeconds(10.0f);
		////atahoAnimator->PlayAnimation(L"BATTLE_IDLE");
		//Time::WaitForSeconds(1.0f);
		//
		Scene::Update();
		BattleManager::Update();
	}
	void BattleScene::LateUpdate()
	{
		BattleManager::LateUpdate();
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