#include "gtest/gtest.h"

#include "rook.cpp"
#include "queen.cpp"
#include "knight.cpp"
#include "king.cpp"
#include "bishop.cpp"
#include "pawn.cpp"
#include "chessPiece.hpp"
#include "piecevisitor.hpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(ChessPiece, pwan1)
{
    int temp;
    
    ChessPiece *pawn = new Pawn(0,1,'w','p');
    
    temp = pawn->get_X();
    
    EXPECT_EQ(temp, 0);

}

TEST(ChessPiece, pwan2)
{
    int temp;

    ChessPiece *pawn = new Pawn(0,1,'w','p');

    temp = pawn->get_Y();

    EXPECT_EQ(temp, 1);

}


TEST(ChessPiece, pwa3)
{
    char temp;

    ChessPiece *pawn = new Pawn(0,1,'w','p');

    temp = pawn->get_color();

    EXPECT_EQ(temp, 'w');

}




TEST(ChessPiece, pwan4)
{
    char temp;

    ChessPiece *pawn = new Pawn(0,1,'w','p');

    temp = pawn->get_name();

    EXPECT_EQ(temp, 'p');

}




TEST(ChessPiece, rook1)
{
    int temp;

    ChessPiece *rook = new Rook(7,7,'w','r');

    temp = rook->get_X();

    EXPECT_EQ(temp, 7);


}




TEST(ChessPiece, rook2)
{
    int temp;

    ChessPiece *rook = new Rook(7,7,'w','r');

    temp = rook->get_Y();

    EXPECT_EQ(temp, 7);


}


TEST(ChessPiece, rook3)
{
    char temp;

    ChessPiece *rook = new Rook(7,7,'w','r');

    temp = rook->get_color();

    EXPECT_EQ(temp, 'w');


}


TEST(ChessPiece, rook4)
{
    char temp;

    ChessPiece *rook = new Rook(7,7,'w','r');

    temp = rook->get_name();

    EXPECT_EQ(temp, 'r');


}

TEST(ChessPiece, knight)
{

    ChessPiece *knight = new Knight(7,1,'w','n');
   int x = knight->get_X();
   int y = knight->get_Y();
   char color = knight->get_color();
   char temp = knight->get_name();
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 1);
    EXPECT_EQ(color, 'w');
    EXPECT_EQ(temp, 'n');

}

TEST(ChessPiece, knight2)
{

    ChessPiece *knight = new Knight(0,6,'b','N');
   int x = knight->get_X();
   int y = knight->get_Y();
   char color = knight->get_color();
   char temp = knight->get_name();
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 6);
    EXPECT_EQ(color, 'b');
    EXPECT_EQ(temp, 'N');

}

TEST(ChessPiece, QueenBlack)
{
   
   ChessPiece *queen = new Queen(0,4,'b','Q');
   int x = queen->get_X();
   int y = queen->get_Y();
   char color = queen->get_color();
   char temp = queen->get_name();
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 4); 
    EXPECT_EQ(color, 'b');
    EXPECT_EQ(temp, 'Q');

}

TEST(ChessPiece, QueenWhite)
{
   
   ChessPiece *queen = new Queen(7,4,'w','q');
   int x = queen->get_X();
   int y = queen->get_Y();
   char color = queen->get_color();
   char temp = queen->get_name();
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 4); 
    EXPECT_EQ(color, 'w');
    EXPECT_EQ(temp, 'q');

}

TEST(ChessPiece, KingBlack)
{

   ChessPiece *king = new King(0,3,'b','K');
   int x = king->get_X();
   int y = king->get_Y();
   char color = king->get_color();
   char temp = king->get_name();
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 3);
    EXPECT_EQ(color, 'b');
    EXPECT_EQ(temp, 'K');

}

TEST(ChessPiece, KingWhite)
{

   ChessPiece *king = new King(7,3,'w','k');
   int x = king->get_X();
   int y = king->get_Y();
   char color = king->get_color();
   char temp = king->get_name();
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 3);
    EXPECT_EQ(color, 'w');
    EXPECT_EQ(temp, 'k');

}

TEST(ChessPiece, BishopWhite)
{

   ChessPiece *bishop = new Bishop(7,5,'w','b');
   int x = bishop->get_X();
   int y = bishop->get_Y();
   char color = bishop->get_color();
   char temp = bishop->get_name();
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 5);
    EXPECT_EQ(color, 'w');
    EXPECT_EQ(temp, 'b');

}

TEST(ChessPiece, BishopBlack)
{

   ChessPiece *bishop = new Bishop(0,5,'b','B');
   int x = bishop->get_X();
   int y = bishop->get_Y();
   char color = bishop->get_color();
   char temp = bishop->get_name();
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 5);
    EXPECT_EQ(color, 'b');
    EXPECT_EQ(temp, 'B');

}



