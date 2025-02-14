#pragma once

namespace wb
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Max = 16,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}