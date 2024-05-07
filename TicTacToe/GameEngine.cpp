//
//  GameEngine.cpp
//  TicTacToe
//
//  Created by DanTatar on 06.05.2024.
//

#include "GameEngine.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

GameEngine::GameEngine() : turn(0) {}

void GameEngine::NextTurn(){
    turn = (turn+1) % 2;
}

void GameEngine::Run(){
    cout << "Welcome to the TicTacToe game!" << endl;
    board.Render();
    
    Player FirstPlayer('x');
    Player SecondPlayer('o');
    
    while(true){
        // Read user input
        int x,y;
        
        if(turn == 0){
            cout << "First player's turn" << endl;
        } else {
            cout << "Second player's turn!" << endl;
        }
        
        while(true){
            cout << "Input cell coordinates \n";
            cin >> x >> y;
            if(board.checkInput(x, y)) break;
        }
        
        if(turn == 0){
            board.SetPieceAt(x, y, FirstPlayer.symbol);
        } else {
            board.SetPieceAt(x, y, SecondPlayer.symbol);
        }
        
        // Check winner
        if(board.CheckForTheWinner()){
            if(turn == 0){
                cout << "First player won!" << endl;
            } else {
                cout << "Second player won!" << endl;
            }
            
            break;
        }
        
        // Render and NextTurn
        NextTurn();
        board.Render();
    }
}
