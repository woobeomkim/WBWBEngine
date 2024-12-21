#include "wbMonster.h"

namespace wb
{
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		mX = 0.0f;
		mY = 0.0f;
		mSize = 100;
		mbDead = false;
		isLeft = rand() % 2;
	}
	void Monster::Update()
	{
		if (isLeft)
		{
			mX -= 0.1f;
		}
		else
		{
			mX += 0.1f;
		}

		if (mX <= 0.0f + mSize /2)
			isLeft = false;
		
		if (mX >= 1600 - mSize /2)
			isLeft = true;
	}
 	void Monster::Render(HDC hdc)
	{
		Ellipse(hdc, mX - mSize / 2, mY - mSize/2, mX + mSize/2, mY + mSize/2);
	}
	void Monster::LateUpdate()
	{
	}
}