#include "wbApplication.h"

Application::Application()
	: mHwnd(nullptr)
	, mHdc(nullptr)
	, mX(0.0f)
	, mY(0.0f)
{
}

Application::~Application()
{
}

void Application::Initialize(HWND hwnd)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
}

void Application::Update()
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        mX -= 0.01f;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        mX += 0.01f;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        mY -= 0.01f;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        mY += 0.01f;
    }
}

void Application::Render()
{
   // HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
   //
   // HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);
    Rectangle(mHdc, 200 + mX, 200 + mY, 300 + mX, 300 + mY);
    //SelectObject(mHdc, oldBrush);

    //DeleteObject(blueBrush);

    //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

   // Ellipse(mHdc, 200 + mX, 200 + mY, 300 + mX, 300 + mY);

    //SelectObject(mHdc, oldPen);
    //DeleteObject(redPen);
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
