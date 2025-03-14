#pragma once
#include "wbComponent.h"

namespace wb
{
	class Stat : public Component
	{
	public:
		struct Data
		{
			int hp;
			int mp;
			int atk;
			int def;
			int spd;
			int exp;
			int level;

			void levelUp()
			{

			}
		};

		Stat();
		~Stat();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void InitializeStat(Data data)
		{
			mData = data;
		}

		void SetStat(Data data)
		{
			mData = data;
		}

		Data GetStat()
		{
			return mData;
		}
	private:
		Data mData;

	};
}
