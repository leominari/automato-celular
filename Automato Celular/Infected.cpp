#include "Infected.h"

ReturnType Infected::ableToMove(int dir, int (&matrix)[TMATRIX][TMATRIX])
{
    if (this->Move(dir, matrix))
    {
        return this->bitten(dir, matrix);
    }
    return ReturnType(-1, -1, false);
}

ReturnType Infected::bitten(int dir, int (&matrix)[TMATRIX][TMATRIX])
{
    switch (dir)
    {
    case 0:
        if (matrix[this->x][this->y] == PEOPLE)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 1:
        if (matrix[this->x][this->y] == PEOPLE)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 2:
        if (matrix[this->x][this->y] == PEOPLE)
        {
            return ReturnType(this->x, this->y, true);
        }
        else
        {
            return ReturnType(-1, -1, false);
        }
        break;
    case 3:
        if (matrix[this->x][this->y] == PEOPLE)
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
