#include "board.hpp"


Board::Board(){
    
    for(unsigned int i = 0; i < 8; i++){
        for(unsigned int j = 0; j < 8; j++){
            board[i][j] = nullptr;
        }
    }
}
Board::~Board()
{
	for (int i = 0; i < 8; i++) {
      	  for (int j = 0; j < 8; j++) {
            if(board[i][j] != nullptr)
            {
                delete board[i][j]; // delete stored pointer
            }
        }
    }
}

ChessPiece* Board::getPiece(int x, int y){
    
    return board[x][y];
}

void Board::resetBoard(){
    
    
    ChessPiece* r1 = new Rook(0,0, 'b', 'R');
    ChessPiece* r2 = new Rook(0,7, 'b', 'R');
    ChessPiece* r3 = new Rook(7,0, 'w', 'r');
    ChessPiece* r4 = new Rook(7,7,'w', 'r');
    ChessPiece* n1 = new Knight(0,1,'b', 'N');
    ChessPiece* n2 = new Knight(0,6, 'b', 'N');
    ChessPiece* n3 = new Knight(7,1, 'w', 'n');
    ChessPiece* n4 = new Knight(7,6,'w', 'n');
    ChessPiece* b1 = new Bishop(0,2, 'b', 'B');
    ChessPiece* b2 = new Bishop(0,5, 'b', 'B');
    ChessPiece* b3 = new Bishop(7,2,'w', 'b');
    ChessPiece* b4 = new Bishop(7,5,'w', 'b');
    ChessPiece* k1 = new King(0,3, 'b', 'K');
    ChessPiece* k2 = new King(7,3,'w', 'k');
    ChessPiece* q1 = new Queen(0,4, 'b', 'Q');
    ChessPiece* q2 = new Queen(7,4,'w', 'q');
    ChessPiece *p1 = new Pawn(1,0, 'b', 'P');
    ChessPiece *p2 = new Pawn(1,1,'b', 'P');
    ChessPiece *p3 = new Pawn(1,2,'b', 'P');
    ChessPiece *p4 = new Pawn(1,3,'b', 'P');
    ChessPiece *p5 = new Pawn(1,4,'b', 'P');
    ChessPiece *p6 = new Pawn(1,5,'b', 'P');
    ChessPiece *p7 = new Pawn(1,6,'b', 'P');
    ChessPiece *p8 = new Pawn(1,7,'b', 'P');
    ChessPiece *p9 = new Pawn(6,0,'w', 'p');
    ChessPiece *p10 = new Pawn(6,1,'w', 'p');
    ChessPiece *p11 = new Pawn(6,2,'w', 'p');
    ChessPiece *p12 = new Pawn(6,3,'w', 'p');
    ChessPiece *p13 = new Pawn(6,4,'w', 'p');
    ChessPiece *p14 = new Pawn(6,5,'w', 'p');
    ChessPiece *p15 = new Pawn(6,6,'w', 'p');
    ChessPiece *p16 = new Pawn(6,7,'w', 'p');
    
    board[0][0] = r1;
    board[0][7] = r2;
    board[7][0] = r3;
    board[7][7] = r4;
    board[0][1] = n1;
    board[0][6] = n2;
    board[7][1] = n3;
    board[7][6] = n4;
    board[0][2] = b1;
    board[0][5] = b2;
    board[7][2] = b3;
    board[7][5] = b4;
    board[0][3]= k1;
    b_k_x = 0;
    b_k_y = 3;
    board[7][3]= k2;
    w_k_x = 7;
    w_k_y = 3;
    board[0][4]= q1;
    board[7][4]= q2;
    board[1][0]= p1;
    board[1][1]= p2;
    board[1][2]= p3;
    board[1][3]= p4;
    board[1][4]= p5;
    board[1][5]= p6;
    board[1][6]= p7;
    board[1][7]= p8;
    board[6][0]= p9;
    board[6][1]= p10;
    board[6][2]= p11;
    board[6][3]= p12;
    board[6][4]= p13;
    board[6][5]= p14;
    board[6][6]= p15;
    board[6][7]= p16;
    
}


void Board::printBoard(){
    std::cout << " ============= CHESS GAME ================" << std::endl;
    std::cout << "  0    1   2   3   4   5   6   7" << std::endl;
    std::cout << " _________________________________" << std::endl;
    for(unsigned int i = 0; i < 8; i++){
        for(unsigned int j = 0; j < 8; j++){
            std::cout << " | ";
            if(board[i][j] != nullptr){
                std::cout << board[i][j]->get_name();
            }
            else{
                std::cout << ' ';
            }
            
        }
        std::cout << " |" << std:: endl;
        std::cout << i << "|___|___|___|___|___|___|___|___|" << std::endl ;
        
    }
     std::cout << "  0    1   2   3   4   5   6   7" << std::endl;
}


