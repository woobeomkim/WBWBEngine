#pragma once
#include "CommonInclude.h"

namespace wb
{
	class Monster
	{
	public:
		Monster();
		~Monster();

		void Initialize();
		void Update();
		void Render(HDC hdc);
		void LateUpdate();

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
		int GetSize() { return mSize; }

		bool IsDead() { return mbDead; }
		void Dead() { mbDead = true; }

	private:
		float mX;
		float mY;
		int mSize;
		bool isLeft;
		bool mbDead;
	};
}
