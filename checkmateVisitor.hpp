#ifndef checkmateVisitor_hpp
#define checkmateVisitor_hpp

#include <stdio.h>

#include "visitor.hpp"

class CheckmateVisitor : public Visitor
{
public:
    
    bool visitPawn(Pawn *pawn, int d_x, int d_y)
    {
        int temp_x = pawn->get_X();
        int temp_y = pawn->get_Y();
        
        
        if(temp_x + 1 == d_x && temp_y + 1 == d_y)
        {
            return true;
        }
        if(temp_x - 1 == d_x && temp_y + 1 == d_y)
        {
            return true;
        }
        
        return false;
        
        
        
    }
    
    
    bool visitRook(Rook *rook, int d_x, int d_y)
    {
        int temp_x = rook->get_X();
        int temp_y = rook->get_Y();
        
        
        if(temp_x == d_x)
        {
            if(temp_y < d_y)
            {
                while(temp_y < 7)
                {
                    if(temp_y + 1 == d_y)
                    {
                        return true;
                    }
                    temp_y += 1;
                }
            }
            
            if(temp_y > d_y)
            {
                while(temp_y > 0)
                {
                    if(temp_y - 1 == d_y)
                    {
                        return true;
                    }
                    temp_y -= 1;
                }
            }
        }
        
        if(temp_y == d_y)
        {
            if(temp_x < d_x)
            {
                while(temp_x < 7)
                {
                    if(temp_x + 1 == d_x && temp_y == d_y)
                    {
                        return true;
                    }
                    temp_x += 1;
                }
            }
            
            if(temp_x > d_x)
            {
                while(temp_x > 0)
                {
                    if(temp_x - 1 == d_x && temp_y == d_y)
                    {
                        return true;
                    }
                    temp_x += 1;
                }
            }
            
        }
        
        
        return false;
    }
    
    bool visitKnight(Knight *knight, int d_x, int d_y)
    {
        return false;
    }
    
    bool visitBishop(Bishop *bishop, int d_x, int d_y)
    {
        return false;
    }
    
    virtual bool visitQueen(Queen *queen, int d_x, int d_y )
    {
        return false;
    }
    
    virtual bool visitKing(King *king, int d_x, int d_y)
    {
        return false;
    }
    
};

#endif

