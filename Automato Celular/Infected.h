#pragma once
#include "Cell.h"
class Infected : public Cell
{
private:
protected:
public:
    Infected()
    {
        this->x = -1;
        this->y = -1;
        this->state = -1;
    }

    Infected(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->state = 0;
    }

    //create a Infected with state
    Infected(int x, int y, int state)
    {
        this->x = x;
        this->y = y;
        this->state = state;
    }
    bool ableToMove(int dir, int TMATRIX);
};