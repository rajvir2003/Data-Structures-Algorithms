#include<bits/stdc++.h>
using namespace std;

void nQueens(int col, int n, vector<vector<int>> &board, vector<int> places, vector<vector<int>> &solutions, vector<int> UD, vector<int> R, vector<int> LD){
    if(col == n){
        solutions.push_back(places);
        return;
    }
    for(int row = 0; row < n; row++){
        if(UD[(n-1)+(row-col)] == 0 && R[row] == 0 && LD[row+col] == 0){
            board[row][col] = 1;
            UD[(n-1)+(row-col)] = 1;
            R[row] = 1;
            LD[row+col] = 1;
            places.push_back(row+1);
            nQueens(col+1, n, board, places, solutions, UD, R, LD);
            board[row][col] = 0;
            UD[(n-1)+(row-col)] = 0;
            R[row] = 0;
            LD[row+col] = 0;
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
    
    vector<int> upperDiagonal(2*n-1,0);
    vector<int> Row(n,0);
    vector<int> lowerDiagonal(2*n-1,0);

    nQueens(0, n, board, places, solutions, upperDiagonal, Row, lowerDiagonal);

    for(auto i : solutions){
        for(auto j : i){
            cout << j << " ";
        } cout << endl;
    }

    return 0;
}