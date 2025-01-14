#pragma once
#include "CommonInclude.h"

namespace wb
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		void SetSize(int size) { mSize = size; }

		void SetSpeed(float speed) { mSpeed = speed; }

		float GetSpeed() { return mSpeed; }
		int GetSize() { return mSize; }
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
		float mSpeed;
		int mSize;
		class Bullet* mBullet;
		bool mbBullet;
	};
}