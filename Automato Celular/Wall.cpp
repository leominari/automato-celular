#include "Wall.h"

bool Wall::ableToMove(int dir)
{
    return false;
}

void Wall::buildWall(int (&matrix)[TMATRIX][TMATRIX], int dir)
{

    switch (dir)
    {
    case 0:
        for (size_t i = 0; i < WALLCELLS; i++)
        {
            if ((this->y - 1) >= 0)
            {
                matrix[this->x][this->y - i] = WALL;
            }
        }
        break;
    case 1:
        for (size_t i = 0; i < WALLCELLS; i++)
        {
            if ((this->x + i) < TMATRIX)
            {
                matrix[this->x + i][this->y] = WALL;
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < WALLCELLS; i++)
        {
            if ((this->y + i) < TMATRIX)
            {
                matrix[this->x][this->y + i] = WALL;
            }
        }
        break;
    case 3:
        for (size_t i = 0; i < WALLCELLS; i++)
        {
            if ((this->x - i) >= 0)
            {
                matrix[this->x - i][this->y] = WALL;
            }
        }
        break;

    default:
        break;
    }
}
