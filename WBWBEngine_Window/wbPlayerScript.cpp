#include "wbPlayerScript.h"
#include "wbInput.h"
#include "wbTime.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbPlayer.h"
#include "wbAnimator.h"

namespace wb
{
	PlayerScript::PlayerScript()
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
		float speed = dynamic_cast<Player*>(GetOwner())->GetSpeed();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (Input::GetKey(eKeycode::A))
		{
			animator->PlayAnimation(L"LEFTWALK", true);
			pos.x -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeycode::D))
		{
			animator->PlayAnimation(L"RIGHTWALK", true);
			pos.x += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeycode::W))
		{
			animator->PlayAnimation(L"UPWALK", true);
			pos.y -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeycode::S))
		{
			animator->PlayAnimation(L"DOWNWALK", true);
			pos.y += speed * Time::DeltaTime();
		}
		tr->SetPosition(pos);
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}