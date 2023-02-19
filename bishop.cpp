#include "bishop.hpp"

Bishop::Bishop(int x, int y, char color, char name)
{
    set_X(x);
    set_Y(y);
    set_color(color);
    set_name(name);
}

bool Bishop::accept(Visitor *pV, int d_x, int d_y)
{
    if(pV->visitBishop(this, d_x, d_y))
    {
        return true;
    }
    return false;
}