TEST(PieceVisitor, visitPawn1)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *pawn = new Pawn(6,4,'w','p');   

    temp = pawn->accept(visitor, 7,7);   

    EXPECT_EQ(temp, false);
}


TEST(PieceVisitor, visitPawn2)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *pawn = new Pawn(6,4,'w','p');

    temp = pawn->accept(visitor, 5,4);

    EXPECT_EQ(temp, true);
}


TEST(PieceVisitor, visitPawn3)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *pawn = new Pawn(1,0,'w','p');

    temp = pawn->accept(visitor, 5,6);

    EXPECT_EQ(temp, false);
}


TEST(PieceVisitor, visitPawn4)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *pawn = new Pawn(1,5,'w','p');

    temp = pawn->accept(visitor, 3,5);

    EXPECT_EQ(temp, false);
}


TEST(PieceVisitor, visitPawn5)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *pawn = new Pawn(6,1,'w','p');

    temp = pawn->accept(visitor, 6,2);

    EXPECT_EQ(temp, false);
}




TEST(PieceVisitor, visitRook1)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *rook = new Rook(5,5,'w','p');

    temp = rook->accept(visitor, 6,6);

    EXPECT_EQ(temp, false);
}

TEST(PieceVisitor, visitRook2)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *rook = new Rook(0,0,'b','R');

    temp = rook->accept(visitor, 7,0);

    EXPECT_EQ(temp, true);
}


TEST(PieceVisitor, visitRook3)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *rook = new Rook(7,7,'b','R');

    temp = rook->accept(visitor, 1,6);

    EXPECT_EQ(temp, false);
}


TEST(PieceVisitor, visitRook4)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *rook = new Rook(6,6,'b','R');

    temp = rook->accept(visitor, 4,6);

    EXPECT_EQ(temp, true);
}

TEST(PieceVisitor, visitRook5)
{
    bool temp;

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *rook = new Rook(2,4,'b','R');

    temp = rook->accept(visitor, 2,7);

    EXPECT_EQ(temp, true);
}


TEST(PieceVisitor, visitKnightSpots)
{
    
    PieceVisitor *visitor = new PieceVisitor();
    
    ChessPiece *knight = new Knight(3,3,'b','N');
    
    bool upright = knight->accept(visitor, 5,4);
     bool upleft = knight->accept(visitor, 5,2);
     bool e = knight->accept(visitor,4,5);
     bool f = knight->accept(visitor, 4,1);
      bool d = knight->accept(visitor, 2,5);
     bool c = knight->accept(visitor, 2,1);
      bool b= knight->accept(visitor, 1,4);
     bool a = knight->accept(visitor, 1,2);
         
         EXPECT_EQ(upright, true);
         EXPECT_EQ(upleft, true);
         EXPECT_EQ(e, true);
         EXPECT_EQ(f, true);
         EXPECT_EQ(d, true);
        EXPECT_EQ(c, true); 
         EXPECT_EQ(b, true);
         EXPECT_EQ(a, true);
}

TEST(PieceVisitor, visitKnightFails)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *knight = new Knight(3,3,'b','N');

    bool upright = knight->accept(visitor, 7,3);
     bool upleft = knight->accept(visitor, 6,4);
     bool e = knight->accept(visitor,4,7);
     bool f = knight->accept(visitor, 3,0);
      bool d = knight->accept(visitor, 100,20);
     bool c = knight->accept(visitor, -5, 4);
      bool b= knight->accept(visitor, 8,8);
     bool a = knight->accept(visitor, 7,7);

         EXPECT_EQ(upright, false);
         EXPECT_EQ(upleft, false);
         EXPECT_EQ(e, false);
         EXPECT_EQ(f, false);
         EXPECT_EQ(d, false);
        EXPECT_EQ(c, false);
         EXPECT_EQ(b, false);
         EXPECT_EQ(a, false);
}

TEST(PieceVisitor, visitQueenPasses)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *queen = new Queen(3,3,'b','N');

    bool upright = queen->accept(visitor, 7,3);
     bool upleft = queen->accept(visitor, 0,3);
     bool e = queen->accept(visitor,3,7);
     bool f = queen->accept(visitor,3,0);
      bool d = queen->accept(visitor, 7,7);
     bool c = queen->accept(visitor, 0,0);
      bool b= queen->accept(visitor, 0,6);
     bool a = queen->accept(visitor,5,1);
     bool x = queen->accept(visitor,2,4);

         EXPECT_EQ(upright, true);
         EXPECT_EQ(upleft, true);
         EXPECT_EQ(e, true);
         EXPECT_EQ(f, true);
         EXPECT_EQ(d, true);
         EXPECT_EQ(c, true);
         EXPECT_EQ(b, true);
         EXPECT_EQ(a, true);
         EXPECT_EQ(x, true);
}

