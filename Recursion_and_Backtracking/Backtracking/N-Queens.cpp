#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int i = row;
    int j = col;
    // checking row
    while(j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    i = row;
    j = col;
    // checking upper diagonal
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--; j--;
    }

    i = row;
    j = col;
    // checking lower diagonal
    while(i < n && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i++; j--;
    }
    return true;
}

void nQueens(int col, int n, vector<vector<int>> &board, vector<int> places, vector<vector<int>> &solutions){
    if(col == n){
        solutions.push_back(places);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            places.push_back(row+1);
            nQueens(col+1, n, board, places, solutions);
            board[row][col] = 0;
            places.pop_back();
        }
    }
}

int main(){
    int n;
    cout << "Input: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> solutions;
    vector<int> places;

    nQueens(0, n, board, places, solutions);

    cout << "Solutions for " << n << " X " << n << " chessboard: " << endl;
    for(auto i : solutions){
        for(auto j : i){
            cout << j << " ";
        } cout << endl;
    }
     
    return 0;
}