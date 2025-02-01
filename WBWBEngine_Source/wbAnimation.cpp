#include "wbAnimation.h"
#include "wbTime.h"
#include "wbTransform.h"
#include "wbGameObject.h"
#include "wbAnimator.h"
#include "wbRenderer.h"
#include "wbCamera.h"
#include "wbTexture.h"

namespace wb
{
	Animation::Animation()
		: Resource(eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete) return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc)
	{
		if (!mTexture)
			assert(false); // Texture 설정하기
		
		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mainCamera)
			pos = mainCamera->CalculatePosition(pos);
	

		Sprite sprite = mAnimationSheet[mIndex];
		if (mTexture->GetTextureType() == Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, sprite.size.x
				, sprite.size.y
				, mTexture->GetHdc()
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, RGB(255, 0, 255));
		}
		else
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; //RGBA의 알파값

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc
				, pos.x, pos.y
				, sprite.size.x
				, sprite.size.y
				, imgHdc
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, func);
		}
	}
	void Animation::CreateAnimation(const std::wstring& name, Texture* spriteSheet
		, Vector2 leftTop, Vector2 size
		, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}
}