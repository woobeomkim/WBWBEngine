#include "wbApplication.h"
#include "wbGameObject.h"

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
}

void Application::Update()
{
	mPlayer->Update();
}

void Application::Render()
{
    mPlayer->Render(mHdc);
}

void Application::LateUpdate()
{
}

void Application::Run()
{
	Update();
	Render();
	LateUpdate();
}
