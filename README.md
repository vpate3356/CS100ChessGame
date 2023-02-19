# Chess Game

 Authors: [Carolina Mena](https://github.com/cmena004),[Yuteng Terrence Wu](https://github.com/YTTWu),[Vraj Patel](https://github.com/vpate3356)

## Project Description


For our project, we decided to create a chess game. Chess is interesting due to many factors, one being that it is a complex game that requires analytical and strategic thinking. This is similar to programming which also requires logical thinking and evaluation of all moves which can affect the entire process. There are many possible combinations and strategies to play a game of chess and likewise in programming there are various ways to create a program. 
  
We plan on using C++ for our game via hammer. 

Our game will have the following input and ouput:
  Input: Two users will each take turns on deciding where to move their individual chess pieces on the game board by using algebraic notation.   
  Output: Each player's moves and which coordinates their pieces move to will be updated and displayed on a new board in the program each time. The new board will be printed after every move.  Once the game is won by one of the two players,the side of the player(Black/White) will be displayed as the winner. 


 We will implement the following design patterns:

 1. Strategy -
We chose this pattern to define each chess pieces. Since strategy patterns are used to manage algorithms and relationships between objects. Each individual piece will have its accept function implemenetation that is unique to it. A problem we will anticipate is making each piece move how its supposed to. To solve this, we will have a base abstract class which all classes can extend and have their own overrited implementation and movement implementations through visitor patterns. 

 2. Visitor - 
We will use the visitor pattern to check if every move made is valid. Inside each type of pieces we have a accept method corresponded with the visit method. Since we have 6 different type we will have 6 unique visit method to check the user desired move is whether allowed within the Chess rule.

## Class Diagram
 
<img width="857" alt="chessGameUML1" src="https://user-images.githubusercontent.com/77029246/110759750-cd3ffb80-8202-11eb-9e16-7d0d99aae481.png">


 
Class diagram description:

The Board class will contain getPiece(int x, int y) to return the piece; resetBoard() to reset the piece coordinates; printBoard() to print out the board visually; checkAccept(ChessPiece *piece, int d_x, int d_y) to check if the move is within the chess rules; PathCheck(ChessPiece *piece, int d_x, int d_y) to make sure the move is valid on the board; printPrompt() to intereact with players; userInputCheck(int temp) and is_number(const std::string& s) are just small helper functions.

We will use a visitor and strategy pattern for our chess game. The strategy pattern will be used for the class ChessPiece. We use strategy pattern to decide what move() function to implement depend on the players choice. The visitor pattern will actually implement the chess piece moving rule for each piece and make sure it is valid. 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots

Simple game resulting in win for white.

<img width="499" alt="1" src="https://user-images.githubusercontent.com/76971229/110770709-7f30f500-820e-11eb-81d9-e5f94783cdb9.png">

<img width="511" alt="2" src="https://user-images.githubusercontent.com/76971229/110770718-81934f00-820e-11eb-9a0c-ca0fdb468837.png">

<img width="485" alt="3" src="https://user-images.githubusercontent.com/76971229/110770723-835d1280-820e-11eb-9f5d-482aba2af55c.png">

Output messages:

Invalid input by user (moving to an unavaible spot, move not capable by a piece).

<img width="475" alt="invalid input" src="https://user-images.githubusercontent.com/76971229/110771680-a0461580-820f-11eb-8c0f-754dc1be5481.png">

Wrong player makes a move.

<img width="533" alt="wrong player move" src="https://user-images.githubusercontent.com/76971229/110771687-a3410600-820f-11eb-8282-f892641458cc.png">

Forfeit the game.

<img width="457" alt="forfeit" src="https://user-images.githubusercontent.com/76971229/110771675-9e7c5200-820f-11eb-948b-c28381aa7164.png">

Winning the game.

<img width="424" alt="win" src="https://user-images.githubusercontent.com/76971229/110771682-a20fd900-820f-11eb-9365-db6c71ed88c0.png">


FULL GAME SUMMARY


<img width="445" alt="game1" src="https://user-images.githubusercontent.com/77029246/110772913-fe272d00-8210-11eb-9048-dabb9ae77d46.png">
<img width="456" alt="game2" src="https://user-images.githubusercontent.com/77029246/110772918-fff0f080-8210-11eb-9a65-5f617ec57bbe.png">
<img width="435" alt="game3" src="https://user-images.githubusercontent.com/77029246/110772923-01221d80-8211-11eb-87ca-70bdb8de1433.png">
<img width="423" alt="game4" src="https://user-images.githubusercontent.com/77029246/110772951-0a12ef00-8211-11eb-97d2-4ea204ce0242.png">

 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > We used googletests for our chessPiece function and all of it's child classes. We tested their 4 variables which were int x-coor, int y-coor, char name, char color. We also tested each pieces movement with the implementation of PieceVisitor. We tested a variety of valid and invalid coordinates and moves to see where the pieces could move to and could not. By playing the game as users continously and trying to move pieces everywhere, we found bugs and were able to update our classes and functions accordingly. 
 > example: finding pawn error 
 > <img width="483" alt="testingpicpawnerror" src="https://user-images.githubusercontent.com/77029246/110769604-362c7100-820d-11eb-942a-08e11b68b3de.png">
 > 

 > VALGRIND with forfeit 
 > 
 > <img width="688" alt="valgrindforfiet" src="https://user-images.githubusercontent.com/77029246/110773465-9f15e800-8211-11eb-962e-9d6458e190d1.png">
 > 


> VALGRIND after a regular game
> <img width="601" alt="regendingvalgrind" src="https://user-images.githubusercontent.com/77029246/110773362-84dc0a00-8211-11eb-95e2-94d53f44c95a.png">

