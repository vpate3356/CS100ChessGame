#ifndef knight_hpp
#define knight_hpp


#include "chessPiece.hpp"
#include "visitor.hpp"
#include <stdio.h>


class Knight : public ChessPiece
{
public:
    Knight(int x, int y, char color, char name);
    bool accept(Visitor *pV, int d_x, int d_y);
};



#endif

