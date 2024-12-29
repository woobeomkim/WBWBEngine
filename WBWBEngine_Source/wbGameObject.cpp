#include "wbGameObject.h"
#include "wbInput.h"
#include "wbBullet.h"
#include "wbTime.h"

namespace wb
{
    GameObject::GameObject()
    {
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Initialize()
    {
    }

    void GameObject::Update()
    {
        if (Input::GetKey(eKeycode::LEFT))
        {
            mX -= mSpeed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeycode::RIGHT))
        {
            mX += mSpeed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeycode::UP))
        {
            mY -= mSpeed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeycode::DOWN))
        {
            mY += mSpeed * Time::DeltaTime();
        }

        if (Input::GetKeyDown(eKeycode::SPACE) && !mbBullet)
        {
            mBullet = new Bullet();
            mBullet->Initialize();
            mBullet->SetPosition(mX, mY - mSize / 2);
            mbBullet = true;
        }

        if (mbBullet)
            mBullet->Update();
    }

    void GameObject::LateUpdate()
    {
        if (mBullet && mBullet->IsDead())
        {
            delete mBullet;
            mBullet = nullptr;
            mbBullet = false;
        }
        if (mbBullet)
            mBullet->LateUpdate();
    }

    void GameObject::Render(HDC hdc)
    {
        // HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
       //
       // HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);


        Rectangle(hdc, mX - mSize / 2, mY - mSize / 2, mX + mSize / 2, mY + mSize / 2);

        if (mbBullet)
            mBullet->Render(hdc);
        //SelectObject(mHdc, oldBrush);

        //DeleteObject(blueBrush);

        //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

       // Ellipse(mHdc, 200 + mX, 200 + mY, 300 + mX, 300 + mY);

        //SelectObject(mHdc, oldPen);
        //DeleteObject(redPen);
    }
}