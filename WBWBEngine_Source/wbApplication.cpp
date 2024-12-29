#include "wbApplication.h"
#include "wbGameObject.h"
#include "wbInput.h"
#include "wbMonster.h"
#include "wbTime.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mPlayer(nullptr)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}

	Application::~Application()
	{
		if (mPlayer)
			delete mPlayer;
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;
		
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		mBackBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHdc = CreateCompatibleDC(mHdc);
		
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
		
		mPlayer = new GameObject();
		mPlayer->Initialize();
		mPlayer->SetPosition(mWidth / 2.0f, mHeight / 2.0f);

		for (int i = 0; i < 8; i++)
		{
			Monster* monster = new Monster();
			monster->Initialize();
			monster->SetPosition(100 * (i +1), 100);
			mMonster.push_back(monster);
		}
		Input::Initialize();
		Time::Initialize();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		mPlayer->Update();
		for (int i = 0; i < mMonster.size(); i++)
		{
			mMonster[i]->Update();
		}

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
		mPlayer->Render(mBackHdc);
		for (int i = 0; i < mMonster.size(); i++)
		{
			mMonster[i]->Render(mBackHdc);
		}
		Time::Render(mBackHdc);
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	void Application::LateUpdate()
	{
		mPlayer->LateUpdate();
		for (int i = 0; i < mMonster.size(); i++)
		{
			mMonster[i]->LateUpdate();
		}

		for (int i = 0; i < mMonster.size(); i++)
		{
			Monster* dead = mMonster[i];
			if (mMonster[i]->IsDead())
			{
				mMonster.erase(mMonster.begin() + i);
				delete dead;
				dead = nullptr;
			}
		}

		Input::LateUpdate();
	}

	void Application::Run()
	{
		Update();
		Render();
		LateUpdate();
	}
}