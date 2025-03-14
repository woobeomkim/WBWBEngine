#pragma once
#include "wbComponent.h"

namespace wb
{
    class BattleSmisu : public Component
    {
    public:
		BattleSmisu();
		~BattleSmisu();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

    };
}
