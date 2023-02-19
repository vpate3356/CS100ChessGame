#ifndef PieceVisitor_hpp
#define PieceVisitor_hpp

#include <math.h>


#include "visitor.hpp"

class PieceVisitor : public Visitor
{
    
public:
    
    bool visitKnight(Knight *knight, int d_x, int d_y)
    {
        int temp_x = knight->get_X();
        int temp_y = knight->get_Y();
        if ((abs(temp_x - d_x) == 2 && abs(temp_y - d_y) == 1) || (abs(temp_x - d_x)) == 1 && abs(temp_y - d_y) == 2){
            return true;
        }
        else {
            return false;
        }
    }
    
    bool visitBishop(Bishop *bishop, int d_x, int d_y)
    
    {
        
        
        
        int temp_x = bishop->get_X();
        
        int temp_y = bishop->get_Y();
        
        
        
        if ((abs(d_x - temp_x ) == abs(d_y - temp_y)) && (abs(d_x - temp_x)<=7) && (abs(d_y - temp_y)<=7))
            
        {
            
            return true;
            
        }
        
        else return false;
        
        
        
    }
    
    
    bool visitPawn(Pawn *pawn, int d_x, int d_y)
    {
        int temp_x = pawn->get_X();
        int temp_y = pawn->get_Y();
        
        if(pawn->getPawn_isMoved() == true)
        {
            if(pawn->get_color() == 'w' || pawn->get_color() == 'W')
            {
                if(d_y == temp_y && d_x - temp_x == -1)
                {
                    return true;
                }
                if(d_y - temp_y == -1 && d_x - temp_x == -1)
                {
                    
                    return true;
                }
                if(d_y - temp_y == 1 && d_x - temp_x == -1)
                {
                    
                    return true;
                }
            }
            
            if(pawn->get_color() == 'b' || pawn->get_color() == 'B')
            {
                if(d_y == temp_y && d_x - temp_x == 1)
                {
                    return true;
                }
                if(d_y - temp_y == -1 && d_x - temp_x == 1)
                {
                    
                    return true;
                }
                if(d_y - temp_y == 1 && d_x - temp_x == 1)
                {
                    
                    return true;
                }
            }
            
        }
        else
        {
            if(pawn->get_color() == 'w' || pawn->get_color() == 'W')
            {
                if(d_y == temp_y && d_x - temp_x == -1)
                {
                    pawn->setPawn_isMoved();
                    return true;
                }
                
                if(d_y - temp_y == -1 && d_x - temp_x == -1)
                {
                    
                    return true;
                }
                if(d_y - temp_y == 1 && d_x - temp_x == -1)
                {
                    
                    return true;
                }
                
                if(d_y == temp_y && d_x - temp_x == -2)
                {
                    pawn->setPawn_isMoved();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            if(pawn->get_color() == 'b' || pawn->get_color() == 'B')
            {
                if(d_y == temp_y && d_x - temp_x == 1)
                {
                    pawn->setPawn_isMoved();
                    return true;
                }
                
                if(d_y - temp_y == -1 && d_x - temp_x == 1)
                {
                    
                    return true;
                }
                if(d_y - temp_y == 1 && d_x - temp_x == 1)
                {
                    
                    return true;
                }
                
                if(d_y == temp_y && d_x - temp_x == 2)
                {
                    pawn->setPawn_isMoved();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            
        }
        return false;
    }
    
    bool visitRook(Rook *rook, int d_x, int d_y)
    {
        int temp_x = rook->get_X();
        int temp_y = rook->get_Y();
        int temp;
        
        if(d_x == temp_x)
        {
            temp = d_y - temp_y;
            if(-7 <= temp && temp <= 7)
            {
                return true;
            }
            
            return false;
        }
        if(d_y == temp_y)
        {
            temp = d_x - temp_x;
            
            if(-7 <= temp && temp <= 7)
            {
                return true;
            }
            
        }
        return false;
    }
    
    bool visitKing(King *king, int d_x, int d_y)
    {
        int temp_x = king->get_X();
        int temp_y = king->get_Y();
        
        if (abs(d_x - temp_x) == 1 && d_y == temp_y)
        {
            return true;
        }
        else if (abs(d_y - temp_y) == 1 && d_x == temp_x)
        {
            return true;
        }
        else if(abs(d_x - temp_x)==(abs(d_y - temp_y) && (abs(d_x - temp_x)<=1) && (abs(d_y - temp_y)<=1)))
        {
            return true;
        }
        else return false;
    }
    
    bool visitQueen(Queen *queen, int d_x, int d_y )
    {
        int temp_x = queen->get_X();
        int temp_y = queen->get_Y();
        
        
        if(temp_x == d_x  && (abs(d_y - temp_y)<=7))
        {   // going up or down
            return true;
        }
        else if(temp_y == d_y  && (abs(d_x - temp_x)<=7))
        { // side
            return true;
        }
        
        else if ((abs(d_x - temp_x )== abs(d_y - temp_y)) && (abs(d_x - temp_x)<=7) && (abs(d_y - temp_y)<=7))
        { //diagonal
            return true;
        }
        return false;
        
    }
};



#endif

