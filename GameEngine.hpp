//
//  GameEngine.hpp
//  TicTacToe
//
//  Created by DanTatar on 06.05.2024.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include "GameBoard.hpp"

class GameEngine {
public:
    int turn;
    GameBoard board;
    
    GameEngine();
    void Run();
private:
    void NextTurn();
};

#endif /* GameEngine_hpp */
