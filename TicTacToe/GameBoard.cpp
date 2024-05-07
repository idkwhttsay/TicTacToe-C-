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
    positions[x*3+y] = c;
}

char GameBoard::GetPieceAt(int x, int y){
    return positions[x*3+y];
}

bool GameBoard::CheckForTheWinner(){
    for(int i = 0; i < BOARD_HEIGHT; ++i){
        if(GetPieceAt(i, 0) == '.') continue;
        
        bool ok = true;
        for(int j = 1; j < BOARD_WIDTH; ++j){
            if(GetPieceAt(i, j-1) != GetPieceAt(i, j)) {
                ok = false;
                break;
            }
        }
        
        if(ok){
            return true;
        }
    }
    
    for(int i = 0; i < BOARD_WIDTH; ++i){
        if(GetPieceAt(0, i) == '.') continue;
        
        bool ok = true;
        for(int j = 1; j < BOARD_HEIGHT; ++j){
            if(GetPieceAt(j - 1, i) != GetPieceAt(j, i)) {
                ok = false;
                break;
            }
        }
        
        if(ok){
            return true;
        }
    }
    
    if(GetPieceAt(0, 0) != '.'){
        bool ok = true;
        for(int i = 1; i < BOARD_WIDTH; ++i){
            if(GetPieceAt(i-1, i-1) != GetPieceAt(i, i)){
                ok = false;
                break;
            }
        }
        
        if(ok){
            return true;
        }
    }
    
    if(GetPieceAt(0, BOARD_WIDTH-1) != '.'){
        bool ok = true;
        for(int i = 1, j = BOARD_WIDTH-2; i < BOARD_WIDTH; ++i, --j){
            if(GetPieceAt(i-1, j+1) != GetPieceAt(i, j)){
                ok = false;
                break;
            }
        }
        
        if(ok){
            return true;
        }
    }
    
    return false;
}

void GameBoard::Render(){
    
    cout << "   | 0 | 1 | 2 " << endl;
    cout << "---+---+---+---" << endl;
    
    for(int i = 0; i < BOARD_HEIGHT; ++i){
        cout << " " << i << " |";
        for(int j = 0; j < BOARD_WIDTH; ++j){
            cout << ' ' << positions[i*3 + j] << ' ';
            if(j != BOARD_WIDTH - 1) cout << '|';
        }
        
        cout << endl;
        if(i != BOARD_HEIGHT - 1){
            for(int j = 0; j <= BOARD_WIDTH; ++j){
                cout << "---";
                if(j != BOARD_WIDTH) cout << '+';
            }
        }
        
        cout << endl;
    }
}

bool GameBoard::checkInput(int x, int y){
    if(x < 0 || y < 0 || x > BOARD_HEIGHT-1 || y > BOARD_WIDTH-1) {
        cout << "Out of board bounds. Try again \n";
        return false;
    }
    
    if(GetPieceAt(x, y) != '.'){
        cout << "This cell is taken. Try again \n";
        return false;
    }
    
    return true;
}
