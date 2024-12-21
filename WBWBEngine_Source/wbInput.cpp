#include "wbInput.h"

std::vector<wb::Input::Key> wb::Input::mKeys = {};

int ASCII[] =
{
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT,VK_RIGHT,VK_UP,VK_DOWN,
};

namespace wb
{
	Input::Input()
	{
	}

	Input::~Input()
	{
	}

	void Input::Initialize()
	{
		for (int i = 0; i < (UINT)eKeycode::END; i++)
		{
			Key key;
			key.keycode = (eKeycode)i;
			key.state = eKeyState::None;
			key.bPreesed = false;
			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			Key& key = mKeys[i];
			
			if (GetAsyncKeyState(ASCII[(UINT)key.keycode]) & 0x8000)
			{
				if (key.bPreesed)
				{
					key.state = eKeyState::Pressed;
				}
				else
				{
					key.state = eKeyState::Down;
				}
				key.bPreesed = true;
			}
			else
			{
				if (key.bPreesed)
				{
					key.state = eKeyState::Up;
				}
				else
				{
					key.state = eKeyState::None;
				}
				key.bPreesed = false;
			}
		}
	}

	void Input::LateUpdate()
	{
	}
}