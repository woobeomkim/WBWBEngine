#pragma once
#include "CommonInclude.h"
#include "wbScene.h"

namespace wb
{
	class SceneManager
	{
	public:
		// ���ø��Լ��� �� ������� ��������� ����
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			 Scene* scene = new T();
			mActiveScene = scene;
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}
		static class Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		SceneManager();
		~SceneManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);


	private:
		static std::map<const std::wstring, class Scene*> mScene;
		static class Scene* mActiveScene;
	};
}
