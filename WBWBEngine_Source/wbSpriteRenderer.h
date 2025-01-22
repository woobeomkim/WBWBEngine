#pragma once
#include "wbComponent.h"
namespace wb
{
    class SpriteRenderer : public Component
    {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
    };
}
