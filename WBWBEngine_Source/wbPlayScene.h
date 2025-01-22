#pragma once
#include "wbScene.h"

namespace wb
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	
		void OnEnter() override;
		void OnExit() override;
	private:

	};
}