bool Board::checkAccept ( ChessPiece *piece, int d_x, int d_y){
    PieceVisitor* pVisitor = new PieceVisitor();
    
    
    if(piece->accept(pVisitor, d_x, d_y) && pathCheck(piece, d_x, d_y))
    {
        
        
        if( board[d_x][d_y] != nullptr)
        {
            if(board[d_x][d_y]->get_color() ==  piece->get_color())
            {
                std::cout << "The piece at this spot is not movable"<< std::endl;
		delete pVisitor; 
                return false;
            }
            else
            {
                if( board[d_x][d_y]->get_color() == 'w' ){
                std::cout << "White " << board[d_x][d_y]->get_name() << " was killed " << std::endl;
                }
                else {
                    std::cout << "Black " << board[d_x][d_y]->get_name() << " was killed " << std::endl;
                }
            }
            
        }
	
	delete board[d_x][d_y];
        board[d_x][d_y] = piece;
	
        board[piece->get_X()][piece->get_Y()] = nullptr;

        piece->set_X(d_x);
        piece->set_Y(d_y);
	delete pVisitor;
        
        if(d_x == b_k_x && d_y == b_k_y)
        {
            isThereAWinner = true;
            std::cout << "WHITE WIN!!!\n\n\n";
            
        }
        if(d_x == w_k_x && d_y == w_k_y)
        {
            isThereAWinner = true;
            std::cout << "BLACK WIN!!!\n\n\n";
        }
        
        if(piece->get_color() == 'b' && piece->get_name() == 'K')
        {
            b_k_x = d_x;
            b_k_y = d_y;
        }
        if(piece->get_color() == 'w' && piece->get_name() == 'k')
        {
            w_k_x = d_x;
            w_k_y = d_y;
        }
        printBoard();
        return true;
        
        
        
        
        
    }
    delete pVisitor;
    return false;
    
}




