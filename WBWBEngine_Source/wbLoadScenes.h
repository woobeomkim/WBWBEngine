#pragma once

#include "wbPlayScene.h"
#include "wbSceneManager.h"
#include "wbTitleScene.h"

namespace wb
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}