#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;

    // indexes
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count < total){
        // printing starting row
        for(int index = startingCol; index <= endingCol && count < total; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // printing ending col
        for(int index = startingRow; index <= endingRow && count < total; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // printing ending row
        for(int index = endingCol; index >= startingCol && count < total; index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // printing starting col
        for(int index = endingRow; index >= startingRow && count < total; index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int> > matrix = {
        {5,3,7},
        {8,2,9},
        {0,1,4}
    };

    vector<int> ans = spiralOrder(matrix);
    for(auto i: ans){
        cout << i << " ";
    }

    return 0;
}