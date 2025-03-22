#pragma once

#include "MoveBase.h"

namespace wb
{
	class Move
	{
	public:
		Move(MoveBase* base);
		~Move();
	private:
		MoveBase* mMoveBase;
	};
}
