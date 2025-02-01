#pragma once

namespace wb
{
	struct Vector2
	{
		float x;
		float y;

		Vector2() :x(0.0f), y(0.0f) {}

		Vector2(float _x, float _y) :x(_x), y(_y) {}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator*(float scalar)
		{
			return Vector2(x * scalar, y * scalar);
		}

		Vector2 operator/(float scalar)
		{
			return Vector2(x / scalar, y / scalar);
		}

		static Vector2 One;
		static Vector2 Zero;
	};
}