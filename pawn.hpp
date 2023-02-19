#ifndef Pawn_hpp
#define Pawn_hpp

#include <stdio.h>
#include "chessPiece.hpp"
#include "visitor.hpp"



class Pawn : public ChessPiece
{
private:
    bool isMoved = false;
public:
    Pawn(int x, int y, char color, char name);
    bool accept(Visitor *pV, int d_x, int d_y);

    bool getPawn_isMoved();
    void setPawn_isMoved();

    
};

#endif

