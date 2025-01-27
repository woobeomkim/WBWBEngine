#pragma once
#include "wbResources.h"
#include "wbTexture.h"

namespace wb
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"BG", L"C:\\Users\\woobu\\OneDrive\\πŸ≈¡ »≠∏È\\WBWBEngine\\WBWBEngine\\Resources\\bmp\\aaa.cns.bmp");
	}
}