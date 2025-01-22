#include "wbTitleScene.h"
#include "wbSceneManager.h"
#include "wbInput.h"

namespace wb
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeycode::SPACE))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		std::wstring title = L"환세취호전 Press Space";
		TextOut(hdc, 1600 / 2.0f, 800 / 2.0f, title.c_str(), wcslen(title.c_str()));
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
