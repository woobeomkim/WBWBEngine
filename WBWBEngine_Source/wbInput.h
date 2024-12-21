#pragma once
#include "CommonInclude.h"

enum class eKeycode
{
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	LEFT,RIGHT,UP,DOWN,
	SPACE,
	END
};

enum class eKeyState
{
	Pressed,
	Up,
	Down,
	None
};

namespace wb
{
	class Input
	{
	public:
		struct Key
		{
			eKeycode keycode;
			eKeyState state;
			bool bPreesed;
		};
		Input();
		~Input();

		static void Initialize();
		static void Update();
		static void LateUpdate();

		static bool GetKey(eKeycode keycode) { return mKeys[(UINT)keycode].state == eKeyState::Pressed; }
		static bool GetKeyDown(eKeycode keycode) { return mKeys[(UINT)keycode].state == eKeyState::Down; }
		static bool GetKeyUp(eKeycode keycode) { return mKeys[(UINT)keycode].state == eKeyState::Up; }
	private:
		static std::vector<Key> mKeys;
	};
}