#include "RinShan.h"
#include "wbAnimator.h"
#include "wbGameObject.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"

namespace wb
{
	RinShan::RinShan()
	{
	}
	RinShan::~RinShan()
	{
	}
	void RinShan::Initialize()
	{
	}
	void RinShan::Update()
	{

		if (!mAnimator)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case wb::PlayerScript::eState::Idle:
			idle();
			break;
		case wb::PlayerScript::eState::Walk:
			move();
			break;
		case wb::PlayerScript::eState::Die:
			break;
		case wb::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void RinShan::LateUpdate()
	{
	}
	void RinShan::Render(HDC hdc)
	{
	}
	void RinShan::idle()
	{
		if (Input::GetKey(eKeycode::Left))
		{
			mState = eState::Walk;
			mDir = eDir::Left;
			mAnimator->PlayAnimation(L"LEFTWALK", true);
		}
		else if (Input::GetKey(eKeycode::Right))
		{
			mState = eState::Walk;
			mDir = eDir::Right;
			mAnimator->PlayAnimation(L"RIGHTWALK", true);
		}
		else if (Input::GetKey(eKeycode::Up))
		{
			mState = eState::Walk;
			mDir = eDir::Up;
			mAnimator->PlayAnimation(L"UPWALK", true);
		}
		else if (Input::GetKey(eKeycode::Down))
		{
			mState = eState::Walk;
			mDir = eDir::Down;
			mAnimator->PlayAnimation(L"DOWNWALK", true);
		}


	}
	void RinShan::move()
	{
		int order = (int)GetOrder();
		Vector2 target = trail[order - 1];
		float speed = 0.1f;
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		
		float newX = pos.x;
		float newY = pos.y;
		float distance = Vector2::Distance(pos, target);
		float maxFollowDistance = sqrt(mDiffWidth * mDiffWidth + mDiffHeight * mDiffHeight);
		
		Vector2 direction = (target - pos).Normalized();
		pos = pos + direction * mSpeed  * moveDeltaTime;
		if (maxFollowDistance != distance)
		{
		//if (Input::GetKey(eKeycode::Left))
		//{
		//	mDir = eDir::Left;
		//	//newX -= mSpeed * Time::DeltaTime();
		//	pos.x = pos.x - (target.x - pos.x) * speed;
		//	mIsMoving = true;
		//}
		//else if (Input::GetKey(eKeycode::Right))
		//{
		//	mDir = eDir::Right;
		//	//newX += mSpeed * Time::DeltaTime();
		//	pos.x += (target.x - pos.x) * speed;
		//	mIsMoving = true;
		//}
		//else if (Input::GetKey(eKeycode::Up))
		//{
		//	mDir = eDir::Up;
		//	//newY -= mSpeed * Time::DeltaTime();
		//	pos.y = pos.y - ((target.y - pos.y)) * speed;
		//	mIsMoving = true;
		//}
		//else if (Input::GetKey(eKeycode::Down))
		//{
		//	mDir = eDir::Down;
		//	//newY += mSpeed * Time::DeltaTime();
		//	pos.y += ((target.y - pos.y)) * speed;
		//	mIsMoving = true;
		//}
		//else
		//{
		//	mIsMoving = false;
		//}
		//pos = Vector2(newX, newY);
		//pos.x += (target.x - pos.x) * speed;
		//pos.y += (target.y - pos.y) * speed;
		}
		trail[(int)GetOrder()] = pos;
		tr->SetPosition(pos);

		if (!mIsMoving)
		{
			switch (mDir)
			{
			case eDir::Left:
				mAnimator->PlayAnimation(L"LEFTWALK_IDLE", true);
				break;
			case eDir::Right:
				mAnimator->PlayAnimation(L"RIGHTWALK_IDLE", true);
				break;
			case eDir::Up:
				mAnimator->PlayAnimation(L"UPWALK_IDLE", true);
				break;
			case eDir::Down:
				mAnimator->PlayAnimation(L"DOWNWALK_IDLE", true);
				break;
			}
			mState = eState::Idle;
		}
	}

}