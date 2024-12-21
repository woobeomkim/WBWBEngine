#pragma once
#include "CommonInclude.h"


class Application
{
public:
	Application();
	~Application();

	void Initialize(HWND hwnd);
	void Update();
	void Render();
	void LateUpdate();

	void Run();
private:
	HWND mHwnd;
	HDC mHdc;

	class GameObject* mPlayer;
};

