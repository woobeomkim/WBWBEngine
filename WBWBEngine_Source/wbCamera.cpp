#include "wbCamera.h"
#include "wbApplication.h"
#include "wbGameObject.h"
#include "wbTransform.h"

namespace wb
{
	extern Application app;

	Camera::Camera()
		: Component(eComponentType::Camera)
		, mTarget(nullptr)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookAT(Vector2::Zero)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		mResolution.x = app.GetWidth();
		mResolution.y = app.GetHeight();
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookAT = tr->GetPosition();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookAT = cameraTr->GetPosition();
		}

		mDistance = mLookAT - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}