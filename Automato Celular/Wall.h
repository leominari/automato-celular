#pragma once
#include "Cell.h"


class Wall : public Cell
{
private:
protected:
public:
	Wall()
	{
		this->x = -1;
		this->y = -1;
		this->state = -1;
	}

	Wall(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->state = 0;
	}

	//create a Wall with state
	Wall(int x, int y, int state)
	{
		this->x = x;
		this->y = y;
		this->state = state;
	}

    bool ableToMove(int dir, int TMATRIX);
};
