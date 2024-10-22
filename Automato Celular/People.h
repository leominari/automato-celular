#pragma once
#include "Cell.h"
#include "ReturnType.h"

class People : public Cell
{
private:
protected:
public:
    People()
    {
        this->x = -1;
        this->y = -1;
        this->state = -1;
    }

    People(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->state = 0;
    }

    //create a People with state
    People(int x, int y, int state)
    {
        this->x = x;
        this->y = y;
        this->state = state;
    }

    ReturnType ableToMove(int dir, int (&matrix)[TMATRIX][TMATRIX]);

    ReturnType battle(int dir, int (&matrix)[TMATRIX][TMATRIX]);
};
