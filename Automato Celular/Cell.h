#pragma once
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

	//move functions
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();


	bool checkUp(int TMATRIX);
	bool checkDown(int TMATRIX);
	bool checkLeft(int TMATRIX);
	bool checkRight(int TMATRIX);

	//select move
	void switchMove(int dir, int TMATRIX);
};