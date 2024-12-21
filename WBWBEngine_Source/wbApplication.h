#pragma once
#include "CommonInclude.h"

namespace wb
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Update();
		void Render();
		void LateUpdate();

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		std::vector<class Monster*>& GetMonsters() { return mMonster; }

		void Run();
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		class GameObject* mPlayer;
		std::vector<class Monster*> mMonster;
	};
}