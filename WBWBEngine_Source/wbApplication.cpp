#include "wbApplication.h"
#include "wbGameObject.h"
#include "wbInput.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mPlayer(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer = new GameObject();
		mPlayer->Initialize();
		Input::Initialize();
	}

	void Application::Update()
	{
		mPlayer->Update();
		Input::Update();
	}

	void Application::Render()
	{
		mPlayer->Render(mHdc);
	}

	void Application::LateUpdate()
	{
		mPlayer->LateUpdate();
		Input::LateUpdate();
	}

	void Application::Run()
	{
		Update();
		Render();
		LateUpdate();
	}
}