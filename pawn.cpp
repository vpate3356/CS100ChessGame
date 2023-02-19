#include "pawn.hpp"


Pawn::Pawn(int x, int y, char color, char name)
{
    set_X(x);
    set_Y(y);
    set_color(color);
    set_name(name);
}



bool Pawn::accept(Visitor *pV, int d_x, int d_y)
{
    if(pV->visitPawn(this, d_x, d_y))
    {
        return true;
    }
    return false;
}


bool Pawn::getPawn_isMoved()
{
    return isMoved;
}


void Pawn::setPawn_isMoved()
{
    isMoved = true;
}


