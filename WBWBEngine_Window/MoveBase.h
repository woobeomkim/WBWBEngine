#pragma once
#include "CommonInclude.h"

namespace wb
{
	class Animation;
	class GameObject;
	class MoveBase
	{
	public:
		MoveBase();
		~MoveBase();

		void SetName(const std::wstring& name)
		{
			mName = name;
		}

		std::wstring& GetName()
		{
			return mName;
		}
		int GetPower()
		{
			return mPower;

		}

		void SetPower(int power)
		{
			mPower = power;
		}

		void SetAccuracy(int accuracy)
		{
			mAccuracy = accuracy;
		}

		int GetAccuracy()
		{
			return mAccuracy;
		}

		void SetPriority(int priority)
		{
			mPriority = priority;
		}

		int GetPriority()
		{
			return mPriority;
		}

		void SetAnimation(Animation* anim)
		{
			mAnimation = anim;
		}

		Animation* GetAnimation()
		{
			return mAnimation;
		}
	private:
		std::wstring mName;
		int mPower;
		int mAccuracy;
		int mPriority;

		Animation* mAnimation;
	};
}
