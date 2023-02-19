#ifndef board_hpp
#define board_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <ios>
#include <limits>
#include <algorithm>
#include "pawn.cpp"
#include "rook.cpp"
#include "queen.cpp"
#include "knight.cpp"
#include "king.cpp"
#include "bishop.cpp"

#include "piecevisitor.hpp"



class Board{
private:
ChessPiece *board[8][8];
int w_k_x;
int w_k_y;
int b_k_x;
int b_k_y;
bool isThereAWinner = false;


public:
Board();
~Board();
ChessPiece* getPiece(int x, int y);
void resetBoard();
void printBoard();
bool checkAccept(ChessPiece *piece, int d_x, int d_y);
bool checkMate(ChessPiece *piece, int d_x, int d_y);
bool pathCheck(ChessPiece *piece, int d_x, int d_y);
void printPrompt();
bool userInputCheck(int temp);
bool is_number(const std::string& s);
};

#endif


