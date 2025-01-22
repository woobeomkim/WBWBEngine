#pragma once

#include "CommonInclude.h"
#include "wbEntity.h"

namespace wb
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(class GameObject* obj);
		void SetName(const std::wstring& name) { mName = name; }
	private:
		std::wstring mName;
		std::vector<class GameObject*> mGameObjects;
	};
}