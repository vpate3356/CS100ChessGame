#ifndef queen_hpp
#define queen_hpp
#include <stdio.h>
#include "chessPiece.hpp"
#include "visitor.hpp"

class Visitor;

class Queen : public ChessPiece
{

public:
     Queen(int x, int y, char color, char name);
     bool accept(Visitor *pV, int d_x, int d_y);
};

#endif /* Queen_hpp */

