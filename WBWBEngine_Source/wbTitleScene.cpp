#include "wbTitleScene.h"
#include "wbSceneManager.h"
#include "wbInput.h"
#include "wbGameObject.h"
#include "wbObject.h"
#include "wbSpriteRenderer.h"
#include "wbResource.h"
#include "wbResources.h"
#include "wbTexture.h"
#include "wbTime.h"

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
		GameObject* com = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* sr = com->AddComponent<SpriteRenderer>();
		mTex = Resources::Find<Texture>(L"COMPILE1");

		sr->SetName(L"SR");
		sr->SetTexture(mTex);
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		
		accTime += Time::DeltaTime();

		if (accTime >= 1.0f)
		{
			GameObject* com = Instantiate<GameObject>(eLayerType::BackGround);
			SpriteRenderer* sr = com->AddComponent<SpriteRenderer>();
			mTex = Resources::Find<Texture>(L"COMPILE2");
			sr->SetName(L"SR");
			sr->SetTexture(mTex);
		}

		if (accTime >= 3.0f)
		{
			GameObject* com = Instantiate<GameObject>(eLayerType::BackGround);
			SpriteRenderer* sr = com->AddComponent<SpriteRenderer>();
			mTex = Resources::Find<Texture>(L"TITLE");
			sr->SetName(L"SR");
			sr->SetTexture(mTex);
		}
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
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
