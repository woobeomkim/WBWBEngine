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

		static void SetTrail(Vector2 pos , ePlayerOrder order)
		{
			trail[(int)order] = pos;
		}

	private:
		void idle();
		void move();
		void moveCharacter(float newX, float newY);
		void updateFollowerPosition(Vector2 target);
	protected:
		ePlayerOrder mOrder;
		Player* mPlayer;
		float mAccTime;
		static float moveDeltaTime;
		const float mDiffHeight = 64.0f;
		const float mDiffWidth = 48.0f;
		static std::vector<Vector2> trail;
		static const int trailSize;
		float mSpeed;
		eState mState;
		class Animator* mAnimator;
		bool mIsMoving;
		eDir mDir;
		float mHorizontal = 0.0f;
		float mVertical = 0.0f;

	};
}
