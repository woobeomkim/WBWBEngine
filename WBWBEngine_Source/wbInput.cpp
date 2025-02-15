#include "wbInput.h"
#include "wbApplication.h"

std::vector<wb::Input::Key> wb::Input::mKeys = {};
wb::Vector2 wb::Input::mMousePosition = wb::Vector2::One;

extern wb::Application app;

int ASCII[] =
{
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT,VK_RIGHT,VK_UP,VK_DOWN,
	VK_SPACE,VK_LBUTTON,VK_MBUTTON,VK_RBUTTON
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
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::LateUpdate()
	{
	}
	void Input::createKeys()
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
	void Input::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}
	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keycode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}
	bool Input::isKeyDown(eKeycode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPreesed)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPreesed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPreesed)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPreesed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(app.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}

	void Input::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPreesed = false;
		}
	}
}