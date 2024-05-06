//
//  GameBoard.cpp
//  TicTacToe
//
//  Created by DanTatar on 06.05.2024.
//

#include "GameBoard.hpp"
#include <iostream>

using namespace std;

int GameBoard::BOARD_WIDTH = 3;
int GameBoard::BOARD_HEIGHT = 3;

GameBoard::GameBoard(){
    for(int i = 0; i < BOARD_HEIGHT; ++i){
        for(int j = 0; j < BOARD_WIDTH; ++j){
            SetPieceAt(i, j, '.');
        }
    }
}

void GameBoard::SetPieceAt(int x, int y, char c){
    if(x < 0 || y < 0) return;
    if(x > BOARD_HEIGHT-1 || y > BOARD_WIDTH-1) return;
    
    positions[x*3+y] = c;
}

void GameBoard::Render(){
    for(int i = 0; i < BOARD_HEIGHT; ++i){
        for(int j = 0; j < BOARD_WIDTH; ++j){
            cout << ' ' << positions[i*3 + j] << ' ';
            if(j != BOARD_WIDTH - 1) cout << '|';
        }
        
        cout << endl;
        if(i != BOARD_HEIGHT - 1){
            for(int j = 0; j < BOARD_WIDTH; ++j){
                cout << "---";
                if(j != BOARD_WIDTH - 1) cout << '+';
            }
        }
        
        cout << endl;
    }
}
