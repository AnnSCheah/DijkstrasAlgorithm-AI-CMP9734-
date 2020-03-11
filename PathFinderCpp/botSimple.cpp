#include "bots.h"

void cBotSimple::ChooseNextGridPosition()
{
	bool done = false;

	while (!done)
	{
		if (PositionX() < gTarget.PositionX())
		{
			done =SetNext(PositionX() + 1, PositionY(), gLevel);
		}
		else if (PositionX() > gTarget.PositionX())
		{
			done = SetNext(PositionX() - 1, PositionY(), gLevel);
		}
		else if (PositionY() < gTarget.PositionY())
		{
			done = SetNext(PositionX(), PositionY() + 1, gLevel);
		}
		else
		{
			done = SetNext(PositionX(), PositionY() - 1, gLevel);
		}
	}
}

void cBotSimple2::ChooseNextGridPosition()
{
	if (PositionX() < gTarget.PositionX())
	{
		if (SetNext(PositionX() + 1, PositionY(), gLevel) == 0)
		{
			SetNext(PositionX(), PositionY() + 1, gLevel);
		}
	}
	else if (PositionY() < gTarget.PositionY())
	{
		SetNext(PositionX(), PositionY() + 1, gLevel);
	}
	else if (PositionY() > gTarget.PositionY())
	{
		SetNext(PositionX(), PositionY() - 1, gLevel);
	}

	//if (PositionX() < gTarget.PositionX())
	//{
	//	currentDirection = SetNext(PositionX() + 1, PositionY(), gLevel);
	//}
}