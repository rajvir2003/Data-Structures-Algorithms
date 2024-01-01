#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int>> &board){ 
    for(int i = 0; i < board.size(); i++){
        // check row
        if(board[row][i] == val) return false;
        // check col
        if(board[i][col] == val) return false;
    }

    // check 3x3 matrix
    int inI = row-row%3;
    int inJ = col-col%3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[inI+i][inJ+j] == val) return false;
        }
    }
    return true;
}

bool SudokuSolver(vector<vector<int>> &board){
    // iterate through every cell of the board
    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board.size(); col++){
            // if cell is empty
            if(board[row][col] == 0){
                // try to put values from 1 to 9
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row, col, val, board)){
                        board[row][col] = val;

                        if(SudokuSolver(board)) return true;
                        else board[row][col] = 0;   // if solution does not exist then backtrack and try to put other values
                    }
                }
                // if no value is satisfying the conditions then return false
                return false;
            }
        }
    }
    // if there is no empty cell then return true
    return true;
}

int main(){
    vector<vector<int>> board = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if(SudokuSolver(board)){
        for(auto i: board){
            for(auto j: i){
                cout << j << " ";
            } cout << endl;
        }
    }

    return 0;
}