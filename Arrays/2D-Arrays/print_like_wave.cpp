#include<bits/stdc++.h>
using namespace std;

vector<int> printWave(vector<vector<int>> matrix, int nRows, int mCols){
    vector<int> v;
    
    for (int col = 0; col < mCols ; col++)
    {
        if(col&1){
            // if col is odd -> move bottom to top
            for (int row = nRows-1; row >= 0; row--)
            {
                v.push_back(matrix[row][col]);
            } 
        }
        else{
            // if col is even -> move top to bottom
            for (int row = 0; row < nRows; row++)
            {
                v.push_back(matrix[row][col]);
            }
        }
    }
    return v;
}

int main(){
    vector<vector<int>> matrix = {
        {2,4,5,7},
        {9,7,3,1},
        {8,3,5,6}
    };
    int row = 3;
    int col = 4;

    vector<int> ans = printWave(matrix,row,col);
    for(auto i : ans){
        cout << i << " ";
    }

    return 0;
}