#include "queen.hpp"



Queen::Queen(int x, int y, char color, char name)
{
    set_X(x);
    set_Y(y);
    set_color(color);
    set_name(name);
}

bool Queen::accept(Visitor *pV, int d_x, int d_y)
{
    if(pV->visitQueen(this,d_x,d_y))
    {
        return true;
    }
    return false;
}

