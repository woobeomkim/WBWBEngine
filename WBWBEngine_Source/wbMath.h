#pragma once
#include <cmath>

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

		static float Distance(const Vector2& a, const Vector2& b)
		{
			float dx = b.x - a.x;
			float dy = b.y - a.y;
			return sqrt(dx * dx + dy * dy);  // 피타고라스 정리
		}
		
		static Vector2 lerp( Vector2& start, Vector2& end, float t)
		{
			return start + (end - start) * t;
		}
		float Length() const
		{
			return sqrt(x * x + y * y);
		}

		Vector2 Normalized() const
		{
			float length = Length();
			if (length == 0) return Vector2(0, 0);  // 길이가 0이면 (0,0) 반환
			return Vector2(x / length, y / length);
		}
		static Vector2 One;
		static Vector2 Zero;
	};
}