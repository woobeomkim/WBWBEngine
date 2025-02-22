#pragma once
#include "..\\WBWBEngine_Source\\wbResources.h"
#include "..\\WBWBEngine_Source\\wbTexture.h"

namespace wb
{
	void LoadResources()
	{
		//TitleScene
		Resources::Load<Texture>(L"COMPILE1", L"..\\Resources\\Bmp\\title\\aaa.bmp");
		Resources::Load<Texture>(L"COMPILE2", L"..\\Resources\\Bmp\\title\\compile.bmp");
		Resources::Load<Texture>(L"TITLE", L"..\\Resources\\Bmp\\title\\title.bmp");
		Resources::Load<Texture>(L"BLACK", L"..\\Resources\\Bmp\\title\\black.bmp");
		Resources::Load<Texture>(L"PLAYER_AT", L"..\\Resources\\Bmp\\AnimationSheet\\cara_at1.bmp");
		Resources::Load<Texture>(L"PLAYER_RS", L"..\\Resources\\Bmp\\AnimationSheet\\cara_rs1.bmp");
		Resources::Load<Texture>(L"PLAYER_SM", L"..\\Resources\\Bmp\\AnimationSheet\\cara_sm1.bmp");
		
		//BattleScene
		Resources::Load<Texture>(L"BOSS_1", L"..\\Resources\\Bmp\\AnimationSheet\\boss_1.bmp");
		Resources::Load<Texture>(L"BOSS_2", L"..\\Resources\\Bmp\\AnimationSheet\\boss_2.bmp");
		Resources::Load<Texture>(L"PIG", L"..\\Resources\\Bmp\\AnimationSheet\\zj_ana.bmp");
		Resources::Load<Texture>(L"MONKEY", L"..\\Resources\\Bmp\\AnimationSheet\\zsa_saru.bmp");
		Resources::Load<Texture>(L"BATTLE_AT", L"..\\Resources\\Bmp\\AnimationSheet\\btl_at.bmp");
		
		
		//Resources::Load<Texture>(L"PLAYER1_IDLE", L"..\\Resources\\Bmp\\AnimationSheet\\cara_at_idle.bmp");
	}
}