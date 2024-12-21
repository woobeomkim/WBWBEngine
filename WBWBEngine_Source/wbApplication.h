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

		void Run();
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		class GameObject* mPlayer;
		class Monster* mMonster;
	};
}