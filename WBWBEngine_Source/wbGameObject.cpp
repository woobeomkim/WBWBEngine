#include "wbGameObject.h"
#include "wbInput.h"

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
        mX = 0.0f;
        mY = 0.0f;
    }

    void GameObject::Update()
    {
        if (Input::GetKey(eKeycode::LEFT))
        {
            mX -= 0.1f;
        }
        if (Input::GetKey(eKeycode::RIGHT))
        {
            mX += 0.1f;
        }
        if (Input::GetKey(eKeycode::UP))
        {
            mY -= 0.1f;
        }
        if (Input::GetKey(eKeycode::DOWN))
        {
            mY += 0.1f;
        }
    }

    void GameObject::LateUpdate()
    {
    }

    void GameObject::Render(HDC hdc)
    {
        // HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
       //
       // HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);


        Rectangle(hdc, 200 + mX, 200 + mY, 300 + mX, 300 + mY);
        //SelectObject(mHdc, oldBrush);

        //DeleteObject(blueBrush);

        //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

       // Ellipse(mHdc, 200 + mX, 200 + mY, 300 + mX, 300 + mY);

        //SelectObject(mHdc, oldPen);
        //DeleteObject(redPen);
    }
}