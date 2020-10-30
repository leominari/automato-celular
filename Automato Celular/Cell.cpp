#include "Cell.h"

void Cell::setAlive()
{
	this->state = 1;
}

void Cell::moveUp()
{
	this->y = this->y - 1;
}
void Cell::moveRight()
{
	this->x = this->x + 1;
}
void Cell::moveDown()
{
	this->y = this->y + 1;
}
void Cell::moveLeft()
{
	this->x = this->x - 1;
}

bool Cell::checkUp(int TMATRIX)
{
	if ((this->y - 1) > 0)
	{
		return true;
	}
	return false;
}

bool Cell::checkRight(int TMATRIX)
{
	if ((this->x + 1) < TMATRIX)
	{
		return true;
	}
	return false;
}

bool Cell::checkDown(int TMATRIX)
{
	if ((this->y + 1) < TMATRIX)
	{
		return true;
	}
	return false;
}

bool Cell::checkLeft(int TMATRIX)
{
	if ((this->x - 1) > 0)
	{
		return true;
	}
	return false;
}

void Cell::Move(int dir, int TMATRIX)
{
	switch (dir)
	{
	case 0:
		if (this->checkUp(TMATRIX))
			this->moveUp();
		break;
	case 1:
		if (this->checkRight(TMATRIX))
			this->moveRight();
		break;
	case 2:
		if (this->checkDown(TMATRIX))
			this->moveDown();
		break;
	case 3:
		if (this->checkLeft(TMATRIX))
			this->moveLeft();
		break;

	default:
		break;
	}
}
