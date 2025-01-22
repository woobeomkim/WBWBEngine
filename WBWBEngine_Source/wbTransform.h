#pragma once
#include "wbComponent.h"

namespace wb
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition = pos; }
		Vector2 GetPosition() { return mPosition; }
	private:
		Vector2 mPosition;
	};
}
