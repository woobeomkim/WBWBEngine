#include "wbPlayer.h"

namespace wb
{
	Player::Player()
		:mSpeed(100.0f)
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}