TEST(PieceVisitor, visitQueenFails)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *queen = new Queen(3,3,'b','N');

    bool upright = queen->accept(visitor,5 ,6);
     bool upleft = queen->accept(visitor, 6,4);
     bool e = queen->accept(visitor,4,7);
     bool f = queen->accept(visitor, 0,1);
      bool d = queen->accept(visitor, 100,20);
     bool c = queen->accept(visitor, -5, 4);
      bool b= queen->accept(visitor, 11,10);
     bool a = queen->accept(visitor, 6,7);

         EXPECT_EQ(upright, false);
         EXPECT_EQ(upleft, false);
         EXPECT_EQ(e, false);
         EXPECT_EQ(f, false);
         EXPECT_EQ(d, false);
        EXPECT_EQ(c, false);
         EXPECT_EQ(b, false);
         EXPECT_EQ(a, false);
}

TEST(PieceVisitor, visitKingPasses)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *king = new King(3,3,'b','N');

    bool upright = king->accept(visitor,4 ,3);
     bool upleft = king->accept(visitor,4,4);
     bool e = king->accept(visitor,4,2);
     bool f = king->accept(visitor, 3,4);
      bool d = king->accept(visitor, 3,2);
     bool c = king->accept(visitor, 2, 4);
      bool b= king->accept(visitor, 2,2);
     bool a = king->accept(visitor, 2,3);

         EXPECT_EQ(upright,true);
         EXPECT_EQ(upleft, true);
         EXPECT_EQ(e, true);
         EXPECT_EQ(f, true);
         EXPECT_EQ(d, true);
        EXPECT_EQ(c, true);
         EXPECT_EQ(b, true);
         EXPECT_EQ(a, true);
}

TEST(PieceVisitor, visitKingFails)
{
    
    PieceVisitor *visitor = new PieceVisitor();
    
    ChessPiece *king = new King(3,3,'b','N');
    
    bool upright = king->accept(visitor,5 ,6);
     bool upleft = king->accept(visitor, 6,4);
     bool e = king->accept(visitor,4,7);
     bool f = king->accept(visitor, 0,1);
      bool d = king->accept(visitor, 100,20);
     bool c = king->accept(visitor, -5, 4);
      bool b= king->accept(visitor, 11,10);
     bool a = king->accept(visitor, 6,7);
         
         EXPECT_EQ(upright, false);
         EXPECT_EQ(upleft, false);
         EXPECT_EQ(e, false);
         EXPECT_EQ(f, false);
         EXPECT_EQ(d, false);
        EXPECT_EQ(c, false);
         EXPECT_EQ(b, false);
         EXPECT_EQ(a, false);
}
TEST(PieceVisitor,visitBishopPass)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *bishop = new Bishop(3,3,'b','N');

    bool upright = bishop->accept(visitor,6,0);
     bool upleft = bishop->accept(visitor,1,5 );
     bool e = bishop->accept(visitor,2,4);
     bool f = bishop->accept(visitor,6,0);
      bool d = bishop->accept(visitor,4,2);
     bool c = bishop->accept(visitor,0, 6);
      bool b= bishop->accept(visitor,0,0);
     bool a = bishop->accept(visitor, 7,7);

         EXPECT_EQ(upright, true);
         EXPECT_EQ(upleft,true);
         EXPECT_EQ(e, true);
         EXPECT_EQ(f, true);
         EXPECT_EQ(d,true);
        EXPECT_EQ(c,true);
         EXPECT_EQ(b,true);
         EXPECT_EQ(a, true);
}

TEST(PieceVisitor, visitBishopFails)
{

    PieceVisitor *visitor = new PieceVisitor();

    ChessPiece *bishop = new Bishop(3,3,'b','N');

    bool upright = bishop->accept(visitor,5,6);
     bool upleft = bishop->accept(visitor, 6,4);
     bool e = bishop->accept(visitor,4,7);
     bool f = bishop->accept(visitor,0,1);
      bool d = bishop->accept(visitor,100,20);
     bool c = bishop->accept(visitor,-5, 4);
      bool b= bishop->accept(visitor,11,10);
     bool a = bishop->accept(visitor, 6,7);

         EXPECT_EQ(upright, false);
         EXPECT_EQ(upleft, false);
         EXPECT_EQ(e, false);
         EXPECT_EQ(f, false);
         EXPECT_EQ(d, false);
        EXPECT_EQ(c, false);
         EXPECT_EQ(b, false);
         EXPECT_EQ(a, false);
}
                                                                                                             


