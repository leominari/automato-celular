#pragma once
class ReturnType
{
public:
    int x;
    int y;
    bool status;

    ReturnType(int x, int y, bool status)
    {
        this->x = x;
        this->y = y;
        this->status = status;
    }
};
