#include "People.h"

ReturnType People::ableToMove(int dir, int (&matrix)[TMATRIX][TMATRIX])
{
    if (this->Move(dir, matrix))
    {
        return this->battle(dir, matrix);
    }
    return ReturnType(-1, -1, false);
}

ReturnType People::battle(int dir, int (&matrix)[TMATRIX][TMATRIX])
{
    switch (dir)
    {
    case 0:
        if (matrix[this->x][this->y] == INFECTED)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 1:
        if (matrix[this->x][this->y] == INFECTED)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 2:
        if (matrix[this->x][this->y ] == INFECTED)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 3:
        if (matrix[this->x][this->y] == INFECTED)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;

    default:
        break;
    }
}