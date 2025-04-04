#pragma once
#include "CommonInclude.h"

namespace wb
{
	class GameObject;
	class MoveBase
	{
	public:
		MoveBase(std::wstring moveName, int moveCost, int movePower,int moveRange);
		~MoveBase();

		virtual void Execute(GameObject* sourceUnit,GameObject* targetUnit) = 0;

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

		void SetRange(int range)
		{
			mRange = range;
		}

		int GetRange()
		{
			return mRange;
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


	protected:
		std::wstring mName;
		int mCost;
		int mPower;
		int mRange;
		int mAccuracy;
		int mPriority;

	};
}
