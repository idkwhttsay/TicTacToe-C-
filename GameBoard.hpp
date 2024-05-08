//
//  GameBoard.hpp
//  TicTacToe
//
//  Created by DanTatar on 06.05.2024.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

class GameBoard {
    
public:
    GameBoard();
    void Render();
    void SetPieceAt(int x, int y, char c);
    char GetPieceAt(int x, int y);
    bool CheckForTheWinner();
    bool checkInput(int x, int y);
private:
    static int BOARD_WIDTH;
    static int BOARD_HEIGHT;
    char positions[9];
};

#endif /* GameBoard_hpp */
