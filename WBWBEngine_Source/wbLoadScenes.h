#pragma once

#include "wbPlayScene.h"
#include "wbSceneManager.h"
#include "wbTitleScene.h"
#include "..\\WBWBEngine_Window\\wbBattleScene.h"
#include "..\\WBWBEngine_Window\\wbStudyScene.h"

namespace wb
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<StudyScene>(L"StudyScene");
		SceneManager::CreateScene<BattleScene>(L"BattleScene");


		SceneManager::LoadScene(L"TitleScene");
	}
}