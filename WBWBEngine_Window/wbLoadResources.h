#pragma once
#include "wbResources.h"
#include "wbTexture.h"

namespace wb
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"BG", L"C:\\Users\\woobu\\OneDrive\\���� ȭ��\\WBWBEngine\\WBWBEngine\\Resources\\bmp\\aaa.cns.bmp");
	}
}