#pragma once
#include "wbResources.h"
#include "wbTexture.h"

namespace wb
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"COMPILE1", L"..\\Resources\\Bmp\\title\\aaa.bmp");
		Resources::Load<Texture>(L"COMPILE2", L"..\\Resources\\Bmp\\title\\compile.bmp");
		Resources::Load<Texture>(L"TITLE", L"..\\Resources\\Bmp\\title\\title.bmp");
	}
}