#include "wbBullet.h"
#include "wbApplication.h"
#include "wbMonster.h"

extern wb::Application app;

namespace wb
{
	Bullet::Bullet()
	{
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Initialize()
	{
		mSpeed = 0.5f;
		mX = 0.0f;
		mY = 0.0f;
		mSize = 25.0f;
		mbDead = false;
	}

	void Bullet::Update()
	{
		mY -= mSpeed;

		std::vector<Monster*> monsters = app.GetMonsters();

		for (int i = 0; i < monsters.size(); i++)
		{
			float monsterY = monsters[i]->GetPositionY();
			float monsterX = monsters[i]->GetPositionX();
			int monsterSize = monsters[i]->GetSize();

			float monsterHalfSize = monsterSize / 2.0f;
			float mHalfSize = mSize / 2.0f;

			// 몬스터의 AABB 범위
			float monsterMinX = monsterX - monsterHalfSize;
			float monsterMaxX = monsterX + monsterHalfSize;
			float monsterMinY = monsterY - monsterHalfSize;
			float monsterMaxY = monsterY + monsterHalfSize;

			// 플레이어의 AABB 범위
			float mMinX = mX - mHalfSize;
			float mMaxX = mX + mHalfSize;
			float mMinY = mY - mHalfSize;
			float mMaxY = mY + mHalfSize;

			// 충돌 여부 확인
			if (monsterMaxX >= mMinX && monsterMinX <= mMaxX &&
				monsterMaxY >= mMinY && monsterMinY <= mMaxY) {
				Dead();
				monsters[i]->Dead();
			}
		}

		if (mY <= 0.0f)
			Dead();
	}

	void Bullet::Render(HDC hdc)
	{
		Ellipse(hdc, mX - mSize / 2, mY - mSize / 2, mX + mSize / 2, mY + mSize / 2);
	}

	void Bullet::LateUpdate()
	{
	}
}