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

bool Cell::checkUp(int (&matrix)[TMATRIX][TMATRIX])
{
	if ((this->y - 1) > 0)
	{
		if (matrix[x][y - 1] == WALL)
		{
			return false;
		}

		return true;
	}
	return false;
}

bool Cell::checkRight(int (&matrix)[TMATRIX][TMATRIX])
{
	if ((this->x + 1) < TMATRIX)
	{
		if (matrix[x + 1][y] == WALL)
		{
			return false;
		}

		return true;
	}
	return false;
}

bool Cell::checkDown(int (&matrix)[TMATRIX][TMATRIX])
{
	if ((this->y + 1) < TMATRIX)
	{
		if (matrix[x][y + 1] == WALL)
		{
			return false;
		}

		return true;
	}
	return false;
}

bool Cell::checkLeft(int (&matrix)[TMATRIX][TMATRIX])
{
	if ((this->x - 1) > 0)
	{
		if (matrix[x - 1][y] == WALL)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool Cell::Move(int dir, int (&matrix)[TMATRIX][TMATRIX])
{
	switch (dir)
	{
	case 0:
		if (this->checkUp(matrix))
		{
			this->moveUp();
			return true;
		}
		break;
	case 1:
		if (this->checkRight(matrix))
		{
			this->moveRight();
			return true;
		}
		break;
	case 2:
		if (this->checkDown(matrix))
		{
			this->moveDown();
			return true;
		}
		break;
	case 3:
		if (this->checkLeft(matrix))
		{
			this->moveLeft();
			return true;
		}
		break;

	default:
		break;
	}
}
