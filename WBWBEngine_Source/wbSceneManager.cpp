#include "wbSceneManager.h"
#include "wbScene.h"

namespace wb
{
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
		
		if (iter == mScene.end())
			return nullptr;
		
		mActiveScene = iter->second;
		mActiveScene->OnEnter();


		return iter->second;
	}

	SceneManager::SceneManager()
	{
	}
	SceneManager::~SceneManager()
	{
	}
	void SceneManager::Initialize()
	{
		mActiveScene->Initialize();
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}