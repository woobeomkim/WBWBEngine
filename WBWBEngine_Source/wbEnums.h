#pragma once

namespace wb
{
	enum class ePlayerOrder
	{
		First,
		Second,
		Third,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Particle,
		Max = 16,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Ataho,
		Smisu,
		RinShan,
		BattleAtaho,
		BattleRinShan,
		BattleSmisu,
		Stat,
		Camera,
		End,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}