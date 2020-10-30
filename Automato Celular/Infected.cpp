#include "Infected.h"

bool Infected::ableToMove(int dir, int TMATRIX)
{
    this->Move(dir, TMATRIX);
    return true;
}
