#ifndef Rook_hpp
#define Rook_hpp
#include <stdio.h>
#include "chessPiece.hpp"
#include "visitor.hpp"



class Rook : public ChessPiece
{
public:
   Rook(int x, int y, char color, char name);
   bool accept(Visitor *pV, int d_x, int d_y);


};


#endif /* Rook_hpp */

