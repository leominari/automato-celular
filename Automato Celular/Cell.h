#pragma once
#include "Settings.h"

class Cell
{
private:
protected:
public:
	int x;
	int y;
	int state;
	//Create a cell with state 0

	Cell()
	{
		this->x = -1;
		this->y = -1;
		this->state = -1;
	}

	Cell(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->state = 0;
	}

	//create a cell with state
	Cell(int x, int y, int state)
	{
		this->x = x;
		this->y = y;
		this->state = state;
	}

	~Cell()
	{
		//destructor
	}

	//set cell alive
	void setAlive();

	void killCell();

	//move functions
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();


	bool checkUp(int (&matrix)[TMATRIX][TMATRIX]);
	bool checkDown(int (&matrix)[TMATRIX][TMATRIX]);
	bool checkLeft(int (&matrix)[TMATRIX][TMATRIX]);
	bool checkRight(int (&matrix)[TMATRIX][TMATRIX]);

	//select move
	bool Move(int dir, int (&matrix)[TMATRIX][TMATRIX]);
};