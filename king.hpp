#ifndef King_hpp
#define King_hpp
#include <stdio.h>
#include "chessPiece.hpp"
#include "visitor.hpp"

class Visitor;

class King : public ChessPiece
{

public:
    King(int x, int y, char color, char name);
    bool accept(Visitor *pV, int d_x, int d_y);


};
#endif /* King_hpp */