bool Board::pathCheck(ChessPiece *piece, int d_x, int d_y)
{
    int temp_x = piece->get_X();
    int temp_y = piece->get_Y();
    
    if(piece->get_name() == 'R' || piece->get_name() == 'r')
    {
        if(temp_y == d_y)
        {
            if(temp_x < d_x)
            {
                while(temp_x != d_x - 1)
                {
                    temp_x += 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            if(temp_x > d_x)
            {
                while(temp_x != d_x + 1)
                {
                    temp_x -= 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
        }
        
        if(temp_x == d_x)
        {
            if(temp_y < d_y)
            {
                while(temp_y != d_y - 1)
                {
                    temp_y += 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            if(temp_y > d_y)
            {
                while(temp_y != d_y + 1)
                {
                    temp_y -= 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
        }
    }
    
    if(piece->get_name() == 'p' || piece->get_name() == 'P')
    {
        int temp_y = piece->get_Y();
        int temp_x = piece->get_X();
        
        
        
        if(piece->get_color() == 'w')
        {
            if((board[temp_x-1][temp_y] != NULL && d_x == temp_x - 1 && d_y == temp_y)
               || (board[temp_x-1][temp_y] != NULL && d_x == temp_x - 2 && d_y == temp_y))
            {
                return false;
            }
            if(d_x == temp_x - 1 && d_y == temp_y + 1)
            {
                if(board[d_x][d_y] != NULL)
                {
                    return true;
                }
                return false;
            }
            if(d_x == temp_x - 1 && d_y == temp_y - 1)
            {
                if(board[d_x][d_y] != NULL)
                {
                    return true;
                }
                return false;
            }
            return true;
        }
        if(piece->get_color() == 'b')
        {
            if((board[temp_x+1][temp_y] != NULL && d_x == temp_x + 1 && d_y == temp_y) || (board[temp_x+1][temp_y] != NULL && d_x == temp_x + 2 && d_y == temp_y))
            {
                return false;
            }
            if(d_x == temp_x + 1 && d_y == temp_y + 1)
            {
                if(board[d_x][d_y] != NULL)
                {
                    return true;
                }
                return false;
            }
            if(d_x == temp_x + 1 && d_y == temp_y - 1)
            {
                if(board[d_x][d_y] != NULL)
                {
                    return true;
                }
                return false;
            }
        }
        
        
        return true;
        
    }
    
    if(piece->get_name() == 'N' || piece->get_name() == 'n')
    {
        return true;
    }
    
    
    if(piece->get_name() == 'B' || piece->get_name() == 'b')
    {
        /*b  diagonal down right*/
        
        if((temp_x < d_x) && (temp_y < d_y))
        {
            while((temp_x != d_x - 1) && (temp_y != d_y - 1))
            {
                temp_x += 1;
                temp_y += 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        if((temp_x > d_x) && (temp_y > d_y))      /*w diagonal upper  left*/
        {
            while((temp_x != d_x + 1) && (temp_y != d_y + 1))
            {
                temp_x -= 1;
                temp_y -= 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        /*b diagonal down left*/
        
        if((temp_x < d_x) && (temp_y > d_y))
        {
            while((temp_x != d_x - 1) && (temp_y != d_y + 1))
            {
                temp_x += 1;
                temp_y -= 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        if((temp_x > d_x) && (temp_y < d_y)) /*w diagonal upper right*/
        {
            while((temp_x != d_x + 1) && (temp_y != d_y - 1))
            {
                temp_x -= 1;
                temp_y += 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        return true;
    }
    
    if(piece->get_name() == 'K' || piece->get_name() == 'k')
    {
        return true;
    }
    
    if(piece->get_name() == 'Q' || piece->get_name() == 'q')
    {
        /*b  diagonal down right*/
        
        if((temp_x < d_x) && (temp_y < d_y))
        {
            while((temp_x != d_x - 1) && (temp_y != d_y - 1))
            {
                temp_x += 1;
                temp_y += 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        if((temp_x > d_x) && (temp_y > d_y))      /*w diagonal upper  left*/
        {
            while((temp_x != d_x + 1) && (temp_y != d_y + 1))
            {
                temp_x -= 1;
                temp_y -= 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        /*b diagonal down left*/
        
        if((temp_x < d_x) && (temp_y > d_y))
        {
            while((temp_x != d_x - 1) && (temp_y != d_y + 1))
            {
                temp_x += 1;
                temp_y -= 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        
        if((temp_x > d_x) && (temp_y < d_y)) /*w diagonal upper right*/
        {
            while((temp_x != d_x + 1) && (temp_y != d_y - 1))
            {
                temp_x -= 1;
                temp_y += 1;
                if(board[temp_x][temp_y] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        
        if(temp_y == d_y)
        {
            if(temp_x < d_x)
            {
                while(temp_x != d_x - 1)
                {
                    temp_x += 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            if(temp_x > d_x)
            {
                while(temp_x != d_x + 1)
                {
                    temp_x -= 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
        }
        
        if(temp_x == d_x)
        {
            if(temp_y < d_y)
            {
                while(temp_y != d_y - 1)
                {
                    temp_y += 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            if(temp_y > d_y)
            {
                while(temp_y != d_y + 1)
                {
                    temp_y -= 1;
                    if(board[temp_x][temp_y] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            
        }
        
        
    }
    
    return true;
}



void Board::printPrompt()
{
    int counter = 0;
    char color;
    
    do
    {
        
        std::string temp = "";
        int currRow = 0;
        int currCol=0;
        int destRow=0;
        int destCol=0;
        
        if(counter % 2 ==0){
            std::cout << "White's turn to play (lower case pieces):   " << std::endl;
            color = 'w';
        }
        else {
            std::cout << "Black's turn to play (upper case pieces):   " << std::endl;

            color = 'b';
        }
        
        std:: cout << " Row of piece you want to move (0-7) : (Enter F to forfeit)" << std::endl;
        std::cin >> temp;
        if(temp == "F" || temp == "f")
        {
            std::cout << "YOU SUCK LOSER!!!\n\n";
            break;
        }
        
        if(!is_number(temp))
        {
            std::cout << "invalid input, please check coordinates again.\n\n";
            printBoard();
            continue;
        }
        currRow = std::stoi(temp);
        
        std::cout << " Column of piece you want to move (0-7): " << std::endl;
        std::cin >> temp;
        
        if(!is_number(temp))
        {
            std::cout << "invalid input, please check coordinates again.\n\n";
            printBoard();
            continue;
        }
        currCol = std::stoi(temp);
        
        if(userInputCheck(currRow) && userInputCheck(currCol))
        {
            if(board[currRow][currCol] != NULL)
            {
                ChessPiece* curr = getPiece(currRow, currCol);
                if(curr->get_color() != color){
                    std::cout << "Not your piece: Choose a piece of your color. "<< std::endl;
                    continue;
                }
                
                std::cout <<"Moving Piece " << curr->get_name()<< " at spot (" << currRow << ","<< currCol << ")"<< std:: endl;
                
                std:: cout << " Row of where you want to move (0-7) : " << std::endl;
		std::cin >> temp;
                
                if(!is_number(temp))
                {
                    std::cout << "invalid input, please check coordinates again.\n\n";
                    printBoard();
                    continue;
                }
                destRow = std::stoi(temp);                


                std::cout << " Column of where you want to move (0-7): " << std::endl;
                std::cin >> temp;
                
                if(!is_number(temp))
                {
                    std::cout << "invalid input, please check coordinates again.\n\n";
                    printBoard();
                    continue;
                }
                destCol = std::stoi(temp);
		

                if(checkAccept(curr, destRow, destCol) == true)
                {
                    std::cout << " Piece moved to new spot\n\n" << std::endl;
                    counter = counter +1;
                    continue;
                }
                
            }
            std::cout << " invalid input, please check coordinates again.\n\n" << std::endl;
            printBoard();
        }
        
        
    }
    while (!isThereAWinner);
    
    
    
}


bool Board::userInputCheck(int temp)
{
    if(temp >= 0 && temp <= 7)
    {
        return true;
    }
    
    
    std::cout << "invalid input, please check coordinates again.\n\n\n";
    printBoard();
    return false;
}



bool Board::is_number(const std::string& s)
{
    return !s.empty() && find_if(s.begin(),
                                 s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

