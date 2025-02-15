#include "wbPlayerScript.h"
#include "wbInput.h"
#include "wbTime.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbAnimator.h"
#include "wbPlayer.h"

namespace wb
{
	//std::queue<Vector2> PlayerScript::mWayPoints = {};
	std::queue<std::pair<Vector2,PlayerScript::eDir>> PlayerScript::mWayPoints = {};
	const int PlayerScript::mMaxWayPoints = 50;
	PlayerScript::PlayerScript()
		: mState(eState::Idle)
		, mAnimator(nullptr)
		, mIsMoving(false)
		, mDir(eDir::None)
		, mSpeed(100.0f)
		, mAccTime(0.0f)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
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
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{

		if (Input::GetKey(eKeycode::LEFT))
		{
			mState = eState::Walk;
			mDir = eDir::Left;
			mAnimator->PlayAnimation(L"LEFTWALK", true);
		}
		else if (Input::GetKey(eKeycode::RIGHT))
		{
			mState = eState::Walk;
			mDir = eDir::Right;
			mAnimator->PlayAnimation(L"RIGHTWALK", true);
		}
		else if (Input::GetKey(eKeycode::UP))
		{
			mState = eState::Walk;
			mDir = eDir::Up;
			mAnimator->PlayAnimation(L"UPWALK", true);
		}
		else if (Input::GetKey(eKeycode::DOWN))
		{
			mState = eState::Walk;
			mDir = eDir::Down;
			mAnimator->PlayAnimation(L"DOWNWALK", true);
		}


	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		mHorizontal = 0.0f;
		mVertical = 0.0f;

		// Ű �Է� ����
		bool left = Input::GetKey(eKeycode::LEFT);
		bool right = Input::GetKey(eKeycode::RIGHT);
		bool up = Input::GetKey(eKeycode::UP);
		bool down = Input::GetKey(eKeycode::DOWN);

		// �ݴ� ���� �Է� ���� ó��
		if (left && right) left = right = false;
		if (up && down) up = down = false;
		if (left && up || left && down) left = up = down = false;
		if (right && up || right && down) right = up = down = false;



		// �Է� ����: ���������� ���� ������ ���� (�ֱ� �Է��� ����ϱ� ���� ���� �߰�)
		if (left) { mHorizontal = -1.0f; mDir = eDir::Left; }
		else if (right) { mHorizontal = 1.0f; mDir = eDir::Right; }

		if (up) { mVertical = -1.0f; mDir = eDir::Up; }
		else if (down) { mVertical = 1.0f; mDir = eDir::Down; }

		// �밢�� �̵� ���� (���� �ڵ� ����)
		if (mHorizontal != 0.0f && mVertical != 0.0f)
		{
			if (mDir == eDir::Left || mDir == eDir::Right)
				mVertical = 0.0f;
			else
				mHorizontal = 0.0f;
		}


		if (mPlayer->GetLeader() == nullptr)
		{
			Vector2 pos = tr->GetPosition();;

			// �̵� ����
			pos.x += mHorizontal * mSpeed * Time::DeltaTime();
			pos.y += mVertical * mSpeed * Time::DeltaTime();
			tr->SetPosition(pos);

			//mWayPoints.push(pos);
			mWayPoints.push({ pos,mDir });
			if (mWayPoints.size() > mMaxWayPoints)
				mWayPoints.pop();
			
		}
		else
		{
			//Transform* nextTr = mPlayer->GetLeader();
			//Vector2 nextPos = nextTr->GetPosition();

			// �� ĳ������ �̵� ��θ� ���󰡱� (��������Ʈ ���)
			mAccTime += Time::DeltaTime();
			if (!mWayPoints.empty() && mAccTime>=0.5f)
			{
				mAccTime = 0.0f;
				//Vector2 targetPos = mWayPoints.front(); // ���� ������ ��ġ ��������
				Vector2 targetPos = mWayPoints.front().first; // ���� ������ ��ġ ��������
				eDir dir = mWayPoints.front().second; // ���� ������ ��ġ ��������
				mWayPoints.pop();
				Vector2 currentPos = tr->GetPosition();
				Vector2 pos;
				int count = (UINT)GetOrder();
				//Transform* tr = GetOwner()->GetComponent<Transform>();
				//Vector2 pos = tr->GetPosition();
				pos = targetPos;

				/*switch (mDir)
				{
					case eDir::Left:
						pos.x = pos.x + count * mDiffWidth;
						break;

					case eDir::Right:
						pos.x = pos.x - count * mDiffWidth;
						break;

					case eDir::Down:
						pos.y = pos.y - count * mDiffHeight;
						break;

					case eDir::Up:
						pos.y = pos.y + count * mDiffHeight;
						break;
				}*/
				switch (dir)
				{
					case eDir::Left:
						pos.x = pos.x + count * mDiffWidth;
						break;

					case eDir::Right:
						pos.x = pos.x - count * mDiffWidth;
						break;

					case eDir::Down:
						pos.y = pos.y - count * mDiffHeight;
						break;

					case eDir::Up:
						pos.y = pos.y + count * mDiffHeight;
						break;
				}

				//pos.x = std::lerp(currentPos.x, targetPos.x, mSpeed * Time::DeltaTime());
				//pos.y = std::lerp(currentPos.y, targetPos.y - count * mDiffHeight, mSpeed * Time::DeltaTime());
				
				tr->SetPosition(pos);
				//mWayPoints.pop();
			}
		}
		
			//if(mAnimator->GetActiveAnimation()->IsComplete() || (mHorizontal == 0.0f && mVertical == 0.0f))
			if (mHorizontal == 0.0f && mVertical == 0.0f)
			{
				switch (mDir)
				{
				case eDir::Left:  mAnimator->PlayAnimation(L"LEFTWALK_IDLE", false); break;
				case eDir::Right: mAnimator->PlayAnimation(L"RIGHTWALK_IDLE", false); break;
				case eDir::Up:    mAnimator->PlayAnimation(L"UPWALK_IDLE", false); break;
				case eDir::Down:  mAnimator->PlayAnimation(L"DOWNWALK_IDLE", false); break;
				}
				mState = eState::Idle;
			}
		
	}
}