#pragma once

namespace wb
{
	struct Vector2
	{
		float x;
		float y;

		Vector2() :x(0.0f), y(0.0f) {}

		Vector2(float _x, float _y) :x(_x), y(_y) {}

		static Vector2 One;
		static Vector2 Zero;
	};
}