/*
 * #include "chessPiece.hpp"
 * #include "knight.hpp"
 * #include "pawn.hpp"
 * #include "bishop.hpp"
 * #include "rook.hpp"
 * #include "king.hpp"
 * #include "queen.hpp"
 * #include "knight.hpp"
 * #include "visitor.hpp"(commented out)
 * #include "piecevisitor.hpp"
 * #include "checkmateVisitor.hpp"
 * #include <iostream>
 * #include <string>
 *
 *
 *
 * int main()
 * {
 *     PieceVisitor *visitor = new PieceVisitor();
 *         
 *             ChessPiece *pawn = new Pawn(0,1,'w','N');
 *                 ChessPiece *rook = new Rook(7,7,'w', 'R');
 *                     ChessPiece *king = new King(0,0,'w', 'R');
 *                         ChessPiece *queen = new Queen(2,3, 'w', 'Q');
 *                             ChessPiece *bishop = new Bishop(5,7, 'B',  'D');
 *                                 ChessPiece *knight = new Knight(0,0,'w', 'R');
 *                                     
 *                                         CheckmateVisitor *visit = new CheckmateVisitor();
 *
 *                                             std::cout << rook->get_X() << std::endl;
 *                                                 std::cout << rook->get_Y() << std::endl;
 *                                                     std::cout << rook->get_color() << std::endl;
 *                                                         std::cout << rook->get_name() << std::endl;
 *
 *                                                             if(rook->accept(visit,7,5))
 *                                                                 {
 *                                                                         std::cout << "move valid" << std::endl;
 *
 *                                                                             }
 *                                                                                 else
 *                                                                                     {
 *                                                                                             std::cout << "move invalid" << std::endl;
 *                                                                                                 }
 *
 *                                                                                                     return 0;
 *
 *                                                                                                     };
 *                                                                                                     */



#include "chessPiece.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
#include "visitor.hpp"
#include "piecevisitor.hpp"
#include "board.cpp"
#include <iostream>
#include <string>
#include<stdlib.h>

 
int main (){
    Board* chessboard = new Board();
    chessboard->resetBoard();
    chessboard->printBoard();
    chessboard->printPrompt();
    
    delete chessboard;



return 0;

}


