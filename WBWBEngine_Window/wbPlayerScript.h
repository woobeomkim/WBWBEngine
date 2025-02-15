#pragma once
#include "wbScript.h"
#include "CommonInclude.h"

namespace wb
{
	class Player;
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Die,
			Attack
		};

		enum class eDir
		{
			Left,
			Right,
			Up,
			Down,
			None,
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(Player* player)
		{
			mPlayer = player;
		}

		void SetOrder(ePlayerOrder order)
		{
			mOrder = order;
		}

		ePlayerOrder GetOrder()
		{
			return mOrder;
		}

		eDir GetDir()
		{
			return mDir;
		}
	private:
		void idle();
		void move();
	private:
		ePlayerOrder mOrder;
		Player* mPlayer;
		float mAccTime;
		const float mDiffHeight = 64.0f;
		const float mDiffWidth = 48.0f;
		//static std::queue<Vector2> mWayPoints;
		static std::queue<std::pair<Vector2,eDir>> mWayPoints;
		static const int mMaxWayPoints;
		float mSpeed;
		eState mState;
		class Animator* mAnimator;
		bool mIsMoving;
		eDir mDir;
		float mHorizontal = 0.0f;
		float mVertical = 0.0f;

	};
}
